import sys
from collections import deque

class Country:
  name: str

  # military
  # @todo inf, cav, art should be counted in the thousands. I.e. int * 1000 (maybe these should actually be doubles)
  infantry: float
  infantry : int
  cavalry: float 
  artillery: float
  army_force_limits: int
  max_manpower: float

  big_ship: int
  light_ship: int
  galley: int
  transport: int
  naval_force_limits: int
  max_sailor: int

  # subject military 
  subjects_infantry: float
  subjects_cavalry: float 
  subjects_artillery: float
  subjects_army_force_limits: int
  subjects_max_manpower: float

  subjects_big_ship: int
  subjects_light_ship: int
  subjects_galley: int
  subjects_transport: int
  subjects_naval_force_limits: int
  subjects_max_sailor: int

  # score
  admin_rank: float
  admin_rating: float
  diplo_rank: float
  diplo_rating: float
  mil_rank: float
  mil_rating: float
  total_score: float
  card_score: float

  # income
  tax: float
  production: float
  trade: float
  gold: float
  tariff: float
  vassal_income: float
  harbor_fees: float
  subsidies: float
  war_reparation: float
  spoils_of_war: float
  condottieri_income: float

  #tech
  admin_tech: int
  diplo_tech: int
  mil_tech: int

  # @todo, what struct should this be? Should be better to be a dict[institution, bool]?
  #embraced_institutions: array[int]

  development: float
  # @todo should be an enum
  my_subject_type: str
  great_power_score: float
  owned_subjects: deque()

  def total_army_size(self):
    return self.infantry + self.cavalry + self.artillery

  def total_navy_size(self):
    return self.big_ship + self.light_ship + self.galley + self.transport

  def total_score_rating(self):
    return self.admin_rating + self.diplo_rating + self.mil_rating

  def total_income(self):
    return self.tax + self.production + self.trade + self.gold + self.tariff + self.harbor_fees + self.subsidies + self.war_reparation + self.spoils_of_war + self.condottieri_income

  def total_tech(self):
    return self.admin_tech + self.diplo_tech + self.mil_tech

  def army_counter(self, unit_type: str, unit_strength: float) -> None:
    if (unit_type.compare("infantry") == 0):
      self.infantry += unit_strength
    elif (unit_type.compare("cavalry") == 0):
      self.cavalry += unit_strength
    elif (unit_type.compare("artillery") == 0):
      self.artillery += unit_strength
    else:
      return
      # write to log that an unidentified unit_type came through.
      

  def naval_counter(self, unit_type: str) -> None:
    if (unit_type.compare("bigShip") == 0):
      self.big_ship += 1
    elif (unit_type.compare("lightShip") == 0):
      self.light_ship += 1
    elif (unit_type.compare("galley") == 0):
      self.galley += 1
    elif (unit_type.compare("transport") == 0):
      self.transport += 1
    else:
      return
      # write to log that an unidentified unit_type came through.

  #### SUBJECT FUNCTIONS #####
  # Countries tag should be added, not the .txt file. I.E. ENG/SWE not ENG.txt/SWE.txt
  def add_subject(self, subjects_name: str) -> None:
    self.owned_subjects.add(subjects_name)

  def subjects_unit_type_strength(self, unit_type: str):
    if (unit_type.compare("infantry") == 0):
      return self.subjects_infantry
    elif (unit_type.compare("cavalry") == 0):
      return self.subjects_cavalry
    elif (unit_type.compare("artillery") == 0):
      return self.subjects_artillery
    else:
      return
      # write to log that an unidentified unit_type came through.
  
  def subject_total_army_strength(self) -> float:
    return self.subjects_infantry + self.subjects_cavalry + self.subjects_artillery

  def subject_ship_type_strength(self, ship_type: str):
    if(ship_type.compare("bigShip") == 0):
      return self.subjects_big_ship
    elif(ship_type.compare("lightShip") == 0):
      return self.subjects_light_ship
    elif(ship_type.compare("galley") == 0):
      return self.subjects_galley
    elif(ship_type.compare("transport") == 0):
      return self.subjects_transport
    # else: