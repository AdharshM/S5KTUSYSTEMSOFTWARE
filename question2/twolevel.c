#include <stdio.h>
#include <string.h>

struct dnode
{
	char dirname[30];
	int fcount;
	char files[15][30];
} dir[10];


void main()
{

	int n,i,j ,ch,inc;
       
	char dname[20] , fname[20],tmpname[20];

	struct dnode temp;

	printf("ENTER THE NUMBER OF DIRECTORY ENTRIES\n");
	scanf("%d",&n);

	for(i=0;i<n;++i)
	{
		printf("ENTER THE NAME OF DIRECTORY %d",(i+1));
	    	scanf("%s",dir[i].dirname);
		printf("ENTER THE NUMBER OF FILES UNDER %s",dir[i].dirname);

		scanf("%d",&dir[i].fcount);

		printf("ENTER THE FILES UNDER %s",dir[i].dirname);

		for(j=0;j<dir[i].fcount;++j)
		{
			scanf("%s",dir[i].files[j]);
		}



	}
	
	while(1)
	{
             printf("ENTER YOUR CHOICE \n");
	     printf("1. ADD A FILE \n");
	     printf("2. ADD A DIRECTORY\n");

	     printf("3. DELETE A FILE \n");
	     printf("4. DELETE DIRECOTRY\n");
	     printf("5. TRAVERSE DIRECTORY STRUCTURE\n");
	     printf("ENTER YOUR CHOICE \n");
	     scanf("%d",&ch);

	     switch(ch)
	     {
		     case 1 : printf("ENTER THE NAME OF THE DIRECTORY");
			      scanf("%s",dname);
			      for(i=0;i<n;++i)
			      {
				      if(strcmp(dname,dir[i].dirname)==0)
				      {
					      printf("ENTER THE NAME OF FILE\n");
					      
					      dir[i].fcount+=1;
					      
					      inc=dir[i].fcount;
					      
					      scanf("%s",dir[i].files[inc-1]);
					      

				              break; 
				      
				      }
			      }

			      if(i==n)
			      {
				      printf("DIRECTORY NOT FOUND\n");
			      }
			      break;

	            case 2 :
			      printf("ENTER THE NAME OF THE NEW DIRECTORY\n");
			      //scanf("%s",dname);

			      n+=1;

			      //dir[n-1].dirname = dname ;
			      //strcpy(dname,dir[n-1].dirname);
			      
			      scanf("%s",dir[n-1].dirname);

			      dir[n-1].fcount=0;
			      break ;

		   case 3 : 

			      printf("ENTER THE NAME OF THE DIRECTORY");
                              scanf("%s",dname);
                              for(i=0;i<n;++i)
                              {
                                      if(strcmp(dname,dir[i].dirname)==0)
                                      {
                                              printf("ENTER THE NAME OF FILE\n");

                                              scanf("%s",fname);
					      for(j=0;j<dir[i].fcount;j++)
					      {
						      if(strcmp(fname,dir[i].files[j])==0)
						      {
							      strcpy(dir[i].files[j],tmpname);
							      strcpy(dir[i].files[dir[i].fcount-1],dir[i].files[j]);
							      strcpy(tmpname,dir[i].files[dir[i].fcount-1]);
							      dir[i].fcount-=1;

							      break;
						


						      }
					      }
					      if(j==dir[i].fcount)
					      {
					        printf("FILE NOT FOUND\n");
					      }


                                              break;

                                      }
                              }

			      if(i==n)
			      {
				      printf("DIRECOTORY NOT FOUND\n");
			      }
			      break;




                    case 4 : 
			      printf("ENTER THE NAME OF THE DIRECTORY\n");
			      scanf("%s",dname);

			      for(i=0;i<n;++i)
			      {
				      if(strcmp(dir[i].dirname,dname)==0)
				      {

					      temp=dir[i];
					      dir[i]=dir[n-1];
					      dir[n-1]=temp;
					      n-=1;
					      break;
				      
				      
				      
				      
				      }

			      }

			      if(i==n)
			      {
				      printf("DIRECTORY NOT FOUND\n");
			      }

			      break;




	            case 5 :
			       for(i=0;i<n;++i)
			       {
				       printf("DIRECTORY NAME = %s\n",dir[i].dirname);
				       printf("FILES = ");
				       for(j=0;j<dir[i].fcount;++j)
				       {
					       printf("%s\n",dir[i].files[j]);
				       }

				       printf("\n\n");
			       }
			       break;

			 
                    default : break ;

		


	     }

	     


             printf("DO YOU WANT TO ENTER MORE \n");
	     scanf("%d",&ch);
	     if(ch!=1)
		      {break;}

	}



}
