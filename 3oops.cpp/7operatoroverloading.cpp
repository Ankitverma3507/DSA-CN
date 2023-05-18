#include<iostream>
using namespace std;

class fraction
{
    private:
    int numerator;
    int denominator;

    public:
    fraction(int numerator, int denominator)
    {
        this->denominator= denominator;
        this->numerator= numerator;
    }

    void print()
    {
        cout<<this->numerator<<"/"<<this->denominator<<endl;
    }

    void simplify()
    {
        int gcd=1;
        int j=min(this->numerator, this->denominator);
        for(int i=1; i<j; i++)
        {
            if(this->numerator%i==0 && this->denominator%i==0)
            {
                gcd=i;
            }
        }

        this->numerator=this->numerator/gcd;
        this->denominator=this->denominator/gcd;
    }

    fraction add(fraction f2)
    {
        int lcm= denominator * f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;

        int num= (x*numerator) + (y*f2.numerator);

        // numerator=num;
        // denominator=lcm;
        fraction fnew(num,lcm);


        fnew.simplify( );
        return fnew;

    }
    fraction operator+(fraction f2)
    {
        int lcm= denominator * f2.denominator;
        int x=lcm/denominator;
        int y=lcm/f2.denominator;

        int num= (x*numerator) + (y*f2.numerator);

        // numerator=num;
        // denominator=lcm;
        fraction fnew(num,lcm);


        fnew.simplify( );
        return fnew;
    }

    fraction operator*(fraction const &f2)
    {
        int n= numerator* f2.numerator;
        int d= denominator*f2.denominator;

        fraction fnew(n,d);
        fnew.simplify();

        return fnew;
    }

    //preincrement overload
    fraction &operator++()//we changed the return type from void to fraction as we want to get something return from this function and  we used & becoz we dont want any buffer memory to be made
    {
    numerator=numerator+denominator;
    simplify();

    return *this; //here we are returning the whole fraction
}

//post increment
    fraction operator++(int)
    {
        fraction fnew(numerator,denominator);
        numerator=numerator+denominator;
        simplify();
        fnew.simplify();
        return fnew;
    }
};
int main()
{
    fraction f1(10,2);
    fraction f2(15,4);

    f1.add(f2);
    fraction f4=f1+f2;
    f1.print();
    f4.print();

    // fraction f5= f1*f2;
    // ++f5;
    // f5.print();

    fraction f5= ++f1;
    f5.print();

return 0;
}