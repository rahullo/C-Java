import java.util.Scanner;

public class matric {

    int[][] twoDArray;
    Scanner sc = new Scanner(System.in);

    public matric(){
        System.out.println("Entered inside of a constructor:  ");
        twoDArray = new int[3][3];
    }

    public void insertingArrayElement(){
        int i, j;
        System.out.println("Enter the all element: ");
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                twoDArray[i][j] = sc.nextInt();
                
            }
        }
    }

    public void printingArrayElement(){
        int i, j;
        
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                    System.out.println("twoDArray["+i+"]["+j+"]" + twoDArray[i][j]);
            }
        }
    }

    public int findingGreatest(){
        int i, j;
        int ans = Integer.MIN_VALUE;
        
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(twoDArray[i][j] > ans){
                    ans = twoDArray[i][j];
                }
            }
        }

        return ans;
    }

    public static void main(String args[]){
        matric obj = new matric();
        obj.insertingArrayElement();
        obj.printingArrayElement();

        int greatest = obj.findingGreatest();
        System.out.println("greatest element is " + greatest);
    }
}
