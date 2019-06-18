package person;

public class Student extends Person {

  int id = 0;
  RecordBook recordBook = new RecordBook();
  
  Student(String name, String surname, int id) {
    super(name, surname);
    this.id = id;
  }
  
}
