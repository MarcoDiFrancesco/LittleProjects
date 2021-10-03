package pickacolor;

import javafx.application.Application;
import javafx.event.Event;
import javafx.event.EventHandler;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.control.ColorPicker;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.stage.Stage;

public class PickAColor extends Application {

    @Override
    public void start(Stage stage) {
        Circle circle = new Circle(40, 30, 30);
        ColorPicker colorPicker = new ColorPicker();
        circle.setFill(Color.BLACK); // set defualt color
        colorPicker.setOnAction(new EventHandler() {
            @Override
            public void handle(Event event) {
                System.out.println(event.getEventType());
                circle.setFill(colorPicker.getValue());
            }
        });
        colorPicker.setLayoutX(90);
        colorPicker.setLayoutY(15);

        Group group = new Group();
        group.getChildren().add(circle);
        group.getChildren().add(colorPicker);
        Scene scene = new Scene(group, 400, 100);

        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }

}
