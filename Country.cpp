
class Country {
  private:
    //military values
    //Land forces
    int infrantry = 0;
    int calvary = 0;
    int artillery = 0;
    int armyForceLimit = 0;

    //Naval forces
    int bigShip = 0;
    int lightShip = 0;
    int galley = 0;
    int transport = 0;
    int navalForceLimit = 0;

    //Score
    int adminRating = 0;
    int adminGrowth = 0;
    int diploRating = 0;
    int diploGrowth = 0;
    int milRating = 0;
    int milGrowth = 0;
    int scoreTotal = 0;

    //Income
    int tax = 0;
    int production = 0;
    int trade = 0;
    int gold = 0;

    //Technology levels
    int adminTech = 0;
    int diploTech = 0;
    int milTech = 0;
    int techTotal = 0;

    //Misc
    int development = 0;

  public:
    //Getters
    int getInfrantry();
    int getCalvary();
    int getArillery();
    int getArmyForceLimit();
    int getBigShip();
    int getLightShip();
    int getGalley();
    int getTransport();
    int getNavalForceLimit();
    int getAdminRating();
    int getAdminGrowth();
    int getDiploRating();
    int getDiploGrowth();
    int getMilRating();
    int getMilGrowth();
    int getScoreTotal();
    int getTax();
    int getProduction();
    int getTrade();
    int getGold();
    int getAdminTech();
    int getDiploTech();
    int getMilTech();

    //Setters
    void setInfrantry(int inf);
    void setCalvary(int cav);
    void setArillery(int art);
    void setArmyForceLimit(int limit);
    void setBigShip(int big);
    void setLightShip(int light);
    void setGalley(int gal);
    void setTransport(int trans);
    void setNavalForceLimit(int nlimit);
    void setAdminRating(int arating);
    void setAdminGrowth(int agrowth);
    void setDiploRating(int drating);
    void setDiploGrowth(int dgrowth);
    void setMilRating(int mrating);
    void setMilGrowth(int mgrowth);
    void setScoreTotal(int stotal);
    void setTax(int itax);
    void setProduction(int ipro);
    void setTrade(int itra);
    void setGold(int igold);
    void setAdmvoidech(int atech);
    void setDiploTech(int dtech);
    void setMilTech(int mtech);
}

//default constructor
Country::Country(){
}

//Getter functions
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

int Country::getAdminRating(){
  return adminRating;
}

int Country::getAdminGrowth(){
  return adminGrowth;
}

int Country::getDiploRating(){
  return diploRating;
}

int Country::getDiploGrowth(){
  return diploGrowth;
}

int Country::getMilRating(){
  return milRating;
}

int Country::getMilGrowth(){
  return milGrowth;
}

int Country::getScoreTotal(){
  return scoreTotal;
}

int Country::getTax(){
  return tax;
}

int Country::getProduction(){
  return production;
}

int Country::getTrade(){
  return trade;
}

int Country::getGold(){
  return gold;
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

//Setter functions
void Country::setInfrantry(int Country::inf){
  infrantry = inf;
}

void Country::setCalvary(int Country::cal){
  calvary = cal;
}

void Country::setArtillery(int Country::art){
  artillery = art;
}

void Country::setArmyForceLimit(int Country::alimit){
  armyForceLimit = alimit;
}

void Country::setBigShip(int Country::big){
  bigShip = big;
}

void Country::setLightShip(int Country::light){
  lightShip = light;
}

void Country::setGalley(int Country::gal){
  galley = gal;
}

void Country::setTransport(int Country::trans){
  transport = trans;
}

void Country::setNavalForceLimit(int Country::nlimit){
  navalForceLimit = nlimit;
}

void Country::setAdminRating(int Country::arating){
  adminRating = arating;
}

void Country::setAdminGrowth(int Country::agrowth){
  adminGrowth = agrowth;
}

void Country::setDiploRating(int Country::drating){
  diploRating = drating;
}

void Country::setDiploGrowth(int Country::dgrowth){
  diploGrowth = dgrowth);
}

void Country::setMilRating(int Country::mrating){
  milRating = mrating;
}

void Country::setMilGrowth(int Country::mgrowth){
  milGrowth = milRating;
}

void Country::setScoreTotal(int Country::stotal){
  scoreTotal = stotal;
}

void Country::setTax(int Country::itax){
  tax = itax;
}

void Country::setProduction(int Country::ipro){
  production = ipro;
}

void Country::setTrade(int Country::itra){
  trade = itra;
}

void Country::setGold(int Country::igold){
  gold = igold;
}

void Country::setAdminTech(int Country::atech){
  adminTech = atech;
}

void Country::setDiploTech(int Country::dtech){
  diploTech = dtech;
}

void Country::setMilTech(int Country::mtech){
  milTech = mtech;
}

//Total functions
int Country::ArmyTotal(){
  return infrantry+calvary+artillery;
}

int Country::NavyTotal(){
  return bigShip+lightShip+galley+transport;
}

int Country::scoreGrowthTotal(){
  return adminGrowth+diploGrowth+milGrowth;
}

//Finish this one when all variables added
int Country::incomeTotal(){
  return tax+production+trade+gold;
}

int Country::techTotal(){
  return adminTech+diploTech+milTech;
}
