package university;

public class University {
  public static void main(String[] args) {
    University university = new University();
  }
  
  public University(){
    Student student1 = new Student("Marco","Di Francesco",202351);
    Exam exam1 = new Exam("Geometry",20);
    Exam exam2 = new Exam("Math",30);
    
    student1.recordBook.addExam(exam1);
    student1.recordBook.addExam(exam2);
    student1.recordBook.addExam(new Exam("Physics",30));
    
    System.out.println(student1.recordBook.average);
  }
}
