#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
	int findnumberdigit(int n)
	{
		int dig=(int)(floor(log(n)/log(16) )+1);
		return dig;
	}


void main()
{
	FILE *symptr,*opptr , *proptr ,*objptr,*inter;
	char label[20],opcode[20],operand[20];
	int locctr,start;
	char record[200];
	int wordlen,i;
	char scancode[20],scanvalue[20];
	char scanlabel[20];
	int scanaddress;
	int length;

	proptr=fopen("program.txt","r");
	fscanf(proptr ,"%s%s%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
	{
		locctr=atoi(operand);
		start=locctr;
		printf("%d",locctr);
		objptr=fopen("obcode.txt","a+");
		inter=fopen("length.txt","r");
		fscanf(inter,"%d",&length);
		fclose(inter);
		printf("%d",length);
		fprintf(objptr,"H_%s_%s_%X\n",opcode,operand,length);
		fprintf(objptr,"T");
	}
	else
	{
		printf("ERROR");
		exit(1);
	}	
	fscanf(proptr,"%s %s %s",label,opcode,operand);
	while(strcmp(opcode,"END")!=0)
	{
		if(feof(proptr))
		{ break;
		}
		if((strcmp(opcode,"BYTE")==0 )|| (strcmp(opcode,"WORD")==0))
		{
			if(strcmp(opcode,"WORD")==0)
			{
				wordlen=strlen(opcode);
				fprintf(objptr,"_");
				for(i=1;i<=(6-wordlen+3);++i)
				{
					fprintf(objptr,"0");
				}
				fprintf(objptr,"%s",operand);
			}
			else
			{
				fprintf(objptr,"%s",operand);
			}
		}
		else if((strcmp(opcode,"RESW")==0 )|| (strcmp(opcode,"RESB")==0))
		{
			;
		}
		else
		{
			opptr=fopen("optab.txt","r");
			fscanf(opptr,"%s%s",scancode,scanvalue);
			while(!feof(opptr))
			{
				if(strcmp(scancode,opcode)==0)
				{
					fclose(opptr);
					//printf("%s",scanvalue);
					break;
				}
				else
				{
					fscanf(opptr,"%s%s",scancode,scanvalue);
				}
			}
			if(feof(opptr))
			{
				printf("OPTAB ERROR");
				fclose(opptr);
				fclose(objptr);
				fclose(proptr);
				exit(1);
			}
			symptr=fopen("symtab.txt","r");
			fscanf(symptr,"%s%d",scanlabel,&scanaddress);
			while(!feof(symptr))
			{ //printf("\n%s%s",scanlabel,label);
				if(strcmp(scanlabel,operand)==0)
				{
					fclose(symptr);
					break;
				}
				else
				{
					fscanf(symptr,"%s%d",scanlabel,&scanaddress);
					}
				}
				if(feof(symptr))
				{
					printf("SYMTAB ERROR");
					fclose(symptr);
					fclose(objptr);
					fclose(proptr);
					exit(1);
				}
				fprintf(objptr,"_%s",scanvalue);
				for(i=1;i<=(4-findnumberdigit(scanaddress));++i)
				{
					fprintf(objptr,"0");
				}
				fprintf(objptr,"%X_",scanaddress);
			}
			fscanf(proptr,"%s %s %s",label,opcode,operand);
		}
		fprintf(objptr,"\nE_%d",start);
		fclose(objptr);
		fclose(proptr);
}

/*

OUTPUT
_____________

optab.txt
__________
LDA 00
ADD 18
JEQ 30
STA 0C
TIX 2C


program.txt
______________
SUM START 0
_ LDA ZERO
_ ADD THREE
_ STA SUM
SAMPLE LDA ZERO
ZERO WORD 0
THREE WORD 3
SUM RESW 1
_ END 1000


length.txt
____________
15


symtab.txt
____________

SAMPLE 9
ZERO C
THREE F
SUM 12


obcode.txt
_______________
H_START_0_F
T_000009__180009__0C000C__000009__000000_000003
E_0
*/
