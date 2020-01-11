#include <iostream>
#include "complex.h"

int main()
{
  Complex_number a;
  Complex_number b;
  std::cout << "Input the first complex number: \n";
  a.read(std::cin);
  a.print(std::cout);
  std::cout << "Input the second complex number: \n";
  b.read(std::cin);
  b.print(std::cout);
  std::cout << "\n\n\n";
  if (Complex_number::equ(a,b))
      std::cout << "Input numbers are equivalent\n";
  else
      std::cout << "Input numbers are not equivalent\n";
  std::cout << "\n\n\n";
  if (Complex_number::equ_rational(a,b))
      std::cout << "Rational part of input numbers are equivalent\n";
  else
      std::cout << "Rational part of input numbers are not equivalent\n";
  std::cout << "\n\n\n";
  std::cout << "The sum of input complex numbers:\n";
  Complex_number::sum(a,b).print(std::cout);
  std::cout << "\n\n\n";
  std::cout << "The difference of input complex numbers:\n";
  Complex_number::sub(a,b).print(std::cout);
  std::cout << "\n\n\n";
  std::cout << "The multiple of input complex numbers:\n";
  Complex_number::mul(a,b).print(std::cout);
  std::cout << "\n\n\n";
  std::cout << "The private of input complex numbers:\n";
  Complex_number::div(a,b).print(std::cout);
  return 0;
}
