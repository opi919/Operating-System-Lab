import java.text.SimpleDateFormat;
import java.util.Date;

public class AskingTime {

  static String time;
  static Object lock = new Object();

  static class FirstThread extends Thread {
    @Override
    public void run() {
      System.out.println("In firstThread: " + this.getName());
      System.out.println("Getting time...");
      getTime();
      synchronized (lock) {
        System.out.println("Time: " + time);
      }
    }
  }

  static class SecondThread extends Thread {
    @Override
    public void run() {
      synchronized (lock) {
        System.out.println("In secondThread: " + this.getName());
        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy hh:mm:ss");
        time = sdf.format(new Date());
        lock.notify();
      }
    }
  }

  public static void main(String[] args) {
    FirstThread firstThread = new FirstThread();
    firstThread.start();
  }

  public static void getTime() {
    SecondThread secondThread = new SecondThread();
    secondThread.start();
    synchronized (lock) {
      try {
        lock.wait();
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}
