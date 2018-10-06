package classi;


public class Contact {
	private String firstName;

	private String familyName;

	public Contact(String firstName, String familyName) {
		super();
		this.firstName = firstName;
		this.familyName = familyName;
	}

	public String getFirstName() {
		return firstName;
	}

	public String getFamilyName() {
		return familyName;
	}
}
