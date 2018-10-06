package benzinaio;

public class Benzinaio {
	private float soldi = 0; // i soldi iniziali in cassa sono 0 euro
	private float costoBenzinaStandard; // costo in euro della benzina per litro
	private float costoBenzinaAumentato;
	private float serbatoio; // litri benzina nel serbatoio
	private float soldiInseriti;
	private float litriInseriti;
	private String psw;

	// -----------------------------------------------------------------------------

	public float getSoldi() {
		return soldi;
	}

	public void setSoldi(float soldi) {
		this.soldi = soldi;
	}

	public float getCostoBenzinaStandard() {
		return costoBenzinaStandard;
	}

	public void setCostoBenzinaStandard(float costoBenzinaStandard) {
		this.costoBenzinaStandard = costoBenzinaStandard;
	}

	public float getSerbatoio() {
		return serbatoio;
	}

	public void setSerbatoio(float serbatoio) {
		this.serbatoio = serbatoio;
	}

	public float getCostoBenzinaAumentato() {
		return costoBenzinaAumentato;
	}

	public void setCostoBenzinaAumentato(float costoBenzinaAumentato) {
		this.costoBenzinaAumentato = costoBenzinaAumentato;
	}

	public String getPassword() {
		return psw;
	}

	public void setPassword(String password) {
		this.psw = password;
	}

	public float getSoldiInseriti() {
		return soldiInseriti;
	}

	public void setSoldiInseriti(float soldiInseriti) {
		this.soldiInseriti = soldiInseriti;
	}

	public float getLitriInseriti() {
		return litriInseriti;
	}

	public void setLitriInseriti(float litriInseriti) {
		this.litriInseriti = litriInseriti;
	}

	// -----------------------------------------------------------------------------

	public void disponibilitaBenzina(float serbatoio, float litriRichiesti) {
		if (serbatoio >= litriRichiesti) {
			serbatoio = serbatoio - litriRichiesti; // ho abbastanza benzina
		} else {
			// non ho abbastanza benzina
		}
	}

	public void costoRifornimento(float serbatoio, float litriRichiesti, float costoBenzinaAumentato,
			float costoBenzinaStandard, float soldiRichiesti) {
		if (serbatoio > 50) {
			soldiRichiesti = litriRichiesti * costoBenzinaStandard;
		} else {
			soldiRichiesti = litriRichiesti * costoBenzinaAumentato;
		}
	}

	public void controlloPassword(String password) {
		if (password.equals(password)) {
			// password corretta
		}
	}

	public void quantitaBenzinaDaErogare(float soldiInseriti) {

	}

}