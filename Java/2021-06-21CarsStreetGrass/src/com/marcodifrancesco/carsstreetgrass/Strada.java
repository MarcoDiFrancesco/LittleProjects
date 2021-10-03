package com.marcodifrancesco.carsstreetgrass;

import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class Strada extends Terreno {
    private boolean hasCar;

    Strada(int row, int col) {
        super(row, col);
        hasCar = false;
        super.rectangle.setFill(Color.GRAY);
        update();
    }

    boolean getCar() {
        return hasCar;
    }

    void setCar() {
        hasCar = true;
        update();
    }

    void removeCar() {
        hasCar = false;
        update();
    }

    void update() {
        getChildren().clear();
        getChildren().add(rectangle);
        if (hasCar) {
            Circle circle = new Circle(super.size / 2);
            circle.setFill(Color.YELLOW);
            getChildren().add(circle);
        }
    }
}
