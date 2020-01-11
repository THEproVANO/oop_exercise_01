#pragma once
#include <iostream>

class Complex_number
{
private:
        double r;
        double phi;
public:
        Complex_number();//����������� �� ���������
        Complex_number(double r, double phi);//�����������
        Complex_number(const Complex_number &complex);
        ~Complex_number();
        //getters � setters
        double get_module() const;
        double get_angle() const;
        static Complex_number sum(const Complex_number &,const Complex_number &);
        static Complex_number sub(const Complex_number &,const Complex_number &);
        static Complex_number mul(const Complex_number &,const Complex_number &);
        static Complex_number div(const Complex_number &,const Complex_number &);
        static bool equ(const Complex_number &,const Complex_number &);//���������
        static bool equ_rational(const Complex_number &,const Complex_number &);//��������� �� �������������� �����
        Complex_number conj() const;
        void print(std::ostream& out) const;
        void read(std::istream& in);
};
