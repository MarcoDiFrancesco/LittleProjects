package com.marcodifrancesco.carsstreetgrass;

import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import javafx.util.Pair;

import java.util.ArrayList;
import java.util.Random;

public class Game extends BorderPane {
    PlayingField playingField;
    Node[] fields;
    int availableCars;
    boolean gettingCar;
    ArrayList<Pair<Integer, Integer>> cars;
    boolean gameStarted;

    Game() {
        gameStarted = false;
        cars = new ArrayList<>();
        gettingCar = false;
        availableCars = 3;
        playingField = new PlayingField();
        setCenter(playingField);
        addHandlerTerreno();
        updateFields();
    }

    void update() {
        for (Pair<Integer, Integer> car : cars) {
            int row = car.getKey();
            int col = car.getValue();
            ((Strada) playingField.terreni[row][col]).setCar();
        }
        playingField.updateTerreno();
        updateFields();
    }

    void updateFields() {
        HBox fieldsBox = new HBox();
        fields = new Node[3];
        fields[0] = new Text(String.format("Auto Disponibili: %d", availableCars));
        Button button1 = new Button("Aggiungi auto");
        button1.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> getCar());
        Button button2 = new Button("Inizia");
        button2.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleStart());
        if (gettingCar) {
            button1.setDisable(true);
            button2.setDisable(true);
        }
        fields[1] = button1;
        fields[2] = button2;
        fieldsBox.getChildren().addAll(fields);
        setBottom(fieldsBox);
    }

    void handleTerreno(Terreno terreno) {
        if (gettingCar) {
            getCar(terreno);
        } else {
            changeTerrenoType(terreno);
        }
    }

    void changeTerrenoType(Terreno terreno) {
        Terreno newTerreno;
        if (terreno instanceof Strada) {
            Strada strada = (Strada) terreno;
            if (strada.getCar())
                return;
            newTerreno = new Prato(terreno.row, terreno.col);
        } else {
            newTerreno = new Strada(terreno.row, terreno.col);
        }
        newTerreno.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleTerreno(newTerreno));
        playingField.terreni[terreno.row][terreno.col] = newTerreno;
        update();
    }

    void getCar(Terreno terreno) {
        if (terreno instanceof Strada) {
            gettingCar = false;
            availableCars -= 1;
            Strada strada = (Strada) terreno;
            cars.add(new Pair(strada.row, strada.col));
            update();
        }
    }

    void addHandlerTerreno() {
        for (int row = 0; row < playingField.size; row++) {
            for (int col = 0; col < playingField.size; col++) {
                Terreno terreno = playingField.terreni[row][col];
                playingField.terreni[row][col].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleTerreno(terreno));
            }
        }
    }

    void getCar() {
        if (availableCars == 0) {
            popup("No cars available");
            return;
        }
        gettingCar = true;
        fields[1].setDisable(true);
        fields[2].setDisable(true);
        update();
    }

    void randomMove() {
        Random random = new Random();
        for (int carIdx = 0; carIdx < cars.size(); carIdx++) {
            int val = random.nextInt(4);
            int row = cars.get(carIdx).getKey();
            int col = cars.get(carIdx).getValue();
            if (val == 0)
                moveCar(row, col, row, col - 1, carIdx);
            else if (val == 1)
                moveCar(row, col, row - 1, col, carIdx);
            else if (val == 2)
                moveCar(row, col, row, col + 1, carIdx);
            else if (val == 3)
                moveCar(row, col, row + 1, col, carIdx);
        }
    }

    void moveCars(String move) {
        for (int carIdx = 0; carIdx < cars.size(); carIdx++) {
            int row = cars.get(carIdx).getKey();
            int col = cars.get(carIdx).getValue();
            if (move == "up")
                moveCar(row, col, row, col - 1, carIdx);
            else if (move == "left")
                moveCar(row, col, row - 1, col, carIdx);
            else if (move == "down")
                moveCar(row, col, row, col + 1, carIdx);
            else if (move == "right")
                moveCar(row, col, row + 1, col, carIdx);
        }
    }

    void moveCar(int row1, int col1, int row2, int col2, int carIdx) {
        if (row2 < 0 || col2 < 0 || row2 >= playingField.size || col2 >= playingField.size) {
            System.out.format("Auto %d - Direzione X=%d - Direzione Y=%d - Mossa non permessa\n", carIdx, row2, col2);
            return;
        }
        Terreno strada1 = playingField.terreni[row1][col1];
        Terreno strada2 = playingField.terreni[row2][col2];
        if (strada2 instanceof Strada) {
            if (((Strada) strada2).getCar()) {
                popup("Crash");
            }
            ((Strada) strada1).removeCar();
            ((Strada) strada2).setCar();
            cars.set(carIdx, new Pair(row2, col2));
        }
        System.out.format("Auto %d - Direzione X=%d - Direzione Y=%d - Mossa permessa\n", carIdx, row2, col2);
    }

    void handleStart() {
        FlowPane pane = new FlowPane();
        Button upButton = new Button("Up");
        upButton.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> moveCars("up"));
        pane.getChildren().add(upButton);
        Button leftButton = new Button("Left");
        leftButton.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> moveCars("left"));
        pane.getChildren().add(leftButton);
        Button downButton = new Button("Down");
        downButton.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> moveCars("down"));
        pane.getChildren().add(downButton);
        Button rightButton = new Button("Right");
        rightButton.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> moveCars("right"));
        pane.getChildren().add(rightButton);

        Button randomButton = new Button("Random");
        randomButton.addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> randomMove());
        pane.getChildren().add(randomButton);

        Stage stage = new Stage();
        stage.setScene(new Scene(pane, 200, 100));
        stage.show();
    }

    void popup(String text) {
        StackPane pane = new StackPane();
        pane.getChildren().add(new Text(text));
        Stage stage = new Stage();
        stage.setScene(new Scene(pane, 300, 100));
        stage.show();
    }
}
