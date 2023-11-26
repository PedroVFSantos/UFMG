package DCC.QuintoPeriodo.LP;

/**
 * revisao
 */
class Animal {

  private String nomeAnimal;
  private double pesoAnimal;
  private int idadeAnimal;
}

public Animal(String nomeAnimal, double pesoAnimal, int idadeAnimal){
  this.nomeAnimal = nomeAnimal;
  this.pesoAnimal = pesoAnimal;
  this.idadeAnimal = idadeAnimal;
}

public int getIdadeAnimal(){
  return idadeAnimal;
}

public String getNomeAnimal(){
  return nomeAnimal;
}

public double getPesoAnimal(){
  return pesoAnimal;
}

public void setPesoAnimal(double pesoAnimal){
  this.pesoAnimal = pesoAnimal;
}

class Carnivoro extends Animal {
  public Carnivoro (String nomeAnimal, double pesoAnimal, int idadeAnimal){
    super(nomeAnimal, pesoAnimal, idadeAnimal);
  }

  public void come (Animal animal){
  double novoPeso = getPesoAnimal() = animal.getPeso();
  setPeso(novoPeso);
  }

  class Herbivoro extends Animal {
    public void Herbivoro (String nomeAnimal, double pesoAnimal, getIdadeAnimal){
      super(nomeAnimal, pesoAnimal, idadeAnimal);
    }
    public void come (){

    }
  }
}
