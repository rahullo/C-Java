//     2. Create a class hierarchy representing a university system with a base class Person and subclasses Student and Professor. Add necessary attributes and methods.

class Person {
    String name;
    String profession;
    int id;

    public Person(String name, String profession, int id){
        this.name = name;
        this.profession = profession;
        this.id = id;
    }

    void activity(){
        System.out.println(name+" is a "+profession+" with ID: "+id);
    }
}


class Student extends Person{
    int rollNo;
    public Student(String name, String profession, int id, int roll){
        super(name, profession, id);
        this.rollNo = roll;
    }

    void activity(){
        System.out.println(name+" is a "+profession+" with ID: "+id+" and roll number: "+rollNo);
    }
}


public class University2 {
    public static void main(String[] args) {
        Person p1 = new Person("Rahul", "Student", 23);
        p1.activity();

        Student s1 = new Student("Amit", "Student", 25, 65);
        s1.activity();
    }
}
