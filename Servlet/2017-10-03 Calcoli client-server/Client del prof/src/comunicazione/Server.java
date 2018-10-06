package comunicazione;

import java.io.*;
import java.net.*;

public class Server {
	ServerSocket server = null;
	Socket socketClient = null;
	int porta = 6666;
	DataInputStream in;
	DataOutputStream out;
	int tot;

	public void Comunica() {
		try {
			System.out.println("[3] Aspetto messaggio dal client ");
			String stringn1 = in.readLine();
			int n1 = Integer.parseInt(stringn1);
			String stringn2 = in.readLine();
			int n2 = Integer.parseInt(stringn2);
			String s = in.readLine();
			char segno = s.charAt(0);
			System.out.println("[4] Calcolo con i numeri e il segno ricevuto ");
			if (segno == '+')
				tot = n1 + n2;
			else if (segno == '/')
				tot = n1 / n2;
			else if (segno == '-')
				tot = n1 - n2;
			else if (segno == '*')
				tot = n1 * n2;
			else
				System.err.println("Carattere non valido inserito come segno");
			System.out.println("[5] Rispondo con il totale (" + tot + ") ");
			out.writeBytes(tot + "\n");
			System.out.println("[6] Chiudo la connessione ");
			socketClient.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public Socket attendi() {
		try {
			System.out.println("[0] Inizializzo il server ");
			server = new ServerSocket(porta);
			System.out.println("[1] Server pronto in ascolto sulla porta: " + porta);
			socketClient = server.accept();
			System.out.println("[2] Connessione accettata e stabilita con il cliente ");
			server.close();
			in = new DataInputStream(socketClient.getInputStream());
			out = new DataOutputStream(socketClient.getOutputStream());
		} catch (IOException e) {
			e.printStackTrace();
		}
		return socketClient;
	}

	public static void main(String[] args) {
		Server s = new Server();
		s.attendi();
		s.Comunica();
	}
}
