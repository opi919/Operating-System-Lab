import java.text.SimpleDateFormat;
import java.util.Date;

public class timeExample {
    public static void main(String[] args) {
        Thread requestor = new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    System.out.println("Ask for time.");
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        Thread responder = new Thread(new Runnable() {
            @Override
            public void run() {
                while (true) {
                    SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");
                    System.out.println("Time: " + sdf.format(new Date()));
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });

        requestor.start();
        responder.start();
    }
}
