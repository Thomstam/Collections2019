public class RedAnt extends Ants {

    private int maxWeightCanCarry;

    public RedAnt(String id, String x , String y, String maxWeightCanCarry){
        this.id = Integer.parseInt(id);
        this.location = new Location(Integer.parseInt(x),Integer.parseInt(y));
        this.maxWeightCanCarry = Integer.parseInt(maxWeightCanCarry);
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

    public int getMaxWeightCanCarry() {
        return maxWeightCanCarry;
    }

    public void setMaxWeightCanCarry(int maxWeightCanCarry) {
        this.maxWeightCanCarry = maxWeightCanCarry;
    }
}
