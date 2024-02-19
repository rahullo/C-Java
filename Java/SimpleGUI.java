

public class SimpleGUI extends Application {

    @Override
    public void start(Stage primaryStage) {
        // Create a Button
        Button btn = new Button();
        btn.setText("Click Me");

        // Set up event handling for the Button
        btn.setOnAction(event -> System.out.println("Button clicked"));

        // Create a layout and add the Button to it
        StackPane root = new StackPane();
        root.getChildren().add(btn);

        // Create a Scene and set it on the Stage
        Scene scene = new Scene(root, 300, 250);
        primaryStage.setScene(scene);

        // Set the title of the Stage and show it
        primaryStage.setTitle("Simple JavaFX Application");
        primaryStage.show();
    }

    public static void main(String[] args) {
        // Launch the application
        launch(args);
    }
}

