import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;

public class Algorithms {

    public static void main(String[] args) {
        int counter = 1;
        BlackAnt blackAnt;
        RedAnt redAnt;
        ArrayList<ArrayList<Ants> > aList =
                new ArrayList<ArrayList<Ants>>(2);
        ArrayList<RedAnt> reds = new ArrayList<>();
        ArrayList<BlackAnt> blacks = new ArrayList<>();

        try{BufferedReader bufferedReader =new BufferedReader(new FileReader("examples.txt"));
            String line;

            while ((line = bufferedReader.readLine()) != null){
                String[] parts =  line.split(" ",4);
                String id = parts[0];
                String x = parts[1];
                String y = parts[2];
                String restOFThem = parts[3];
                if ((counter % 2 ) == 1){
                    redAnt = new RedAnt(id, x, y, restOFThem);
                    counter++;
                    reds.add(redAnt);

                }else {
                    blackAnt = new BlackAnt(id, x, y, restOFThem);
                    counter++;
                    blacks.add(blackAnt);
                }
            }
        }catch (IOException e){

        }
    }

    public double measureDistance(int x1, int x2, int y1, int y2){
        return Math.sqrt(Math.pow(x1 - y1,2) + Math.pow(x2 - y2,2));
    }

}
