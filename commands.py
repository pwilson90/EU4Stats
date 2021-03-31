void printCountry( ofstream& output, int index){
  if(output.is_open()){
    output << "Name: " << countriesArray[index].getName() << endl;
    output << "Administration Rating: " << countriesArray[index].getAdminRating() << endl;
    output << "Diplomatic Rating: " << countriesArray[index].getDiploRating() << endl;
    output << "Military Rating: " << countriesArray[index].getMilRating() << endl;
    output << "Card Total: " << countriesArray[index].getCardScore() << endl;
    output << "Score Total: " << countriesArray[index].getScoreTotal() << endl << endl;

    output << "Taxation Income: " << countriesArray[index].getTax() << endl;
    output << "Production Income: " << countriesArray[index].getProduction() << endl;
    output << "Trade Income: " << countriesArray[index].getTrade() << endl;
    output << "Gold Income: " << countriesArray[index].getGold() << endl;
    output << "Tariff Income: " << countriesArray[index].getTariff() << endl;
    output << "Vassal Income: " << countriesArray[index].getVassalIncome() << endl;
    output << "Harbor Fees Income: " << countriesArray[index].getHarborFees() << endl;
    output << "Subsidies Income: " << countriesArray[index].getSubsidies() << endl;
    output << "War Reparations Income: " << countriesArray[index].getWarReparation() << endl;
    output << "Spoils of War Income: " << countriesArray[index].getSpoilsOfWar() << endl;
    output << "Condottieri Income: " << countriesArray[index].getCondottieriIncome() << endl;
    output << "Total Income: " << countriesArray[index].incomeTotal() << endl << endl;

    output << "Adm Tech: " << countriesArray[index].getAdminTech() << endl;
    output << "Dip Tech: " << countriesArray[index].getDiploTech() << endl;
    output << "Mil Tech: " << countriesArray[index].getMilTech() << endl;
    output << "Tech Total: " << countriesArray[index].techTotal() << endl;
    countriesArray[index].printInstitutions(output);
    output << endl;

    output << "Infantry Amount: " << countriesArray[index].getInfantry() << endl;
    output << "Cavalry Amount: " << countriesArray[index].getCavalry() << endl;
    output << "Artillery Amount: " << countriesArray[index].getArtillery() << endl;
    output << "Subject Infantry: " << countriesArray[index].getSubjectArmy("infantry") << endl;
    output << "Subject Cavalry: " << countriesArray[index].getSubjectArmy("cavalry") << endl;
    output << "Subject Artillery: " << countriesArray[index].getSubjectArmy("artillery") << endl;
    output << "Army Strength Total: " << countriesArray[index].armyStrengthTotal() << endl;
    output << "Subject Army Total: " << countriesArray[index].getSubjectArmyTotal() << endl;
    output << "Max Manpower: " << countriesArray[index].getMaxManpower() << endl << endl;

    output << "Heavy Ship Amount: " << countriesArray[index].getBigShip() << endl;
    output << "Light Ship Amount: " << countriesArray[index].getLightShip() << endl;
    output << "Galley Amount: " << countriesArray[index].getGalley() << endl;
    output << "Transport Amount: " << countriesArray[index].getTransport() << endl;
    output << "Subject Heavy Ships: " << countriesArray[index].getSubjectNavy("bigShip") << endl;
    output << "Subject Light Ships: " << countriesArray[index].getSubjectNavy("lightShip") << endl;
    output << "Subject Galleys: " << countriesArray[index].getSubjectNavy("galley") << endl;
    output << "Subject Transports: " << countriesArray[index].getSubjectNavy("transport") << endl;
    output << "Naval Strength Total: " << countriesArray[index].navyTotal() << endl;
    output << "Subject Navy Total: " << countriesArray[index].getSubjectNavalTotal() << endl;
    output << "Max Sailor: " << countriesArray[index].getMaxSailor() << endl << endl;

    output << "Development: " << countriesArray[index].getDevelopment() << endl;
    output << "Great Power Score: " << countriesArray[index].getGreatPowerScore() << endl << endl;

    output << countriesArray[index].getName() << " subjects: " << endl;
    countriesArray[index].printSubjects(output);
    output << endl << endl;
  }
}

void printSpecifiedCountry(string tag){
  int index = binarySearch(countriesArray, 0, countriesArrayCounter-1, tag);
  ofstream output;

  //If the tag object is not yet made make it.
  if(index == -1){
    countryUpdate(tag, countriesArrayCounter);
    int index = binarySearch(countriesArray, 0, countriesArrayCounter-1, tag);
  }
  output.open("TestData/specifiedOutput.txt");
  if(output.is_open()){
    printCountry(output, index);
  }
  output.close();
}

//Prints out all country object information
void printAllCountries(){
  ofstream output;
  output.open("TestData/output.txt");
  if(output.is_open()){
    for(int i = 0; i < countriesArrayCounter; i ++){
      printCountry(output, i);
    }
  }
  output.close();
}

//for Testing, prints out Array of players
void printPlayers(){
  for(int i = 0; i < playerArrayCounter; i++){
    cout << "Player " << i << " is " << playerArray[i] << endl;
  }
}

void printInsitutionPenalties(){
  cout << "Institution Penalties: ";
  for(int i = 0; i < 7; i++){
    cout << institutionMalus[i] << " ";
  }
  cout << endl << endl;
}

void printCountriesArrayOrder(){
  cout << "Country order: ";
  for(int i = 0; i < countriesArrayCounter; i++){
    cout << countriesArray[i].getName() << " ";
  }
  cout << endl;
}