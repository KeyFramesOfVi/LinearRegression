#include <boost/tokenizer.hpp>
#include <boost/algorithm/string/trim.hpp>
#include <boost/lexical_cast.hpp>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <unsupported/Eigen/MatrixFunctions>
#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>

#ifndef UTILS_HPP
#define UTILS_HPP


/** Utils class
  *
  * Class designed to accomodate my Machine Learning Algorithms, 
  *
  * ************************************************************************PUBLIC OPERATIONS***************************************************************************
  * int GetRows( data )                              						 --> Get the number of rows from the data 
  * int GetColumns( data )													 --> Get the number of columns from the data
  * CSVToMatrix( data, index, m  )                   						 --> Transfer info from the CSV, stopping at the column specified by index
  * CSVToVector( data, index, v )											 --> Transfer info from the CSV, stopping at the column specified by index
  * CSVToArray( data, index, a )											 --> Transfer info from the CSV, stopping at the column specified by index
  * Eigen::VectorXd GetMean( m )         								 	 --> Gets the mean of each column in the Matrix given  							
  * Eigen::VectorXd gradientDescent( m, mean )         						 --> Gets the standard deviation of each column in the Matrix given 
  *
**/


class Utils{
private:
	typedef boost::tokenizer< boost::escaped_list_separator<char> > Tokenizer;
public:
	int GetRows( std::string && data );
	int GetColumns( std::string && data );
	void CSVToMatrix( std::string && data, int index, Eigen::MatrixXd & m );
	void CSVToVector( std::string && data, int index, Eigen::VectorXd & v );
	void CSVToArray( std::string && data, int index, Eigen::ArrayXXd & a );
	Eigen::VectorXd GetMean( Eigen::MatrixXd & m );
	Eigen::VectorXd GetStandardDeviation( Eigen::MatrixXd & m, const Eigen::VectorXd & mean );
};

#endif 
