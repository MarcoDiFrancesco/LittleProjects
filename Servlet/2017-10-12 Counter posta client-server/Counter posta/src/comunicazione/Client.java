package comunicazione;

import java.io.*;
import java.net.*;

public class Client {
	Socket socketDispenser = null;
	int porta = 6666;
	DataInputStream in;
	DataOutputStream out;
	BufferedReader tastiera;

	public void Comunica()// 1b e creiamo una pubblic void comunica
	{
		try {
			for (;;) {
				System.out.println("[2] Messaggio da inviare al server");
				tastiera = new BufferedReader(new InputStreamReader(System.in));
				String stringa = tastiera.readLine();
				System.out.println("[3] Invio ");
				out.writeBytes(stringa + "\n");
				System.out.println("[4] Ricevo la risposta");
				String ricevuta = in.readLine();
				if (ricevuta.equals("exit")) {
					System.out.println("Fine");
					break;
				}
				System.out.println("[5] Totale: " + ricevuta);
			}
		
		
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	public Socket Connetti() {
		try {
			System.out.println("[1] Provo a connettermi al server ");
			Socket socketDispenser = new Socket(InetAddress.getLocalHost(), porta);
			System.out.println("[2] Connesso! ");
			in = new DataInputStream(socketDispenser.getInputStream());
			out = new DataOutputStream(socketDispenser.getOutputStream());
		} catch (UnknownHostException e) {
			System.err.println("Host non trovato ");
		} catch (Exception e) {
			System.err.println("Impossibile stabilire una connessione ");
		}
		return socketDispenser;
	}

	public static void main(String[] args) {
		Client c = new Client();
		c.Connetti();
		c.Comunica();
	}
}
