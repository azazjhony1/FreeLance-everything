public class t extends Thread{

    public void run(){
        System.out.println("Run : " + Thread.currentThread().getName() + " is running ");
    }

    public static void main(String[] args) {

        for(int i=0 ; i <100 ; i++){
            try{ Thread.currentThread().sleep(10); }   catch(Exception e){ }
            t thread1 = new t() ;
            thread1.start();
        }
        
    }

}
