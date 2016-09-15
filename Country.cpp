#include <string>
#include "Country.h"

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

int Country::getInfrantry(){
  return infrantry;
}

int Country::getCalvary(){
  return calvary;
}

int Country::getArillery(){
  return artillery;
}

int Country::getArmyForceLimit(){
  return armyForceLimit;
}

int Country::getCurrentArmySize(){
  return currentArmySize;
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

void Country::setCurrentArmySize(int aSize){
  currentArmySize = aSize;
}

void Country::setMaxManpower(double maxMan){
  maxManpower = maxMan;
}

void Country::setNavalForceLimit(int nLimit){
  navalForceLimit = nLimit;
}

void Country::setMaxSailor(double maxSail){
  maxSailor = maxSail;
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
int Country::armyTotal(){
  return infrantry+calvary+artillery;
}

int Country::navyTotal(){
  return bigShip+lightShip+galley+transport;
}

double Country::scoreRatingTotal(){
  return adminRating+diploRating+milRating;
}

//Finish this one when all variables added
double Country::incomeTotal(){
  return tax+production+trade+gold+tariff+harborFees+subsidies+warReparations+spoilsOfWar+condottieriIncome;
}

int Country::techTotal(){
  return adminTech+diploTech+milTech;
}

//Increase respective unit count
void unitCounter(int unitType, double unitStrength){
  ;
}
