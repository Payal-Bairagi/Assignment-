public class  ConsoleInput{
	
	public static Integer getInt() {
		int num1 = Integer.parseInt(getString());
		return num1;
	}
	
	public static char getChar() {
		String str = getString();
		char ch = str.charAt(0);
		return ch;
	}
	
	public static Float getFloat() {
		float num1 = Float.parseFloat(getString());
		return num1;
	}
	
	public static double getDouble() {
		double num1 = Double.parseDouble(getString());
		return num1;
	}
	
	public static String getString() {
		try {
		byte[] arrInput = new byte[100];
		int length = System.in.read(arrInput);
		byte[] arrFinal = new byte[length-2];
		System.arraycopy(arrInput, 0, arrFinal,0, length-2);
		
		String objString = new String(arrFinal);
		return objString;
		
		}catch(Exception e) {
			e.printStackTrace();
			return null;
		}
	}
}
