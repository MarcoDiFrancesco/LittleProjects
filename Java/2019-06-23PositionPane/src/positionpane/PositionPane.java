package positionpane;


import java.util.ArrayList;
import java.util.List;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class PositionPane extends Application {

  @Override
  public void start(Stage stage) {
    // main pane
    AnchorPane pane = new AnchorPane();
    pane.setMinHeight(150);
    
    // help circle
    StackPane helpPane = new StackPane();
    Circle circle = new Circle();
    circle.setRadius(30);
    circle.setStroke(Color.RED);
    circle.setFill(Color.YELLOW);
    Text text = new Text("?");
    text.setStroke(Color.RED);
    text.setFill(Color.WHITE);
    text.setFont(Font.font("VERDANA",FontWeight.BOLD,18));
    helpPane.getChildren().addAll(circle,text);
    pane.getChildren().add(helpPane);
    
    // button pane
    HBox buttonPane = new HBox();
    List<Button> listButton = new ArrayList();
    listButton.add(new Button("One"));
    listButton.add(new Button("Two"));
    listButton.add(new Button("Three"));
    listButton.add(new Button("Four"));
    listButton.add(new Button("Five"));
    listButton.add(new Button("Six"));
    listButton.add(new Button("Seven"));
    for (int i = 0; i < listButton.size(); i++ ) {
      listButton.get(i).setOnAction(new Controller(pane, helpPane, i*10));   
    }
   buttonPane.getChildren().addAll(listButton);
    buttonPane.setSpacing(10);  // set spacing between buttons
    pane.getChildren().add(buttonPane);
        
    // set position of the panes
    pane.setBottomAnchor(buttonPane, 20.0);
    pane.setRightAnchor(buttonPane, 20.0);
    pane.setTopAnchor(helpPane, 20.0);
    pane.setLeftAnchor(helpPane, 20.0);
    
    Scene scene = new Scene(pane);
    stage.setScene(scene);
    stage.show();
  }

  public static void main(String[] args) {
    launch(args);
  }
}
