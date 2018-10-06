package comunicazione;

import java.io.*;
import java.net.*;

public class Client {
	Socket socketDispenser = null;
	int porta = 6666;
	DataInputStream in;
	DataOutputStream out;
	BufferedReader tastiera;

	public void comunica()// 1b e creiamo una pubblic void comunica
	{
		try {
			System.out.println("[2] Messaggio da inviare al server");
			tastiera = new BufferedReader(new InputStreamReader(System.in));
			String n1 = tastiera.readLine();
			tastiera = new BufferedReader(new InputStreamReader(System.in));
			String n2 = tastiera.readLine();
			tastiera = new BufferedReader(new InputStreamReader(System.in));
			String segno = tastiera.readLine();

			if (segno == null) {
				System.err.println("Segno non valido, non invio niente al server");
			} else {
				System.out.println("[3] Invio ");
				out.writeBytes(n1 + "\n");
				out.writeBytes(n2 + "\n");
				out.writeBytes(segno + "\n");
				System.out.println("[4] In attesa di una risposta");
				String ricevuta = in.readLine();
				System.out.println("[5] Totale: " + ricevuta);
			}
			System.out.println("[6] Fine ");
		}

		catch (IOException e) {
			e.printStackTrace();
		}
	}

	public Socket connetti() {
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
		c.connetti();
		c.comunica();
	}
}
