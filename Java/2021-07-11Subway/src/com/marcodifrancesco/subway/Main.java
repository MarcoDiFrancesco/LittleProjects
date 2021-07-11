package com.marcodifrancesco.subway;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Game root = new Game();
        primaryStage.setTitle("Game");
        primaryStage.setScene(new Scene(root, 400, 150));
        primaryStage.show();
        new Palette();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
