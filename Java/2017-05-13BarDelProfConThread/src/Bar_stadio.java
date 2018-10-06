import java.util.concurrent.*;

public class Bar_stadio {
	public static void main(String[] args) {
		System.out.println("HELLO!!!!");
		int i;
		Bar M = new Bar();
		ClienteOspite[] CO = new ClienteOspite[50];
		ClienteLocale[] CL = new ClienteLocale[50];
		Barista B = new Barista(M);
		for (i = 0; i < 50; i++) {
			CO[i] = new ClienteOspite(M);
			CL[i] = new ClienteLocale(M);
		}
		for (i = 0; i < 50; i++) {
			CO[i].start();
			CL[i].start();
		}
		B.start();
	}
}