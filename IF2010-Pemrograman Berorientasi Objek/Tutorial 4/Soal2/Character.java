public class Character {
    private String name;
    private int level;
    private double powerBase;

    public Character(String name, int level, double powerBase){
        this.name = name;
        this.level = level;
        this.powerBase = powerBase;
    }

    public String getName(){
        return name; 
    }

    public int getLevel(){
        return level;
    }

    public double getPowerBase(){
        return powerBase;
    }

    public double calculatePower(){
        return powerBase;
    }

    public void printInfo(){
        System.out.println("Nama: " + getName());
        System.out.println("Nama Kapital: " + getName().toUpperCase());
        System.out.println("Inisial: " + getName().charAt(0));
        System.out.println("Panjang Nama: " + getName().length());
        System.out.println("Level: " + getLevel());
        System.out.println("Power Akhir: " + calculatePower());
    }
}
