package proveFile;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;

public class Main {
	public static void main(String[] args) {
		scriviFileInJava8();
	}

	// questo metodo serve per leggere file
	// con la scrittura di java 8
	// commento in più doppio triplo quadruplo
	
	@SuppressWarnings("unused")
	private static void leggiFileInJava8() {
		Charset c = Charset.forName("UTF-8");
		Path file = Paths.get("src/proveFile/file.txt");

		try (BufferedReader bufferedReader = Files.newBufferedReader(file, c)) {
			String s = null;
			while ((s = bufferedReader.readLine()) != null) {
				System.out.println(s);
			}
		} catch (FileNotFoundException e) {
			System.err.println(e.getMessage());
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}

	private static void scriviFileInJava8() {
		Charset c = Charset.forName("UTF-8");
		Path file = Paths.get("src/proveFile/lettura.txt");

		FileWriter w;
		try {
			w = new FileWriter("src/proveFile/scrittura.txt");
			w.write("abcd\nefghi");
			w.flush();
		} catch (IOException e1) {
			e1.printStackTrace();
		}

		try (BufferedReader bufferedReader = Files.newBufferedReader(file, c)) {
			String s = null;
			while ((s = bufferedReader.readLine()) != null) {
				System.out.println(s);
			}
		} catch (FileNotFoundException e) {
			System.err.println(e.getMessage());
		} catch (IOException e) {
			System.err.println(e.getMessage());
		}
	}
}
