
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.File;  
import java.io.FileWriter;
import java.util.Scanner;


public class thread {

    public void run(){
        System.out.println("hello world");
    }

    public String read(){
        String s="";
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
    
        return s;
    }

    public void write(String s){
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
    
    
    public static void main(String[] args) {
        thread t1= new thread();
        String s2=t1.read();
        thread t2= new thread();
        t2.write(s2);
    }
    
}
