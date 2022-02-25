import javax.swing.*;
import java.awt.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class CounterApp {
    static int counter = 1;
    static String nimi = "";
    static String opiskelijaNumero = "";
    static String opintopisteet = "";
    static ArrayList<Opiskelija> Opiskelijat = new ArrayList<>();

    public static void main(String[] args) {
        StartApp();
    }

    public static void customSetFont(JLabel label) {
        label.setFont(new Font("Verdana", Font.BOLD, 14));
    }

    public static void ContentPanel(JFrame window, String label, JTextField textField) {
        JLabel textLabel = new JLabel(label);
        customSetFont(textLabel);
        window.getContentPane().add(textLabel);
        window.getContentPane().add(textField);
    }

    public static ArrayList<String> Labels(String[] list) {
        return (new ArrayList<>(Arrays.asList(list)));
    }

    public static void StartApp() {
        JFrame mainWindow = new JFrame("Counter App");
        mainWindow.setSize(400, 400);
        mainWindow.setLayout(new GridLayout(10, 1));

        String[] labelList = {"Nimi", "Opiskelijanumero", "Opintopisteet"};
        ArrayList<String> labels = Labels(labelList);


        ArrayList<JTextField> textFields = new ArrayList<>();
        JTextField firstNameTextField = new JTextField();
        JTextField opiskelijaNumeroTextField = new JTextField();
        JTextField opintoisteetTextField = new JTextField();
        Collections.addAll(textFields, firstNameTextField, opiskelijaNumeroTextField, opintoisteetTextField);

        int x = 0;
        for (String i : labels) {
            ContentPanel(mainWindow, i, textFields.get(x));
            x += 1;
        }

        // Vie tiedot nappi
        JButton pushDataButton = new JButton("Vie Tiedot");
        pushDataButton.setFont(new Font("Verdana", Font.BOLD, 14));
        mainWindow.getContentPane().add(pushDataButton);
        mainWindow.setVisible(true);


        // Lisätään tapahtumankäsittelijä
        pushDataButton.addActionListener(e -> {
            nimi = firstNameTextField.getText();
            opiskelijaNumero = opiskelijaNumeroTextField.getText();
            opintopisteet = opintoisteetTextField.getText();
            System.out.println("Opiskelijoita lisätty: " + counter);

            Opiskelija o = new Opiskelija(nimi, opiskelijaNumero);
            o.setOpintopisteet(Integer.parseInt(opintopisteet));
            Opiskelijat.add(o);
            counter++;
            for (Opiskelija i : Opiskelijat) {
                System.out.println();
                i.tulostaTiedot();
            }

            System.out.println("Opiskelijataulukon koko: " + Opiskelijat.size());
            System.out.println("----------------");
        });
    }


}
