package client.start;


import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;


public class Start extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        Parent root = FXMLLoader.load(getClass().getResource("../fxml/authorization.fxml"));
        primaryStage.setTitle("authorization");
        primaryStage.setScene(new Scene(root, 300, 150));
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
