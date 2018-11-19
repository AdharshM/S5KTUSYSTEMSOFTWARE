import java.util.*;
import java.util.concurrent.Semaphore;
import java.util.Random;

class producerconsumer
{
       static final int BUFFER_SIZE=10;
	
       static volatile ArrayList<Integer> list = new ArrayList<Integer>(BUFFER_SIZE);
	
       static volatile Semaphore empty=new Semaphore(BUFFER_SIZE);
       static volatile Semaphore full= new Semaphore(0);
       static volatile Semaphore mutex=new Semaphore(1);
 	
     static class Producer extends Thread
     {

	public void run()
	{
		Random rand= new Random();
		for(int i=0;i<5;++i)
		{
		try
			{	
	
			
				empty.acquire();
				mutex.acquire();
				list.add(rand.nextInt(100));
				
				System.out.println("PRODUCER PRODUCED ITEM"+list.size()+"="+list.get(list.size()-1) );
				Thread.sleep(1000);
				mutex.release();
				full.release();
				
					
			
		}catch(Exception e)
		{
			System.out.println("PRODUCER INTERRUPTED\n");
			
		}
	     }
        }
     }

static class 	Consumer extends Thread
     {

	public void run()
	{
		for(int i=0;i<5;++i)
		{
		try
			{	
	
				full.acquire();
				mutex.acquire();
				int removed=list.get(list.size()-1);
				list.remove(list.size()-1);
				System.out.println("CONSUMER CONSUMED ITEM"+removed );
				Thread.sleep(1000);
				mutex.release();
				empty.release();
				
					
			
			
		}catch(Exception e)
		{
			System.out.println("CONSUMER INTERRUPTED\n");
			
		}
      	 }
     }
}

   public static void main(String args[])
	{
		new Producer().start();
		new Consumer().start();

	}
}

