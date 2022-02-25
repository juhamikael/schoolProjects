import java.util.ArrayList;
import java.util.Scanner;

public class Henkilotiedot {
    public static void main(String[] args) {
        ArrayList<Henkilo> henkilot = new ArrayList<Henkilo>();
        while(true){
            System.out.print("Syota numero valilta 1-4: ");
            vaihtoEhdot();
            System.out.print("Valinta: ");
            Scanner scanner = new Scanner(System.in);
            int toiminto = scanner.nextInt();
            switch (toiminto) {
                case 1 -> {
                    String nimi = nimi();
                    int ika = ika();
                    String osoiteTiedot[] = OsoiteTiedot();
                    henkilot.add(new Henkilo(nimi, ika, new Osoite(osoiteTiedot[0], osoiteTiedot[1], osoiteTiedot[2])));
                }
                case 2 -> {
                    System.out.println("Syota henkilon nimi jonka haluat poistaa listasta: ");
                    String poistettavaNimi = nimi();
                    System.out.flush();
                    henkilot.removeIf(h -> h.getNimi().equals(poistettavaNimi));
                }
                case 3 -> {
                    if (henkilot.isEmpty()){
                        System.out.println("\nHenkiloita ei ole lisattyna\n");
                    }else
                    {
                        System.out.println("\n----------------------");
                        System.out.println("TULOSTETAAN HENKILOT:");
                        System.out.println("----------------------\n");
                        int i = 1;
                        for (Henkilo h : henkilot) {
                            System.out.println("HENKILON " + i + " TIEDOT:");
                            h.tulostaTiedot();
                            i+=1;
                        }
                        System.out.println("----------------------");
                    }
                }
            }
            if (toiminto == 4){
                System.out.println("Lopetetaan, kiitos näkemiin!");
                break;
            }
        }
    }
    public static String nimi(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Syota nimi: ");
        return scanner.nextLine();
    }
    public static int ika(){
        Scanner scanner = new Scanner(System.in);
        System.out.print("Syota Ika: ");
        return scanner.nextInt();
    }
    public static String[] OsoiteTiedot(){
        String[] osoiteTiedot = new String[3];
        Scanner scanner = new Scanner(System.in);
        System.out.print("Syota katuosoite: ");
        osoiteTiedot[0] = scanner.nextLine();

        System.out.print("Syota postinumero: ");
        osoiteTiedot[1] = scanner.nextLine();

        System.out.print("Syota kunta: ");
        osoiteTiedot[2] = scanner.nextLine();
        return osoiteTiedot;
    }
    public static void vaihtoEhdot(){
        System.out.println("\n----------------------");
        System.out.println("1. Lisää uusi henkilö");
        System.out.println("2. Poista henkilö");
        System.out.println("3. Tulosta henkilöt");
        System.out.println("4. Lopeta");
        System.out.println("----------------------\n");
    }

}
