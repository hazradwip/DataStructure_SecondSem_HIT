#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *create(node*,int);
node *concate(node*,node*);
void display(node*);
int main()
{
    int n1,n2,i,d1,d2;
    node *c;
    node *head=NULL;
    node *list1=NULL;
    node *list2=NULL;
    printf("\ncreate 1st node\n");
    printf("\nEnter the no.of nodes to create\n");
    scanf("%d",&n1);
    list1=(node*)malloc(n1*sizeof(node));
    for(i=0;i<n1;i++)
    {
        printf("\nEnter the value of the  node\n");
        scanf("%d",&d1);
        head=create(head,d1);
    }
    list1=head;
    printf("\ncreate 2nd node\n");
    printf("\nEnter the no.of nodes to create\n");
    scanf("%d",&n2);
    list2=(node*)malloc(n2*sizeof(node));
    head=NULL;
    for(i=0;i<n2;i++)
    {
        printf("\nEnter the value of the  node\n");
        scanf("%d",&d2);
        head=create(head,d2);
    }
    list2=head;
    display(list1);
    printf("\n");
    display(list2);
    c=concate(list1,list2);
    printf("\n");
    display(c);
}
node *create(node *head, int x)
{
    node *q,*p;
    q=(node*)malloc(sizeof(node));
    q->data=x;
    q->next=NULL;
    if(head==NULL)
        head=q;
    else
    {
        p=head;
        while(p->next!=NULL)
            p=p->next;
         p->next=q;   
    }
    return head;
}
node *concate(node *list1,node *list2)
{
    if(list1==NULL)
        return list2;
    else if(list2==NULL)
        return list1;
    else
    {
        node*p;
        p=list1;
        while(p->next!=NULL)
            p=p->next;
        p->next=list2;
    }
    return list1;
}
void display(node *head)
{
    node *p;
    p=head;
    while(p!=NULL)
    {
        printf("|%d|->",p->data);
        p=p->next;
    }
}
