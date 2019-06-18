package person;

public class Person {

  String name = "";
  String surname = "";

  Person(String name, String surname) {
    this.name = name;
    this.surname = surname;
  }

  public static void main(String[] args) {
    Student student1 = new Student("Marco","Di Francesco",202351);
    Exam exam1 = new Exam("Geometry",20);
    Exam exam2 = new Exam("Math",30);
    
    student1.recordBook.addExam(exam1);
    student1.recordBook.addExam(exam2);
    student1.recordBook.addExam(new Exam("Physics",30));
    
    System.out.println(student1.recordBook.calculateAverage());
  }

}
