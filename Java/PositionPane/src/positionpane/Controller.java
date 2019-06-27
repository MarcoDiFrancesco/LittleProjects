package positionpane;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.StackPane;

class Controller implements EventHandler<ActionEvent> {

  double circlePosition = 0;
  AnchorPane pane = null;
  StackPane helpPane = null;
  
  Controller(AnchorPane pane, StackPane helpPane, int circlePosition){
    this.pane = pane;
    this.helpPane = helpPane;
    this.circlePosition = circlePosition;
  }
  
  @Override
  public void handle(ActionEvent event){
    pane.setLeftAnchor(helpPane,circlePosition);
    System.out.println("Help pane XLayout set to: " + circlePosition);
  }
  
}
