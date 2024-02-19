class Superclass {
    int num = 10;
    void display() {
        System.out.println("Superclass method");
    }
}

class Subclass extends Superclass {
    int num = 20;
    void display() {
        super.display(); // Calling superclass method
        System.out.println("Subclass method");
    }
    void print() {
        System.out.println("Superclass num: " + super.num); // Accessing superclass variable
        System.out.println("Subclass num: " + num);
    }
}

public class MainSuper{
    public static void main(String[] args) {
        Subclass obj = new Subclass();
        obj.display(); // Output: Superclass method Subclass method
        obj.print();   // Output: Superclass num: 10 Subclass num: 20
    }
}

