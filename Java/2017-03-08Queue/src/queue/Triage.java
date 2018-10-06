package queue;

public class Triage {
	private Queue greenQueue = new Queue();
	private Queue yellowQueue = new Queue();
	private Queue redQueue = new Queue();

	/*
	 * public void removePearson() { if (redQueue.size() >= 1) {
	 * redQueue.dequeue(); } else if (yellowQueue.size() >= 1) {
	 * yellowQueue.dequeue(); } else if (greenQueue.size() >= 1) {
	 * greenQueue.dequeue(); } }
	 * 
	 * public void addPatient(Patient patient){
	 * switch(patient.getGravityCode()){ case GREEN;
	 * greenQueue.enqueue(patient); break; case YELLOW;
	 * yellowQueue.enqueue(patient); break; case RED; redQueue.enqueue(patient);
	 * break; } }
	 */
	public Queue getGreenQueue() {
		return greenQueue;
	}

	public void setGreenQueue(Queue greenQueue) {
		this.greenQueue = greenQueue;
	}

	public Queue getYellowQueue() {
		return yellowQueue;
	}

	public void setYellowQueue(Queue yellowQueue) {
		this.yellowQueue = yellowQueue;
	}

	public Queue getRedQueue() {
		return redQueue;
	}

	public void setRedQueue(Queue redQueue) {
		this.redQueue = redQueue;
	}
}
