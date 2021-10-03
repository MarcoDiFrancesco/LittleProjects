package com.marcodifrancesco.slotmachine;

import javafx.scene.control.Button;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Shape;

public class Coin extends StackPane {
    private boolean valid = true;
    Circle circle;
    Coin() {
        circle = new Circle(30);
        getChildren().add(circle);
    }

    boolean disable() {
        if (!valid) {
            return false;
        }
        valid = false;
        circle.setFill(Color.WHITE);
        return true;
    }
}
