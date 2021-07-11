#include <iostream>
using namespace std;
typedef int DataType;
class Item
{
public:
    DataType data;
    Item * next;
    Item(){next = NULL;}
};

class Link
{
public:
    Item *head;
    Link(){head = NULL;}
    ~Link(){DeleteAll();}
    void Initiate();
    void DeleteAll();
    void HeadCreate(int n);
    void TailCreate(int n);
    void HeadCreateWithHead(int n);
    void TailCreateWithHead(int n);
    int Length();
    Item * Locatex(DataType x);
    Item * Locatei(int i);
    bool Insert(DataType x, int i);
    bool Delete(int i);
    void Print();
};

void Link::Initiate()
{
    DeleteAll();
    head = NULL;
}

void Link::HeadCreate(int n)
{
    DeleteAll();
    Item *s, *p;
    int i;
    p = NULL;
    for(i=1; i<=n; i++)
    {
        s = new Item();
        cin>>s->data;
        s->next = p;
        p = s;
    }
    head = p;
}

void Link::TailCreate(int n)
{
    Item *s, *r, *p; // use r to trace the s
    int i;
    DeleteAll();
    p=NULL;
    for(i=1; i<=n; i++)
    {
        s = new Item();
        cin>>s->data;
        s->next=NULL;
        if(p==NULL) p=r=s; //p=r=s when empty 
        else
        {
            r->next = s; // r->next： assign s to pointer field of r 
            r=s;
        }
    }
    head = p;
}

void Link::HeadCreateWithHead(int n)
{
    Item *p, *s;
    DeleteAll();
    p = new Item();
    p->next = NULL;
    for(int i=1; i<=n; i++)
    {
        s = new Item();
        cin>>s->data;
        s->next = p->next;
        p->next = s;
    }
    head = p;
}

void Link::TailCreateWithHead(int n)
{
    Item *p, *s, *r;
    DeleteAll();
    p = new Item();
    p->next = NULL;
    r=p;
    for(int i=1; i<=n; i++)
    {
        s = new Item();
        cin>>s->data;
        r->next=s;//assign s to pointer field of r
        r=s;
    }
    r->next = NULL;
    head = p;
}

