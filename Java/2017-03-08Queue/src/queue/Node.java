package queue;

public class Node {
	private Object value;
	private Node next;

	public Node(Object value, Node next) {
		super();
		this.setValue(value);
		this.next = next;
	}

	public void setNext(Node node) {
		next = node;
	}

	public Node getNext(Node node) {
		return next;
	}

	public Object getValue() {
		return value;
	}

	public void setValue(Object value) {
		this.value = value;
	}
}
