import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class reader {

    //String ArrayList declaration for input text data
    String[] string_data;
    Double[] num_data;


    private void save(String filename) {
        BufferedReader in = null;
        try {
            in = new BufferedReader(new FileReader(filename));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        List<String> list = new ArrayList<>();
        String str = null;
        while (true) {
            try {
                if ((str = in.readLine()) == null) break;
            } catch (IOException e) {
                e.printStackTrace();
            }
            list.add(str);
        }
        string_data = list.toArray(new String[0]);
    }

    private void conversion() {
        reader P = new reader();
        P.save("a.txt");
        int count = 0;

        //Extracting data from a String to Double array
        List<Double> ds = new ArrayList<>();
        //ArrayList<ArrayList<Double>> may = new ArrayList<>();
        for (int x = 0; x < P.string_data.length; x++) {
            String input = P.string_data[x];
            String[] numbers = input.replaceAll("[^0-9.]+", " ").trim().split(" ");

            for (int i = 0; i < numbers.length; i++) {
                ds.add(i, Double.parseDouble(numbers[i]));
                //may.add(new ArrayList<>());
                //may.get(x).add(Double.parseDouble(numbers[i]));
                count = count + 1;

            }
            num_data = ds.toArray(new Double[numbers.length]);
        }

        Double[][] alldata = new Double[P.string_data.length][8];
        int o = 0;
        for (int i = 0; i < count; i++) {
            if (num_data[i] % 2.0 == 0) {
                for (int j = 0; j < 8; j++) {
                    alldata[o][j] = num_data[i + j];
                }
                i = i + 7;
                o++;
            } else {
                for (int j = 0; j < 4; j++) {
                    alldata[o][j] = num_data[i + j];
                }
                i = i + 3;
                o++;
            }
        }

        for (int j = 0; j < num_data.length; j++) {
            System.out.println(" " + num_data[j]);
        }
        System.out.println();
        System.out.println(count);
        for (int j = 0; j < alldata.length; j++) {
            for (int y = 0; y < alldata[j].length; y++) {
                System.out.print(" " + alldata[j][y]);
            }
            System.out.println();
        }

    }


    public static void main(String[] args) {

        reader Agapi = new reader();
        Agapi.conversion();
    }
}


    //MANAGED TO SAVE EACH STRING IN AN ARRAY AS NUMERICAL VALUES




