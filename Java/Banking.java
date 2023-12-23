class Account {
    int accountNum;
    String accountHolderName;
    int balance;
    
    public Account(int accountNum,String accountHolderName, int balance){
        this.accountNum = accountNum;
        this.accountHolderName = accountHolderName;
        this.balance = balance;
    }

    int credit(int ammount){
        this.balance += ammount;
        return ammount;
    }

    int debit(int ammount){
        this.balance -= ammount;
        return ammount;
    }

    
}

// class SavingAccount extends Account{
//     public SavingAccount(){
//     }
// }

public class Banking{
    public static void main(String args[]){
        Account ac1 = new Account(1234, "Rahul", 2000);

        System.out.println(ac1.credit(200)+"RS Credit to your accout Number " + ac1.accountNum+ ". Available balance on your account is "+ac1.balance+"RS.");       
        System.out.println(ac1.debit(100)+"RS Dedited from your accout Number " + ac1.accountNum+ ". Available balance on your account is "+ac1.balance+"RS.");

    }
}