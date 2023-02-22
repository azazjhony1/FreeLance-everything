public class test{
    public static void main(String[] args) {
        
        Thread t1 = new Thread(new xThread() , "t1") ; 
        Thread t2 = new Thread(new xThread() , "t2") ; 

        Thread t3 = new xThread() ;
        Thread t4 = new xThread() ; 

        Thread t5 = new xThread("t5") ; 

        try{ Thread.currentThread().sleep(1000); }   catch(Exception e){ }
        t1.start();

        try{ Thread.currentThread().sleep(1000); }   catch(Exception e){ }
        t2.start();

        try{ Thread.currentThread().sleep(1000); }   catch(Exception e){ }
        t3.start();

        try{ Thread.currentThread().sleep(1000); }   catch(Exception e){ }
        t4.start();
        

        try{ Thread.currentThread().sleep(1000); }   catch(Exception e){ }

        System.out.println("Main : " + Thread.currentThread());        

    }
}