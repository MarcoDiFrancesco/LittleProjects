package university;

public class RecordBook {

  // assuming max number of exam of a student is 100

  private Exam[] exam = new Exam[100];
  int counterExam = 0;
  float average = 0;

  public void addExam(Exam examToAdd) {
    exam[counterExam] = examToAdd;
    counterExam++;
    calculateAverage();
  }

  private void calculateAverage() {
    float sum = 0;
    for (int i = 0; i < counterExam; i++) {
      sum += exam[i].mark;
    }
    // set new calculated average
    average = sum / (float) counterExam;
  }
  
  
}
