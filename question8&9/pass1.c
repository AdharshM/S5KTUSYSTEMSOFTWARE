#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main()
{
	char label[20],opcode[20],operand[20];
	int charlength=0;
	char scanlabel[20]; int value;
	int locctr,start;
	int length;
	FILE *symptr ,*opptr, *proptr,*inter;
	proptr=fopen("program.txt","r");
	fscanf(proptr ,"%s%s%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0)
		{
			locctr=atoi(operand);
			start=locctr;
			printf("%d",locctr);
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
			if(strcmp(label,"_")!=0)
			{
				symptr=fopen("symtab.txt","a+");
				fseek(symptr,0,SEEK_SET);
				while(!feof(symptr))
				{
					fscanf(symptr,"%s%d",scanlabel,&value);
					if(strcmp(scanlabel,label)==0)
					{
						printf("Error symbol table");
						fclose(symptr);
						exit(1);
					}
				}
				fseek(symptr,0,SEEK_END);
				fprintf(symptr,"%s %X\n" ,label,locctr);
				fclose(symptr);
			}
//printf("%s",opcode);
			if(strcmp(opcode,"RESW")==0)
			{
				locctr= locctr + 3*atoi(operand);
			}
			else if(strcmp(opcode,"RESB")==0)
			{
				locctr +=atoi(operand);
			}
			else if(strcmp(opcode,"WORD")==0)
			{
				locctr+=3;
			}
			else if(strcmp(opcode,"BYTE")==0)
			{
				charlength=strlen(operand);
				locctr+=charlength;
			}
			else
			{
				locctr+=3;
			}
			fscanf(proptr,"%s %s %s",label,opcode,operand);
		}
		fclose(proptr);
		length=locctr-start;
		inter=fopen("length.txt","w");
		fprintf(inter,"%X",length);
		fclose(inter);
		printf("PROGRAM LENGTH=%d",length);
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
*/
