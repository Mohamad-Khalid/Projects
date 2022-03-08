import java.util.*;
import java.io.*;
public class GO {

    
                                            // note this
    public static void main(String [] args) throws IOException {

        /* Read from standard input */
            // using Scanner object
            Scanner input = new Scanner(System.in);
            int x = input.nextInt();
            System.out.println("Standard input by Scanner: x =  "+ x);

            // Using BufferedReader object -- faster way
            BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
            String y = bf.readLine(); // readline read strings only
            x = Integer.parseInt(y); // cast string to int
            System.out.println("Standered input by bufferedReader : x = "+x);
         //-------------------------------------------------------------------
        
         /* Read from file */
            // using Scanner object
            File f = new File("input.txt");// create a file
            f.createNewFile();// create a file
            Scanner inFl = new Scanner(f);
            x = inFl.nextInt();
            inFl.close();
            System.out.println("Read from file by Scanner : x = "+x);

            // using bufferedReader object
            BufferedReader bfInFile = new BufferedReader(new FileReader("input.txt"));
            y = bfInFile.readLine();
            x = Integer.parseInt(y);
            System.out.println("Read from File by BufferedReader x = "+ x);
          //---------------------------------------------------------------------------      
    
           /* Writing to file  */
            // using FileWriter
            FileWriter fw = new FileWriter("out.txt");
            fw.write("I write to a file ");
            fw.write(5555);
            fw.close();//very very important

       

    }
}
