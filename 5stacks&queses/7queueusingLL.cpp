#include<iostream>
using namespace std;
template <typename T>
class node
{
    public:
    T data;
    node <T>*next;

    node (T data)
    {
        this->data= data;
        next= NULL;
    }
};

template <typename T>
class queueusingLL
{
    node <T>*head;
    node <T>*tail;
    int size;

    public:
    queueusingLL()
    {
        head=NULL;
        tail=NULL;
        size=0;
    }

    int getsize()
    {
        return size;
    }

    bool isempty()
    {
        if(size==0){return true;}
        else {return false;}
    }

    void enqueue(T element)
    {
        node <T> *newnode= new node<T>(element);
        if(size==0)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {   
            tail->next=newnode;
            tail=tail->next;
        }
        size++;
    }

    T front()
    {
        if(isempty()){return 0;}
        return head->data;
    }

    T dequeue()
    {
        if(isempty()){return 0;}
        T ans =head->data;
        node <T> *temp=head;
        head=head->next;
        delete temp;
        size--;
        return ans;
    }

};
int main()
{
    queueusingLL<int> s;
s.enqueue(10);
s.enqueue(20);
s.enqueue(30);
s.enqueue(40);
s.enqueue(50);
s.enqueue(60);

cout<< s.front()<<endl;
cout<<s.dequeue()<<endl;
cout<<s.dequeue()<<endl;
cout<<s.dequeue()<<endl;

cout<<s.getsize()<<endl;
cout<<s.isempty()<<endl;

return 0;
}