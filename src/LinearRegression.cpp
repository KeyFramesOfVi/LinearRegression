#include "../include/LinearRegression.hpp"


LinearRegression::LinearRegression( std::string && data ){
    data_ = data;
	Init();
}
void LinearRegression::Init(){

	/******** Initialize Matrices ********/

	Eigen::MatrixXd x( u_.GetRows( std::move( data_ ) ), u_.GetColumns( std::move( data_ ) ) - 1 );
	Eigen::VectorXd y( u_.GetRows( std::move( data_ ) ) );

	u_.CSVToMatrix( std::move( data_ ), x.cols(), x);
	u_.CSVToVector( std::move( data_ ), x.cols(), y);

	/******** Add Intercept Term to X ********/

	Eigen::MatrixXd temp( x.rows(), x.cols() + 1 );
	temp << Eigen::VectorXd::Ones( x.rows() ), x;
	x = temp;
	temp.resize( 0, 0 ); // Lowers temp memory allocation

	/******** Initialize Weights ********/

	Eigen::VectorXd theta( x.cols() );
	theta.setZero();

	/******** Normalize Data ********/

 	Normalization( x );

 	/******** Set up Parameters for Gradient Descent ********/

 	double alpha = 0.3; // Learning Rate 
 	double num_iters = 100; // Epochs 
 	Eigen::VectorXd j_history = GradientDescent( x, y, theta, alpha, num_iters );
    std::cout << j_history << std::endl; //Print the cost during every iteration of Gradient Descent 
}

void LinearRegression::Normalization( Eigen::MatrixXd & x ){
    Eigen::VectorXd mean = u_.GetMean( x );
    Eigen::VectorXd std = u_.GetStandardDeviation( x, mean );
    
    for( int i = 1; i < x.cols(); ++i )
        x.array().col( i ) -= mean[ i ];

    for( int k = 1; k < x.cols(); ++k ){
        x.col( k ) /= std[ k ];
    }
}

double LinearRegression::ComputeCost( const Eigen::MatrixXd & x, const Eigen::VectorXd & y, const Eigen::VectorXd & theta ){
    int m = y.size();
    Eigen::VectorXd result = ( x * theta - y );
    result = result.array().pow( 2 );
    double J = result.sum();
    J /= ( 2 * m );
    return J; 
}

Eigen::VectorXd LinearRegression::GradientDescent( const Eigen::MatrixXd & x, const Eigen::VectorXd & y, Eigen::VectorXd & theta, double alpha, int num_iters ){
    int m = y.size(); //Length of results 
    int n = x.cols(); // Number of features 
    double result;
    Eigen::MatrixXd temp;
    Eigen::VectorXd J_history(num_iters);
    J_history.setZero();
    Eigen::VectorXd h;
    Eigen::VectorXd t;
    for( int i = 0; i < num_iters; ++i ){
        h = x * theta; 
        t = Eigen::VectorXd::Zero( n );
        for( int j = 0; j < m; ++j ){
            result = h[ j ] - y[ j ];
            temp = x.row( j ).transpose() * result;
            t = t + temp;
        }
        theta = theta - ( alpha * t ) / m;
        J_history[i] = ComputeCost( x, y, theta );
    }
    return J_history;
}
