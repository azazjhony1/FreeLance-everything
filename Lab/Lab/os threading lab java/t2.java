public class t2 extends Thread{

    t2(String str){
        super(str);
    }

    public void run(){
        System.out.println("Run : " + Thread.currentThread().getName() + " is running ");
    }

    public static void main(String[] args) {
        
            t2 thread1 = new t2("test") ;
            thread1.start();
        
    }

}
