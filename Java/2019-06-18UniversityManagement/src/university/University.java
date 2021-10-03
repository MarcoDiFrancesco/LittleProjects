package university;

import java.util.ArrayList;
import java.util.List;

public class University {

    List<Student> students;

    public static void main(String[] args) {
        Student student = new Student("Marco", "Di Francesco", 202351);
        List<Student> students = new ArrayList<>();
        students.add(student);
        University university = new University(students);
        Exam exam1 = new Exam("Geometry", 20);
        Exam exam2 = new Exam("Math", 30);
        student.recordBook.addExam(exam1);
        student.recordBook.addExam(exam2);
        System.out.println();
        for (Student s : students) {
            System.err.println(s);
        }
    }

    public University(List<Student> students) {
        this.students = students;
    }
    
    public University() {
        this.students = new ArrayList<>();
    }
}
