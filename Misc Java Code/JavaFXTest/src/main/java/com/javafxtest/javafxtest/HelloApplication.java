package com.javafxtest.javafxtest;

import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.layout.StackPane;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application implements EventHandler<ActionEvent> {

    Button button;

    @Override
    public void start(Stage stage) throws IOException {
        StackPane layout = new StackPane();
        Scene scene = new Scene(layout, 320, 240);


        button = new Button();
        button.setText("Click Me");

        layout.getChildren().add(button);

        stage.setTitle("Hello!");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }

    @Override
    public void handle(ActionEvent actionEvent) {
        
    }
}