import java.util.Scanner;

public class simpleCalculator {
    public static void main(String args[]){
        int num1, num2;
        char operator;

        System.out.println("Enter the operation: ");
        System.out.println("Enter a for addition: ");
        System.out.println("Enter s for subtration: ");
        System.out.println("Enter m for multiplication: ");
        System.out.println("Enter d for division: ");
        System.out.println("Enter r for Modulo: ");



        Scanner sc = new Scanner(System.in);

    
        operator = sc.next().charAt(0);

        System.out.println("Enter the num1: ");
        num1 = sc.nextInt();
        System.out.println("Enter the num2: ");
        num2 = sc.nextInt();

        System.out.println(num1 + " and " + num2);



        // if(operator == 'a'){
        //     int ans = num1 + num2;
        //     System.out.println("Addition of " + num1 + " and " + num2 + " = " + ans);
        // }else if (operator == 's'){
        //     int ans = num1 - num2;
        //     System.out.println("Subtraction between " + num1 + " and " + num2 + " = " + ans);
        // }else if (operator == 'm'){
        //     int ans = num1 * num2;
        //     System.out.println("Multiplication between " + num1 + " and " + num2 + " = " + ans);
        // }else if (operator == 'd'){
        //     int ans = num1 / num2;
        //     System.out.println("Division between " + num1 + " and " + num2 + " = " + ans);
        // }


        switch (operator) {
            case 'a':
                int sum = num1 + num2;
                System.out.println("Addition of " + num1 + " and " + num2 + " = " + sum);
                break;
            case 's':
                int diff = num1 - num2;
                System.out.println("Subtration of " + num1 + " and " + num2 + " = " + diff);
                break;
            case 'm':
                int prod = num1 * num2;
                System.out.println("Multiplication of " + num1 + " and " + num2 + " = " + prod);
                break;
            case 'd':
                int div = num1 / num2;
                System.out.println("Division of " + num1 + " and " + num2 + " = " + div);
                break;
            case 'r':
                int remainder = num1 % num2;
                System.out.println("Modulo of " + num1 + " and " + num2 + " = " + remainder);
                break;
        
            default:
                System.out.println("choose correct option: ");;
        }

    }
}
