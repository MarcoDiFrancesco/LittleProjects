package albero2;

import java.util.ArrayList;
import java.util.List;

public class Albero {

	private Nodo root;
	private Nodo max;

	public Albero() {
		root = new Nodo(80);
	}

	private void addNumber(int numero, Nodo p) {
		if (numero > p.getN()) {
			if (p.getMaggiore() != null) {
				addNumber(numero, p.getMaggiore());
			} else {
				Nodo n = new Nodo(numero);
				p.setMaggiore(n);
			}
		} else if (numero < p.getN()) {
			{
				if (p.getMinore() != null) {
					addNumber(numero, p.getMinore());
				} else {
					Nodo n = new Nodo(numero);
					p.setMinore(n);
				}
			}
		}
	}

	public void print() {
		StringBuilder sb = new StringBuilder();
		List<Integer> ints = new ArrayList<>();
		print(root, sb, ints);
		System.out.println(ints);
	}

	private void print(Nodo n, StringBuilder sb, List<Integer> ints) {
		ints.add(n.getN());
		sb.append(n.getN());
		if (n.getMaggiore() != null) {
			print(n.getMaggiore(), sb, ints);
		}
		if (n.getMinore() != null) {
			print(n.getMinore(), sb, ints);
		}
	}

	public Nodo getRoot() {
		return root;
	}

	public void setRoot(Nodo root) {
		this.root = root;
	}

	public void addNumber(int i) {
		addNumber(i, root);

	}

	public Nodo getMax() {
		return max;
	}

	public void setMax(Nodo max) {
		this.max = max;
	}

}
