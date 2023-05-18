#include<iostream>
#include<string.h>
using namespace std;


class student
{
    int age;

    public:
    char *name;

    student(int age, char *name)
    {
        this->age=age;
        //this is shallow copy this will only copy the address of 1st index of an array
        // this->name=name;

        //we will use deep copy in which we will make new array in which we will make whole new array in which we will copy all the content of previous array
        this-> name= new char[strlen(name)+1];
        strcpy(this->name,name);
    }
    

    //Inbuilt copy constructor always do the shallow copy constructor so to use it we have to make our own copy constructor 
    //-------------------------------->>>>>how to make our own copy constructor
    student(student const &s) //here & is used becoz we dont want ki infinite loop banta jaye copy constructor ko bulane ke liye and const qk we dont want ki koi s kko use krke main object mein change kr sake
    {
        this->age=s.age;
        // this->name=name;//======this again is shallow copy whic we dont want

        this ->name= new char[strlen(s.name)+1];
        strcpy(this->name, s.name);
    }

    void display()
{
    cout<<name<<" "<<age<<endl;
}
};
int main()
{
char name[]="abcd";
student s1(20,name);
s1.display();

name[3]='e';
student s2(3,name);
s2.display();

s1.display();
return 0;
}