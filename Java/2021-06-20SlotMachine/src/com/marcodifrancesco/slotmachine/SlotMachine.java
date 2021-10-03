package com.marcodifrancesco.slotmachine;

import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.Stage;

public class SlotMachine extends BorderPane {
    VBox centerBox, coinBox;
    int credit, points;
    Wheel[] wheels;
    Text[] fields;
    Button[] buttons;
    Coin[] coins;

    SlotMachine() {
        Text text = new Text("Super SLOTS");
        setTop(text);
        setAlignment(text, Pos.TOP_CENTER);

        resetGame();
    }

    private void resetGame() {
        credit = points = 0;
        wheels = new Wheel[3];
        getWheels();
        fields = new Text[2];
        buttons = new Button[3];
        getButtons();
        coins = new Coin[3];
        getCoins();
        updatePane();
    }

    void updatePane() {
        centerBox = new VBox();

        HBox wheelsBox = new HBox();
        wheelsBox.getChildren().addAll(wheels);
        centerBox.getChildren().add(wheelsBox);

        HBox fieldsBox = new HBox();
        getFields();
        fieldsBox.getChildren().addAll(fields);
        centerBox.getChildren().add(fieldsBox);

        HBox buttonsBox = new HBox();
        buttonsBox.getChildren().addAll(buttons);
        centerBox.getChildren().add(buttonsBox);

        setCenter(centerBox);

        VBox coinBox = new VBox();
        coinBox.getChildren().addAll(coins);
        setRight(coinBox);
    }

    private void popup(String text) {
        StackPane stackPane = new StackPane();
        stackPane.getChildren().add(new Text(text));
        Scene scene = new Scene(stackPane, 400, 100);
        Stage stage = new Stage();
        stage.setScene(scene);
        stage.show();
    }

    private void checkWin() {
        if (wheels[0].equals(wheels[1]) && wheels[0].equals(wheels[2]) && wheels[1].equals(wheels[2])) {
            popup("HAI VINTO");
            credit += points * 100;
            points = 0;
            getWheels();
        }
    }

    private void handleWheel(int wheel) {
        if (points > 0) {
            wheels[wheel] = new Wheel();
            wheels[wheel].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleWheel(wheel));
            points /= 2;
        } else {
            popup("Non hai abbastanza credito per spinnare la wheel");
        }
        checkWin();
        updatePane();
    }

    public void getWheels() {
        wheels[0] = new Wheel();
        wheels[0].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleWheel(0));
        wheels[1] = new Wheel();
        wheels[1].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleWheel(1));
        wheels[2] = new Wheel();
        wheels[2].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleWheel(2));
    }

    public void getFields() {
        fields[0] = new Text(String.format("Credit %d   ", credit));
        fields[1] = new Text(String.format("Points %d   ", points));
    }

    public void getButtons() {
        buttons[0] = new Button("New Game");
        buttons[0].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleNewGame());
        buttons[1] = new Button("Spin");
        buttons[1].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleSpin());
        buttons[2] = new Button("Pay");
        buttons[2].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handlePay());
    }

    public void handleNewGame() {
        if (credit < 100) {
            popup("Non hai credito sufficiente, inserisci una moneta");
        } else {
            credit -= 100;
            points += 128;
        }
        updatePane();
    }

    public void handleCoin(int coin) {
        // True if coin was valid
        System.out.println(coin);
        if (coins[coin].disable()) {
            System.out.println("True");
            credit += 100;
        }
        updatePane();
    }

    public void getCoins() {
        coins[0] = new Coin();
        coins[0].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleCoin(0));
        coins[1] = new Coin();
        coins[1].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleCoin(1));
        coins[2] = new Coin();
        coins[2].addEventHandler(MouseEvent.MOUSE_CLICKED, mouseEvent -> handleCoin(2));
    }

    void handleSpin() {
        if (points > 0) {
            getWheels();
            points /= 2;
        } else {
            popup("Non hai abbastanza credito");
        }
        updatePane();

    }

    void handlePay() {
        System.out.format("Hai vinto %d euro\n", credit / 100);
        resetGame();
    }

}
