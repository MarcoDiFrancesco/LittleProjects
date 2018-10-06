package classi;

import java.io.Serializable;
import liste.Lista;

public class Phone implements Serializable {
	private static final long serialVersionUID = 1L;
	private Lista contatti = new Lista();

	public Phone() {

	}

	public Lista getContatti() {
		return contatti;
	}

	public void setContatti(Lista contatti) {
		this.contatti = contatti;
	}
}
