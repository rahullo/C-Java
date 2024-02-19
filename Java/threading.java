
class MyThread extends Thread {
    public void run() {
        for (int i = 0; i < 5; i++) {
            System.out.println(Thread.currentThread().getName() + ": " + i);
            try {
                Thread.sleep(1000); // Pause for 1 second
            } catch (InterruptedException e) {
                System.out.println("Thread interrupted");
            }
        }
    }
}

class MyThreadTwo extends Thread{
    String thr;

    MyThreadTwo(String name){
        thr = name;
    }

    public void run(){
        for(int i = 0; i < 10; i++){
            System.out.println(thr + i);
        }
    }
}

public class threading {
    public static void main(String[] args) {
        MyThread thread1 = new MyThread();
        MyThread thread2 = new MyThread();

        thread1.setName("Thread 1");
        thread2.setName("Thread 2");

        // thread1.start();
        // thread2.start();


        MyThreadTwo threadOne = new MyThreadTwo("Thread 1: ");
        MyThreadTwo threadTwo = new MyThreadTwo("Thread 2: ");

        threadOne.start();
        threadTwo.start();
    }
}
