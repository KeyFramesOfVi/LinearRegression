#include "Utils.hpp" 

#ifndef LINEARREGRESSION_HPP
#define LINEARREGRESSION_HPP


/** Linear Regression class
  *
  * CONSTRUCTION: Takes a .csv file and begins the Linear Regression algorithm
  *
  * ************************************************************************PUBLIC OPERATIONS***************************************************************************
  * void init( )                              								 --> Begin Linear Regression
  * void Normalization( x )                   								 --> Normalize the data so all data is evaluated in the same general range
  * double computeCost( x, y, theta )         								 --> Computes the cost of the current GradientDescent stage                							
  * Eigen::VectorXd gradientDescent( x, y, theta, alpha, num_iters )                --> Converges the Linear Regression algorithm to minima
  *
**/


class LinearRegression{
private:
	std::string data_;
	Utils u_;
public:
	LinearRegression( std::string && data );
	void Init();
	void Normalization( Eigen::MatrixXd & x );
	double ComputeCost( const Eigen::MatrixXd & x, const Eigen::VectorXd & y, const Eigen::VectorXd & theta );
	Eigen::VectorXd GradientDescent( const Eigen::MatrixXd & x, const Eigen::VectorXd & y, Eigen::VectorXd & theta, double alpha, int num_iters );
};

#endif //LINEARREGRESSION_HPP