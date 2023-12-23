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
                    System.out.println("twoDArray["+i+"]["+j+"] " + twoDArray[i][j]);
            }
        }
    }

    public int[] findingGreatest(){
        int i, j;
        int[] ans = new int[2];
        int num = Integer.MIN_VALUE;
        
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(twoDArray[i][j] > num){
                    num = twoDArray[i][j];
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }

        return ans;
    }

    public static void main(String args[]){
        matric obj = new matric();
        obj.insertingArrayElement();
        obj.printingArrayElement();

        int[] greatest = obj.findingGreatest();
        System.out.println("greatest element is at place " + greatest[0] + " and " + greatest[1]);
    }
}
