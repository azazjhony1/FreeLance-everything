
import java.util.logging.Level;
import java.util.logging.Logger;

public class Queue {

    public int size=5;
    Mythread t[];
    public int sum=0;

    public Queue() {
        this.t = new Mythread[5];
    }
    synchronized public void execute(){
        
        for(int i=0;i<5;i++){
            try {
                if(i==3){
                    System.out.println("An interept occured during process... handling interept");
                    this.wait(1000*4);
                    System.out.println("Interept handled , resuming the process "+t[i].name);
                    
                }
            t[i].start();
            this.sum=this.sum + t[i].burst;
            this.wait(1000*((t[i].burst)+1));
        } catch (InterruptedException ex) {
            Logger.getLogger(Queue.class.getName()).log(Level.SEVERE, null, ex);
        }
            
        }
        
    }
    
    
    public static void main(String[] args) {
      Queue q1 =new Queue();
      
      Mythread t1 =new Mythread("thread 1",5);
      Mythread t2 =new Mythread("thread 2",8);
      Mythread t3 =new Mythread("thread 3",11);
      Mythread t4 =new Mythread("thread 4",4);
      Mythread t5 =new Mythread("thread 5",2);
      
      q1.t[0]=t1;
      q1.t[1]=t2;
      q1.t[2]=t3;
      q1.t[3]=t4;
      q1.t[4]=t5;
      
      q1.execute();
      
      System.out.println("total time : "+q1.sum+" average time "+q1.sum/5 );
      
}
}