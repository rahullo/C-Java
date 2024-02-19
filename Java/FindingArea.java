
class ShapeArea{
    float length, height;
    float radius;
    ShapeArea(float length, float height){
        this.length = length;
        this.height = height;
    }

    ShapeArea(float radius){
        this.radius = radius;
    }

    float rectangleArea(){
        float ans =  length * height;
        return ans;
    }  
    
    double circleArea(){
        double ans =  3.1 * this.radius * this.radius;
        return ans;
    }
}

public class FindingArea {
    public static void main(String[] args){
        ShapeArea calc = new ShapeArea(5, 6);
        ShapeArea calc2 = new ShapeArea(6);
        System.out.println("Area of a rectangle: " +calc.rectangleArea());
        System.out.println("Area of a circle: " +calc2.circleArea());
        ;
    }
}
