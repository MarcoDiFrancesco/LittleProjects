package queue;

public class Queue {
	private Node head;
	private Node tail;
	private int counter = 0;

	public void enqueue(Object value) {
		Node node = new Node(value, null);
		tail.setNext(node);
		tail = node;
		counter++;
	}

	/*
	 * public void dequeue() {
	 * 
	 * head = head.getNext(); counter--; }
	 */
	public int size() {
		return counter;
	}

	public Node getHead() {
		return head;
	}

	public void setHead(Node head) {
		this.head = head;
	}
}
