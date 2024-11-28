// This program made by Ali Mohammed 20210876
// and Noor Eldin Tarik mohammed 20210426
// For Dr. Mohammed El-Ramly FCAI Cairo University
// To print a histogram in stars
// A simplified version
// 27 Mar. 2022

#include <iostream>
#include <string>
#include <array>
#include <vector>
// #include <iomanip>
// #include <ctime>        // std::time
// #include <cstdlib>      // std::rand, std::srand

using namespace std;

void change_value (vector <int> number1)
{
  for (int i = 0; i < number1.size(); ++i)
  {
    number1[i] = 0;
  }
}

void change_value2 (int number2[3])
{
  for (int i = 0; i < 3; ++i)
  {
    number2[i] = 0;
  }
}

void change_value2 (array <int,3> number3)
{
  for (int i = 0; i < 3; ++i)
  {
    number3[i] = 0;
  }
}

int main() 
{
  // call by value
  vector <int> number1 = {10 , 20 , 30};
  change_value(number1);
  cout << number1[0] << endl;;

  // call by Reference
  // ************************************
  int number2 [] = {10,20,30};
  change_value2(number2);
  cout << number2[0] << endl;

  // call by value
  // ************************************
  array <int , 3> number3 = {10,20,30};
  cout << number3[0];
}