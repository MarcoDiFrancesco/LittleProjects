package zaino;

public class Oggetto {
	private String nome;
	private String descrizione;
	public Oggetto(String nome,String descrizione)
	{
		this.nome=nome;
		this.descrizione=descrizione;
	}
	public Oggetto(Oggetto o)
	{
		nome=o.nome;
		descrizione=o.descrizione;
	}
	
	public String getNome()
	{return nome;}
	
	public String getDescrizione()
	{return descrizione;}
	@Override
	
	public String toString() {
		return "Oggetto [nome=" + nome + ", descrizione=" + descrizione + "]";
	}
	
}
