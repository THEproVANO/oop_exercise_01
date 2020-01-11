#include "complex.h"
#include <iostream>
#include <math.h>

Complex_number::~Complex_number(){}
Complex_number::Complex_number()
{
    this->r = 0;
    this->phi = 0;
}

Complex_number::Complex_number(double r, double phi_r) //угол в радианах
{
    this->r = r;
    if (phi_r < 0)
        while ((phi_r + 2*M_PI) < 0)
            phi_r = phi_r + 2*M_PI;
    else if (phi_r > 0)
        while ((phi_r - 2*M_PI) > 0)
            phi_r = phi_r - 2*M_PI;
    if (phi_r < 0)
        phi_r = 2*M_PI + phi_r;
    this->phi = phi_r;
}

double Complex_number::get_module() const
{
    return this->r;
}

double Complex_number::get_angle() const
{
    return this->phi;
}

Complex_number Complex_number::sum(const Complex_number &A,const Complex_number &B)
{
    double Im = A.r*sin(A.phi)+B.r*sin(B.phi);//мнимая часть
    double Re = A.r*cos(A.phi)+B.r*cos(B.phi);//действительная часть
    double module = sqrt(pow(Im,2) + pow(Re,2));//модуль комплексного числа
    double result_angle = atan2(Im,Re);
    Complex_number result(module,result_angle);
    return result;
}

Complex_number Complex_number::sub(const Complex_number &A,const Complex_number &B)
{
    double Im = A.r*sin(A.phi)-B.r*sin(B.phi);//мнимая часть
    double Re = A.r*cos(A.phi)-B.r*cos(B.phi);//действительная часть
    double module = sqrt(pow(Im,2) + pow(Re,2));//модуль комплексного числа
    double result_angle = atan2(Im,Re);
    Complex_number result(module,result_angle);
    return result;
}

Complex_number Complex_number::mul(const Complex_number &A,const Complex_number &B)
{
    double module = A.r*B.r;//модуль комплексного числа
    double result_angle = A.phi + B.phi;
    Complex_number result(module,result_angle);
    return result;
}

Complex_number Complex_number::div(const Complex_number &A,const Complex_number &B)
{
    double module = A.r/B.r;//модуль комплексного числа
    double result_angle = A.phi - B.phi;
    Complex_number result(module,result_angle);
    return result;
}

bool Complex_number::equ(const Complex_number &A,const Complex_number &B)
{
    return (A.r == B.r && A.phi == B.phi) ? true: false;
}

Complex_number Complex_number::conj() const
{
    Complex_number result(this->r,-this->phi);
    return result;
}

bool Complex_number::equ_rational(const Complex_number &A, const Complex_number &B)
{
    return (A.r == B.r) ? true: false;
}

void Complex_number::print(std::ostream& out) const
{
    std::cout << "Module of complex number: " << this->r <<"\n";
    std::cout << "Angle of complex number: " << this->phi <<"\n";
}

void Complex_number::read(std::istream& in)
{
    std::cout << "Module of complex number: ";
    in >> this->r;
    std::cout << "Angle of complex number: ";
    double phi_r = 0;
    in >> phi_r;
    if (phi_r < 0)
        while ((phi_r + 2*M_PI) < 0)
            phi_r = phi_r + 2*M_PI;
    else if (phi_r > 0)
        while ((phi_r - 2*M_PI) > 0)
            phi_r = phi_r - 2*M_PI;
    if (phi_r < 0)
        phi_r = 2*M_PI + phi_r;
    this->phi = phi_r;
}


