#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};
void addatbeg(struct node **, int);
void displaydata(struct node **);
int deleteatbeg(struct node **);
void addatend(struct node **, int);
int deleteatend(struct node **);
int lenghtoflist(struct node *);
int searchelement(struct node *, int );
int frequency(struct node *, int);
void addatanypos(struct node **, int, int);
void reverselist(struct node **);
void deletestocc(struct node **, int);
void sortlist(struct node *);
void r_Duplicate(struct node *);
void reverseKthNode(struct node **, int );
void deleteAtPos(struct node **, int);
int main()
{
struct node *head=NULL;
int n, e, f, pos, key;
while(1)
{
printf("\n1.Add at beginning\n");
printf("2.Delete at beginning\n");
printf("3.display list\n");

printf("4.Add at end\n");
printf("5.Delete at end\n");
printf("6.Length of list\n");
printf("7.Search an element\n");
printf("8.Frequency of element:\n");
printf("9.Add node at any given position\n");
printf("10.Reverse List\n");
printf("11.Delete the First occurence\n");
printf("12.Sort_list \n");
printf("13.Remove Duplicate\n");
printf("14.Reverse Every kth node\n");
printf("15.Delete at position\n");
printf("Enter n: ");
scanf("%d",&n);
switch(n)
{
case 1: printf("Enter the date: ");
scanf("%d",&e);
addatbeg(&head, e);
break;
case 2: if(head==NULL)
printf("List empty");
else
{
e=deleteatbeg(&head);
}
break;
case 3: displaydata(&head);
break;
case 4: printf("Enter the data: ");
scanf("%d",&e);
addatend(&head, e);
break;
case 5: if(head==NULL)

printf("List empty");
else
{
e=deleteatend(&head);
}
break;
case 6: e=lenghtoflist(head);
printf("List length=%d",e);;
break;
case 7: if(head==NULL)
{
printf("list empty");
}
else
{
printf("Enter the key: ");
scanf("%d",&e);
f=searchelement(head, e);
if(f)
printf("Key is found:");
else
printf("Key not found");
}
break;
case 8: printf("Enter the key for frequency: ");
scanf("%d",&e);
f=frequency(head, e);
printf("The frequency of %d is %d", e, f);
case 9: printf("Enter the data: ");
scanf("%d",&e);
printf("Enter position: ");
scanf("%d",&pos);
addatanypos(&head, e, pos);
break;
case 10:reverselist(&head);
break;
case 11:printf("Enter the key: ");
scanf("%d",key);
deletestocc(&head, key);
break;
case 12: sortlist(head);
break;
case 13: r_Duplicate(head);
break;
case 14: printf("Enter k: ");
scanf("%d",&e);
reverseKthNode(&head, e);
break;
case 15:printf("Enter pos: ");
scanf("%d",&e);
deleteAtPos(&head, e);
break;
default: exit(0);
}
}
}
void addatbeg(struct node **head, int e)
{
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
if(p==NULL)
{
perror(" ");
return;
}
p->data=e;
p->next=*head;
*head=p;
}
void displaydata(struct node **head)
{
struct node *cur=*head;
if(*head==NULL)
{
printf("-List Empty-\n-Enter data-\n");
return;
}
while(cur)
{
printf("%d\t",cur->data);
cur=cur->next;
}
}
int deleteatbeg(struct node **head)
{
struct node *p=*head;
*head=(*head)->next;
int e=p->data;
free(p);
return e;
}
void addatend(struct node **head, int e)
{
struct node *p;
struct node *cur=*head;
p=(struct node*)malloc(sizeof(struct node));
if(p==NULL)
{
perror(" ");
return;
}
p->data=e;
p->next=NULL;
if(*head==NULL)
*head=p;
else
{
while(cur->next)
cur=cur->next;
cur->next=p;
}
}
int deleteatend(struct node **head)
{
struct node *cur=*head;
struct node *prev=NULL;
int e;
while(cur->next)
{
prev=cur;
cur=cur->next;
}
e=cur->data;
if(prev)
prev->next=NULL;
else
*head=NULL;
free(cur);
return e;
}
int lenghtoflist(struct node *head)
{
struct node *p=head;
int count=0;
while(p)
{
count++;
p=p->next;
}
return count;
}
int searchelement(struct node *head, int key)
{
struct node *cur=head;
while(cur)
{
if(key==cur->data)
return 1;
cur=cur->next;
}
return 0;
}
int frequency(struct node *head, int key)
{
struct node *cur=head;
int c=0;
while(cur)
{
if(key==cur->data)
{
c++;
cur=cur->next;

}
}
return c;
}
void addatanypos(struct node **head, int e, int pos)
{
struct node *p;
struct node *cur=*head;
struct node *prev=NULL;
p=(struct node *)malloc(sizeof(struct node));
if(p==NULL)
{
perror("");
return ;
}
p->data=e;
p->next=NULL;
if(pos<=0 || *head==NULL)
{
p=*head;
*head=p;
return;
}
for(int i=1;i<=pos && cur ;i++)
{
prev=cur;
cur=cur->next;
}
prev->next=p;
p->next=cur;
}
void deleteAtPos(struct node **head, int pos)

{
struct node *prev=NULL;
struct node *cur=*head;
if(pos<=0)
{
*head=(*head)->next;
free(cur);
return;
}
else if(pos>lenghtoflist(*head))
{
while(cur->next)
{
prev=cur;
cur=cur->next;
}
prev->next=NULL;
free(cur);
}
else
{
for(int i=0;i<pos-1;i++)
{
prev=cur;
cur=cur->next;
}
prev->next=cur->next;
free(cur);
}
}
void reverselist(struct node **head)
{
struct node *p=*head;
struct node *q, *r=NULL;
if(p)
q=p->next;
if(q)

r=q->next;
while(q)
{
q->next=p;
p=q;
q=r;
if(r)
r=r->next;
}
if(*head)
(*head)->next=NULL;
*head=p;
}
void deletestocc(struct node** head, int key)
{
struct node* cur = *head;
struct node* prev = NULL;
if (cur == NULL)
return;
while (cur != NULL && cur->data != key)
{
prev = cur;
cur = cur->next;
}
if (cur == NULL)
return;
if (cur == *head)
{
*head = cur->next;
free(cur);
return;
}
prev->next = cur->next;
free(cur);
}
void sortlist(struct node *head)
{
struct node *min;
int temp;
struct node *i, *j;
for(i=head;i&&i->next;i=i->next)
{
min = i;
for (j=i->next;j!=NULL;j=j->next)
{
if (j->data < min->data)
min = j;
}
if (min!=i)
{
temp = i->data;
i->data = min->data;
min->data = temp;
}
}
}
void reverseKthNode(struct node **head, int k)
{
if (*head == NULL || k <= 1)
{
return;
}
int n = lenghtoflist(*head) / k;
struct node *cur = *head;
struct node *prev = NULL;
for (int i = 0; i < n; i++)
{
struct node *p = cur;
struct node *q = NULL;
struct node *r = NULL;
for (int c = 0; c < k; c++)
{
struct node *temp = cur->next;
cur->next = q;
q = cur;
cur = temp;
}
if (i == 0)
*head = q;
else
prev->next = q;
p->next = cur;
prev = p;
r = cur;
}
}
void r_Duplicate(struct node* head)
{
if (head == NULL)
return;
struct node* current = head;
while (current != NULL)
{
struct node* runner = current;
while (runner->next != NULL)
{
if (runner->next->data == current->data)
{
struct node* temp = runner->next;
runner->next = runner->next->next;
free(temp);
}
else
{
runner = runner->next;
}
}
current = current->next;
}
}
