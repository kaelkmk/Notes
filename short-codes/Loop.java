import java.util.Scanner;

public class Loop {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // this is how to stay in while loop
        while(true) {
            System.out.print("Input Something : ");
            String a = input.next();
            if(a.equals("X")) {
                input.close();
                System.out.println("Program Terminated!");  
                break;
            }

            // important here
            else if(a.equals("F")) {
                while(true) {
                    System.out.print("Function Entered : ");
                    String b = input.next();
                    if(b.equals("X")) {
                        System.out.println("Jobs done ! so the Function is Exited");
                        // if you use 'return', program will be exited
                        break; // break to return to the MAIN FUNCTION
                    }
                    else {
                        continue;
                    }
                }
            }
            else {
                // continue if other command
                continue;
            }
        }
    }

}
