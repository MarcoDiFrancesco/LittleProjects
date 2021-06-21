package com.marcodifrancesco.numpad;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.input.KeyEvent;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.TilePane;
import javafx.scene.text.Text;
import javafx.stage.Stage;

import java.util.Arrays;


public class Main extends Application {


    @Override
    public void start(Stage primaryStage) {
        MyPane myPane = new MyPane();
        Scene scene = new Scene(myPane, 500, 500);
        primaryStage.setTitle("My Title");
        primaryStage.setScene(scene);
        primaryStage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
