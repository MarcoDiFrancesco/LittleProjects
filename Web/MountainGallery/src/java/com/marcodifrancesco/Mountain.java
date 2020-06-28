package com.marcodifrancesco;

public class Mountain {

    String id;
    String name;
    String height;
    String desctiption;

    public Mountain(String id, String name, String height, String desctiption) {
        this.id = id;
        this.name = name;
        this.height = height;
        this.desctiption = desctiption;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getHeight() {
        return height;
    }

    public void setHeight(String height) {
        this.height = height;
    }

    public String getDesctiption() {
        return desctiption;
    }

    public void setDesctiption(String desctiption) {
        this.desctiption = desctiption;
    }

    public String getInsertSql() {
        return "INSERT INTO NAME.MOUNTAIN (ID, NAME, HEIGHT, DESCRIPTION) "
                + "VALUES(" + this.getId() + ","
                + "'" + this.getName() + "',"
                + this.getHeight() + ","
                + "'" + this.getDesctiption() + "'"
                + ")";
    }

    public String getJson() {
        String output = "{";
        output += String.format("\"%s\": \"%s\",", "ID", this.id);
        output += String.format("\"%s\": \"%s\",", "Name", this.name);
        output += String.format("\"%s\": \"%s\",", "Height", this.height);
        output += String.format("\"%s\": \"%s\"", "Description", this.desctiption);
        output += "}";
        return output;
    }
}
