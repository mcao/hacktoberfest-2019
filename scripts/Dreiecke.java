import java.util.Scanner;

public class Dreiecke {

    public static void main(String[] args) {

        // Erzeuge Scanner zur Größeneingabe und Verknüpfung mit entsprechenden Variablen
        Scanner input = new Scanner(System.in);
        System.out.println("Wie groß sollen deine Dreiecke sein?");
        int triangleSize = input.nextInt();
        System.out.println("Wieviele dieser " + triangleSize + " Reihen großen Dreiecke möchtest du zeichnen?");
        int triangleNumber = input.nextInt();
        // Schleife für Anzahl der Dreiecke
        for (int i = 1; i <= triangleNumber; i++) {
            // Schleife für Zeilenanzahl Dreiecke
            for (int a = 1; a <= triangleSize; a++) {
                // Schleife für Anzahl Sterne pro Zeile
                for (int b = 1; b <= a; b++) {
                    System.out.print('*');
                }
                System.out.println();
            }
            System.out.println();
        }

    }
}
