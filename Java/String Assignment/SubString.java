
public class SubString {
	
	    public static void main(String[] args) {
	        String str = "The quick brown fox jumps over the lazy dog.";

	        // replace "fox" with "cat"
	        String newStr = str.replaceAll("fox", "cat");

	        System.out.println("Original string: " + str);
	        System.out.println("New String: " + newStr);
	    }
	}

