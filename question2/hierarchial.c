#include <stdio.h>
#include <string.h>
#include<stdlib.h>


int flag=0,delflag=0;

struct node 
{
	char name[20];
	struct node *ch[5];

};


void buildstructure(struct node* ptr)
{
	int i,ch;
	struct node * newnode;
       if(ptr!=NULL)
       {
	       printf("ENTER THE NAME OF THE DIRECTORY \n");
	       scanf("%s",ptr->name);

	       for(i=0;i<5;++i)
	       {
		       printf("DOES THE DIRECTORY %s HAVE  SUBDIRECTORY ?(0/1) \nIT ALREADY HAS %d SUBDIRECTORY",ptr->name,i);
                       scanf("%d",&ch);
		       if(ch==1)
		       {
			      newnode = (struct node *) malloc(sizeof(struct node)) ;
			      ptr->ch[i] = newnode ;
			      buildstructure(newnode);

		       }
		       else
		       {
			       break ;

		       }
	       }
	       if(i!=5)
	       {
		       while(i<5)
		       {
			       ptr->ch[i]=NULL;
			       i+=1;

		       }
	       }
       
       }	       
}


void add_new(struct node*ptr,char src[])
{
	int i;
	if(ptr!=NULL)
	{
		if(strcmp(ptr->name,src)==0)
		{
			struct node *newnode = (struct node*) malloc(sizeof(struct node));

			printf("ENTER THE NAME OF FILE\n");
			scanf("%s",newnode->name);
			for(i=0;i<5;++i)
			{
			  if(ptr->ch[i]==NULL)
			  {
		             flag=1;
		             ptr->ch[i]=newnode;
			     return;
			  }
			}

		}
		else
		{
                    for(i=0;i<5;++i)
		    {
		     add_new(ptr->ch[i],src);
		    }
		}
	}
}

void delete_dir(struct node *parent_ptr , struct node *ptr,char string[],int index)
{
	int i;
	if(ptr!=NULL)
	{
		if(strcmp(ptr->name,string)==0)
		{
			parent_ptr->ch[index]=NULL;
			delflag=1;
			return;
			
		
		}
		else
		{
			for(i=0;i<5;++i)
			{
				delete_dir(ptr,ptr->ch[i],string,i);
			}
		   
		}
	}



}


void display(struct node *ptr)
{     
         int i;

	if(ptr!=NULL)
	{
		printf("%s",ptr->name);
		for( i=0;i<5;++i)
		{
		  display(ptr->ch[i]);
		}
	
	}
}

void main()
{
    int ch=1;
    char dir[30];
    struct node *root =(struct node *)malloc(sizeof(struct node));
    buildstructure(root);

    struct node *temp =root;
   
    while(1)
    {
	    temp=root;
	    printf("ENTER YOUR CHOICE\n");
	    printf("1) ADD DIRECTORY/FILE \n");
	    printf("2) DELETE DIRECTORY\n");
	    printf("3) TRAVERSE DIRECTORY\n");
	    scanf("%d",&ch);
	    switch(ch)
	    {
		    
		    case 1:
			    flag=0;
			    printf("ENTER THE NAME OF THE DIRECTORY\n");
			    scanf("%s",dir);
			    add_new(temp,dir);
			    if(flag==1)
			    {
				    printf("DIRECTORY ADDED\n");
			    }
			    else
			    {
			       printf("DIRECTORY COULD NOT BE ADDED\n");
			    }


			    break;
	            case 2 : 
			    delflag=0;
                            printf("ENTER THE NAME OF THE DIRECTORY\n");
                            scanf("%s",dir);
                            delete_dir(NULL,temp,dir,0);
                            if(delflag==1)
                            {
                                    printf("DIRECTORY DELETED\n");
                            }
                            else
                            {
                               printf("DIRECTORY NOT DELETED\n");
                            }

			    break;
	            case 3:
			    display(temp);
			    break;
	            default: break ;
	    }
	    printf("DO YOU WANT TO ENTER MORE(0/1)\n");
	    scanf("%d",&ch);
	    if(ch==0)
	    {
		    break;
	    }
    
    
    }
    
    display(temp);


}

