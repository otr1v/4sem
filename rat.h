#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void cut(int& num, int& den);
int nod(int a, int b);

class rational
{
    public:
        int numerator;
        int denominator;
        rational()
        {
           numerator   = 0;
           denominator = 1; 
        }
        rational(int numerator_, int denominator_)
        {
            if (denominator_ == 0)
            {
                // cout << "error" << endl;
                throw invalid_argument("denominator is zero");
            }
            else
            {
                if (denominator_ < 0)
                {
                    denominator = (-1) * denominator_;
                    numerator   = (-1) * numerator_;
                }
                else                    //return *this;
                {
                    denominator = denominator_;
                    numerator   = numerator_;
                }
                //cout << numerator;
                cut(numerator, denominator);
            }
            
        }
        rational operator=(rational r2)
        {
            denominator = r2.denominator;
            numerator   = r2.numerator;
            return *this;
        }

        rational operator++(int) 
        {
			numerator += denominator;
			return * this;
		}

		rational & operator++() 
        {
			numerator += denominator;
			return * this;
		}
       
};

ostream& operator<<(ostream& os, rational r);
rational operator+(rational r1, rational r2);
rational operator-(rational r1, rational r2);
rational operator*(rational r1, rational r2);
rational operator/(rational r1, rational r2);
bool operator==(rational r1, rational r2);
bool operator>(rational r1, rational r2);
// rational operator++(rational r1);
// rational operator++(rational& r1);
