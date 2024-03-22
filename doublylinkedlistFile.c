#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct song
{
char name[20];
char singer[20];
double time;
};
struct node
{
struct song s;
struct node *next;
struct node *prev;
};
void addatbeg(struct node **head, struct song s);
void addatendll(struct node **head, struct song s);
void Displaylist(struct node *head);
void readdata(struct song *s);
void deletename(struct node **head, char song[]);
void displaytime(struct node *head);
void deletesinger(struct node **head, char singer[]);
void reverselist(struct node **head);
int main()
{
struct song s;
struct node *head = NULL;
int ch;
char name[20];
while (1)
{
printf("1. Add a song\n");
printf("2. Delete song by name\n");
printf("3. Delete songs by singer\n");
printf("4. Display songs by duration\n");
printf("5. Display all songs\n");
printf("6. Reverse the list\n");
printf("7. Delete the song \n");
printf("8. Exit\n");
printf("Enter choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:
readdata(&s);
addatendll(&head, s);
break;
case 2:
printf("Enter the song name to be deleted: ");
scanf("%s", name);
deletename(&head, name);
break;
case 3:
printf("Enter the singer name to delete all songs: ");
scanf("%s", name);
deletesinger(&head, name);
break;
case 4:
displaytime(head);
break;
case 5:
Displaylist(head);
break;
case 6:
reverselist(&head);
break;
case 7:
deletesongprev(&head);
break;
default:
printf("Invalid choice\n");
exit(0);
}
}
}
void readdata(struct song *s)
{
printf("Enter song name: ");
scanf("%s", s->name);
printf("Enter singer name: ");
scanf("%s", s->singer);
printf("Enter duration: ");
scanf("%lf", &s->time);
}
void addatbeg(struct node **head, struct song s)
{
struct node *newNode = (struct node *)malloc(sizeof(struct node));
if (newNode == NULL)
{
printf("Memory allocation failed\n");
return;
}
newNode->s = s;
newNode->next = NULL;
newNode->prev = NULL;
if (*head == NULL)
{
*head = newNode;
(*head)->next = *head;
(*head)->prev = *head;
}
else
{
newNode->next = *head;
newNode->prev = (*head)->prev;
(*head)->prev->next = newNode;
(*head)->prev = newNode;
*head = newNode;
}
}
void Displaylist(struct node *head)
{
if (head == NULL)
{
printf("List is empty\n");
return;
}
struct node *cur = head;
do
{
printf("Song name: %s\n", cur->s.name);
printf("Singer name: %s\n", cur->s.singer);
printf("Duration: %.2lf\n\n", cur->s.time);
cur = cur->next;
}
while (cur != head);
}
void deletename(struct node **head, char song[])
{
if (*head == NULL)
{
printf("List is empty\n");
return;
}
struct node *cur = *head;
struct node *prevNode = NULL;
do
{
if (strcmp(cur->s.name, song) == 0)
{
if (cur == *head)
{
if (cur->next == *head)
{
free(cur);
*head = NULL;
return;
}
else
{
(*head)->next->prev = (*head)->prev;
(*head)->prev->next = (*head)->next;
*head = (*head)->next;
free(cur);
return;
}
}
else
{
cur->prev->next = cur->next;
cur->next->prev = cur->prev;
free(cur);
return;
}
}
prevNode = cur;
cur = cur->next;
}
while (cur != *head);
printf("Song not found\n");
}
void deletesinger(struct node **head, char singer[])
{
if (*head == NULL)
{
printf("List is empty\n");
return;
}
struct node *cur = *head;
struct node *prevNode = NULL;
int isDeleted = 0;
do
{
if (strcmp(cur->s.singer, singer) == 0)
{
isDeleted = 1;
if (cur == *head)
{
if (cur->next == *head)
{
free(cur);
*head = NULL;
return;
}
else
{
(*head)->next->prev = (*head)->prev;
(*head)->prev->next = (*head)->next;
*head = (*head)->next;
free(cur);
cur = *head;
}
}
else
{
cur->prev->next = cur->next;
cur->next->prev = cur->prev;
struct node *temp = cur;
cur = cur->next;
free(temp);
}
}
else
{
prevNode = cur;
cur = cur->next;
}
} while (cur != *head);
if (!isDeleted)
printf("No songs found for the given singer\n");
}
void displaytime(struct node *head)
{
if (head == NULL)
{
printf("List is empty\n");
return;
}
struct node *cur = head;
struct node *shortest = cur;
cur = cur->next;
while (cur != head)
{
if (cur->s.time < shortest->s.time)
shortest = cur;
cur = cur->next;
}
printf("Shortest Song:\n");
printf("Song name: %s\n", shortest->s.name);
printf("Singer name: %s\n", shortest->s.singer);
printf("Duration: %.2lf\n\n", shortest->s.time);
}
void addatendll(struct node **head, struct song s)
{
struct node *newNode = (struct node *)malloc(sizeof(struct node));
if (newNode == NULL)
{
printf("Memory allocation failed\n");
return;
}
newNode->s = s;
newNode->next = NULL;
newNode->prev = NULL;
if (*head == NULL)
{
*head = newNode;
(*head)->next = *head;
(*head)->prev = *head;
}
else
{
struct node *lastNode = (*head)->prev;
newNode->next = *head;
newNode->prev = lastNode;
lastNode->next = newNode;
(*head)->prev = newNode;
}
}
void reverselist(struct node **head)
{
if (*head == NULL)
{
printf("List is empty\n");
return;
}
struct node *current = *head;
struct node *temp = NULL;
do
{
temp = current->prev;
current->prev = current->next;
current->next = temp;
current = current->prev;
}
while (current != *head);
*head = temp->prev;
}
void deletesongprev(struct node **head)
{
struct node *cur = *head;
struct node *temp = cur->prev;
if (cur->next == cur)
{
free(cur);
*head = NULL;
return;
}
do
{
if (cur->s.time > temp->s.time)
{
temp->next = cur->next;
cur->next->prev = temp;
if (cur == *head)
*head = cur->next;
struct node *temp2 = cur;
cur = cur->next;
free(temp2);
}
else
{
cur = cur->next;
temp = temp->next;
}
}
 while (cur != *head);
}
