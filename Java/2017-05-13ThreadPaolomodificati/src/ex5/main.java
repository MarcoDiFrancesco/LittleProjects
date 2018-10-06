package ex5;

public class main extends Thread{
	public static void main(String[] args) {
		double[] array = new double [100030];
		for (int i = 0; i < array.length; i++) {
			
			array[i]= (int)( Math.random()*250);
		}

		Exchange a = new Exchange(array);
		Bubble a1 = new Bubble(array);
		Sort a2 = new Sort(array);
		a.start();
		a1.start();
		a2.start();
	}




}
