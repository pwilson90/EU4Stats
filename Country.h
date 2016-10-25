#ifndef _Country_H
#define _Country_H

#include <string>
#include <fstream>

class Country {

  private:
    //saved as the TAG not TAG.txt
    std::string name;

    //miliTariffy values
    //Land forces
    double infantry = 0;
    double cavalry = 0;
    double artillery = 0;
    int armyForceLimit = 0;
    double armyStrength = 0;
    double maxManpower = 0;

    //Naval forces
    int bigShip = 0;
    int lightShip = 0;
    int galley = 0;
    int transport = 0;
    int navalForceLimit = 0;
    double maxSailor = 0;

    //Subject Military values
    double subjectInfantry = 0;
    double subjectCavalry = 0;
    double subjectArtillery = 0;
    int subjectBigShip = 0;
    int subjectLightShip = 0;
    int subjectGalley = 0;
    int subjectTransport = 0;

    //Score
    double adminRank = 0;
    double adminRating = 0;
    double diploRank = 0;
    double diploRating = 0;
    double milRank = 0;
    double milRating = 0;
    double scoreTotal = 0;
    double cardScore = 0;

    //Income
    double tax = 0;
    double production = 0;
    double trade = 0;
    double gold = 0;
    double tariff = 0;
    double vassalIncome = 0;
    double harborFees = 0;
    double subsidies = 0;
    double warReparations = 0;
    double spoilsOfWar = 0;
    double condottieriIncome = 0;

    //Technology levels
    int adminTech = 0;
    int diploTech = 0;
    int milTech = 0;
    int technologyTotal = 0;
    int embracedInstitutions[7];

    //Misc
    int development = 0;
    std::string mySubjectType = "";
    double greatPowerScore = 0;

    //Subject info
    std::string subjectArray[30];
    int subjectArrayPlace = 0;


  public:
    //Constructors
    Country();
    Country(std::string tag);

    //Getters
    std::string getName();

    double getInfantry();
    double getCavalry();
    double getArtillery();
    int getArmyForceLimit();
    double getMaxManpower();
    int getBigShip();
    int getLightShip();
    int getGalley();
    int getTransport();
    int getNavalForceLimit();
    double getMaxSailor();

    double getAdminRank();
    double getAdminRating();
    double getDiploRank();
    double getDiploRating();
    double getMilRank();
    double getMilRating();
    double getScoreTotal();
    double getCardScore();

    double getTax();
    double getProduction();
    double getTrade();
    double getGold();
    double getTariff();
    double getVassalIncome();
    double getHarborFees();
    double getSubsidies();
    double getWarReparation();
    double getSpoilsOfWar();
    double getCondottieriIncome();

    int getAdminTech();
    int getDiploTech();
    int getMilTech();
    int getEmbracedInstitutions(int institution);

    int getDevelopment();
    std::string getSubjectType();
    double getGreatPowerScore();

    //Setters
    void setName(std::string tag);

    void setArmyForceLimit(int limit);
    void setMaxManpower(double maxMan);
    void setSubjectArmy(double strength, std::string unitType);
    void setNavalForceLimit(int nLimit);
    void setMaxSailor(double maxSail);
    void setSubjectNavy(int strength, std::string unitType);

    void setAdminRank(double aRank);
    void setAdminRating(double aRating);
    void setDiploRank(double dRank);
    void setDiploRating(double dRating);
    void setMilRank(double mRank);
    void setMilRating(double mRating);
    void setScoreTotal(double sTotal);
    void setCardScore(double cScore);

    void setTax(double iTax);
    void setProduction(double iProduction);
    void setTrade(double iTrade);
    void setGold(double iGold);
    void setTariff(double iTariff);
    void setVassalIncome(double iVassal);
    void setHarborFees(double iHarbor);
    void setSubsidies(double iSubsidies);
    void setWarReparation(double iReparation);
    void setSpoilsOfWar(double iSpoil);
    void setCondottieriIncome(double iCondottieri);

    void setAdminTech(int aTech);
    void setDiploTech(int dTech);
    void setMilTech(int mTech);
    void setEmbracedInstitutions(int embraced, int institution);

    void setDevelopment(int devel);
    void setSubjectType(std::string subjectType);
    void setGreatPowerScore(double gpScore);

    //Unit Counter
    void armyCounter(std::string unitType, double aStrength);
    void navyCounter(std::string unitType);

    //Various "total" functions
    double armyStrengthTotal();
    int navyTotal();
    double scoreRatingTotal();
    double incomeTotal();
    int techTotal();

    //Subject functions
    void addSubject(std::string subject);

    int getSubjectArrayCount();
    std::string getSubjectName(int subPosition);
    double getSubjectArmy(std::string unitType);
    double getSubjectArmyTotal();
    int getSubjectNavy(std::string unitType);
    int getSubjectNavalTotal();

    //Testing functions
    void printSubjects(std::ofstream& output);
    void printInstitutions(std::ofstream& output);
};

#endif
