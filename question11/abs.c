#include <stdio.h>
#include<stdlib.h>

void main()
{
	char rec[20];
	char progname[20];
	int start, length,locctr;
	FILE *objptr;
	objptr=fopen("program.txt","r");
	
	
	fscanf(objptr,"%s",rec);
	
	
	if(strcmp(rec,"H")==0)
	{
		//printf("HEADER RECORD");
		fscanf(objptr,"%s",progname);
		fscanf(objptr,"%X",&start);
		locctr=start;
		fscanf(objptr,"%X",&length);
		fscanf(objptr,"%s",rec);
	}	
	else
	{
		fclose(objptr);
		exit(1);
	}
	printf("ADDRESS\tOBJECT CODE\n");
	while(strcmp(rec,"E")!=0)
	{
		if(strcmp(rec,"T")==0)
		{
			fscanf(objptr,"%X",&start);
			locctr=start;
			fscanf(objptr,"%X",&length);
			
		}
		else
		{
			printf("%X\t%s\n",locctr,rec);
			locctr+=3;

		}		
				
		fscanf(objptr,"%s",rec);
	}

	fclose(objptr);

}
