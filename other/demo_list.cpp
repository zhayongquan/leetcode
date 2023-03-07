//#1 demo
#include<iostream>
#include<list>

using namespace std;

struct listnode{
    double val;
    listnode *next;
};

int main()
{
    listnode *head = nullptr;  //init is head is null
    head = new listnode;       //allocate the new memory
    head->val = 11.1;          //head node init val
    head->next = nullptr;

    listnode *secondptr = new listnode;
    secondptr->val = 12.2;
    secondptr->next = nullptr;
    head->next = secondptr;

    cout<<"first is :"<<head->val<<endl;
    cout<<"second is :"<<head->next->val<<endl;
    return 0;
    
}

