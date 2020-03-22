#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
node *head=NULL;
node *create(node*,int);
node *insert_beg(node*,int);
node *insert_end(node*,int);
node *insert_any(node*,int,int);
node *del_beg(node*);
node *del_end(node*);
node *del_any(node*,int);
node *rev(node*);
int count(node*);
void display(node*);
int main()
{
    int ch,n,i,d;
    node *r;
    do{
    printf("\nEnter 1 to create list\nEnter 2 to insert\nEnter 3 to delete\nEnter 4 to Display\nEnter 5 to reverse the list\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("\nEnter the no.of nodes to create\n");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                printf("\nEnter the value of the  node\n");
                scanf("%d",&d);
                head=create(head,d);
            }
            break;
        case 2:
            printf("\nEnter 1 to insert at beg\nEnter 2 to insert at end\nEnter 3 to insert at any pos\n");
            int choice,v,pos;
            printf("\nEnter choice to insert\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    printf("\nEnter value to insert\n");
                    scanf("%d",&v);
                    head=insert_beg(head,v);
                    break;
                case 2:
                    printf("\nEnter value to insert\n");
                    scanf("%d",&v);
                    head=insert_end(head,v);
                    break;
                case 3:
                    printf("\nEnter position to insert\n");
                    scanf("%d",&pos);
                    printf("\nEnter value to insert\n");
                    scanf("%d",&v);
                    head=insert_any(head,pos,v);
                    break;
                default:
                    printf("\nInvalid choice\n");
                    break;
            }
            break;
        case 3:
            printf("\nEnter 1 to delete at beg\nEnter 2 to delete at end\nEnter 3 to delete at any pos\n");
            int che,p;
            printf("\nEnter choice to delete\n");
            scanf("%d",&che);
            switch(che)
            {
                case 1:
                    head=del_beg(head);
                    break;
                case 2:
                    head=del_end(head);
                    break;
                case 3:
                    printf("\nEnter the position to delete\n");
                    scanf("%d",&p);
                    head=del_any(head,p);
                    break;
                default:
                    printf("\nInvalid choice\n");
                    break;
            }
        break;
        case 4:
            display(head);
            break;
        case 5:
            r=rev(head);
            display(r);
            break;
        default:
            printf("\nInvalid choice\n");
    }
    }while(1);
    /*head=create(head,1);
    head=create(head,8);
    head=create(head,3);
    head=insert_beg(head,9);
    head=insert_end(head,5);
    head=insert_any(head,4,4);
    display(head);
    printf("\n%d",count(head)+1);
    printf("\nAfter deletion at beginning\n");
    head=del_beg(head);
    display(head);
    printf("\nAfter deletion at end\n");
    head=del_end(head);
    display(head);
    printf("\nAfter deletion at any pos\n");
    head=del_any(head,3);
    display(head);*/
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
node *insert_beg(node* head,int x)
{
    node *p,*q;
    q=head;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    head=p;
    p->next=q;
    return head;
}
node *insert_end(node* head,int x)
{
    node *p,*q;
    p=(node*)malloc(sizeof(node));
    p->data=x;
    p->next=NULL;
    q=head;
    while(q->next!=NULL)
        q=q->next;
    q->next=p;
    return head;
}
node *insert_any(node* head,int pos,int x)
{
    if(pos==1)
        head=insert_beg(head,x);
    else if(pos==(count(head)+2))
        head=insert_end(head,x);
    else
    {
        node *q,*t;
        q=(node*)malloc(sizeof(node));
        q->data=x;
        q->next=NULL;
        int c=1;
        t=head;
        while(t->next!=NULL)
        {
            if(c==pos-1)
            {
                q->next=t->next;
                t->next=q;
            }
            c++;
            t=t->next;
        }
    }
    return head;
}
node *del_beg(node* head)
{
    node* p;
    p=head;
    if(head==NULL)
        printf("\nNo Node to delete\n");
    else
        head=head->next;
        free(p);
    return head;
}
node *del_end(node* head)
{
    node *p,*t;
    p=head;
    if(head==NULL)
        printf("\n No need to delete\n");
    else if(p->next==NULL)
    {
        head=NULL;
        printf("\nNULL\n");
        free(p);
    }
    else
    {
        while(p->next!=NULL)
        {
            t=p;
            p=p->next;
        }
    }
    t->next=NULL;
    free(p);
    return head;
}
node* del_any(node* head,int pos)
{
    if(head==NULL)
        printf("No node to delete\n");
    else if(head->next==NULL)
        head=del_beg(head);
    else if(pos==count(head))
        head=del_end(head);
    else
    {
        node *p,*t;
        int c=1;
        p=head;
        while(p->next!=NULL&&c<pos)
        {
            t=p;
            p=p->next;
            c++;
        }
        t->next=p->next;
        free(p);
        return head;
    }
}
int count(node* head)
{
    node *p;
    int c=0;
    p=head;
    while(p->next!=NULL)
    {
        ++c;
        p=p->next;
    }
    return c;
}
node *rev(node* head)
{
    node *p,*c,*g;
    g=head;
    p=g;
    c=g->next;
    g=g->next;
    p->next=NULL;
    while(g!=NULL)
    {
        g=g->next;
        c->next=p;
        p=c;
        c=g;
    }
    g=p;
    return g;
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