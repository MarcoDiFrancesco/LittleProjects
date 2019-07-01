package university;

public class Student extends Person {

  int id = 0;
  RecordBook recordBook;
  
  Student(String name, String surname, int id) {
    super(name, surname);
    this.id = id;
    recordBook = new RecordBook();
  }
  
}
