package ex2;

import java.util.Scanner;

public class mainù extends Thread{
	public static void main(String[] args) throws InterruptedException {
		ThreadWorker worker = new ThreadWorker();
		System.out.println("delego il mio lavoro al mio lavoratore");
		worker.sleep(1);

		Scanner sc = new Scanner(System.in);

		while(true){
			System.out.println("1 per chiedere lo stato del lavoro");
			System.out.println("2 per terminare");
			String input = sc.next();
			if(input.equals("1")){
				System.out.println(worker.getWorkToDo());
			}else if(input.equals("2"))
				worker.stopThread();
			break;
		}
		sc.close();
	}


}

