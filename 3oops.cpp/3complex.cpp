#include <iostream>
using namespace std;

class complex
{
private:
    int real;
    int img;

public:
    complex(int real, int img)
    {
        this->img = img;
        this->real = real;
    }

    void print()
    {
        cout << this->real << "+" << this->img << "i" << endl;
    }

    void add(complex c2)
    {
        int realp = real + (c2.real);
        int imgp = img + (c2.img);

        real = realp;
        img = imgp;
    }

    void multiply(complex c2)
    {
        int realp = (real * (c2.real) - img * (c2.img));
        int imgp = real * (c2.img) + (c2.real) * img;

        real = realp;
        img = imgp;
    }
};
int main()
{
    complex c1(5, 4);
    complex c2(2, -1);

    int choice;
    cout << "Enter your choice" << endl;
    cin>>choice;
    if (choice == 1)
    {
        c1.add(c2);
        cout << "addition of two complex no is ";
        c1.print();
    }
    else if (choice == 2)
    {
        c1.multiply(c2);
        cout << "multiplication of two complex no is ";
        c1.print();
    }

    else
        return 0;

    return 0;
}