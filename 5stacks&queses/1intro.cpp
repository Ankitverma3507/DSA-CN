#include<iostream>
using namespace std;

class stackusingArray
{
    int *data;
    int nextindex;
    int  capacity;

    public:
    stackusingArray()
    {
        data=new int[4];
        nextindex=0;
        capacity=4;
    }

        //1st size of stack
        int size()
        {
            return nextindex;
        }

        // empty or not
        bool isEmpty(){
            if (nextindex==0){return true;}
            else {return false;}
        }

        //add new element
        void push (int element)
        {
            if(nextindex==capacity)
            {
                // cout<<"Stack is full"<<endl;
                // return;
                // to remove this length constrain we will make new array dynamically and copy all the data of previous one into it.
                int *newdata= new int[2*capacity];
                for(int i=0; i<capacity; i++)
                {
                    newdata[i]=data[i];
                }
                capacity *=2;
                delete [] data;
                data= newdata;
            }
            
                data[nextindex]=element;
                nextindex++;
            
        }

        //delete top element
        int pop()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty"<<endl;
                return INT64_MIN;
            }
            else 
            nextindex--;
            return data[nextindex];
        }

        //display of top element
        int top()
        {
            if(isEmpty())
            {
                cout<<"Stack is empty"<<endl;
                return INT64_MIN;
            }
            else 
            {
                return data[nextindex-1];
            }
        }
    
};
int main()
{
// stackusingArray s(4);
stackusingArray s; //as we made new push function 
s.push(10);
s.push(20);
s.push(30);
s.push(40);
s.push(60);

cout<<s.top()<<endl;

cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;

cout<<s.size()<<endl;

cout<<s.isEmpty()<<endl;

return 0;
}