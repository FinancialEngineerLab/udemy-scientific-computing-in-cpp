#include "matrix.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
  Matrix MatrixValues("C:\\temp\\MatrixValue.txt");
  std::cout << MatrixValues.getName() << std::endl;

  std::cout << "a(0,1)" << MatrixValues.getValue(0,1) << std::endl;

  return 0;
}
