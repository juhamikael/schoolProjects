public class Osoite{
    private String mKatuosoite;
    private String mPostinumero;
    private String mKunta;

    private Opiskelija a = new Opiskelija();

    public Osoite(){
        mKatuosoite = "N/A";
        mPostinumero = "N/A";
        mKunta = "N/A";
    }
    public Osoite(String aKatuosoite, String aPostinumero, String aKunta){
        mKatuosoite=aKatuosoite;
        mPostinumero = aPostinumero;
        mKunta = aKunta;
    }


    public void setKatuosoite(String aKatuosoite){
        mKatuosoite = aKatuosoite;
    }
    public void setPostinumero(String aPostinumero){
        mPostinumero = aPostinumero;
    }
    public void setKunta(String aKunta){
        mKunta = aKunta;
    }
    public String getKatuosoite(){
        return mKatuosoite;
    }

    public String getPostinumero(){
        return mPostinumero;
    }
    public String getKunta(){
        return mKunta;
    }

    public void tulostaTiedot(){
        System.out.println("OSOITETIEDOT");
        System.out.println(getKatuosoite());
        System.out.println(getPostinumero() + " " + getKunta());
        System.out.println();
    }
}
