package calculator;

import javafx.event.Event;
import javafx.event.EventHandler;

public class Listener implements EventHandler{

  String operator = "";
  String input1 = "";
  String input2 = "";
  
  Listener(String operator, String input1, String input2){
    this.operator = operator;
    this.input1 = input1;
    this.input2 = input2;
  }
  
  @Override
  public void handle(Event event) {
    if(operator == "+") {
      
    }
    System.out.println(operator);
    System.out.println(input1);
    System.out.println(input2);
    
  }

}
