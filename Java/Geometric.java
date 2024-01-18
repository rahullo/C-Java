//     3. Create a class hierarchy for geometric shapes. Define a base class Shape with methods to calculate area and perimeter. Create subclasses for Circle, Rectangle, and Triangle.

class Shape {
    int height;
    int breadth;


    // To find area of shape(rectangle)
    double area(double h, double b){
        System.out.println("Area of Shape...");
        return height*breadth;
    }
    // To find perimeter of shape(rectangle)
    int perimeter(int h, int b){
        return 2*(height+breadth);
    }
}

class Circle extends Shape{
    double pi;

    public Circle(double pi){
        this.pi = pi;
    }

    double area(int r){
        return pi*r*r;
    }

    double perimeter(int r){
        return 2*pi*r;
    }
}

class Rectangle extends Shape{

}

class Triangle extends Shape{

    double area(double h, double b){
        System.out.println("Area of Shape...");

        return 0.5 * h * b;
    }

    double perimeter(double s1, double s2, double s3){
        return s1+s2+s3;
    }
}


public class Geometric {
    public static void main(String[] args) {
        Circle c1 = new Circle(3.14);

        System.out.println("Area of Circle with radius 4 = "+c1.area(4));
        System.out.println("Perimeter of Circle with radius = "+ c1.perimeter(4));

        Triangle t1 = new Triangle();
        System.out.println("Area of Triangle = "+t1.area(10, 12));
        System.out.println("Perimeter of Triangle = "+t1.perimeter(10, 11, 11));
    }
}
