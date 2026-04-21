public class Courier {
    private String name;
    private int speed;

    public Courier(){
        this.name = "Unknown";
        this.speed = 10;
    }

    public Courier(String name, int speed){
        this.name = name;
        this.speed = speed;
    }

    public String deliver(String item){
        return this.name + " delivers " + item;
    }

    public int getSpeed(){
        return this.speed;
    }

    public String toString(){
        return this.name + " with speed " + this.getSpeed() + " is ready to deliver";
    }
}