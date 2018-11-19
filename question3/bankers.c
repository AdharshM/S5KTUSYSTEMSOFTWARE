#include <stdio.h>

void main()
{
	int m , n,i,j,k,x ;

	int available[30],allocation[30][30],max[30][30],need[30][30],seq[30];
	int finish[30],temp,finished=0;

	printf("\nENTER THE NUMBER OF PROCESSES \n");
	scanf("%d",&n);
	printf("\nENTER THE NUMBER OF RESOURCES\n");
	scanf("%d",&m);
	
	printf("ENTER THE RESOURCES AVAILABLE AFTER ALL ALLOCATION\n");
	for(i=0;i<m;++i)
	{
		printf("\n RESOURCE %d",i);
                scanf("%d",&available[i]);
	}

	printf("ENTER THE ALLOCATED RE SOURCES FOR EACH PROCESS\n");
	for(i=0 ;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			printf("\nPROCESS %d RESOURCE %d ",i,j);
			scanf("%d",&allocation[i][j]);
		}
	}
	printf("ENTER THE MAXIMUM RESOURCES NEEDED FOR EACH PROCESS\n");
	
	for(i=0 ;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			printf("\nPROCESS %d RESOURCE %d ",i,j);
			scanf("%d",&max[i][j]);
                        need[i][j]=max[i][j]-allocation[i][j];
		}
	}

	printf("CURRENT STATE OF THE SYSTEM\n");
        printf("\n AVAILABLE\n");
        for(i=0;i<m;++i)
	{
		printf("%d",available[i]);
	}

	printf("\n ALLOCATION\n");
	for(i=0;i<n;++i)
	{
		printf("\n");
        	for(j=0;j<m;++j)
		{
			printf("\t %d",allocation[i][j]);
		}
	}

	
	printf("\n MAX \n");
	for(i=0;i<n;++i)
	{
		printf("\n");
        	for(j=0;j<m;++j)
		{
			printf("\t %d",max[i][j]);
		}
	}







        for(i=0;i<n;++i)
	{
		finish[i]=0;
	}

	for(i=0;i<n;++i)
	{
		for(j=0;j<n;++j)
		{
			if(finish[j]==0)
			{
			  temp=1;
           		  for(k=0;k<m;++k)
			  {
				if(need[j][k]>available[k])
				{
					temp=0;
				}
			  }
		          if(temp==1)
			  {
				finish[j]=1;
				seq[finished]=j;
				finished++;
				for(x=0;x<m;++x)
  				{
					available[x]+=allocation[j][x];
				}
				
			  }	
			}
		}
	}

if( finished==n)
{

   printf("\nSYSTEM IS IN A SAFE STATE\nSAFE SEQUENCE\n");
   for(i=0;i<finished;++i)
   {
	printf("--%d--",seq[i]); 
   }
   
}
else
{
	printf("UNSAFE STATE \n");
}





}
