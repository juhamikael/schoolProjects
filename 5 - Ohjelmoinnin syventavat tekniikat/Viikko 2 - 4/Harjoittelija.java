public class Harjoittelija extends Opiskelija{
    private String mTyopaikka;
    private float mPalkka;

    public Harjoittelija(){
        mTyopaikka = "Tuntematon";
        mPalkka = 0;
    }
    public Harjoittelija(String aNimi, String aOpiskelijaNumero, String aTyopaikka, float aPalkka){
        super(aNimi, aOpiskelijaNumero);
        mTyopaikka = aTyopaikka;
        mPalkka = aPalkka;
        System.out.println("Harjoittelijan 4 parametrinen rakentaja");
    }

    public void setTyopaikka(String aTyopaikka){
        mTyopaikka = aTyopaikka;
    }
    public void setPalkka(float aPalkka){mPalkka = aPalkka;}
    public String getTyopaikka(){return mTyopaikka;}
    public float getPalkka(){return mPalkka;}

    public void tulostaTiedot(){
        System.out.println("Nimi: " + getnimi());
        System.out.println("Opintopisteet: "+ getOpintopisteet());
        System.out.println("Harjoittelupaikka: " + getTyopaikka());
        System.out.println("Palkka: " + getPalkka());
    }

}
