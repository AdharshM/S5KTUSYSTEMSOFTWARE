#include<stdio.h>
#include<string.h>
#include <stdlib.h>


struct entry
{
	char key[3];
	int value;
	struct entry *next;
}*symtab[56];



int hashfunction(char str[])
{
	int sum=0;
	sum+=(str[0]-65);
	sum+=(str[1]-65);
	return sum;

}

void insert()
{	
	int index;
	int value;
	char str[3];
	struct entry *ptr=NULL;
	struct entry *ptr1=NULL;
 	
	struct entry *new_entry = (struct entry*)malloc(sizeof(struct entry));
	
	printf("Enter the Key value\n");
	scanf("%s",str);
        printf("ENTER THE VALUE\n");
	scanf("%d",&value);

	
	index=hashfunction(str);
	printf("%d",index);
	
	if(symtab[index]==NULL)
	{
		strcpy(new_entry->key,str);
		new_entry->value=value;
		new_entry->next=NULL;
		symtab[index]=new_entry;
		
		
	}
	else
	{

		ptr=symtab[index];
		if(strcmp(ptr->key,str)==0)
		{
			   printf("\nDUPLICATE ENTRY\n");
			  return ;
		}

		while(ptr != NULL)
		{	
			
			if(strcmp(ptr->key,str)==0)
			{
		          printf("\nDUPLICATE ENTRY\n");
			  return ;
			}
			ptr1=ptr;
			ptr=ptr->next;
		}
		
		strcpy(new_entry->key,str);
		new_entry->value=value;
		new_entry->next=NULL;
		
		ptr1->next=new_entry;	
		
	}

}

void search()
{	
	char key[3];
	printf("\nENTER THE KEY VALUE\n");
	scanf("%s",key);
	
	
	int index=hashfunction(key);

	if(symtab[index]==NULL)
	{
	   printf("ENTRY NOT FOUND\n");
	   return;

	}
	else
	{	
		struct entry *ptr=symtab[index];
		while(ptr!=NULL)
		{
			if(strcmp(ptr->key,key)==0)
			{
	
			printf("VALUE=%d",ptr->value);
			return;
		
			}
			ptr=ptr->next;
		}
		if(ptr==NULL)
		{
			printf("ELEMENT N0T FOUND\n");
		}

	}

}



void main()
{
	
	int ch=1,i;
	for(i=0;i<52;++i)
	{
		symtab[i]=NULL;
	}

	
	while(ch==1)
	{
		
	printf("\n HASH TABLE OPERATIONS \n *****************************\n");
	printf("1.INSERTION\n 2.SEARCHING \nENTER YOUR CHOICE\n ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1: insert(); break;
		case 2 :  search() ; break;
		default : printf("INVALID CHOICE\n"); break; 
	
	}
	printf("DO YOU WANT TO  ENTER MORE (0/1)\n");
	scanf("%d",&ch);
	
	}	
	
}
	
/*

 HASH TABLE OPERATIONS 
 *****************************
1.INSERTION
 2.SEARCHING 
ENTER YOUR CHOICE
 1
Enter the Key value
BC
ENTER THE VALUE
34
3DO YOU WANT TO  ENTER MORE (0/1)
1

 HASH TABLE OPERATIONS 
 *****************************
1.INSERTION
 2.SEARCHING 
ENTER YOUR CHOICE
 1
Enter the Key value
AD
ENTER THE VALUE
66
3DO YOU WANT TO  ENTER MORE (0/1)
1

 HASH TABLE OPERATIONS 
 *****************************
1.INSERTION
 2.SEARCHING 
ENTER YOUR CHOICE
 2

ENTER THE KEY VALUE
BC
VALUE=34DO YOU WANT TO  ENTER MORE (0/1)






*/
