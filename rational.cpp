
#include "rat.h"
//using namespace std;     //after compilation flag : -std=c++11

//========================


int main()
{
    rational r(80, -12);
    rational R2(1, 1);
    rational c;
    c = R2 - r;
   
    cout << c;
    cout << r;
    return 0;
}

//========================================================

int nod(int a, int b)
{
	while (a != b)
	{
	if (a > b) 
		a = a - b;
	else 
		b = b - a;
	}
	return a;
}

//==========================================

void cut(int& numerator, int& denominator)
{
	int x = nod(abs(numerator), abs(denominator));
    //cout << x;
    //cout << numerator;
    if (denominator < 0)
    {
        denominator = denominator * (-1);
        numerator   = numerator * (-1);
    }

	if ((x != 0))
	{
		numerator   = numerator / x;
		denominator = denominator / x;
	}
	if (denominator == 0)
	{
		throw invalid_argument("denominator is zero");
	}
	
}

//========================================================


ostream& operator<<(ostream& os, rational r)
{
    if (r.denominator == 1)
    {
        os << "number is " << r.numerator << endl;
    }
    else
    {
        os <<  r.numerator << "/" << r.denominator << endl;
    }

    return os;
}

//==================================================

rational operator+(rational r1, rational r2)
{
    int tmp1 = r1.denominator * r2.numerator;
    int tmp2 = r2.numerator * r1.denominator;

    r1.denominator = r1.denominator * r2.denominator;
    r1.numerator   = tmp1 + tmp2;

    cut(r1.numerator, r1.denominator);

    return r1;
}

//===================================

rational operator-(rational r1, rational r2)
{
    int tmp1 = r1.denominator * r2.numerator;
    int tmp2 = r1.numerator * r2.denominator;

    r1.numerator   = tmp2 - tmp1;
    r1.denominator = r1.denominator * r2.denominator;

    cut(r1.numerator, r1.denominator);

    return r1;
}

//=================================================

rational operator*(rational r1, rational r2)
{
    r1.denominator = r1.denominator * r2.denominator;
    r1.numerator   = r1.numerator * r2.numerator;

    cut(r1.numerator, r1.denominator);

    return r1;
}

//===========================================

rational operator/(rational r1, rational r2)
{
    r1.denominator = r1.denominator * r2.numerator;
    r1.numerator   = r1.numerator * r2.denominator;

    cut(r1.numerator, r1.denominator);

    return r1;
}

//==============================================

bool operator==(rational r1, rational r2)
{
    if((r1.denominator == r2.denominator) && (r1.numerator == r2.numerator))
    {
        return 1;
    }
    return 0;
}

//==========================================

bool operator>(rational r1, rational r2)
{
    rational tmp = r1 - r2;
    if (r1.numerator < 0)
    {
        return 0;
    }
    return 1;
}

//====================================

bool operator<(rational r1, rational r2)
{
    rational tmp = r1 - r2;
    if (r1.numerator > 0)
    {
        return 0;
    }
    return 1;
}

//======================================


istream& operator>>(istream& is, rational& r)
{
    is >>  r.numerator >>  r.denominator;

    return is;
}

//=========================

// rational operator++(rational& a)
// {
//     rational prev = a;
//     rational r2(1, 1);
//     a = a + r2;
//     return prev;
// }

// //=====================================

// rational operator++(rational a)
// {
//     rational r2(1, 1);
//     a = a + r2;
//     return a;
// }
