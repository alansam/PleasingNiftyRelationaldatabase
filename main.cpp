/*
Here is my code. Now I need to figure it out how can add the space function in my program. Btw here is the instruction of my program part:
Objectives:
• read from/write to a file
• create input and output stream objects
Exercise 1
Create a file, input.txt, and type the following 8 integers in it:
4 4 4 4 4 4 4 4. Save the file and exit. Write a program that reads
data from the file input “input.txt”. Your program should display
an output similar to the one given below:
 x  x^2 Current Sum
=== === ==========
 4   16      4
 4   16      8
 4   16     12
 4   16     16
 4   16     20
 4   16     24
 4   16     28
 4   16     32
The average of these 8 numbers is: 4
Code that I wrote:
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>

//using namespace std;
std::string const file_name_i("./input.txt");
std::string const file_name_o("./output.txt");

std::vector<int> read_data(std::string const file_name);
void analysis(std::vector<int> collect,
              std::string const file_name,
              bool serialize = false);

int main() {
  /*
  int x_;

  std::ifstream inStream;
  inStream.open(file_name);
  if (!inStream.is_open()) {
    std::string emsg("File open error: ");
    emsg += file_name;
    throw std::runtime_error(emsg);
  }
  */

  std::vector<int> collect;
  /*
  for (size_t i_ = 1; i_ <= 8; i_++) {
    inStream >> x_;
    sum = sum + x_;
    std::cout << std::setw(2)
              << x_
              << std::setw(5)
              << pow(x_, 2)
              << std::setw(8)
              << sum
              << std::endl; // isspace(int, pow)
  }
  */
  /*
  while (!inStream.eof()) {
    //  just read the file and save data into a vector
    //  allows analysis of the data independent of I/O 
    inStream >> x_;
    collect.push_back(x_);
  }
  */
  collect = read_data(file_name_i);

  //  analysis
  analysis(collect, file_name_o, false);
  /*
  std::cout << "=== === ============" << std::endl;
  std::cout << " x  x^2 Current Sum." << std::endl;
  std::cout << "=== === ============" << std::endl;

  int sum = 0;
  for (auto xx : collect) {
    sum += xx;
    std::cout << std::setw(2)
              << xx
              << std::setw(5)
              << pow(xx, 2)
              << std::setw(8)
              << sum
              << std::endl; // isspace(int, pow)
  }

  std::cout << std::endl;
  double avg = (static_cast<double>(sum) / collect.size());
  std::cout << "The average of these "
            << collect.size()
            << " numbers is: "
            << avg
            << std::endl;
  */

  return 0;
}

// FZ

std::vector<int> read_data(std::string const file_name) {
  std::vector<int> collect;
  std::ifstream inStream;

  inStream.open(file_name);
  if (!inStream.is_open()) {
    std::string emsg("File open error: ");
    emsg += file_name;
    throw std::runtime_error(emsg);
  }

  while (!inStream.eof()) {
    int x_;
    //  just read the file and save data into a vector
    //  allows analysis of the data independent of I/O 
    inStream >> x_;
    collect.push_back(x_);
  }

  //  resource cleanup
  inStream.close();

  return collect;
}

void analysis(std::vector<int> collect,
              std::string const file_name,
              bool serialize) {
  std::ofstream outStream;
  std::streambuf * coutbuf;

  if (serialize) {
    outStream.open(file_name);
    if (!outStream.is_open()) {
      std::string emsg("File open error: ");
      emsg += file_name;
      throw std::runtime_error(emsg);
    }
    coutbuf = std::cout.rdbuf();
    std::cout.rdbuf(outStream.rdbuf());
  }

  std::cout << "=== === ============" << std::endl;
  std::cout << " x  x^2 Current Sum." << std::endl;
  std::cout << "=== === ============" << std::endl;

  int sum = 0;
  for (auto xx : collect) {
    sum += xx;
    double pwr = pow(xx, 2);
    std::cout << std::setw(2)
              << xx
              << std::setw(5)
              << pwr
              << std::setw(8)
              << sum
              << std::endl; // isspace(int, pow)
  }

  double avg = (static_cast<double>(sum) / collect.size());
  std::cout << '\n'
            << "The average of these "
            << collect.size()
            << " numbers is: "
            << std::fixed
            << avg
            << std::endl;

  if (serialize) {
    //  resource cleanup
    std::cout.rdbuf(coutbuf);
    outStream.close();
  }
}
