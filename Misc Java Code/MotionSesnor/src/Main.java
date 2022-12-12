import com.fazecast.jSerialComm.SerialPort;

import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import java.awt.*;
import java.awt.event.*;
import java.awt.TrayIcon.MessageType;
import java.io.File;
import java.net.MalformedURLException;
import java.util.Scanner;
import java.util.Timer;

public class Main {

    static int distance = 0;

    public static void main(String[] args) throws InterruptedException {



        SerialPort ports[] = SerialPort.getCommPorts();
        System.out.println("Select a port:");
        int i = 1;
        for (SerialPort port : ports) {
            System.out.println(i++ + ". " + port.getSystemPortName());
        }
        Scanner s = new Scanner(System.in);
        int chosenPort = s.nextInt();

        // open and configure the port
        SerialPort port = ports[chosenPort - 1];
        if (port.openPort()) {
            System.out.println("Successfully opened the port.");
        } else {
            System.out.println("Unable to open the port.");
            return;
        }
        port.setComPortTimeouts(SerialPort.TIMEOUT_READ_SEMI_BLOCKING, 0, 0);
        Thread.sleep(10000);
        // enter into an infinite loop that reads from the port and updates the GUI
        Scanner data = new Scanner(port.getInputStream());
        while (data.hasNextLine()) {

            // number = Integer.parseInt(data.nextLine());
            String incomingData = data.nextLine();
            distance = Integer.parseInt(incomingData);
            if (distance < 70) {
                try{
                    //Obtain only one instance of the SystemTray object
                    SystemTray tray = SystemTray.getSystemTray();

                    // If you want to create an icon in the system tray to preview
                    Image image = Toolkit.getDefaultToolkit().createImage("Frogpaint.png");
                    //Alternative (if the icon is on the classpath):
                    //Image image = Toolkit.getDefaultToolkit().createImage(getClass().getResource("icon.png"));

                    TrayIcon trayIcon = new TrayIcon(image, "Java AWT Tray Demo");
                    //Let the system resize the image if needed
                    trayIcon.setImageAutoSize(true);
                    //Set tooltip text for the tray icon
                    trayIcon.setToolTip("System tray icon demo");
                    tray.add(trayIcon);

                    // Display info notification:
                    trayIcon.displayMessage("MOTION SENSOR TRIGGERED", "This motion device has been tripped", MessageType.INFO);
                    // Error:
                    // trayIcon.displayMessage("Hello, World", "Java Notification Demo", MessageType.ERROR);
                    // Warning:
                    // trayIcon.displayMessage("Hello, World", "Java Notification Demo", MessageType.WARNING);
                }catch(Exception ex){
                    System.err.print(ex);

                }

            }

        }







    }
}