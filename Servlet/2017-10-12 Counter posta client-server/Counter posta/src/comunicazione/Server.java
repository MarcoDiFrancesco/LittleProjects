package comunicazione;

import java.io.*;
import java.net.*;

public class Server {
	ServerSocket server = null;
	Socket socketClient = null;
	int porta = 6666;
	DataInputStream in;
	DataOutputStream out;
	int counter = 0;

	public void Comunica() {
		try {
			for (;;) {
				System.out.println("[3] Aspetto messaggio dal client ");
				String stringa = in.readLine();
				if (stringa.equals("exit")) {
					System.out.println("[6] Chiudo la connessione ");
					out.writeBytes("exit");
					socketClient.close();
					break;
				} else {
					counter++;
					out.writeBytes(counter + "\n");
				}
			}
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
