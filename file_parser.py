from collections import deque

# python refactor

class File_Parser:
  balance = deque()

  # Checks to see if there is an bracket or paranthesis, the adds/removes from the stack as necessary.
  def update_balance(file_string: str) -> None:
    i = 0
    while i != file_string.length():
      # Find a front brace and put it on the stack
      if file_string[i] == '{' or file_string[i] == '(':
        balance.push(file_string[i])
      
      # Match end brace with proper front brace
      # If properly matched remove the front brace from the stack
      elif file_string[i] == '}' or file_string[i] == ')':
        if balance.top() == '{' and file_string[i] == '}' or balance.top() == '(' and file_string[i] == ')':
          balance.pop()
        else:
          break

      i += 1

# Parse inside of country block into tag files
  def makeTagFiles(game_file: str, file_string: str) -> None;
    str tag_filename
    
void makeTagFiles(ifstream& gameFile, string line, stack<char>& balance)
  string tagFileName
  ofstream tagFile

  regex tagFileNameRegex("^\\s*([A-Za-z0-9]3)=\\$")
  smatch match

  if(gameFile.is_open())
    while(!balance.empty() and getline(gameFile,line))
      # Already writing to a tag file?
      if(tagFile.is_open())
        tagFile << line << endl
      
      # Is a new tag starting?
      else if(regex_match(line, match, tagFileNameRegex))
        # Check that no file is currently being worked on and
        # the country code block is being read
        if(tagFile.is_open() == false)
          tagFileName = "Countries/" + match[1].str() + ".txt"
          tagFile.open(tagFileName)
          tagFile << line << endl
        
      

      # Update bracket stack
      updateBalance(line, balance)

      # Ends a tagFile when true
      # Stack size 1 = not in a tag file and in country block
      if(balance.size() == 1)
        tagFile.close()
       else if(balance.empty())
        break
      
    
  


# Fix stuff below

void updatePlayerArray(ifstream& gameFile, string line, stack<char>& balance)
  regex tagName("^\\s*\"([A-Za-z]3)\"$")
  smatch match

  while(!balance.empty() and getline(gameFile,line))
    if(regex_match(line, match, tagName))
      playerArray[playerArrayCounter] = match[1].str()
      playerArrayCounter++
    

    updateBalance(line, balance)
  


void updateInstitutionPenalties(ifstream& tagFile, string line, stack<char>& balance)
  regex malusValue("([0-9]+.[0-9]3)")
  smatch match

  if(tagFile.is_open())
    # gets institution penalties index
    getline(tagFile, line)
    trim_inplace(line)
    updateBalance(line, balance)

    for(int i = 0 i < 7 i++)
      regex_search(line, match, malusValue)
      institutionMalus[i] = stod(match[1].str())
      line = match.suffix().str()
    

    # gets final bracket
    getline(tagFile, line)
    updateBalance(line, balance)
  


void parseGameFile(string saveFile)
  string line
  ifstream gameFile

  string playerNations = "players_countries="
  string tagBlockStart = "countries="
  string institutionPenalties = "institutions_penalties="

  # Stack to keep paranthesis balanced
  stack<char> balance

  gameFile.open(saveFile)
  if(gameFile.is_open())
    while(getline(gameFile,line))
      trim_inplace(line)
      # Update bracket stack
      updateBalance(line, balance)

      # Gets players for the game
      if (line.compare(playerNations) == 0)
        updatePlayerArray(gameFile, line, balance)
      
      # Is "country" block being entered
      else if(line.compare(tagBlockStart) == 0)
        makeTagFiles(gameFile, line, balance)
      
      # set current institution tech penalties
      else if(line.compare(institutionPenalties) == 0)
        updateInstitutionPenalties(gameFile, line, balance)
      
    
  
  gameFile.close()


void updateCountryTech(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance)
  regex techLevels("\\s*(adm|mil|dip)_tech=([1-9]+)")
  smatch match

  if(tagFile.is_open())
    while(balance.size() > 1 and getline(tagFile, line))
      if(regex_match(line, match, techLevels))
        if(match[1].str().compare("adm") == 0)
          countriesArray[arrPlacement].setAdminTech(stoi(match[2].str()))
         else if(match[1].str().compare("dip") == 0)
          countriesArray[arrPlacement].setDiploTech(stoi(match[2].str()))
         else if(match[1].str().compare("mil") == 0)
          countriesArray[arrPlacement].setMilTech(stoi(match[2].str()))
        
      

      updateBalance(line, balance)
    
  


void updateCountryIncome(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance)
  double incomeArray[16]

  string yearlyIncome = "income="
  string lastMonthIncome = "lastmonthincometable="
  regex incomeValue("([0-9]+\\.[0-9]3)")
  smatch match

  if(tagFile.is_open())
    while(balance.size() > 1 and getline(tagFile, line))
      trim_inplace(line)
      if(line.compare(lastMonthIncome) == 0)

        # push the income= bracket onto the stack
        updateBalance(line, balance)

        # pulls the income lists
        getline(tagFile, line)

        for(int i = 0 i < 16 i++)
          regex_search(line, match, incomeValue)
          incomeArray[i] = stod(match[1].str())
          line = match.suffix().str()
        

        countriesArray[arrPlacement].setTax(incomeArray[0])
        countriesArray[arrPlacement].setProduction(incomeArray[1])
        countriesArray[arrPlacement].setTrade(incomeArray[2])
        countriesArray[arrPlacement].setGold(incomeArray[3])
        countriesArray[arrPlacement].setTariff(incomeArray[4])
        countriesArray[arrPlacement].setVassalIncome(incomeArray[5])
        countriesArray[arrPlacement].setHarborFees(incomeArray[6])
        countriesArray[arrPlacement].setSubsidies(incomeArray[7])
        countriesArray[arrPlacement].setWarReparation(incomeArray[8])
        countriesArray[arrPlacement].setSpoilsOfWar(incomeArray[9])
        countriesArray[arrPlacement].setCondottieriIncome(incomeArray[10])
      

      updateBalance(line, balance)
    
  


void updateCountryScoreRank(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance)
  double scoreRatingArray[3]

  regex scoreValue("([0-9]+\\.[0-9]3)")
  smatch match

  if(tagFile.is_open())
    # pulls the score list
    getline(tagFile, line)

    for(int i = 0 i < 3 i++)
      regex_search(line, match, scoreValue)
      scoreRatingArray[i] = stod(match[1].str())
      line = match.suffix().str()
    

    countriesArray[arrPlacement].setAdminRating(scoreRatingArray[0])
    countriesArray[arrPlacement].setDiploRating(scoreRatingArray[1])
    countriesArray[arrPlacement].setMilRating(scoreRatingArray[2])
  


void updateCountryRegiment(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance)
  string armyType
  bool foundType = false

  regex unitType("\\s*type=\"(.*)\"")
  regex unitStrength("\\s*strength=([0|1]\\.[0-9]3)")
  smatch match

  if(tagFile.is_open())
    while(balance.size() > 2 and getline(tagFile, line))
      if(regex_match(line, match, unitType))
        for(int i = 0 i < landUnitArraySize i++)

          # Infantry is index 0-147
          # Calvary is index 148-251
          # Artillery is index 252-263, as of patch 1.17.x
          if(match[1].str().compare(landUnitArray[i]) == 0 and i < 148)
            armyType = "infantry"
            foundType = true
            break
           else if(match[1].str().compare(landUnitArray[i]) == 0 and i >= 148 and i < 252)
            armyType = "cavalry"
            foundType = true
            break
           else if(match[1].str().compare(landUnitArray[i]) == 0 and i >= 252)
            armyType= "artillery"
            foundType = true
            break
          
        
       else if(regex_match(line, match, unitStrength) and foundType == true)
        countriesArray[arrPlacement].armyCounter(armyType, stod(match[1].str()))
      

      updateBalance(line, balance)
    
  


void updateCountryArmy(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance)
  string regiment = "regiment="

  if(tagFile.is_open())
    while(balance.size() > 1 and getline(tagFile, line))
      trim_inplace(line)
      updateBalance(line, balance)
      if(line.compare(regiment) == 0)
        updateCountryRegiment(tagFile, line, arrPlacement, balance)
      
    
  


void updateCountryShipType(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance)
  string shipType
  bool foundType = false

  regex unitType("\\s*type=\"(.*)\"")
  smatch match

  if(tagFile.is_open())
    while(balance.size() > 2 and getline(tagFile, line))
      if(regex_match(line, match, unitType))
        for(int i = 0 i < navalUnitArraySize i++)

          # bigShips is 0-5
          # lightShips is 6-11
          # Galley 12-17
          # Transports 18-23, as of patch 1.17.x
          if(match[1].str().compare(navalUnitArray[i]) == 0 and i < 6)
            shipType = "bigShip"
            foundType = true
            break
           else if(match[1].str().compare(navalUnitArray[i]) == 0 and i >= 6 and i < 12)
            shipType = "lightShip"
            foundType = true
            break
           else if(match[1].str().compare(navalUnitArray[i]) == 0 and i >= 12 and i < 19)
            shipType= "galley"
            foundType = true
            break
           else if(match[1].str().compare(navalUnitArray[i]) == 0 and i >= 18)
            shipType= "transport"
            foundType = true
            break
          
        
      

      updateBalance(line, balance)
    
  
  countriesArray[arrPlacement].navyCounter(shipType)


void updateCountryNavy(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance)
  string ship = "ship="

  if(tagFile.is_open())
    while(balance.size() > 1 and getline(tagFile, line))
      trim_inplace(line)
      updateBalance(line, balance)
      if(line.compare(ship) == 0)
        updateCountryShipType(tagFile, line, arrPlacement, balance)
      
    
  


void updateCountrySubject(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance)
  regex tag("\"([A-Z]3)\"")
  smatch match

  if(tagFile.is_open())
    while(balance.size() > 1 and getline(tagFile, line))
      trim_inplace(line)
      updateBalance(line, balance)
      if(regex_match(line, match, tag))
        countriesArray[arrPlacement].addSubject(match[1].str())
        countryUpdate(match[1].str(), countriesArrayCounter)
        # countriesArrayCounter++
        # quicksort(countriesArray, 0, countriesArrayCounter-1, countriesArrayCounter-1)
      
    
  


void updateCountrySubjectValues(int arrPlacement)
  double infantry = 0
  double cavalry = 0
  double artillery = 0
  int bigShip = 0
  int lightShip = 0
  int galley = 0
  int transport = 0

  # Subject for loop, i = subject value
  for(int i = 0 i < countriesArray[arrPlacement].getSubjectArrayCount() i ++)
    # Country for loop, j = country value. Looking for the subject's object
    for(int j = 0 j < countriesArrayCounter j ++)
      if(countriesArray[j].getName().compare(countriesArray[arrPlacement].getSubjectName(i)) == 0)
        infantry += countriesArray[j].getInfantry()
        cavalry += countriesArray[j].getCavalry()
        artillery += countriesArray[j].getArtillery()
        bigShip += countriesArray[j].getBigShip()
        lightShip += countriesArray[j].getLightShip()
        galley += countriesArray[j].getGalley()
        transport += countriesArray[j].getTransport()
        break
      
    
  

  countriesArray[arrPlacement].setSubjectArmy(infantry, "infantry")
  countriesArray[arrPlacement].setSubjectArmy(cavalry, "cavalry")
  countriesArray[arrPlacement].setSubjectArmy(artillery, "artillery")
  countriesArray[arrPlacement].setSubjectNavy(bigShip, "bigShip")
  countriesArray[arrPlacement].setSubjectNavy(lightShip, "lightShip")
  countriesArray[arrPlacement].setSubjectNavy(galley, "galley")
  countriesArray[arrPlacement].setSubjectNavy(transport, "transport")


void updateCountryDevelopment(ifstream& tagFile, int dev, int arrPlacement, stack<char>& balance)
  countriesArray[arrPlacement].setDevelopment(dev)


void updateCountryGPStatus(ifstream& tagFile, double gpScore, int arrPlacement, stack<char>& balance)
  countriesArray[arrPlacement].setGreatPowerScore(gpScore)


void updateCountryInstitution(ifstream& tagFile, string line, int arrPlacement, stack<char>& balance)
  regex embracedValue("([0-9])")
  smatch match

  if(tagFile.is_open())
    # gets institution numbers
    getline(tagFile, line)
    trim_inplace(line)
    updateBalance(line, balance)

    for(int i = 0 i < 7 i++)
      regex_search(line, match, embracedValue)
      countriesArray[arrPlacement].setEmbracedInstitutions(stoi(match[1].str()), i)
      line = match.suffix().str()
    
    # pulls final bracket
    getline(tagFile, line)
    updateBalance(line, balance)
  


# Country initializers
# Input tag must be a .txt
void countryUpdate(string tag, int arrPlacement)
  string file = "Countries/" + tag + ".txt"
  string line
  ifstream tagFile

  string::size_type sz
  string technology = "technology="
  string ledgerIncome = "ledger="
  string scoreRank = "score_rating="
  string army = "army="
  string navy = "navy="
  string subject = "subjects="
  string institution = "institutions="

  regex development ("\\s*raw_development=([0-9]+)\\.[0-9]3")
  regex maxManpower ("\\s*max_manpower=([0-9]+\\.[0-9]3)")
  regex maxSailor ("\\s*max_sailors=([0-9]+\\.[0-9]3)")
  regex score ("\\s*score=([0-9]+\\.[0-9]3)")
  regex cardScore ("\\s*card_score=([0-9]+\\.[0-9]3)")
  regex gpStatus("\\s*great_power_score=([0-9]+\\.[0-9]3)")
  smatch match

  # Stack to keep paranthesis balanced
  stack<char> balance

  countriesArray[arrPlacement].setName(tag.substr(0,3))
  countriesArrayCounter++

  tagFile.open(file)
  if(tagFile.is_open())
    while(getline(tagFile, line))

      trim_inplace(line)

      # this updateBalance will catch any matching statements bracket
      # Do not add the bracket within the secondary function also
      updateBalance(line, balance)

      if(line.compare(technology) == 0)
        updateCountryTech(tagFile, line, arrPlacement, balance)
       else if(regex_match(line, match, development))
        updateCountryDevelopment(tagFile, stoi(match[1].str()), arrPlacement, balance)
       else if(regex_match(line, match, maxManpower))
        countriesArray[arrPlacement].setMaxManpower(stod(match[1].str()))
       else if(regex_match(line, match, maxSailor))
        countriesArray[arrPlacement].setMaxSailor(stod(match[1].str()))
       else if(line.compare(ledgerIncome) == 0)
        updateCountryIncome(tagFile, line, arrPlacement, balance)
       else if(regex_match(line, match, score))
        countriesArray[arrPlacement].setScoreTotal(stod(match[1].str()))
       else if(line.compare(scoreRank) == 0)
        updateCountryScoreRank(tagFile, line, arrPlacement, balance)
       else if(line.compare(army) == 0)
        updateCountryArmy(tagFile, line, arrPlacement, balance)
       else if(line.compare(subject) == 0)
        # Updates a tag's subject array and creates the subjects object.
        updateCountrySubject(tagFile, line, arrPlacement, balance)
        updateCountrySubjectValues(arrPlacement)
        arrPlacement = binarySearch(countriesArray, 0, countriesArrayCounter-1, tag)
       else if(line.compare(navy) == 0)
        updateCountryNavy(tagFile, line, arrPlacement, balance)
       else if(regex_match(line, match, gpStatus))
         updateCountryGPStatus(tagFile, stod(match[1].str()), arrPlacement, balance)
       else if(regex_match(line, match, cardScore))
         countriesArray[arrPlacement].setCardScore(stod(match[1].str()))
       else if(line.compare(institution) == 0)
        updateCountryInstitution(tagFile, line, arrPlacement, balance)
      
    
  
  tagFile.close()

  # Sort newly create object into proper place in the array
  quicksort(countriesArray, 0, countriesArrayCounter-1, countriesArrayCounter-1)


void fillCountryData()
  # countriesArrayCounter = playerArrayCounter
  for(int i = 0 i < playerArrayCounter i++)
    countryUpdate(playerArray[i], countriesArrayCounter)
  
