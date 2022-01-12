public class Opiskelija {
    // Tietojäsenet alkuun
        private String mNimi;
        private String mOpiskelijaNumero;
        private int mOpintopisteet;

        public Opiskelija(){
            mNimi = "Tuntematon";
            mOpiskelijaNumero = "N/A";
            mOpintopisteet = 0;
        }

        public Opiskelija(String aNimi, String aOpiskelijaNumero){
            mNimi = aNimi;
            mOpiskelijaNumero = aOpiskelijaNumero;
        }

        public void setNimi(String aNimi){
            mNimi = aNimi;
        }

        public void setOpiskelijaNumero(String aOpiskelijaNumero){
            mOpiskelijaNumero = aOpiskelijaNumero;
        }

        public void setOpintopisteet(int aOpintopisteet){
            mOpintopisteet = aOpintopisteet;
        }

        public void tulostaTiedot(){
            System.out.println("Nimi: " + mNimi);
            System.out.println("Opiskelija numero: " + mOpiskelijaNumero);
            System.out.println("Opintopisteet: " + mOpintopisteet);
        }
}
