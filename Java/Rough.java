//     1. Demonstrate the use of the super keyword in Java, especially in a constructor.
//     2. Create a class hierarchy representing a university system with a base class Person and subclasses Student and Professor. Add necessary attributes and methods.
//     3. Create a class hierarchy for geometric shapes. Define a base class Shape with methods to calculate area and perimeter. Create subclasses for Circle, Rectangle, and Triangle.
//     4. Explain the concept of method overriding in Java with an example.
//     5. Define a base class Animal with a method makeSound(). Create two subclasses Dog and Cat that override the makeSound() method to print a specific sound.
//     6. Create a simulation of a transportation system with a base class Vehicle and subclasses Car, Bus, and Bicycle. Implement methods for calculating fuel consumption, capacity, and routes.
//     7. Design a class hierarchy for a zoo management system. Include classes for Animal, Mammal, Bird, and Reptile. Implement methods for feeding, breeding, and habitat management.


// class Animal {

//     String name;
//     String food;

//     public Animal(String name, String food){
//         this.name = name;
//         this.food = food;

//     }

//     public void eat(){
//         System.out.println(name + " can eat " + food);
//     }
// }


// class Lion extends Animal {


//     public Lion(String name, String food){
//         super(name, food);

//     }

//     public void eat(){
//         System.out.println("Lion eats meat(non-veg)..");
//     }
// }

// class Rough {
//     public static void main(String[] args){
//         System.out.println("Rahul Lohra");

//         Animal a1 = new Animal("Goat", "Grass");

//         // Lion l1 = new Lion();

//         a1.eat();
//         // l1.eat();
//     }
// }

/**
 * Rough
 */
// public class Rough {

//     public static void main(String[] args) {
//         String name = "Alice";
//         name = name.toUpperCase(); // name still holds "Alice"
//         System.out.println("Name " + name);
//         String newName = name.toUpperCase(); // newName holds "ALICE"

//         System.out.println("newName " + newName);

//     }
// }

// public class Rough {
//     public static void main(String[] args) {
//         String inputString = "Hello, this is a sample string with several words";

//         int wordCount = countWords(inputString);
//         System.out.println("Number of words in the string: " + wordCount);
//     }

//     // Function to count the number of words in a string
//     public static int countWords(String str) {
//         if (str == null || str.isEmpty()) {
//             return 0; // Return 0 if the string is null or empty
//         }

//         String[] words = str.split("\\s+"); // Split the string into words using whitespace as delimiter
//         return words.length; // Return the number of words
//     }
// }


public class Rough {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("No command-line arguments provided.");
        } else {
            System.out.println("The values given at the command line are:");
            for (String arg : args) {
                System.out.println(arg);
            }
        }
    }
 }
 