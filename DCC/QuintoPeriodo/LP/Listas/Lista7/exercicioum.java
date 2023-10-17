class Animal {
    private String nome;
    private double peso;
    private int idade;

    public Animal(String nome, double peso, int idade) {
        this.nome = nome;
        this.peso = peso;
        this.idade = idade;
    }

    public int getIdade() {
        return idade;
    }

    public double getPeso() {
        return peso;
    }

    public void setPeso(double peso) {
        this.peso = peso;
    }

    public String getNome() {
        return nome;
    }
}

class Carnivoro extends Animal {
    public Carnivoro(String nome, double peso, int idade) {
        super(nome, peso, idade);
    }

    public void come(Animal animal) {
        double novoPeso = getPeso() + animal.getPeso();
        setPeso(novoPeso);
    }
}

class Herbivoro extends Animal {
    public Herbivoro(String nome, double peso, int idade) {
        super(nome, peso, idade);
    }

    public void come() {
    }
}

