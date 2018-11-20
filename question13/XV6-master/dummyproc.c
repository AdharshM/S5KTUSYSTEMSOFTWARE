#include "types.h"
#include "stat.h"
#include "user.h"


int
main(int argc , char *argv[])
{

    int i,id,k ;
    double x=0;
    for(i=0;i<2;++i)
    {
      id=fork();
      if(id <0)
      {
        printf(1, "%d failed in fork!\n", getpid() );
      }
      else if(id>0)
      {
         printf(1, "Parent %d creating child  %d\n", getpid(), id );
         wait();
      }
      else
      {
        printf(1, "Child %d created\n",getpid() );
        for(k=0;k<1000;k+=0.1)
        {
          x+=k;
        }
        break;
      }
    }

    exit();

}
