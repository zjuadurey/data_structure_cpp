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
    DataType Get(int i);
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
        r=s;  // the end of the list is the end of Item s
    }
    r->next = NULL;
    head = p;
}

int Link::Length()
{
    int count = 0;
    Item *p;
    p= head->next;
    while(p)
    {
        count++;
        p = p->next;
    }
    return count;
}

Item * Link::Locatei(int i)
{
    Item *p;
    if(i==0) return head;
    p = head->next;
    int count=1;

    while(count<i && p!=NULL)
    {
        p = p->next;
        count++;
    }
    if(count==i) return p;
    else{
        cout<<"position i is not correct! "<<endl;
        return NULL;
    }
}

Item * Link::Locatex(DataType x)
{
    Item *p = head->next;
    while(p && p->data!=x) p = p->next;
    if(p) return p;
    else{
        cout << x << " is not exist! "<<endl;
        return NULL;
    }
}

DataType Link::Get(int i)
{
    Item *p = head->next;
    int count = 1;
    while(p && count<i)
    {
        p = p->next;
        count++;
    }
    if(!p||count>i)
    {
        cout<<"position is not correct! " <<endl;
        return 0;
    }
    else return p->data;
}

bool Link::Insert(DataType x, int i)
{
    Item *p, *s;
    p = Locatei(i-1);
    if(!p) return false;
    s = new Item();
    s->data = x;
    s->next = p->next;
    p->next = s;
    return true;
}

bool Link::Delete(int i)
{
    Item *p = Locatei(i-1);
    if(!p)
    {
        cout << "position is not correct! "<<endl;
        return false;
    }
    Item  *q = p->next;
    if(q)
    {
        p->next = q->next;
        delete q;
        return true;
    }
    else{
        cout << "position is not correct! "<<endl;
        return false;
    }
}

void Link::Print()
{
    Item *p = head->next;
    while(p)
    {
        cout << p->data<< " ";
        p = p->next;
    }
    cout << endl;
}

void Link::DeleteAll()
{
    Item *p = head, *q;
    while(p)
    {
        q = p->next;
        delete p;
        p = q;
    }
    head = NULL;
}

int main()
{
    int n;
    cin>>n;
    Link a;
    a.Initiate();
    a.TailCreateWithHead(n);
    a.Delete(7);
    a.Print();
    return 0;
}