#ifndef _Country_H
#define _Country_H

#include <string>

class Country {

  private:
    std::string name;

    //miliTariffy values
    //Land forces
    int infrantry = 0;
    int calvary = 0;
    int artillery = 0;
    int armyForceLimit = 0;
    int currentArmySize = 0;
    double maxManpower = 0;

    //Naval forces
    int bigShip = 0;
    int lightShip = 0;
    int galley = 0;
    int transport = 0;
    int navalForceLimit = 0;
    double maxSailor = 0;

    //Score
    double adminRank = 0;
    double adminRating = 0;
    double diploRank = 0;
    double diploRating = 0;
    double milRank = 0;
    double milRating = 0;
    double scoreTotal = 0;

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

    //Misc
    int development = 0;

  public:
    //Constructors
    Country();
    Country(std::string tag);

    //Getters
    std::string getName();
    int getInfrantry();
    int getCalvary();
    int getArillery();
    int getArmyForceLimit();
    int getCurrentArmySize();
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
    int getDevelopment();

    //Setters
    void setName(std::string tag);
    void setArmyForceLimit(int limit);
    void setCurrentArmySize(int aSize);
    void setMaxManpower(double maxMan);
    void setNavalForceLimit(int nLimit);
    void setMaxSailor(double maxSail);
    void setAdminRank(double aRank);
    void setAdminRating(double aRating);
    void setDiploRank(double dRank);
    void setDiploRating(double dRating);
    void setMilRank(double mRank);
    void setMilRating(double mRating);
    void setScoreTotal(double sTotal);
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
    void setDevelopment(int devel);

    //Unit Counter
    void unitCounter(int unitType, double unitStrength);

    //Misc
    int armyTotal();
    int navyTotal();
    double scoreRatingTotal();
    double incomeTotal();
    int techTotal();

};

#endif
