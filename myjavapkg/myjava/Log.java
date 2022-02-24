package myjava;
import java.util.Arrays;


public class Log {

	public static <T> void log(T input){ System.out.println(input); }

	public static <T> void alog(T[] arr){ System.out.println(Arrays.toString(arr)); }

	public static void mlog(Integer[][] mat){
		for (int i = 0; i < mat.length; ++i){
			if (i == 0) System.out.printf("[[%d", mat[i][0]);
			else System.out.printf(" [%d", mat[i][0]);
			for (int j = 1; j < mat[0].length; ++j) System.out.printf(", %d", mat[i][j]);
			if (i == mat.length-1) System.out.print("]]\n");
			else System.out.print("]\n");
		}
	}

	public static void qlog(String input){ log("'" + input + "'"); }

	public static void qlog(char[] input){ log("'" + new String(input) + "'"); }

};

