public class main {

	public static int[] plusOne(int[] digits){
		int i = digits.length - 1;
		do {
			digits[i] = ++(digits[i]) % 10;
			--i;
			if (i < 0){ // if the number has increased by one significant digit
				if (digits[0] == 0){
					digits = new int[digits.length + 1];
					digits[0] = 1;
				}
				break;
			}
		} while (digits[i + 1] == 0);

		return digits;
	}



	public static <T> void log(T s){
		System.out.println(s);
		int thing = new int(5);
	}

	public static void alog(int[] s){
		int i;
		for (i = 0; i < s.length-1; ++i){
			//log(i);
			System.out.print(s[i]);
			System.out.print(", ");
		}
		System.out.print(s[i]);
	}

	public static void main(String[] args){
		//Solution s = new Solution();
		alog(plusOne(new int[]{1,2,3}));
		log("\n");
		alog(plusOne(new int[]{1,9,8}));
		log("\n");
		alog(plusOne(new int[]{1,2,0}));
		log("\n");
		alog(plusOne(new int[]{0}));
	}

}


