import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;


class IntPair {
    public Integer x, y;

    public IntPair(Integer _x, Integer _y){
        x = _x;
        y = _y;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + x;
        result = prime * result + y;
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null) return false;
        if (getClass() != obj.getClass()) return false;
        IntPair other = (IntPair) obj;
        return x.equals(other.x) && y.equals(other.y);
    }
}



class Solution {
    static <T> void log(T input){ System.out.println(input); }
    static <T> void alog(T[] arr){ System.out.println(Arrays.toString(arr)); }
    static void mlog(Integer[][] mat){
        for (int i = 0; i < mat.length; ++i){
            if (i == 0) System.out.printf("[[%d", mat[i][0]);
            else System.out.printf(" [%d", mat[i][0]);
            for (int j = 1; j < mat[0].length; ++j) System.out.printf(", %d", mat[i][j]);
            if (i == mat.length-1) System.out.print("]]\n");
            else System.out.print("]\n");
        }
    }
    static void mlog(char[][] mat){
        for (int i = 0; i < mat.length; ++i){
            if (i == 0) System.out.printf("[[%c", mat[i][0]);
            else System.out.printf(" [%c", mat[i][0]);
            for (int j = 1; j < mat[0].length; ++j) System.out.printf(" %c", mat[i][j]);
            if (i == mat.length-1) System.out.print("]]\n");
            else System.out.print("]\n");
        }
    }
    static void qlog(String input){ log("'" + input + "'"); }
    static void qlog(char[] input){ log("'" + new String(input) + "'"); }


    static char[][] transparent_origami(ArrayList<IntPair> coords, ArrayList<IntPair> folds){
        HashSet<IntPair> set = new HashSet<>();
        char[][] paper;
        int xMax = 0, yMax = 0;
        for (IntPair coord : coords) {
            for (IntPair fold : folds){
                if (fold.x == 0){
                    coord.x = fold.y - Math.abs(coord.x - fold.y);
                } else {
                    coord.y = fold.y - Math.abs(coord.y - fold.y);
                }
                //break; // only checking after first fold (part 1)
            }
            xMax = Math.max(xMax, coord.x);
            yMax = Math.max(yMax, coord.y);
            //set.add(coord); // part 1
        }
        paper = new char[yMax+1][xMax+1];
        for (char[] row: paper) Arrays.fill(row, ' '); // fill with '.'
        for (IntPair coord : coords){
            paper[coord.y][coord.x] = '#';
        }

        //return set.size(); // part 1
        return paper;
    }

    public static void main(String[] args) throws IOException {
        ArrayList<IntPair> coords = new ArrayList<>();
        BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
        String line;
        while ((line = reader.readLine()) != null && !line.isEmpty()){
            int split = line.indexOf(',');
            Integer x = Integer.parseInt(line.substring(0, split));
            Integer y = Integer.parseInt(line.substring(split+1));
            coords.add(new IntPair(x,y));
        }

        ArrayList<IntPair> folds = new ArrayList<>();
        final String foldMessage = "fold along ";
        while ((line = reader.readLine()) != null){
            char axis = line.substring(foldMessage.length()).charAt(0);
            Integer mid = Integer.parseInt(line.substring(foldMessage.length()+2));
            folds.add(new IntPair((axis == 'x') ? 0 : 1, mid));
        }
        mlog(transparent_origami(coords, folds));
    }
}




