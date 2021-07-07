package com.marcodifrancesco.dice;

import javafx.scene.input.MouseEvent;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

import java.util.Random;

public class Dice extends Pane {
    int value;
    // Number of time cell was clicked
    int clicks = 0;
    Random random = new Random();

    Dice() {
        setBorder(new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID, CornerRadii.EMPTY, BorderWidths.DEFAULT)));
        setPrefSize(80, 80);
        addEventHandler(MouseEvent.MOUSE_CLICKED, this::randomValue);
        randomValue();
        update();
    }

    void randomValue() {
        // Value 1 to 6
        value = random.nextInt(6) + 1;
        update();
    }

    void randomValue(MouseEvent mouseEvent) {
        clicks += 1;
        randomValue();
        mouseEvent.consume();
    }

    void update() {
        getChildren().clear();
        switch (value) {
            case 1 -> getChildren().add(getCircle(40, 40));
            case 2 -> {
                getChildren().add(getCircle(25, 55));
                getChildren().add(getCircle(55, 25));
            }
            case 3 -> {
                getChildren().add(getCircle(25, 55));
                getChildren().add(getCircle(40, 40));
                getChildren().add(getCircle(55, 25));
            }
            case 4 -> {
                getChildren().add(getCircle(25, 25));
                getChildren().add(getCircle(25, 55));
                getChildren().add(getCircle(55, 25));
                getChildren().add(getCircle(55, 55));
            }
            case 5 -> {
                getChildren().add(getCircle(25, 25));
                getChildren().add(getCircle(25, 55));
                getChildren().add(getCircle(55, 25));
                getChildren().add(getCircle(55, 55));
                getChildren().add(getCircle(40, 40));
            }
            case 6 -> {
                getChildren().add(getCircle(20, 25));
                getChildren().add(getCircle(60, 25));
                getChildren().add(getCircle(20, 40));
                getChildren().add(getCircle(60, 40));
                getChildren().add(getCircle(20, 55));
                getChildren().add(getCircle(60, 55));
            }
        }
    }

    Circle getCircle(int x, int y) {
        Circle circle = new Circle(5);
        circle.setLayoutX(x);
        circle.setLayoutY(y);
        return circle;
    }
}
