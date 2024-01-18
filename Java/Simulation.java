// 6. Create a simulation of a transportation system with a base class Vehicle and subclasses Car, Bus, and Bicycle. Implement methods for calculating fuel consumption, capacity, and routes.

class Vehicle{

    void fuelConsumption(){
        System.out.println("Vehicles consumes fuels");
    }

    void capacity(){
        System.out.println("Vehicles have max 50 capacity");
    }

    void routes(){
        System.out.println("Vehicles can run on roads.");
    }

}

class Car extends Vehicle{
    
    void fuelConsumption(){
        System.out.println("Cars consumes fuels");
    }

    void capacity(){
        System.out.println("Cars have max 5 capacity");
    }

    void routes(){
        System.out.println("Cars can run on roads and streets.");
    }

}

class Bus extends Vehicle{
    
    void fuelConsumption(){
        System.out.println("Buses consumes fuels");
    }

    void capacity(){
        System.out.println("Buses have max 50 capacity");
    }

    void routes(){
        System.out.println("Buses can run on roads.");
    }

}

class Bicycle extends Vehicle{
    
    void fuelConsumption(){
        System.out.println("Bicyles consumes no fuels");
    }

    void capacity(){
        System.out.println("Bicyles have max 2 capacity");
    }

    void routes(){
        System.out.println("Bicyles can run on roads and streets.");
    }

}

public class Simulation {
    public static void main(String[] args) {
        Vehicle v1 = new Vehicle();
        Car c1 = new Car();
        Bus b1 = new Bus();
        Bicycle bi1 = new Bicycle();

        v1.fuelConsumption();
        v1.capacity();
        v1.routes();

        c1.fuelConsumption();
        c1.capacity();
        c1.routes();

        b1.fuelConsumption();
        b1.capacity();
        b1.routes();

        bi1.fuelConsumption();
        bi1.capacity();
        bi1.routes();
    }
}
