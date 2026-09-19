
public class ReverseString {
	
	    public static void main(String[] args) {
	        String str = "The quick brown fox jumps";
	        String rev = "";

	        // Reverse using loop
	        for (int i = str.length() - 1; i >= 0; i--) {
	            rev = rev + str.charAt(i);
	        }

	        System.out.println("The given string is: " + str);
	        System.out.println("The string in reverse order is:");
	        System.out.println(rev);
	    }
	}

