package listenerapp;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.event.EventType;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class ListenerApp extends Application {

    Text text;

    @Override
    public void start(Stage stage) {
        Group group = new Group();
        Scene scene = new Scene(group, 500, 500);

        // button section
        Button button = new Button();
        button.setText("Click me");
        Listener listener = new Listener();
        button.addEventHandler(ActionEvent.ACTION, listener);
        group.getChildren().add(button);

        // text section
        text = new Text(10, 50, "Click the button");
        group.getChildren().add(text);

        stage.setTitle("Main pane");
        stage.setScene(scene);
        stage.show();
    }

    public void updateText(int counter) {
        text.setText("You clicked " + counter + " times");
    }

    class Listener implements EventHandler {

        int counter = 0;

        @Override
        public void handle(Event event) {
            updateText(++counter);
        }
    }

    public static void main(String[] args) {
        launch(args);
    }
}
