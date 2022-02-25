public class Henkilo {
    private String mNimi;
    private int mIka;
    private Osoite mOsoite;

    public Henkilo(String aNimi, int aIka){
        mNimi = aNimi;
        mIka = aIka;
    }
    public Henkilo(String aNimi, int aIka,Osoite aOsoite) {
        mNimi = aNimi;
        mIka = aIka;
        mOsoite = aOsoite;
    }

    public void tulostaTiedot(){

        System.out.println("Nimi: "+mNimi);
        System.out.println("Ika: " + mIka);
        mOsoite.tulostaTiedot();

    }
    public String getNimi() {
        return mNimi;
    }
    public int getIka() {
        return mIka;
    }
    public Osoite getmOsoite() {
        return mOsoite;
    }

    public void setmNimi(String aNimi) {
        mNimi = aNimi;
    }

    public void setIka(int aIka) {
        mIka = aIka;
    }
    public void setmOsoite(Osoite aOsoite) {
        mOsoite = aOsoite;
    }
}
