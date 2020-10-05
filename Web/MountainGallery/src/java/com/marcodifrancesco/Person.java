package com.marcodifrancesco;

public class Person {

    String email;
    String password;

    public Person(String email, String password) {
        this.email = email;
        this.password = password;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getSelectSql() {
        return "SELECT * FROM NAME.PEOPLE WHERE EMAIL='" + this.email + "' AND PASSWORD='" + this.password + "'";
    }

    public String getInsertSql() {
        return "INSERT INTO NAME.PEOPLE (EMAIL, PASSWORD) VALUES ('" + this.email + "', '" + this.password + "')";
    }
}
