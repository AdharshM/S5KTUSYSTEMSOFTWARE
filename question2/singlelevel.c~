#include <stdio.h>
#include <string.h>



void main()
 {
     char str[15][30];

     char fname[30],rough[30];

     int i,n,ch,j ,index;

     printf("INITIAL CREATION\n");
     printf("\n**************************\n");
     printf("ENTER THE NUMBER OF FILES IN MAIN DIRECTORY");
     scanf("%d",&n);

     printf("ENTER THE NAMES OF THE FILES \n");


     for(i=0;i<n;++i)
     {
        scanf("%s",str[i]);
     }


   

     while(1)
    {
     printf("ENTER YOUR CHOICE\n");
     printf("1. ADD FILE \n");
     printf("2.DELETE FILE \n");
     printf("3.SHOW DIRECTORY STRUCTURE\n");

     scanf("%d",&ch);
     
     switch(ch)
     {

          case 1 :  printf("ENTER THE NAME OF THE FILE \n");
  	            n=n+1;
                    scanf("%s",str[n-1]);
                    break;

         case 2 :   printf("ENTER THE FILE TO BE DELETED\n");
                    scanf("%s" ,fname);
                 
                    for(j=0;j<n;++j) 
                    {  
                           if(strcmp(fname,str[j])==0)
                           {             
                             strcpy(str[j],str[n-1]);
                             n=n-1;
                              
                              break;
                           }
                    } 
                    if(j==n)
                    {
                       printf("FILE NOT DELETED\n");
                    }
                    else
                    {
                                             printf("FILE DELETED\n");
                    }
                    break; 
         case 3 :
                        for(i=0;i<n;++i)
                       {
                             printf("%s",str[i]);
                       }
                     break;
         default :	break;
   
  


      }
     printf("\nDO YOU WANT TO ENTER MORE (0/1) \n");
     scanf("%d",&ch);
     if(ch!=1)
         {break;}
  
    }
    
    
   }

