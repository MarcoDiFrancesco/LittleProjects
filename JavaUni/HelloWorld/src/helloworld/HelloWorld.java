/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package helloworld;

import javax.swing.JOptionPane;

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

    int[] intArray = {1,2,3,4,5};
    for(int i = 0; i<5; i++){
      System.out.println(intArray[i]);
    }
    
    System.exit(0);
  }

  public HelloWorld() {
    System.out.println("I'm in HelloWorld");
  }

  public void doThat() {
    System.out.println("I'm in obj");
  }

}
