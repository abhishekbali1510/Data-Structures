#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prv;
}*tmp;

// traversing the list
void display(struct node * head)
{
    if(head==NULL)
    {
        printf("no nodes present!!\n");
    }
    else
    {
        printf("Using next pointer : \n");
        while(head)
        {
            printf("%d ",head->data);
            tmp=head;
            head=head->next;
        }
        
        printf("\nUsing prv pointer : \n");
        while(tmp)
        {
            printf("%d ",tmp->data);
            tmp=tmp->prv;
        }
        
    }
}

// insetion at beginning
struct node * insertBeg(struct node * head)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&newNode->data);
    newNode->prv=NULL;
    tmp=head;
    head=newNode;
    newNode->next=tmp;
    if(tmp)
        tmp->prv=newNode;
    return head;
}

// insertion at End
struct node* insertEnd(struct node * head)
{
    struct node *newNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data : ");
    scanf("%d",&newNode->data);
    newNode->next=NULL;
    newNode->prv=NULL;

    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        tmp=head;
        while(tmp->next)
        {
            tmp=tmp->next;
        }
        newNode->prv=tmp;
        tmp->next=newNode;
    }
    return head;

}

// insert at particular postition
struct node * insertPos(struct node * head)
{
    int pos;
    struct node *newNode=(struct node*)malloc(sizeof(struct node)),*prv;
    printf("Enter the data : ");
    scanf("%d",&newNode->data);
    printf("Enter the Position : ");
    scanf("%d",&pos);
    newNode->next=NULL;
    newNode->prv=NULL;
    if(head==NULL)
    {
        head=newNode;
    }
    else if(pos==1)
    {
        tmp=head;
        head=newNode;
        tmp->prv=newNode;
        newNode->next=tmp;
    }
    else
    {
        prv=head;
        tmp=head;
        pos--;
        while(tmp->next&&pos)
        {
            prv=tmp;
            pos--;
            tmp=tmp->next;
        }
        if(pos==0)
        {
            newNode->next=tmp;
            newNode->prv=prv;
            tmp->prv=newNode;
            prv->next=newNode;
        }
        else
        {
            tmp->next=newNode;
            newNode->prv=tmp;
        }
    }
    return head;
    
}

// deletion form beginning
struct node* deleteBeg(struct node *head)
{
    if(head==NULL)
    {
        printf("No nodes to delete");
        return NULL;
    }
    tmp=head;
    head=head->next;
    if(head!=NULL)
    head->prv=NULL;
    free(tmp);
    display(head);
    return head;

}

struct node * deleteEnd(struct node * head)
{
    if(head==NULL)
    {
        printf("No nodes to delete");
        return NULL;
    }
    tmp=head;

    if(head->next==NULL)        //for only one node
    {
        free(tmp);
        return NULL;
    }

    while(tmp->next)
    {
        tmp=tmp->next;
    }

    tmp->prv->next=NULL;
    free(tmp);
    display(head);
    return head;

}

// delete from specific position
struct node * deletePos(struct node * head)
{
    int pos;
    if(head==NULL)
    {
        printf("no node to delete");
        return NULL;
    }
    printf("enter the position you want to delete : ");
    scanf("%d",&pos);
    tmp=head;
    if(pos==1)
    {
        head=head->next;
        if(head)
        head->prv=NULL;
        free(tmp);
        display(head);
        return head;
    }
    pos--;
    while(tmp&&pos)
    {
        tmp=tmp->next;
        pos--;
    }
    if(tmp==NULL)
    {
        printf("position not exist ");
        return head;
    }
    else
    {
        tmp->prv->next=tmp->next;
        if(tmp->next)
        {
            tmp->next->prv=tmp->prv;
        }
        free(tmp);
        display(head);
        return head;
    }
}


//Searching 
void search(struct node *head)
{
    int x,pos=1,found=0;
    if(head==NULL)
    {
        printf("no nodes to search");
        return;
    }
    
    printf("Enter the data you want to search : ");
    scanf("%d",&x);
    tmp=head;
    while(tmp)
    {
        if(tmp->data==x)
        {
            found=1;
            break;
        }
        pos++;
        tmp=tmp->next;
    }
    if(found)
    {
        printf("Element found at %d position ",pos);
    }
    else
    {
        printf("Not found");
    }
    
}



void main()
{
    struct node* head;
    int choice;
    
    while(1)
    {
        printf("\n");
        printf("Enter the choice : \n");
        printf("0. Exit\n");
        printf("1. Display whole list\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Search an Element\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 0: exit(0);
                    break;
            
            case 1: display(head);      
                    break;
            
            case 2: head = insertBeg(head);
                    break;

            case 3: head = insertEnd(head);
                    break;
                
            case 4: head = insertPos(head);
                    break;

            case 5: head = deleteBeg(head);
                    break;
                    
            case 6: head = deleteEnd(head);
                    break;

            case 7: head = deletePos(head);
                    break;

            case 8: search(head);
                    break;

        }
    }
}