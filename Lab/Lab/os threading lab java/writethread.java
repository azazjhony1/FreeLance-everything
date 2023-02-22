import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class writethread extends Thread {
    
    String s = ""; 

    public void setdata(String s){
       s = this.s ; 
    }

    public void run(){
        
        System.out.println("write");
        try {
            
            File f1 = new File("output.txt");
            if (f1.createNewFile()) {
                System.out.println("File created: " + f1.getName());
            } else {
                System.out.println("File already exists.");
            }
        } catch (Exception e) {
        
            System.out.println("An error occurred.");
            e.printStackTrace();
        }
        
      try {
      FileWriter myWriter = new FileWriter("output.txt");
      myWriter.write(s);
      myWriter.close();
      System.out.println("Successfully wrote to the file.");
    } catch (Exception e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
        
    }
        
}


