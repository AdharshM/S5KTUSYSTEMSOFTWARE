#include <stdio.h>

void main() {
    
    int q;    	//TIME QUANTUM   
    int time ;  //TIME SINCE BEGINING
    int count ;  //NUMBER OF PROCESSES REMAINING TO BE EXECUTED  

    int total_tt ,total_wt ;

    int P[20],BT[20] ,WT[20] , TT[20] ,rem_BT[20] ;
    int i ,j, n,temp,pos ;
    
    double avg_wt , avg_tt;


    printf("Enter the number of processes ");
    scanf("%d",&n);
    
    count =n; 
   
    for(i=0 ; i<n;++i) {
     printf("Enter the burst time  for process   %d :" , i+1);
     
      scanf("%d" , &BT[i]); 
      rem_BT[i]=BT[i];     // COPYING TO ANOTHER ARRAY
      P[i]=i+1;
     }
      
     printf("\nENTER THE TIME QUANTUM FOR RR SCHEDULER \n");
     scanf("%d",&q);

    

    while(1)
    {
          for(i=0;i<n;++i)
          {
             if(rem_BT[i]>0) 
             {
                 if(rem_BT[i]>q)
                   {
                      time +=q; 
                       rem_BT[i]-=q; 
                 
		   }
                 else 
                   {
                      time +=rem_BT[i];
 		      WT[i]=time-BT[i]; 
                      rem_BT[i]=0;
                      count=count-1;
                   }
             
    
            }

	  }  
       if(count==0)
          {break;}
     }

    
    
 


    total_tt=0;
     for(i=0;i<n;++i)
    { 
         TT[i]= BT[i] +WT[i]-1;
         total_tt +=TT[i]; 
     }

  total_wt=0;
     for(i=0;i<n;++i)
    { 
        
         total_wt +=WT[i]; 
     }
     


   
    

    printf(" \n\n\t ROUND ROBIN SCHEDULING \n");
    printf("\tPROCESS INFORMATION \n");
    printf("_________________________\n");
    printf(" PID  |  BURST TIME  |  WAITING TIME  | TURNAROUND TIME \n");
    for(i=0;i<n;++i)
    {
      printf("%d\t  %d\t\t %d\t\t %d\t \n" , P[i] ,BT[i] ,WT[i]-1 ,TT[i]);
     }
  
    avg_wt =total_wt/n;
    avg_tt =total_tt/n;

    printf ("\nAverage  waiting time  =%f \n " ,avg_wt );
    printf ("\nAverage turnaround time  =%f \n " ,avg_tt );

           


}












    




