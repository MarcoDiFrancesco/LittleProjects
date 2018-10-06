package es3;

public class Sort extends Thread{
	private int[] b;
	
	
	
	public Sort(int[] b) {
		super();
		this.b = b;
	}
	@Override
	public void run() {
		int inner, outer;
	    int temp;
	 
	    int h = 1;
	    while (h <= b.length / 3) {
	      h = h * 3 + 1;
	    }
	    while (h > 0) {
	      for (outer = h; outer < b.length; outer++) {
	        temp = b[outer];
	        inner = outer;
	 
	        while (inner > h - 1 && b[inner - h] >= temp) {
	          b[inner] = b[inner - h];
	          inner -= h;
	        }
	        b[inner] = temp;
	      }
	      h = (h - 1) / 3;
	    }
		System.out.println("Sort terminato");
	}
	public int[] getB() {
		return b;
	}
}
