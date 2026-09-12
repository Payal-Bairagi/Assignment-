
 class Parent {
     void parentMethod() {
    	 System.out.println("This is Parent class");
     }
}
class Child  extends Parent{
	void childMethod() {
		 System.out.println("This is Child class");
	}

	public static void main(String[] args) {
		Parent parentObj = new Parent();
        Child childObj = new Child();

        // 1. Parent method via Parent object
        parentObj.parentMethod();

        // 2. Child method via Child object
        childObj.childMethod();

        // 3. Parent method via Child object
        childObj.parentMethod();
}
}