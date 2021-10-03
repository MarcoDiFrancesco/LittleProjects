package university;

public class Student extends Person {

    int id;
    RecordBook recordBook;

    Student(String name, String surname, int id) {
        super(name, surname);
        this.id = id;
        recordBook = new RecordBook();
    }

    @Override
    public String toString() {
        return String.valueOf(this.id);
    }
}
