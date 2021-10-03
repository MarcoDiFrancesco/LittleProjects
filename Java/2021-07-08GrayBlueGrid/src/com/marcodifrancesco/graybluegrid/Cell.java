package com.marcodifrancesco.graybluegrid;

import javafx.geometry.Insets;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.CornerRadii;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;

import java.util.Random;

public class Cell extends StackPane {
    public static final Random random = new Random();
    // isColored when blue, false then gray
    int value;
    Color color;
    Text text;

    /**
     * Create Cell with random value and color
     */
    Cell() {
        setPrefSize(50, 50);
        text = new Text();
        text.setStyle("-fx-fill: yellow; -fx-font-size: 16px;");
        setRandColor();
        setRandValue();
        update();
    }

    Cell(int value) {
        this();
        this.value = value;
        update();
    }

    Cell(Color color) {
        this();
        this.value = 0;
        this.color = color;
        System.out.println(this.color);
        update();
    }

    void setRandValue() {
        value = random.nextInt(4);
    }

    void setRandColor() {
        if (random.nextBoolean())
            this.color = Color.GRAY;
        else
            this.color = Color.BLUE;
    }

    void update() {
        // Update color
        setBackground(new Background(new BackgroundFill(color, CornerRadii.EMPTY, Insets.EMPTY)));
        // Update value
        text.setText(Integer.toString(value));
        getChildren().clear();
        getChildren().add(text);
    }

    void updateValue() {
        if (color == Color.BLUE)
            if (value <= 0)
                value = 3;
            else
                value -= 1;
        else if (color == Color.GRAY)
            if (value >= 3)
                value = 0;
            else
                value += 1;
    }

}
