#include<bits/stdc++.h>
using namespace std;

struct  Node
{   
	int val;
	Node* next;
};
Node* reorderList(Node *head) 
{
    if(!head){
        return NULL;
    }
    Node *p = head, *q = head->next;
    //找到中间的节点
    while(q && q->next){
        p = p->next;
        q = q->next->next;  
    }
    //单列表反转
    Node *a = NULL, *b = NULL;
    while(p){
        b = p;
        p = p->next;
        b->next = a;
        a = b; 
    }
    p = head;
    while(b){
        a = b;
        b = b->next;
        a->next = p->next;
        p->next = a;
        p = a->next;
    }
    p->next = NULL;
    return head;
}
int main(){
    Node *head = new Node();
    head->val = 1;
    Node *a = new Node();
    a->val = 2;
    head->next = a;
    Node *b = new Node();
    b->val = 3;
    a->next = b;
    Node *c = new Node();
    c->val = 4;
    b->next = c;
    Node *d = new Node();
    d->val = 5;
    c->next = d;

    head = reorderList(head);
    while(head){
        cout << head->val << endl;
        head = head->next;
    }
    return 0;
}