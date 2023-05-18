#include<iostream>
using namespace std;

class student
{
    public:
    int age;
    int rollnumber;

    static int totalnumber;

    student()
    {
        totalnumber++;
    }
};

int student::totalnumber=0;  //initialisation static members.
int main()
{
//static members are those of which no copy are created for every objects. this property stores in class not in every object. we have to initialize static members outside the class. if we want to access static member we have to use scope resolution operator ::
 student s1;

 cout<<student::totalnumber<<endl; //we can access static member by using any object also

 //if we want to update static member we have to use constructor cause constructor is always called whenever the static member is called
 student s2,d3, s3,s5;
 cout<<student::totalnumber<<endl; //we can access static member by using any object also
 

 //in layman lang static means that the property will depend on the class not on the individual object 
 //static function can only access static property of class

return 0;
}