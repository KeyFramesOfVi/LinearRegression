#include "../include/Utils.hpp"

int Utils::GetRows( std::string && data ){
    int rows; 
    std::ifstream in( data.c_str() );
    rows = std::count( std::istreambuf_iterator<char>(in), 
             std::istreambuf_iterator<char>(), '\n' ) + 1;
    return rows;
}

int Utils::GetColumns( std::string && data ){
    int cols;
    std::ifstream in( data.c_str() );
    std::vector <std::string> vec;
    std::string line;
    getline(in, line);
    Tokenizer tok( line );
    vec.assign( tok.begin(), tok.end() );
    cols = vec.size();
    return cols;
}
void Utils::CSVToMatrix( std::string && data, int index, Eigen::MatrixXd & m ){
    int row_index = 0;
    double temp = 0;
    std::ifstream in( data.c_str() );
    if ( !in.is_open() )
        return ;

    std::vector< std::string > vec;
    std::string line;

    while ( getline( in,line ) ){
        Tokenizer tok( line );
        vec.assign( tok.begin(), tok.end() );

        if ( vec.size() < 2 ) 
            continue;

        for( int i = 0; i < index; ++i ){
            try{
                boost::trim( vec[ i ] );
                temp = boost::lexical_cast<double>( vec[ i ] );
                m( row_index, i ) = temp;
            }
            catch(boost::bad_lexical_cast &){
                m( row_index, i ) = -1;
            }
        }
        ++row_index;
    }
}
void Utils::CSVToVector( std::string && data, int index, Eigen::VectorXd & v ){
    double temp = 0;
    int row_index = 0;
    std::ifstream in( data.c_str() );
    if ( !in.is_open() )
        return ;

    std::vector< std::string > vec;
    std::string line;

    while ( getline( in, line ) ){
        Tokenizer tok( line );
        vec.assign( tok.begin(), tok.end() );

        if ( vec.size() < 2 ) 
            continue;

        try{
            boost::trim( vec[ index ] );
            temp = boost::lexical_cast<double>( vec[ index ] );
            v[ row_index ] = temp;
        }
        catch(boost::bad_lexical_cast &){
             v[ row_index ] = -1;
        }
        ++row_index;
    }
}

void Utils::CSVToArray( std::string && data, int index, Eigen::ArrayXXd & a ){
    int row_index = 1;
    double temp = 0;
    bool first_line = true;
    std::ifstream in( data.c_str() );
    if ( !in.is_open() )
        return ;

    std::vector< std::string > vec;
    std::string line;

    while ( getline( in,line ) ){
        Tokenizer tok( line );
        vec.assign( tok.begin(), tok.end() );

        if ( vec.size() < 2 ) 
            continue;
        if ( first_line ){
            first_line = false; 
            continue;
        }
        for( int i = 0; i < index; ++i ){
            try{
                boost::trim( vec[ i + 1 ] );
                temp = boost::lexical_cast<double>( vec[ i ] );
                a( row_index, i ) = temp;
            }
            catch( boost::bad_lexical_cast & ){
                /* DO NOTHING */
            }
        }
        ++row_index;
    }
}
Eigen::VectorXd Utils::GetMean( Eigen::MatrixXd & m ){
    Eigen::VectorXd mean( m.cols() );
    for( int i = 0; i < m.cols(); ++i ){
        mean[ i ] = m.col( i ).mean();
    }
    return mean;
}

Eigen::VectorXd Utils::GetStandardDeviation( Eigen::MatrixXd & m, const Eigen::VectorXd & mean ){
    double variance; 
    Eigen::VectorXd std( m.cols() );
    for( int i = 1; i < m.cols(); ++i ){
        variance = ( ( m.array().col( i ) - mean[ i ] ).array().pow( 2 ) ).sum();
        std[ i ] = sqrt( variance / ( m.rows() - 1 ) );
        variance = 0;
    }
    return std;
}
