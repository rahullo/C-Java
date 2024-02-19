
class Superclass {
    int num;
    Superclass(int num) {
        this.num = num;
    }
}

class Subclass extends Superclass {
    Subclass(int num) {
        super(num); // Calling superclass constructor
    }
}

public class MainSuper {
    public static void main(String[] args) {
        Subclass obj = new Subclass(10);
        System.out.println("Value of num: " + obj.num); // Output: Value of num: 10
    }
}
