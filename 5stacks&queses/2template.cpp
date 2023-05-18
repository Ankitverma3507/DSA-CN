#include<iostream>
using namespace std;
template <typename T>
class pair
{
    T x;
    T y;

    public:
    void setx( T x)
    {
        this ->x = x;
    }

    void sety(T y )
    {
        this -> y=y;
    }

    T getx()
    {
        return x;
    }

    T gety()
    {
        return y;
    }

};
int main()
 {
// pair<int> p1;
// pair<double>p2;
return 0;
}