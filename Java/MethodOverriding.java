// 4. Explain the concept of method overriding in Java with an example.


class FindingAreaOfRectangle{
    double area(double length, double breadth){
        System.out.println("RECTANGLE");
        return length * breadth;
    }
}


class FindingAreaOfTriangle extends FindingAreaOfRectangle{
    double area(double base, double height){
        System.out.println("TRIANGLE");
        return (0.5)*base*height;
    }
}

public class MethodOverriding {
    public static void main(String[] args) {
        FindingAreaOfRectangle r1 = new FindingAreaOfRectangle();

        FindingAreaOfTriangle t1 = new FindingAreaOfTriangle();

        System.out.println("Area of a Rectangle = " + r1.area(50, 40));
        System.out.println("Area of a Triangle = " + t1.area(50, 40));
    }
}
