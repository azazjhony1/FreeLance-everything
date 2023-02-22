public class xThread extends Thread{
    xThread(){

    }

    xThread(String threadName){
        super(threadName);
        System.out.println("Constructor : " + this);
        start();
    }

    public void run(){
        System.out.println("Run : " + Thread.currentThread().getName());
    }

}
