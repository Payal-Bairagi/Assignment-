class ConsoleInput {

    public static float getFloat() {
        String objString = getString();
        float data = Float.parseFloat(objString.trim());
        return data;
    }

    public static int getInt() {
        String str = getString();
        return Integer.parseInt(str.trim());
    }

    public static double getDouble() {
        String str = getString();
        return Double.parseDouble(str.trim());
    }

    public static char getChar() {
        String str = getString();
        return str.trim().charAt(0);
    }

    public static String getString() {
        try {
            byte arrInput[] = new byte[100];
            int length = System.in.read(arrInput);

            if (length <= 2) return "";

            byte[] arrFinal = new byte[length - 2];
            System.arraycopy(arrInput, 0, arrFinal, 0, length - 2);

            return new String(arrFinal);

        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
