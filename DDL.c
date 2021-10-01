#include<stdio.h>
#include<stdlib.h>

struct node{int data; struct node* next;}*head;

int length()
{
    struct node* temp=head;
    int l=1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
        l++;
    }
    return l;
}

void insertatbegin(int x)
{
    struct node* first=(struct node*)malloc(sizeof(struct node));
    first->data=x;
    first->next=NULL;
    if(head!=NULL)
    {
    first->next=head;
    }
    head=first;
}

void addatlast(int x)
{
    struct node* temp=head;
    struct node* last=(struct node*)malloc(sizeof(struct node));
        last->data=x;
        last->next=NULL;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=last;
}

void addanywhere(int key, int x)
{
    if(key>length()+1)
    {
        printf("Exceeding limits.\n");
    }
    else
    {
        struct node* temp=head;
        if(key==1)
        {
            insertatbegin(x);
        }
        else
        {
        while(key-2)
        {
            key--;
            temp=temp->next;
        }
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=temp->next;
        temp->next=newnode;
        }
    }
}

void delete(int key)
{
     if(key>length()+1)
    {
        printf("Exceeding limits.\n");
    }
    else
    {
        struct node* temp;
        temp=head;
        if(key==1)
        {
            head=temp->next;
        }
        else
        {
        while(key-2)
        {
            key--;
            temp=temp->next;
        }
        temp->next=(temp->next)->next;
        }
    }
}
void print()
{
    struct node *temp=head;
    printf("List is ");
    while(temp!=NULL)
    {
    printf(" %d", temp->data);
    temp=temp->next;
    }
    printf("\n");
}
void selectionsort()
{
    int t, n=length();
    struct node *temp, *small, *linear=head;
    while(linear->next!=NULL)
    {
        temp=linear;
        small=linear;
        while(temp!=NULL)
        {
            if(temp->data<small->data)
            {
                small=temp;
            }
            temp=temp->next;
        }
        t=small->data;
        small->data=linear->data;
        linear->data=t;
        linear=linear->next;
    }
}

int middle()
{
    int i, l=length();
    struct node* temp=head;
    if(head!=NULL)
    {
    for(i=0; i<l/2; i++)
    {
        temp=temp->next;
    }
    return temp->data;
    }
}
//function to find middle of linked list. It returns address of middle of linked list.
struct node* middle_pointer(struct node* start, struct node* last)
{
    if(start==NULL)
    {
        return NULL;
    }
    struct node* slow=start;
    struct node* fast=start->next;

    while(fast!=last)
    {
        fast=fast->next;

        slow=slow->next;
    }
    return slow;
}

struct node* binarysearch(int key)
{
    struct node* start=head;
    struct node* last=NULL;
    do
    {
        struct node* mid=middle_pointer(start, last);
        if(mid==NULL)
            return NULL;
        if(mid->data==key)
            return mid;
        else if(mid->data<key)
            start=mid->next;
        else
            last=mid;
    }while(last!=NULL || last!=start);

    return NULL;
}

int main()
{
    int op, i, n, first, last, bet, key, del, ser, position;
    while(1)
    {

    printf("Enter option:\n1. To insert at beginning\n2. To insert at last\n3. To insert anywhere\n4. To find the length of linked list\n");
    printf("5. To delete\n6. To selection sort\n7. To search by binary method\n8. To find middle\n11. To exit\n");
    scanf("%d", &op);
    switch(op)
    {
        case 1:
            printf("Insert number to add at beginning: ");
            scanf("%d", &first);
            insertatbegin(first);
            print();
        break;
        case 2:
            printf("Insert number to add at last.\n");
            scanf("%d", &last);
            addatlast(last);
            print();
        break;
        case 3:
            printf("Insert data to add at specific place.\n");
            scanf("%d", &bet);
            printf("Enter position.\n");
            scanf("%d", &key);
            addanywhere(key, bet);
            print();
        break;
        case 4:
            printf("Number of nodes=%d\n", length());
        break;
        case 5:
            printf("Enter position to delete\n");
            scanf("%d", &del);
            delete(del);
            print();
        break;
        case 6:
            selectionsort();
            printf("Sorted list is: ");
            print();
        break;
        case 7:
            printf("Enter data to search\n");
            scanf("%d", &ser);
            if(binarysearch(ser)==NULL)
                printf("Value not found\n");
            else
                printf("%d found.\n", binarysearch(ser)->data);
        break;
        case 8:
            printf("%d is middle of list.\n", middle());

        break;
        case 11:
            exit(0);
        break;
        default:
            printf("Wrong choice.\n");
    }
    }
    return 0;
}
