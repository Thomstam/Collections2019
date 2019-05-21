import java.util.ArrayList;

public class BlackAnt extends Ants{

    private ArrayList<Integer> seeds = new ArrayList<>();

    public BlackAnt(String id, String x, String y, String seedsNumber){
        this.id = Integer.parseInt(id);
        this.location = new Location(Integer.parseInt(x),Integer.parseInt(y));
        int converter;
        String[] parts =  seedsNumber.split(" ");
        String part1 = parts[0];
        seeds.add(converter = Integer.parseInt(part1));
        String part2 = parts[1];
        seeds.add(converter = Integer.parseInt(part2));
        String part3 = parts[2];
        seeds.add(converter = Integer.parseInt(part3));
        String part4 = parts[3];
        seeds.add(converter = Integer.parseInt(part4));
        String part5 = parts[4];
        seeds.add(converter = Integer.parseInt(part5));
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public Location getLocation() {
        return location;
    }

    public void setLocation(Location location) {
        this.location = location;
    }

    public ArrayList<Integer> getSeeds() {
        return seeds;
    }

    public void setSeeds(ArrayList<Integer> seeds) {
        this.seeds = seeds;
    }
}
