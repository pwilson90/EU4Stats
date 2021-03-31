int main(int argc, char *argv[]){

  string saveFile = "TestData/mp_Ethiopia1493_10_25.eu4";
  parseGameFile(saveFile);

  //Fills country data
  fillCountryData();

  int choice = -1;
  int stop = 0;
  while(choice != stop){
    cout << "1: Print specified country data.\n"
         << "2: Print all countries data\n"
         << "3: Print countries order\n"
         << "4: Print amount of country objects made\n"
         << "5: Print players\n"
         << "6: Print current institution penalties\n"
         << "0: Exit Program\n";
    cin >> choice;
    switch(choice){
      case(1): {
        string tag;
        cout << "What country's information would you like to see?\n";
        cin >> tag;
        cout << "you entered: " << tag << endl;
        printSpecifiedCountry(tag);
        break;
      }
      case(2): {
        cout << "Printing all country data\n";
        //Prints all countries data to file
        printAllCountries();
        break;
      }
      case(3):{
        printCountriesArrayOrder();
        cout << endl;
       break;
      }
      case(4):{
        cout << "countriesArrayCounter: " << countriesArrayCounter << endl;
        break;
      }
      case(5):{
        printPlayers();
        break;
      }
      case(6):{
        printInsitutionPenalties();
        break;
      }
      default: {
        break;
      }
    }
    cout << endl;
  }

  return 0;
}