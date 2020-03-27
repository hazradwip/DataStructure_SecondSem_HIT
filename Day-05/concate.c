#include "linked_list.h"

Node *concate(Node *, Node *);

int main()
{
    int n1, n2, i, data;

    Node *concatedList = NULL;

    Node *list1 = NULL;
    Node *list2 = NULL;

    printf("\nCreate 1st Linked List\n");
    printf("\nEnter the no.of Nodes : ");
    scanf("%d", &n1);

    //list1 = (Node *)malloc(n1 * sizeof(Node));

    for (i = 0; i < n1; i++)
    {
        printf("\nEnter the value of the  Node : \n");
        scanf("%d", &data);
        list1 = create(list1, data);
    }

    printf("\nCreate 2nd Linked List : ");
    printf("\nEnter the no.of Nodes : ");
    scanf("%d", &n2);

    //list2 = (Node *)malloc(n2 * sizeof(Node));

    for (i = 0; i < n2; i++)
    {
        printf("\nEnter the value of the  Node : ");
        scanf("%d", &data);
        list2 = create(list2, data);
    }

    display(list1);
    printf("\n");

    display(list2);
    printf("\n");

    concatedList = concate(list1, list2);
    display(concatedList);
}

Node *concate(Node *list1, Node *list2)
{
    if (list1 == NULL)
        return list2;
    else if (list2 == NULL)
        return list1;
    else if (list1 == NULL && list2 == NULL)
    {
        printf("\nCouldn't found any Data...!!!");
        exit(0);
    }
    else
    {
        Node *p;
        p = list1;
        while (p->next != NULL)
            p = p->next;
        p->next = list2;
    }
    return list1;
}
