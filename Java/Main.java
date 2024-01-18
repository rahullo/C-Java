//5. Define a base class Animal with a method makeSound(). Create two subclasses Dog and Cat that override the makeSound() method to print a specific sound.


class Animal {
    void makeSound(){
        System.out.println("Animal make Sounds!!");
    }
}

class Dog extends Animal{
    void makeSound(){
        System.out.println("Dog sounds woof woof!!!");
    }
}


class Cat extends Animal{
    void makeSound(){
        System.out.println("Cat sounds meow!!!");
    }
}


public class Main {
    public static void main(String[] args){
        Animal a1 = new Animal();
        Cat c1 = new Cat();
        Dog d1 = new Dog();

        a1.makeSound();
        c1.makeSound();
        d1.makeSound();
    }
}
