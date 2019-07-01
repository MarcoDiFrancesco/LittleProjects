package numberpad;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.control.Button;

public class PersonalizedButton extends Button implements EventHandler<ActionEvent>{
  NumberPad numberPad;

  public PersonalizedButton(NumberPad numberPad, String id, String label) {
    super(label); 
    this.numberPad = numberPad;
    setId(id);
    addEventFilter(ActionEvent.ACTION, this);
  }
  void setButtonWidth(double width){
    this.setMaxWidth(width);
    this.setMaxHeight(width);
  }
  
  @Override
  public void handle(ActionEvent event) {
    //numberPad.compute(this.getId());
  }
  

}
