interface DispositivoElectrico {
    void mostrarInfo();
}

class Televisor implements DispositivoElectrico {
    private final String marca;
    private final int pulgadas;

    public Televisor(String marca, int pulgadas) {
        this.marca = marca;
        this.pulgadas = pulgadas;
    }

    @Override
    public void mostrarInfo() {
        System.out.println("Televisor [Marca: " + marca + ", Pulgadas: " + pulgadas + "\"]");
    }
}

class AireAcondicionado implements DispositivoElectrico {
    private final String modelo;
    private final int btu;

    public AireAcondicionado(String modelo, int btu) {
        this.modelo = modelo;
        this.btu = btu;
    }

    @Override
    public void mostrarInfo() {
        System.out.println("Aire Acondicionado [Modelo: " + modelo + ", BTU: " + btu + "]");
    }
}

public class Main {
    public static void main(String[] args) {
        DispositivoElectrico[] misDispositivos = new DispositivoElectrico[2];

        misDispositivos[0] = new Televisor("Samsung", 55);
        misDispositivos[1] = new AireAcondicionado("LG", 12000);

        System.out.println("--- Lista de Dispositivos ---");
        for (DispositivoElectrico dispositivo : misDispositivos) {
            dispositivo.mostrarInfo();
        }
    }
}