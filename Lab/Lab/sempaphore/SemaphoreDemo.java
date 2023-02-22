
import java.util.concurrent.*;

class Shared
{
	static int count = 0  ; // shared resource
	static int[] arr = new int[5];
}

class MyThread extends Thread
{
	Semaphore sem;
	String threadName;

	public MyThread(Semaphore sem, String threadName)
	{
		super(threadName);
		this.sem = sem;
		this.threadName = threadName;
	}

	@Override
	public void run() {
		
		// run by thread A
		if(this.getName().equals("A"))
		{
			System.out.println("Starting " + threadName);
			try
			{
				// First, get a permit.
				System.out.println(threadName + " is waiting for a permit.");
			
				// acquiring the lock
				sem.acquire();
			
				System.out.println(threadName + " gets a permit.");
		
				// Now, accessing the shared resource.
				// other waiting threads will wait, until this
				// thread release the lock

				while(true){
	
					Shared.arr[Shared.count] = Shared.count;
					System.out.println(threadName + " Writes : " + Shared.arr[Shared.count]);
					Shared.count++ ; 
					if(Shared.count==Shared.arr.length)
						break;
					
				}

			} catch (InterruptedException exc) {
					System.out.println(exc);
				}
		
				// Release the permit.
				System.out.println(threadName + " releases the permit.");
				sem.release();
		}
		
		// run by thread B
		else
		{
			System.out.println("Starting " + threadName);
			try
			{
				// First, get a permit.
				System.out.println(threadName + " is waiting for a permit.");
			
				// acquiring the lock
				sem.acquire();
			
				System.out.println(threadName + " gets a permit.");
		
				// Now, accessing the shared resource.
				// other waiting threads will wait, until this
				// thread release the lock
				while(true){
					if(Shared.count==0){
						break;
					}

					Shared.count-- ; 
					System.out.println(threadName + " Read : " + Shared.arr[Shared.count]);
					
					
					//Thread.sleep(10);
				}
				
			} catch (InterruptedException exc) {
					System.out.println(exc);
				}
				// Release the permit.
				System.out.println(threadName + " releases the permit.");
				sem.release();
		}
	}
}

// Driver class
public class SemaphoreDemo
{
	public static void main(String args[]) throws InterruptedException
	{
		// creating a Semaphore object
		// with number of permits 1
		Semaphore sem = new Semaphore(1);
		
		// creating two threads with name A and B
		// Note that thread A will increment the count
		// and thread B will decrement the count
		MyThread mt1 = new MyThread(sem, "A");
		MyThread mt2 = new MyThread(sem, "B");
		
		// stating threads A and B
	
		mt1.start();
		
		
		
		// waiting for threads A and B
		mt1.join();

		mt2.start();
		mt2.join();
		
	}
}
