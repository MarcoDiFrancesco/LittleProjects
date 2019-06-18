package person;

public class RecordBook {
  Exam[] exam = new Exam[100];
  
  int counter = 0;
  public void addExam(Exam examToAdd){
    exam[counter] = examToAdd;
    counter++;
  }

  public int calculateAverage(){
    int average = 0;
    for(int i=0; i<counter;i++) {
      average += exam[i].mark;
    }
    return(average/counter);
  }
}
