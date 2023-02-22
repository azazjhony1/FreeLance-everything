import java.io.File;
import java.util.Scanner;

public class readthread extends Thread {
    
    String s = ""; 

    public String readdata(){
        return this.s;
    }

    public void run(){
        
        System.out.println("read");
        
        File f1 =new File("input.txt");
        
        try {
      
            Scanner myReader = new Scanner(f1);

            while (myReader.hasNextLine()) {
                String data = myReader.nextLine();
                s=s+data;
            }

            myReader.close();

        } catch (Exception e) {
            
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        
    }

}
