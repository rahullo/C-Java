

public class threading{
    public static void main(String args[]){
        int num = 80;
        try{

            int division = num/0;
            System.out.println(division);
        }catch(ArithmeticException e){
            System.out.println(e);

        }   

    }
}