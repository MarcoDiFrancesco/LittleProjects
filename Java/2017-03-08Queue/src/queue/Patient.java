package queue;

public class Patient {
	private String name;
	private GravityCode gravityCode;

	public Patient(String name, GravityCode gravityCode) {
		super();
		this.setName(name);
		this.gravityCode = gravityCode;
	}

	public GravityCode getGravityCode() {
		return gravityCode;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

}
