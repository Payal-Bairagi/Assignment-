public class Main {

    public static void main(String[] args) {

        PrimeMembers obj = new PrimeMembers();

        // Input using your custom methods
        System.out.print("Enter Name: ");
        obj.setName(getString());

        System.out.print("Enter Age: ");
        obj.setAge((int) getFloat());

        System.out.print("Enter Phone Number: ");
        obj.setPhoneNumber(getString());

        System.out.print("Enter Address: ");
        obj.setAddress(getString());

        System.out.print("Enter Salary: ");
        obj.setSalary(getFloat());

        System.out.print("Enter Joining Year: ");
        obj.setJoiningYear((int) getFloat());

        System.out.print("Enter Joining Fees: ");
        obj.setJoiningFees(getFloat());

        System.out.print("Is Active (1 for true / 0 for false): ");
        float input = getFloat();
        boolean status = (input == 1);
        obj.setIsActive(status);

        // Output
        obj.display();
    }

    // ===== Your Input Methods =====
    public static float getFloat() {
        String objString = getString();
        float data = Float.parseFloat(objString.trim());
        return data;
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
