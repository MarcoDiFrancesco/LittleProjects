/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloworld;

/**
 *
 * @author marco
 */
public class HelloWorld {

    public static void main(String[] args) {
        System.out.println("Hello world");
        System.out.println("That's actually my first program in Java I'm writing after my high school");
        System.out.println("-13 days for the exam and I just started");

        for (int i = 0; i < 5; i++) {
            if (i % 2 == 0) {
                System.out.println(i);
            }
        }
        HelloWorld obj = new HelloWorld();
        obj.doThat();
        /*
        String input = JOptionPane.showInputDialog("Tell me your age");
        System.out.println(input);
         */
        String aLongString = "I'm super long";
        System.out.println(aLongString);

        int[] intArray = {1, 2, 3, 4, 5};
        for (int i = 0; i < 5; i++) {
            System.out.println(intArray[i]);
        }

        int[] giganArray = new int[1];
        giganArray[0] = 0;
        System.out.println("I'm a giant array and the numer 0 is: " + giganArray[0]);

        System.out.println("I'd like to copy an array to another one");
        int[] firstArray = new int[10];
        int[] secondArray = new int[10];

        // filling the array
        for (int i = 0; i < 10; i++) {
            firstArray[i] = i;
            firstArray[i] = i * 2;
        }
        // print arrays
        for (int i = 0; i < firstArray.length; i++) {
            System.out.print(firstArray[i] + " ");
        }
        System.out.print("\n");
        for (int i = 0; i < secondArray.length; i++) {
            System.out.print(secondArray[i] + " ");
        }
        System.out.print("\n");

        System.arraycopy(firstArray, 0, secondArray, 0, 10);

        for (int i = 0; i < firstArray.length; i++) {
            System.out.print(firstArray[i] + " ");
        }
        System.out.print("\n");
        for (int i = 0; i < secondArray.length; i++) {
            System.out.print(secondArray[i] + " ");
        }
        System.out.print("\n");

        SecondClass secondClass1 = new SecondClass(2, 3);
        System.out.println(secondClass1);

        ThirdClass thirdClass1 = new ThirdClass(3, 4, 5);
        System.out.println(thirdClass1);

        System.exit(0);
    }

    public HelloWorld() {
        System.out.println("I'm in HelloWorld");
    }

    public void doThat() {
        System.out.println("I'm in obj");
    }

}
