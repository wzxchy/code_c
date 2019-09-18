#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
struct node
{
    int data;
    node* next;
};
int main()
{
    node* a=new node;
    node* b=new node;

    a->data=1;
    b->data=2;
    a->next=b;
    b->next=NULL;

    cout<<a->data<<endl;
    cout<<b->data<<endl;
    delete a;
    a=b;
    cout<<a->data<<endl;
    a->data=5;
    cout<<b->data<<endl;
    delete b;
    delete a;
    return 0;
}
