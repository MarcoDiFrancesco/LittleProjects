package com.marcodifrancesco.slotmachine;

import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Rectangle;
import javafx.scene.shape.Shape;
import javafx.scene.shape.TriangleMesh;

import java.util.Objects;
import java.util.Random;

public class Wheel extends StackPane {
    Shape shape;
    Paint color;
    Wheel() {
        random();
        update();
    }

    void random() {
        int sz = 30;
        Shape[] shapes = {new Circle(sz), new Rectangle(sz * 2, sz * 2)};
        Color[] colors = {Color.RED, Color.GREEN, Color.YELLOW};
        Random random = new Random();
        int shapeVal = random.nextInt(shapes.length);
        int colorVal = random.nextInt(colors.length);
        shape = shapes[shapeVal];
        color = colors[colorVal];
        shape.setFill(color);
    }

    void update() {
        getChildren().removeAll();
        getChildren().add(shape);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Wheel wheel = (Wheel) o;
        return Objects.equals(shape.getClass(), wheel.shape.getClass()) && Objects.equals(color, wheel.color);
    }

    @Override
    public int hashCode() {
        return Objects.hash(shape);
    }
}
