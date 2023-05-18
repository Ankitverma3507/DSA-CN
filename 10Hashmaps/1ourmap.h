#include<string>
#include<iostream>
using namespace std;

template <typename V>
class mapNode
{
    public:
    string key;
    V value;
    mapNode *next;

    mapNode(string key, V value)
    {
        this->key=key;
        this->value=value;
        next=NULL;
    }

    ~mapNode()
    {
        delete next;
    }
};

template <typename V>

class ourMap
{
    mapNode<V> ** buckets;
    int count;
    int numBuckets;

    public:
    ourMap()
    {
        count=0;
        numBuckets=5;
        buckets= new mapNode<V>* [numBuckets];
        for(int i-0; i<numBuckets; i++)
        {
            buckets[i]=NULL;
        }
    }

    ~ourMap()
    {
        for(int i=0; i<numBuckets; i++)
        {
            delete buckets[i];
        }

        delete [] buckets;
    }


    int size()
    {
        return count;
    }

// give the value corressponds to that key
    V getValue( string key)
    {
        int bucketIndex= getBucketIndex(string key);
        mapNode<V> *head= buckets[bucketIndex];

        while (head!=NULL)
        {
            if(head->key==key)
            {
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }


private:
int getBucketIndex(string key)
{
    int hashcode = 0;

    int currCoeff=1;
    for(int i=key.length()-1; i>=0; i--)
    {
        hashcode += key[i] * currCoeff;
        hashcode = hashcode % numBuckets;
        currCoeff *= 37;
        currCoeff = currCoeff % numBuckets;
    }


    return hashcode % numBuckets;
}


public:
// insert the value
    void insert(string key, V value)
    {
        int bucketIndex= getBucketIndex(string key);
        mapNode<V> *head= buckets[bucketIndex];
        while (head != NULL)
        {
            if(head->key==key)
            {
                head->value= value;
                return;
            }
            head= head->next;
        }

        head= buckets[bucketIndex];
        mapNode<V> *node= new mapNode<V>(key,value);
        node->next=head;
        buckets[bucketIndex]= node;
        count++;
    }

//remove that key and gives value corressponds to that key
    V remove(string key)
    {
        int bucketindex= getBucketIndex(string key);
        mapNode <V> * head= buckets[bucketindex];
        mapNode <V> *prev= NULL;

        while(head!= NULL)
        {
            if(head->key==key)
            {

                if(prev==NULL)
                {
                    buckets[bucketindex]= head->next;
                }

                else{
                prev->next=head->next;
                }
                v value= head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
        } 
        return 0;

    }
};