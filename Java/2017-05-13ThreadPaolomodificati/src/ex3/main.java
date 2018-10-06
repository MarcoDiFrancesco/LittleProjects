package ex3;

public class main {
	public static void main(String[] args) {
			String array[] = new String[100];
		
			
			
			Worker w1 = new Worker(0, 49, array);
			Worker w2 = new Worker(50, 99, array);
			w1.start();
			w2.start();
			
			try {
				w1.join();
			} catch (InterruptedException e) {
			}
			try {
				w2.join();
			} catch (InterruptedException e) {
			}
			for(String string:array){
				System.out.println(string);
			}
	}
}
