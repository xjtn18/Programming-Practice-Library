public class Solution {

	public static <T> void print(T s){
		System.out.println(s);
	}

	public static int lengthOfLastWord(String s) {
		s = s.trim();
		int charcnt = 0, i = s.length()-1;
		while (i > -1 && !Character.isWhitespace(s.charAt(i))){
			charcnt++;
			i--;
		}
		return charcnt;
	}

	public static void main(String[] args){
		print(lengthOfLastWord("Hello World"));
		print(lengthOfLastWord(""));
		print(lengthOfLastWord(" "));
		print(lengthOfLastWord("   haha yo"));
		print(lengthOfLastWord("hi there my name is	jakey"));
	}
}

