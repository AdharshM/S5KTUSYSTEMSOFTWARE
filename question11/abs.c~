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

/*
program.txt
_____________

H COPY 001000 00107A
T 000000 1E 140033 481039 100036 280030 300015 481061 3C0003 20002A 1C0039 30002D
T 002500 15 1D0036 481061 180033 4C1000 801000 601003
E 000000


OUTPUT
________________
ADDRESS	OBJECT CODE
0	140033
3	481039
6	100036
9	280030
C	300015
F	481061
12	3C0003
15	20002A
18	1C0039
1B	30002D
2500	1D0036
2503	481061
2506	180033
2509	4C1000
250C	801000
250F	601003



*/
