module com.javafxtest.javafxtest {
    requires javafx.controls;
    requires javafx.fxml;


    opens com.javafxtest.javafxtest to javafx.fxml;
    exports com.javafxtest.javafxtest;
}