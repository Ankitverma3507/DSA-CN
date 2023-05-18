#include<iostream>
using namespace std;

class student{
    private:
    int age;

    public:
    int rollnumber;

    ~ student()
    {
        cout<<"destructor is called"<<endl;
    }

    //default constructor
    student()
    {cout<<"constructor 1 is called"<<endl;}

    //parametrized const
    student(int rollnumber)
    {cout<<"constructor 2 is called"<<endl;
    this->rollnumber= rollnumber;}

    student (int rollnumber, int age)
    {
        cout<<"cons 3 is called"<<endl;
        this->age= age;
        this->rollnumber= rollnumber;
    }

};
int main()
{
    student s1; //cons 1 is called

    student s2(101); //cons 2 is called

    student s3(20,102);  //cons 3 is called

    student s4(s3);  //copy cons is called

    s2=s3;     //we are only using copy assingment operator

    student s5=s4; //this will work as a coopu sontructor 
return 0;
}