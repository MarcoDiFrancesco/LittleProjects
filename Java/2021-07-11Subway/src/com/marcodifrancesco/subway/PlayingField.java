package com.marcodifrancesco.subway;

import javafx.scene.input.KeyEvent;
import javafx.scene.layout.GridPane;

import java.util.Random;

public class PlayingField extends GridPane {
    private static final int FIELD_SIZE = 4;
    Cell[][] cell;
    public static final Random random = new Random();

    PlayingField() {
        cell = new Cell[FIELD_SIZE][FIELD_SIZE];
        reset();
    }

    void reset() {
        for (int i = 0; i < FIELD_SIZE; i++)
            for (int j = 0; j < FIELD_SIZE; j++)
                cell[i][j] = new CellEmpty();
        update();
    }

    void random() {
        for (int i = 0; i < FIELD_SIZE; i++)
            for (int j = 0; j < FIELD_SIZE; j++)
                cell[i][j] = getRandomType();
        update();
    }

    Cell getRandomType() {
        return switch (random.nextInt(3)) {
            case 0 -> new CellHorizontal();
            case 1 -> new CellCurve();
            case 2 -> new CellExchange();
            default -> new CellEmpty(); // Should never happen
        };
    }


    void update() {
        getChildren().clear();
        for (int i = 0; i < FIELD_SIZE; i++)
            for (int j = 0; j < FIELD_SIZE; j++)
                add(cell[i][j], i, j);
    }
}
