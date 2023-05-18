#include<iostream>
using namespace std;

class polynomial
{
    int *degcoef;
    int capacity;

    public:
    polynomial()
    {
        degcoef= new int[5];
        capacity=5;
        degcoef[5]={0};
    }

    polynomial(polynomial const &p1)
    {
        this->degcoef= new int[capacity];
        for(int i=0; i<capacity; i++)
        {
            this->degcoef[i]=degcoef[i];
        }
    }

    void setcoeff(int d, int element)
    {
        if(d<capacity)
        {degcoef[d]=element;}

        else if(d==capacity)
        {
            int *newdegof= new int[2*capacity];
            for(int i=0; i<capacity; i++)
            {
                newdegof[i]=degcoef[i];
            }
            delete [] degcoef;
            degcoef= newdegof;
            capacity= 2*capacity;
        }

        else
        return;
    }

    polynomial operator+(polynomial p2)
    {
        
    }
};
int main()
{

return 0;
}