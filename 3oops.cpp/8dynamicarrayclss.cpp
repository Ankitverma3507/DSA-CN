#include<iostream>
using namespace std;
class dynamicarr
{
    int *data;
    int nextindex;
    int capacity;

    public:
    dynamicarr()
    {
        data = new int[5];
        nextindex=0;
        capacity=5;
    }

    void add(int element)
    {
        if(nextindex==capacity)
        {
            int *newdata= new int[2*capacity];
            for(int i=0; i<capacity; i++)
            {
                newdata[i]= data[i];
            }
            delete[] data;
            data= newdata;
            capacity*= 2;

        }
        data[nextindex]=element;
        nextindex++;
    }

    int get(int i)
    {
        if(i<nextindex)
        {
            return data[i];
        }
        else
        {return -1;}
    }

    void add(int i, int element)
    {
        if(i<nextindex)
        {data[i]=element;}
        else if(i==nextindex)
        {add(element);}
        else
        return;
    }

    void print()
    {
        for(int i=0; i<nextindex; i++)
        {
            cout<<data[i]<<" ";
        }
    }
};
int main()
{
    dynamicarr d1;
     d1.add(10);
     d1.add(20);
     d1.add(30);
     d1.add(40);
     d1.add(50);
     d1.add(60);

     d1.print();

     
return 0;
}