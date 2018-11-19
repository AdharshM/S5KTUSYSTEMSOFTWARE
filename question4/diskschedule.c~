#include <stdio.h>
#include <stdlib.h>

void selectsort(int a[],int n )
{


        int i,j,temp,smallest_index;

        for(i=0;i<n-1;++i){
                smallest_index=i;
                for(j=i+1;j<n;++j)
                {
                  if(a[j]<a[smallest_index])
                  {
                    smallest_index=j;
                  }

                }

                temp=a[i];
                a[i]=a[smallest_index];
                a[smallest_index]=temp;

        }


}




void main(){


	const int MAX_CYLINDER_COUNT=100;

	int n,i ,ch,  req[30], request,dir;
	int ele_index,index;

	int seek_time[30],total_seek_time;

        int startpoint;

	printf("ENTER THE NUMBER OF DISK REQUESTS \n");
	scanf("%d",&n);


	// INPUT THE DISK REQUESTS FROM THE USER
	printf("ENTER THE DISK REQUESTS \n");
	for(i=0;i<n;++i){
		scanf("%d",&request);

		if(request <0  || request > MAX_CYLINDER_COUNT)
		{
		   printf("ENTER VALID ADDRESS\n");
		   i-=1;
		   continue;
		}
		else 
		{
		   req[i]=request ; 
		}
	}

	// END OF INPUTTING THE REQUESTS
	
        lb :
	printf("\n ENTER THE STARTING POINT OF THE READ HEAD\n");
	scanf("%d",&startpoint);
        if(startpoint <0 || startpoint >MAX_CYLINDER_COUNT){
	
	printf("ENTER A VALID STARTING POINT\n");
	goto lb;
	}


	while(1)
	{
	
		total_seek_time=0;
		printf("DISK SCHEDULER \n________________________________\n");
		printf("1. FCFS \n");
		printf("2. SCAN \n");
		printf("3. C-SCAN \n");

		printf("ENTER  YOUR CHOICE \n");
		scanf("%d",&ch);

		switch(ch){

			case 1 :
				index=0 ;

				seek_time[0]=abs(req[0]-startpoint);
				printf("\n ORDER TRAVERSED=");
				++index;
				printf("%d--%d",startpoint,req[0]);
			
				for(i=1;i<n;++i){
				
					
				 seek_time[index]=abs(req[i]-req[i-1]);
				 index++;
			  
			         //total_seek_time+=abs(req[i]-req[i-1]);	 
				printf("--%d",req[i]);	 
				
				
				}

				for(i=0;i<index;++i){
				  
				  total_seek_time+=seek_time[i];
				}

				printf("\nTOTAL SEEK TIME = %d",total_seek_time);
				break;

			case 2:

				index=0;

				selectsort(req,n);
				for(i=0;i<n;++i)
				{

				   if(req[i]>=startpoint)
				   {
				     ele_index=i;
				     break ;
				   
				   }

				
				}

				printf("ENTER THE DIRECTION \n0. RIGHTWARDS\n1. LEFTWARDS\n");
				scanf("%d",&dir);
				if(dir==0)
				{
					


					seek_time[0]=abs(req[ele_index]-startpoint);
					index++;
					printf("\n ORDER TRAVERSED=");
					printf("%d--%d",startpoint,req[ele_index]);



					for(i=ele_index+1;i<n;i++)
					{

					    seek_time[index] = abs(req[i]-req[i-1]);
					    printf("--%d",req[i]);
					    index++;


					   
					
					}

					if(ele_index-1>=0)
					{
					 printf("--%d",MAX_CYLINDER_COUNT);

					seek_time[index]= MAX_CYLINDER_COUNT-req[n-1];

					
					seek_time[index]+=abs(MAX_CYLINDER_COUNT-req[ele_index-1]);
					printf("--%d",req[ele_index-1]);
					index++;
                                       }
					for(i=ele_index-2;i>=0;i--)
					{
					 printf("--%d",req[i]);
					

					seek_time[index] = abs(req[i]-req[i+1]);
					index++;

					}

					for(i=0;i<index;++i)
					{
						total_seek_time+=seek_time[i];
					     //   printf("%d\n",seek_time[i]);
					
					}
					printf("\nTOTAL SEEK TIME=%d",total_seek_time);

			         

					

				

				
				
				}
				else if(dir==1)
				{

					
				seek_time[0]=abs(startpoint-req[ele_index-1]);
			        index++;
				printf("\n ORDER TRAVERSED=");
				printf("%d--%d",startpoint,req[ele_index-1]);

				for(i=ele_index-2;i>=0;i--)
				{
				         printf("--%d",req[i]);
					seek_time[index] = abs(req[i]-req[i+1]);
					index++;
				
				}


				seek_time[index] = req[0];
				printf("--0");
				seek_time[index] += req[ele_index];//ds
				printf("--%d",req[ele_index]);
				index++;


				for(i=ele_index+1;i<n;++i)
				{
					seek_time[index] = abs(req[i] -req[i-1]);				printf("--%d",req[i]);
					index++;

				}

				for(i=0;i<n;++i)
				{
				
				
					
					total_seek_time+=seek_time[i];
				}

				printf("\n TOTAL SEEK TIME=%d\n",total_seek_time);



				}


				
				
				
				
				
				
				break;
			case 3:	
				index=0;	
				total_seek_time=0;
                                selectsort(req,n);
                                for(i=0;i<n;++i)
                                {

                                   if(req[i]>=startpoint)
                                   {
                                     ele_index=i;
                                     break ;

                                   }


                                }
				printf("ENTER THE DIRECTION \n 0 . RIGHTWARDS\n1. LEFTWARDS\n");
				scanf("%d",&dir);
				if(dir==0)
				{

				   seek_time[0]=abs(req[ele_index]-startpoint);
				printf("\n ORDER TRAVERSED=");
					printf("%d--%d",startpoint,req[ele_index]);

				   index++;

				   for(i=ele_index+1; i<n;++i)
				   {
					   printf("--%d",req[i]);
					  
					   seek_time[index]=abs(req[i]-req[i-1]);	
				            

					   index++;
				   
				   
				   }

				   

				   if(ele_index-1>=0)
				   {
				     		
			   						     seek_time[index]=abs(MAX_CYLINDER_COUNT-req[n-1]);
					
					printf("--%d--0",MAX_CYLINDER_COUNT);
				   	seek_time[index]+=MAX_CYLINDER_COUNT;


				     seek_time[index]+=req[0];
  				     
				     printf("--%d",req[0]);
				     ++index;
				     for(i=1;i<ele_index;++i)
				     {
					
					printf("--%d",req[i]);
				        seek_time[index]= abs(req[i]-req[i-1]);
					//printf(" SEEK %d",seek_time[index]);
					++index;
				     }
				   
				   }

				   for(i=0;i<index;++i)
				   {
					   printf("%d\n",seek_time[i]);
				         total_seek_time+=seek_time[i];
				   
				   }

				   printf("\nTOTAL SEEK TIME =%d",total_seek_time);

				   

				   



				
				
				
				}else if ( dir==1)
				{
					printf("%d",startpoint);
					seek_time[0]=startpoint;
					seek_time[0]+=req[0];
					printf("--0--%d",req[0]);
					index++;
					for(i=1;i<n;++i)
					{
				          printf("--%d",req[i]);
					  seek_time[index]=req[i]-req[i-1];
					  index++;
					}


					for(i=0;i<index;++i)
					{
					
					//	printf("%d\n",seek_time[i]);
					
						total_seek_time+=seek_time[i];
					}

					printf("\nTOTAL SEEK TIME=%d",total_seek_time);



				
				}







				
				break;
			default: 
				printf("ENTER VALID CHOICE\n");
				break ;

		}

   
           printf("\n DO YOU WANT TO ENTER MORE(0/1)\n");
	   scanf("%d",&ch);
	   if(ch!=1)
	   {
	     break;
	   }



	
	}





}





