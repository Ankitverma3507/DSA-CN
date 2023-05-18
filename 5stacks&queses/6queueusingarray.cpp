#include<iostream>
using namespace std;
template <typename T>
class queueusingarray
{
    T *data;
    int firstindex;
    int nextindex;
    int size;
    int capacity; //so we can maintain our round inserting of element when queue is full

    public:

    queueusingarray(int s)
    {
        data= new T[s];
        nextindex =0;
        firstindex =-1;
        size =0;
        capacity=s;
    }

    int getsize()
    {
        return size;
    }

    bool isempty()
    {
        return size==0;
    }


    void enqueue(T element)
    {
        if(size==capacity)
        {
            // cout<<"Queue is full"<<endl;
            // return;
            //----------------------------------->we want our array to be allocated dynamically so we will write code  for it.
            T *newdata= new T[2* capacity];
            int j=0;
            for(int i=firstindex; i<capacity; i++)
            {
                newdata[j]=data[i];
                j++;
            }

            for(int i=0; i<firstindex; i++)
            {
                newdata[j]= data[i];
                j++;
            }
            delete [] data;
            data=newdata;
            firstindex=0;
            nextindex=capacity;
            capacity*=2;
        }
        data[nextindex]=element;
        nextindex=(nextindex +1)% capacity;
        if(firstindex==-1){firstindex=0;}
        size++;
    }

    T front()
    {
        if(firstindex==-1)
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return data[firstindex];
    }

    T dequeue()
    {
        if(firstindex==-1)
        {
            cout<<"queue is empty"<<endl;
            return 0;
        }
        T ans=data[firstindex];
        firstindex= (firstindex +1)%capacity;///same as dequeue
        size--;
        if(size==0)//not necessary but acha lagta hai 
        {
            firstindex=-1;
            nextindex=0;
        }
        return ans;
    }

};
int main()
{
queueusingarray <int> s(5);
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