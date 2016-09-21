#include <string>
#include "Country.h"

#include <iostream>
#include <fstream>

//default constructor
Country::Country(){
}

//Constructs with identifying name
Country::Country(std::string tag){
  name = tag;
}

//Getter functions
std::string Country::getName(){
  return name;
}

double Country::getInfantry(){
  return infantry*1000;
}

double Country::getCavalry(){
  return cavalry*1000;
}

double Country::getArtillery(){
  return artillery*1000;
}

int Country::getArmyForceLimit(){
  return armyForceLimit;
}

double Country::getMaxManpower(){
  return maxManpower;
}

int Country::getBigShip(){
  return bigShip;
}

int Country::getLightShip(){
  return lightShip;
}

int Country::getGalley(){
  return galley;
}

int Country::getTransport(){
  return transport;
}

int Country::getNavalForceLimit(){
  return navalForceLimit;
}

double Country::getMaxSailor(){
  return maxSailor;
}

double Country::getAdminRank(){
  return adminRank;
}

double Country::getAdminRating(){
  return adminRating;
}

double Country::getDiploRank(){
  return diploRank;
}

double Country::getDiploRating(){
  return diploRating;
}

double Country::getMilRank(){
  return milRank;
}

double Country::getMilRating(){
  return milRating;
}

double Country::getScoreTotal(){
  return scoreTotal;
}

double Country::getTax(){
  return tax;
}

double Country::getProduction(){
  return production;
}

double Country::getTrade(){
  return trade;
}

double Country::getGold(){
  return gold;
}

double Country::getTariff(){
  return tariff;
}

double Country::getVassalIncome(){
  return vassalIncome;
}

double Country::getHarborFees(){
  return harborFees;
}

double Country::getSubsidies(){
  return subsidies;
}

double Country::getWarReparation(){
  return warReparations;
}

double Country::getSpoilsOfWar(){
  return spoilsOfWar;
}

double Country::getCondottieriIncome(){
  return condottieriIncome;
}

int Country::getAdminTech(){
  return adminTech;
}

int Country::getDiploTech(){
  return diploTech;
}

int Country::getMilTech(){
  return milTech;
}

int Country::getDevelopment(){
  return development;
}

//Setter functions
void Country::setName(std::string tag){
  name = tag;
}

void Country::setArmyForceLimit(int alimit){
  armyForceLimit = alimit;
}

void Country::setMaxManpower(double maxMan){
  maxManpower = maxMan;
}

void Country::setSubjectArmy(double strength, std::string unitType){
  if(unitType.compare("infantry") == 0){
    subjectInfantry += strength;
  } else if(unitType.compare("cavalry") == 0){
    subjectCavalry += strength;
  } else if(unitType.compare("artillery") == 0){
    subjectArtillery += strength;
  }
}

void Country::setNavalForceLimit(int nLimit){
  navalForceLimit = nLimit;
}

void Country::setMaxSailor(double maxSail){
  maxSailor = maxSail;
}

void Country::setSubjectNavy(int strength, std::string unitType){
  if(unitType.compare("bigShip") == 0){
    subjectBigShip += strength;
  } else if(unitType.compare("lightShip") == 0){
    subjectLightShip += strength;
  } else if(unitType.compare("galley") == 0){
    subjectGalley += strength;
  } else if(unitType.compare("transport") == 0){
    subjectTransport += strength;
  }
}

void Country::setAdminRank(double aRank){
  adminRank = aRank;
}

void Country::setAdminRating(double aRating){
  adminRating = aRating;
}

void Country::setDiploRank(double dRank){
  diploRank = dRank;
}

void Country::setDiploRating(double dRating){
  diploRating = dRating;
}

void Country::setMilRank(double mRank){
  milRank = mRank;
}

void Country::setMilRating(double mRating){
  milRating = mRating;
}

void Country::setScoreTotal(double sTotal){
  scoreTotal = sTotal;
}

void Country::setTax(double iTax){
  tax = iTax;
}

void Country::setProduction(double iProduction){
  production = iProduction;
}

void Country::setTrade(double iTrade){
  trade = iTrade;
}

void Country::setGold(double iGold){
  gold = iGold;
}

void Country::setTariff(double iTariff){
  tariff = iTariff;
}

void Country::setVassalIncome(double iVassal){
  vassalIncome = iVassal;
}

void Country::setHarborFees(double iHarbor){
  harborFees = iHarbor;
}

void Country::setSubsidies(double iSubsidies){
  subsidies = iSubsidies;
}

void Country::setWarReparation(double iReparation){
  warReparations = iReparation;
}

void Country::setSpoilsOfWar(double iSpoil){
  spoilsOfWar = iSpoil;
}

void Country::setCondottieriIncome(double iCondottieri){
  condottieriIncome = iCondottieri;
}

void Country::setAdminTech(int aTech){
  adminTech = aTech;
}

void Country::setDiploTech(int dTech){
  diploTech = dTech;
}

void Country::setMilTech(int mtech){
  milTech = mtech;
}

void Country::setDevelopment(int devel){
  development = devel;
}

//Total functions
double Country::armyStrengthTotal(){
  return (infantry+cavalry+artillery)*1000;
}

int Country::navyTotal(){
  return bigShip+lightShip+galley+transport;
}

double Country::scoreRatingTotal(){
  return adminRating+diploRating+milRating;
}

double Country::incomeTotal(){
  return tax+production+trade+gold+tariff+harborFees+subsidies+warReparations+spoilsOfWar+condottieriIncome;
}

int Country::techTotal(){
  return adminTech+diploTech+milTech;
}

//Increase respective unit count
void Country::armyCounter(std::string unitType, double aStrength){
  if(unitType.compare("infantry") == 0){
    infantry += aStrength;
  } else if(unitType.compare("cavalry") == 0){
    cavalry += aStrength;
  } else if(unitType.compare("artillery") == 0){
    artillery += aStrength;
  }
}

void Country::navyCounter(std::string unitType){
  if(unitType.compare("bigShip") == 0){
    bigShip += 1;
  } else if(unitType.compare("lightShip") == 0){
    lightShip += 1;
  } else if(unitType.compare("galley") == 0){
    galley += 1;
  } else if(unitType.compare("transport") == 0){
    transport += 1;
  }
}

//Subject functions
//Countries tag should be added, not the txt file.
//I.E. ENG or SWE not ENG.txt or SWE.txt
void Country::addSubject(std::string subject){
  subjectArray[subjectArrayPlace] = subject;
  subjectArrayPlace++;
}

int Country::getSubjectArrayCount(){
  return subjectArrayPlace;
}

std::string Country::getSubjectName(int subPosition){
  return subjectArray[subPosition];
}

double Country::getSubjectArmy(std::string unitType){
  double unitStrength = 0;

  if(unitType.compare("infantry") == 0){
    unitStrength = subjectInfantry;
  } else if(unitType.compare("cavalry") == 0){
    unitStrength = subjectCavalry;
  } else if(unitType.compare("artillery") == 0){
    unitStrength = subjectArtillery;
  }

  return unitStrength;
}

double Country::getSubjectArmyTotal(){
  return subjectInfantry+subjectCavalry+subjectArtillery;
};

int Country::getSubjectNavy(std::string unitType){
  int unitStrength = 0;

  if(unitType.compare("bigShip") == 0){
    unitStrength = subjectBigShip;
  } else if(unitType.compare("lightShip") == 0){
    unitStrength = subjectLightShip;
  } else if(unitType.compare("galley") == 0){
    unitStrength = subjectGalley;
  } else if(unitType.compare("transport") == 0){
    unitStrength = subjectTransport;
  }

  return unitStrength;
};

int Country::getSubjectNavalTotal(){
  return subjectBigShip+subjectLightShip+subjectGalley+subjectTransport;
}

//Testing functions
void Country::printSubjects(std::ofstream& output){
  if(output.is_open()){
    for(int i = 0; i < subjectArrayPlace; i++){
      output << "   Subject " << i << ": " << subjectArray[i] << std::endl;
    }
  }
}
