#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#define ESC 27
#define UP 72
#define DO 80
#define RI 77
#define LE 75
#define EN 13
int X=42,Y=10,X_axis=22;
struct node
{
	char data;
	int x,y;
	struct node *next,*pre;
}*start,*first;
struct node *create(struct node *,int,int,int);
struct node *change(struct node *,int,int);
int check(struct node *,int,int,int);
void print(struct node *,struct node *);
int x_a,y_a,score1=0,score2=0;
void main()
{
	char ch,ch1,ch2,ch3,ch4;
	int i,j;
	randomize();
	clrscr();
	x_a=(rand()%79)+3;
	y_a=(rand()%24)+3;
	for(i=0;i<10;i++)
	 {
		start=create(start,0,0,0);
		first=create(first,2,0,0);
	 }
	print(start,first);
	ch=RI;
	ch1=RI;
	ch3='a';
	while(1)
	 {
		while(!kbhit())
		{
			if(ch4==DO)
			{
			i=check(start,start->x,start->y+1,0);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch4;
			j=0;
			}
			else if(ch4==RI)
			{
			i=check(start,start->x+1,start->y,0);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch4;
			j=0;
			}
			else if(ch4==LE)
			{
			i=check(start,start->x-1,start->y,0);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch4;
			j=0;
			}
			else if(ch4==UP)
			{
			i=check(start,start->x,start->y-1,0);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch4;
			j=0;
			}
		       if(ch3=='d')
			{
				i=check(first,first->x+1,first->y,1);
				clrscr();
				print(start,first);
				if(i==1)
					ch1=ch3;
				j=1;
			 }
			else if(ch3=='s')
			 {
				i=check(first,first->x,first->y+1,1);
				clrscr();
				print(start,first);
				if(i==1)
					ch1=ch3;
				j=1;
			 }
			else if(ch3=='a')
			 {
				i=check(first,first->x-1,first->y,1);
				clrscr();
				print(start,first);
				if(i==1)
					ch1=ch3;
				j=1;
			 }
			else if(ch3=='w')
			 {
				i=check(first,first->x,first->y-1,1);
				clrscr();
				print(start,first);
				if(i==1)
					ch1=ch3;
				j=1;
			 }
			if(i==0 && j!=1)
				ch4=ch1;
			else if(i==0 && j==1)
				ch3=ch1;
			delay(100);
		}
		{
		if(i==1)
			ch=getch();
		else
			ch=ch1;
		if(ch==DO)
		 {
			i=check(start,start->x,start->y+1,0);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch;
			ch4=ch;
		 }
		else if(ch==RI)
		 {
			i=check(start,start->x+1,start->y,0);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch;
			ch4=ch;
		 }
		 else if(ch==LE)
		 {
			i=check(start,start->x-1,start->y,0);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch;
			ch4=ch;
		 }
		 else if(ch==UP)
		 {
			i=check(start,start->x,start->y-1,0);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch;
			ch4=ch;
		 }
		else if(ch==ESC)
		 {
			ch2=getch();
			if(ch2==ESC)
				break;
		 }
		else if(ch=='d')
		 {
			i=check(first,first->x+1,first->y,1);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch;
			ch3=ch;
		 }
		else if(ch=='s')
		 {
			i=check(first,first->x,first->y+1,1);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch;
			ch3=ch;
		 }
		else if(ch=='a')
		 {
			i=check(first,first->x-1,first->y,1);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch;
			ch3=ch;
		 }
		else if(ch=='w')
		 {
			i=check(first,first->x,first->y-1,1);
			clrscr();
			print(start,first);
			if(i==1)
			ch1=ch;
			ch3=ch;
		 }
		else if(ch!=RI||ch!=UP||ch!=DO||ch!=LE||
			ch!='a'||ch!='s'||ch!='d'||ch!='w')
			ch=ch1;
	  }
	 }
}
int check(struct node *start,int x,int y,int ch)
{
	struct node *ptr;
	int s,j;
	ptr=start->next->next->next;
	while(ptr->next!=NULL)
	 {
		if(ptr->x==x&&ptr->y==y)
		 {
			 gotoxy(38,12);
			 delline();
			 printf("Game over");
			 getch();
			 delay(500);
			 exit(0);
		 }
	       else if(x==0||y==1||y==26||x==81)
		 {
			 gotoxy(38,12);
			 delline();
			 printf("Game over");
			 getch();
			 delay(500);
			 exit(0);
		 }
		ptr=ptr->next;
	 }
	if(ptr->x==x&&ptr->y==y)
		 {
			 gotoxy(38,12);
			 delline();
			 printf("Game over");
			 getch();
			 delay(500);
			 exit(0);
		 }
	ptr=start->next;
	if(x==x_a&&y==y_a)
	 {
		ptr=start;
		x_a=(rand()%80)+2;
		y_a=(rand()%23)+3;
		if(ch==0)
			score1++;
		else
			score2++;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		s=ptr->x;
		j=ptr->y;
		start=change(start,x,y);
		start=create(start,1,s,j);

	 }
	else if(ptr->x==x&&ptr->y==y)
		return 0;
	else
		start=change(start,x,y);
	return 1;
}
struct node *change(struct node *start,int x,int y)
{
	struct node *ptr;
	ptr=start;
		while(ptr->next!=NULL)
		 {
			ptr=ptr->next;
		 }
		while(ptr->pre!=NULL)
		{
			ptr->x=ptr->pre->x;
			ptr->y=ptr->pre->y;
			ptr=ptr->pre;
		}
			ptr->y=y;
			ptr->x=x;
return start;
}
struct node *create(struct node *start,int k,int x,int y)
{
	struct node *newn,*ptr=NULL;
	newn=(struct node *)calloc(6,sizeof(struct node *));
	newn->data='*';
	newn->next=NULL;
	newn->pre=NULL;
	if(k==2)
	 {
		newn->x=X++;
		newn->y=10;
	 }
	else if(k==0)
	 {
		newn->x=X_axis--;
		newn->y=10;
	 }
	else
	 {
		ptr=start;
		newn->x=x;
		newn->y=y;
	 }
		if(start==NULL)
		 {
			newn->data='';
			start=newn;
			start->pre=NULL;
		 }
		else
		 {
			ptr=start;
			while(ptr->next!=NULL)
			 {
				ptr=ptr->next;
			 }
			ptr->next=newn;
			newn->pre=ptr;
		 }

	return start;
}
void print(struct node *start,struct node *first)
{
	struct node *ptr,*save;
	gotoxy(x_a,y_a);
	printf("0");
	gotoxy(2,1);
	printf("Player 1:%d",score1);
	gotoxy(69,1);
	printf("Player 2:%d",score2);
	ptr=start;
	while(ptr->next!=NULL)
	 {
		gotoxy(ptr->x,ptr->y);
		printf("%c",ptr->data);
		ptr=ptr->next;
	 }
	gotoxy(ptr->x,ptr->y);
	printf("%c",ptr->data);
	save=first;
	while(save->next!=NULL)
	 {
		gotoxy(save->x,save->y);
		printf("%c",save->data);
		save=save->next;
	 }
	gotoxy(save->x,save->y);
	printf("%c",save->data);
}