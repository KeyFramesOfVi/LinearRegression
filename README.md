# LinearRegression

A basic Linear Regression model using the Eigen C++ library.
Normalization has been added, Regularization will be added soon. 

To practice better understanding Machine Learning algorithms, I planned on doing this for the standard algorithms taught in an undergraduate course. 
However, due to my time being focused on other projects, I have stopped this for now. I will update whenever I can afford the time. 


REQUIREMENTS:
==========

To use this code, you must have Eigen C++ (I used Version 3.3 during the time I wrote this), and the Boost C++ Library. Be sure you 
have installed both before you using this. 

Instructions and information about Eigen can be found on:
http://eigen.tuxfamily.org/index.php?title=Main_Page

You can install Boost C++ on Mac using the following command:
`sudo port install boost`

You can install Boost C++ on Linux environments using the following command:
`sudo apt-get install libboost-all-dev`

COMPILING:
==========
To compile on Mac, I used the command:

`$ clang++ -std=c++11 -stdlib=libc++ -I/opt/local/include/ -I/usr/local/include/eigen3 -L/opt/local/lib/ main.cpp LinearRegression.cpp Utils.cpp -o csvparser`

Check where Boost and Eigen are installed for your individual machine if this does not work, and specify your search paths accordingly.

To compile on Ubuntu, I used the command:

`$ g++ -std=c++0x `pkg-config --cflags eigen3` main.cpp LinearRegression.cpp Utils.cpp -o test`

Note that you may have to install pkg-config. If an error appears where the terminal requests you install pkg-config, use this command:

`$ sudo apt-get install pkg-config`

RUNNING:
=======
To run on Mac:

`$ ./test <csv filename>`
(where filename is the location of the csv file. For example, to use the example file I tested on:)

`$ ./test ../csv/ex1data2.csv`
