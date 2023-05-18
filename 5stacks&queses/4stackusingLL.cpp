#include<iostream>
using namespace std;
template <typename T>
class node 
{
    // int data;
    // node *next;
    
    // public:
    // node (int data)
    // {
    //     this ->data=data;
    //     next= NULL;
    // }

    //-------------->as we want to use template while creating stack so we use it
    public:
    T data;
    node <T> *next;

    node (T data)
    {
        this ->data=data;
        next= NULL;
    }
};

template <typename T>
class Stack
{
    //we will change this class also acc. to template
    node <T> *head;
    int size;

    public:

    Stack()
    {
        head=NULL;
        size=0;
    }

    int getsize()
    {
        return size;
    }

    bool isemty()
    {
        if (size==0){return true;}
        else return false;
    }

    void push(T element)
    {
            node <T>*newnode= new node<T> (element);
            newnode->next=head;
            head=newnode;
            size++;
    }

    T pop()
    {
        if (isemty())
        {
            cout<<"stack is empty"<<endl;
            return 0;
        }
        else
        {
            T ans=head->data;
            node <T> *temp=head;
            head=head->next;
            delete temp;

            size--;
            return ans;
        }

    }

    T top()
    {
        if (isemty())
        {
            cout<<"stack is empty"<<endl;
            return 0;
        }
        else 
        {
            return head->data;
        }
    }

};
int main()
{
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);


    cout<<s.top()<<endl;

cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.pop()<<endl;

cout<<s.getsize()<<endl;

cout<<s.isemty()<<endl;


return 0;
}