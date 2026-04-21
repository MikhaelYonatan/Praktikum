import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine().trim());
        Courier[] courier = new Courier[n];
        String[] items = new String[n];

        for(int i = 0; i < n; i++){
            String line = sc.nextLine();
            String[] parts = line.split(" ", 4);
            String type = parts[0];
            String name = parts[1];
            int speed = Integer.parseInt(parts[2]);
            items[i] = parts[3];

            if(type.equals("B")){
                BikeCourier bk = new BikeCourier(name, speed);
                courier[i] = bk;
            }else if(type.equals("C")){
                CarCourier ck = new CarCourier(name, speed);
                courier[i] = ck;
            }
        }
        int sum = 0;
        Boolean fast = false;
        for(int i = 0; i < n; i++){
            System.out.println(courier[i]);
            System.out.println(courier[i].deliver(items[i]));
            sum += courier[i].getSpeed();
            if (courier[i].getSpeed() > 40){
                fast = true;
            }
        }

        System.out.println("Average speed: " + String.format("%.2f",n > 0? (double) sum / n: (double) sum));
        System.out.println("Fast? " + Boolean.toString(fast));

        sc.close();
        return;
    }
}