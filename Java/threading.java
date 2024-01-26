

public class threading{
    public static void main(String args[]){
        int num = 80;
        int division = 1;
        try{

            division = num/0;
        }catch(ArithmeticException e){
            System.out.println(e);

        }   

    }
}