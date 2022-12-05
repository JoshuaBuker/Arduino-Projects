import java.awt.*;
import java.util.Arrays;
import java.util.Scanner;
import javax.swing.*;

import com.fazecast.jSerialComm.*;

public class Main extends JFrame {

    public static int yAxis = 0;
    public static int xAxis = 0;

    public static void main(String[] args) throws Exception {
        // create a window with a slider
    /*    JFrame window = new JFrame();
        JSlider slider = new JSlider();
        JLabel label = new JLabel("Text");

        slider.setMaximum(1023);
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setLocationRelativeTo(null);
        window.add(label);
        window.add(slider);
        window.pack();
        window.setVisible(true);


        // create a new frame to store text field and button
        JFrame f = new JFrame("label");

        // create a label to display text
        JLabel l = new JLabel("Sensor Value");
        l.setFont(new Font("Serif", Font.PLAIN, 72));

        // create a panel
        JPanel p = new JPanel();

        //Create Slider
        JSlider slider = new JSlider();
        slider.setMaximum(1023);

        // add label to panel
        p.add(l);

        // add panel to frame
        f.add(p);
        f.add(slider);

        // set the size of frame
        f.setSize(300, 300);

        f.show();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
*/
        // determine which serial port to use

        Robot robot = new Robot();


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

        // enter into an infinite loop that reads from the port and updates the GUI
        Scanner data = new Scanner(port.getInputStream());
        while (data.hasNextLine()) {

            // number = Integer.parseInt(data.nextLine());
            String incomingData = data.nextLine();
            String[] integers;
            integers = incomingData.split(",");

           xAxis = Integer.parseInt(integers[0]);
           String yAxisSTR = integers[integers.length - 1];
           yAxisSTR.trim();
           yAxis = Integer.parseInt(yAxisSTR);

         Point p = MouseInfo.getPointerInfo().getLocation();
         xAxis = xAxis * -1;

            robot.mouseMove(p.x + xAxis, p.y + yAxis);
            System.out.println(xAxis + "  " + yAxis);




        }
    }
}
