#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int DataType;

class SequenList
{

public:
    void Initiate();
    int Length();
    int Insert(DataType x, int i);
    int Deleted(int i);
    int Locate(DataType x);
    DataType Get(int i);
private:
    DataType data[MAXSIZE];
    int len;
};

void SequenList::Initiate()
{
    len = 0;
}

int SequenList::Insert(DataType x, int i)
{
    if(len>=MAXSIZE)
    {
        cout <<"oveflow!"<<endl;
        return 0;
    }
    else if(i<1||(i>len+1))
    {
        cout <<"position is not correct!"<<endl;
        return 0;
    }
    else{
        for(int j=len; j>=i;j--)
        {
            data[j]=data[j-1];
        }
        data[i-1]=x;
        len++;
        return 1;
    }
}

int SequenList::Deleted(int i)
{
    if(i<1 || (i>len+1))
    {
        cout <<"position is not correct!"<<endl;
        return 0;
    }
    else{
        for(int j=i; i<len; j++)
        {
            data[j-1] = data[j];
        }
        len--;
        return 1;
    }
}

int SequenList::Locate(DataType x)
{
    int j=0;
    while(j<len&&data[j]!=x)
    {
        j++;
    }
    if(j<len) return j+1;
    else return 0;
}

DataType SequenList::Get(int i)
{
    
}


int main()
{
    SequenList L;
    L.Initiate();

    cout << "yes, you can run it!"<<endl;
    return 0;
}