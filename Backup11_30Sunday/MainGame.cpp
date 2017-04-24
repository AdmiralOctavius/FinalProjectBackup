#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

using namespace std;
using namespace System;
//Classes needed
//PlayerRPG, MonstersRPG
//Below: Movement and Adventure game code

//Add Equipment being used
//Do documentation
//Remove 


class Events {
public:
	void InitializeEventRoom(int eventRoomIn);
	void InitializeEventType(int eventTypeIn);
	void InitializeSpecVar1(int SpecVar1In);
	void InitializeSpecVar2(int SpecVar2In);
	void InitializeSpecVar3(int SpecVar3In);
	void InitializeEventDescription(string eventDescriptionIn);
	void InitializeEventResolvedDescription(string eventResolvedDescriptionIn);

	int GetEventRoom();
	int GetEventType();
	int GetSpecVar1();
	int GetSpecVar2();
	int GetSpecVar3();
	string GetEventDescription();
	string GetEventResolvedDescription();

private:

	int eventRoom;
	int eventType;
	int SpecVar1;
	int SpecVar2;
	int SpecVar3;
	string eventDescription;
	string eventResolvedDescription;

};




class Leveling {
public:
	void InitializeLevel(int levelIn);
	void InitializeHealth(int healthIn);
	void InitializeAttack(int attackIn);
	void InitializeDefense(int defenseIn);
	void InitializeXpNeeded(int xpNeededIn);
	int GetXpNeeded();
	int GetHealth();
	int GetAttack();
	int GetDefense();
private:
	int level;
	int health;
	int attack;
	int defense;
	int xpNeeded;
};

int Leveling::GetHealth() {
	return health;
}

int Leveling::GetAttack() {
	return attack;
}

int Leveling::GetDefense() {
	return defense;
}

int Leveling::GetXpNeeded() {
	return xpNeeded;
}

void Leveling::InitializeLevel(int levelIn) {
	level = levelIn;
	return;
}
void Leveling::InitializeHealth(int healthIn) {
	health = healthIn;
	return;
}
void Leveling::InitializeAttack(int attackIn) {
	attack = attackIn;
	return;
}
void Leveling::InitializeDefense(int defenseIn) {
	defense = defenseIn;
	return;
}
void Leveling::InitializeXpNeeded(int xpNeededIn){
	xpNeeded = xpNeededIn;
	return;
}


class PlayerRPG {

public:
	void PlayerHealthDamage(int amountDamaged);
	void PlayerHealthHeal(int amountHealed);
	void PlayerXPAdd(int amountXP);
	void InitializeHealth(int playerHealthIn);
	void InitializeAttack(int playerAttackIn);
	void InitializeXP(int playerXPIn);
	void InitializePlayerLevel(int playerLevelIn);
	void InitializePlayerDefense(int playerDefenseIn);
	int GetPlayerHealth();
	int GetPlayerAttack();
	int GetPlayerXP();
	int GetPlayerDefense();
	void CheckLevelUp(vector<Leveling> levels);
	string GetPlayerInventoryAt(int position);
	void InitializePlayerInventory();
	vector<string> playerInventory;
	PlayerRPG();
	string GetPlayerEquipWeapon();
	string GetPlayerEquipArmor();
	void EquipPlayerWeapon(string itemWeaponIn);
	void EquipPlayerArmor(string itemArmorIn);
	void InitializePlayerName(string playerNameIn);
	string GetPlayerName();

private:
	int playerHealth;
	int playerMaxHealth;
	int playerAttack;
	int playerXP;
	int playerLevel;
	int playerDefense;
	string playerEquipWeapon;
	string playerEquipArmor;
	string playerName;
};

void PlayerRPG::InitializePlayerName(string playerNameIn) {
	playerName = playerNameIn;
	return;
}
string PlayerRPG::GetPlayerName() {
	return playerName;
}

string PlayerRPG::GetPlayerEquipWeapon() {
	return playerEquipWeapon;
}

string PlayerRPG::GetPlayerEquipArmor() {
	return playerEquipArmor;
}

void PlayerRPG::EquipPlayerWeapon(string itemWeaponIn) {
	playerEquipWeapon = itemWeaponIn;
	return;
}

void PlayerRPG::EquipPlayerArmor(string itemArmorIn) {
	playerEquipArmor = itemArmorIn;
	return;
}



PlayerRPG::PlayerRPG() : playerInventory(4) {
	return;
}
	
void PlayerRPG::InitializePlayerInventory() {
	playerInventory.at(0) = "";
	playerInventory.at(1) = "";
	playerInventory.at(2) = "";
	playerInventory.at(3) = "";
	return;
}
string PlayerRPG::GetPlayerInventoryAt(int position) {
	return playerInventory.at(position);
}

void PlayerRPG::CheckLevelUp(vector<Leveling> levels) {
	if (playerXP >= levels.at(playerLevel+1).GetXpNeeded()) {
		playerLevel = playerLevel + 1;
		playerAttack = levels.at(playerLevel).GetAttack();
		playerMaxHealth = levels.at(playerLevel).GetHealth();
		playerDefense = levels.at(playerLevel).GetDefense();
		playerHealth = playerMaxHealth;
		cout << "You have leveled up!" << " New level is level: " << playerLevel << endl;
		cout << "Your new stats: Health: " << playerMaxHealth << " Attack: " << playerAttack << " Defense: " << playerDefense << endl;
	}
	return;
}

void PlayerRPG::PlayerHealthHeal(int amtHealed) {
	playerHealth = playerHealth + amtHealed;
	return;
}

void PlayerRPG::InitializePlayerLevel(int playerLevelIn) {
	playerLevel = playerLevelIn;
	return;
}
void PlayerRPG::InitializeXP(int playerXPIn) {
	playerXP = playerXPIn;
	return;
}

int PlayerRPG::GetPlayerXP() {
	return playerXP;
}

void PlayerRPG::PlayerXPAdd(int amountXP) {
	playerXP = playerXP + amountXP;
	return;
}

void PlayerRPG::InitializeAttack(int playerAttackIn) {
	playerAttack = playerAttackIn;
	return;
}

void PlayerRPG::InitializeHealth(int playerHealthIn) {
	playerHealth = playerHealthIn;
	playerMaxHealth = playerHealthIn;
	return;
}

void PlayerRPG::InitializePlayerDefense(int playerDefenseIn) {
	playerDefense = playerDefenseIn;
	return;
}

void PlayerRPG::PlayerHealthDamage(int amountDamaged) {
	playerHealth = playerHealth - amountDamaged;
	return;
}



int PlayerRPG::GetPlayerHealth() {
	return playerHealth;
}

int PlayerRPG::GetPlayerAttack() {
	return playerAttack;
}

int PlayerRPG::GetPlayerDefense() {
	return playerDefense;
}


class MonstersRPG {

	public:
		void InitializeXP(int monsterXPIn);
		void InitializeName(string monsterNameIn);
		int GetMonsterHealth();
		int GetMonsterAttack();
		void InitializeAttack(int monsterAttackIn);
		void InitializeHealth(int monsterHPIn);
		

		void DisplayName();
		string ShowName();
		int GetXP();

	private:
		int monsterHealth;
		int monsterAttack;
		string monsterName;
		int monsterXPValue;
};

int MonstersRPG::GetXP() {
	return monsterXPValue;
}
void MonstersRPG::InitializeXP(int monsterXPIn) {
	monsterXPValue = monsterXPIn;
	return;
}

int MonstersRPG::GetMonsterAttack() {
	return monsterAttack;
}

int MonstersRPG::GetMonsterHealth() {
	return monsterHealth;
}

void MonstersRPG::InitializeName(string monsterNameIn) {
	monsterName = monsterNameIn;
	return;
}

void MonstersRPG::InitializeAttack(int monsterAttackIn) {
	monsterAttack = monsterAttackIn;
	return;
}

void MonstersRPG::InitializeHealth(int monsterHPIn) {
	monsterHealth = monsterHPIn;
	return;
}

void MonstersRPG::DisplayName() {
	cout << monsterName << endl;
	return;
}

string MonstersRPG::ShowName() {
	return monsterName;
}


class WorldMonsters {
public:
	void addName(string monsterNameCall);
	void addPosition(int monsterPositionCall);
	void addHasKey(int hasKeyIn);
	string getName();
	int getPosition();
	int getHasKey();
private:
	string monsterName;
	int monsterPosition;
	int hasKey;
};

int WorldMonsters::getHasKey(){
	return hasKey;
}
void WorldMonsters::addHasKey(int hasKeyIn) {
	hasKey = hasKeyIn;
	return;
}
void WorldMonsters::addName(string monsterNameCall) {
	monsterName = monsterNameCall;
	return;
}

void WorldMonsters::addPosition(int monsterPositionCall) {
	monsterPosition = monsterPositionCall;
	return;
}

string WorldMonsters::getName() {
	return monsterName;
}

int WorldMonsters::getPosition() {
	return monsterPosition;
}

class Items {
	public:
		void InitializeItemName(string ItemNameIn);
		void InitializeItemPosition(int ItemPositionIn);
		void InitializeItemType(int ItemTypeIn);
		void InitializeItemDescription(string ItemDescriptionIn);
		void InitializeItemWorldDescription(string ItemWorldDescriptionIn);
		void InitializeSpecialVal(int ItemSpecialValIn);
		void InitializeItemNumber(int ItemNumIn);

		string GetItemName();
		int GetItemPos();
		int GetItemType();
		string GetItemDesc();
		string GetItemWorldDesc();
		int GetItemSpecialVal();
		int GetItemNumber();

		void CreateKey(vector<Items>& items);
		
	private:
		string ItemName;
		int ItemPosition; 
		int ItemType;
		string ItemDescription;
		string ItemWorldDescription;
		int ItemSpecialVal;
		int ItemNumber;
		
};

void Items::CreateKey(vector<Items>& items) {
	InitializeItemNumber(items.size());
	InitializeItemName("Key");
	InitializeItemPosition(-1);
	InitializeItemType(0);
	InitializeItemDescription("The key is a key dummy.");
	InitializeItemWorldDescription("A key lies on the floor.");
	InitializeSpecialVal(0);
	return;
}

void Items::InitializeItemNumber(int ItemNumIn) {
	ItemNumber = ItemNumIn;
	return;
}
int Items::GetItemNumber() {
	return ItemNumber;
}
void Items::InitializeItemName(string ItemNameIn) {
	ItemName = ItemNameIn;
	return;
}

void Items::InitializeItemPosition(int ItemPositionIn) {
	ItemPosition = ItemPositionIn;
	return;
}

void Items::InitializeItemType(int ItemTypeIn) {
	ItemType = ItemTypeIn;
	return;
}

void Items::InitializeItemDescription(string ItemDescriptionIn) {
	ItemDescription = ItemDescriptionIn;
	return;
}

void Items::InitializeItemWorldDescription(string ItemWorldDescriptionIn) {
	ItemWorldDescription = ItemWorldDescriptionIn;
	return;
}

void Items::InitializeSpecialVal(int ItemSpecValIn) {
	ItemSpecialVal = ItemSpecValIn;
	return;
}

string Items::GetItemName() {
	return ItemName;
}
int Items::GetItemPos() {
	return ItemPosition;
}

int Items::GetItemType() {
	return ItemType;
}

string Items::GetItemDesc() {
	return ItemDescription;
}
string Items::GetItemWorldDesc() {
	return ItemWorldDescription;
}

int Items::GetItemSpecialVal() {
	return ItemSpecialVal;
}

void moveToRoom(int roomDirection, int& currentRoom, int width) {
	//North
	if (roomDirection == 0) {
		currentRoom = currentRoom - (width * 4);
	}
	//South
	else if (roomDirection == 1) {
		currentRoom = currentRoom + (width * 4);
	}
	//East
	else if (roomDirection == 2) {
		currentRoom = currentRoom + 4;
	}
	//West
	else if (roomDirection == 3) {
		currentRoom = currentRoom - 4;
	}
	return;
}

void roomDescription(int currentRoom, vector<string> description) {

	cout << description.at(currentRoom) << endl;
	return;
}

void checkForItem(int currentRoom, vector<Items> ItemsList) {
	int i = 0;
	for (i = 0; i < ItemsList.size(); i++) {
		if (currentRoom == ItemsList.at(i).GetItemPos() && ItemsList.at(i).GetItemName() != "") {
			cout << ItemsList.at(i).GetItemWorldDesc() << endl;
		}
	}
}

void checkPlayInventory(int selectedItem, vector<string> playerInventory, vector<int> ItemsList, vector<string> ItemDescriptionList) {

	cout << ItemDescriptionList.at(selectedItem) << endl;
}


void GetRandomValidRoom(vector<int>rooms, int& currentRoom, int roomsWidth) {
	//n s e w
	//if they're == 1
	//if 1 then valid room
	//pick random valid?
	int randomPick = 0;
	int randomRoom = 0;
	bool pickValid = false;
	while (pickValid == false) {
		//Gives Number Between 1 and 4
		randomPick = (rand() % 4);
		randomRoom = randomPick + currentRoom;
		if (rooms.at(randomRoom) == 1) {
			moveToRoom(randomPick, currentRoom, roomsWidth);
			pickValid = true;
		}
	}
}

void rpgBattle(vector<WorldMonsters>& monstersPosition, vector<MonstersRPG> monstersList, int& currentRoom, bool& playerAlive, PlayerRPG& player, bool& monstersHere, vector<Leveling> levels, vector<Items> items, vector<int> rooms, int roomsWidth) {

	/*int monsterHealth = 5;
	int monsterAttack = 2;*/
	string playerIn = "";
	int playerInChoice = 0;
	bool combatOngoing = true;
	bool gameOn = true;
	int i = 0;
	int j = 0;
	int k = 0;
	vector<string> CurrentMonsters(0);
	vector<int> CurrentMonstersHealth(0);
	vector<int> CurrentMonstersAttack(0);
	vector<bool> CurrentMonstersAlive(0);
	vector<int> CurrentMonstersPosition(0);
	vector<int> CurrentMonstersXP(0);
	vector<int> CurrentMonstersHasKey(0);
	vector<bool> CurrentMonstersdDeadThisTurn(0);
	bool someMonstersAlive = false;
	int damageTaken = 0;
	bool hasPotion = true;
	int potionPos = 0;
	int amtHealed = 0;
	bool gotPotion = false;
	bool notTakeItem = false;
	bool hitMonster = false;
	for (i = 0; i < monstersPosition.size(); i++) {
		if (currentRoom == monstersPosition.at(i).getPosition()&& monstersPosition.at(i).getName()!="") {
			//Add check for size of monstersList so as to not get error?

			for (j = 0; j < monstersList.size(); j++) {
				if (monstersPosition.at(i).getName() == monstersList.at(j).ShowName()) {
					CurrentMonsters.push_back(monstersList.at(j).ShowName());
					CurrentMonstersHealth.push_back(monstersList.at(j).GetMonsterHealth());
					CurrentMonstersAttack.push_back(monstersList.at(j).GetMonsterAttack());
					CurrentMonstersAlive.push_back(true);
					someMonstersAlive = true;
					CurrentMonstersPosition.push_back(i);
					CurrentMonstersXP.push_back(monstersList.at(j).GetXP());
					CurrentMonstersHasKey.push_back(monstersPosition.at(i).getHasKey());
					CurrentMonstersdDeadThisTurn.push_back(false);
				}
			}
		}
	}

	if (someMonstersAlive == false) {
		combatOngoing = false;
		cout << "No monsters here!" << endl;
		return;
	}
	//Add check for if Monsters in room at all	


		cout << "Combat has begun! What will you do?" << endl;

		while (combatOngoing != false) {
			system("cls");
			cout << "Your Health is: " << player.GetPlayerHealth() << endl;
			
			//cout << "The Monster's health is: " << monsterHealth << endl;
			for (i = 0; i < CurrentMonsters.size(); i++) {
				for (j = 0; j < monstersList.size(); j++) {
					//Error out of bounds, can't figure out what's wrong

					if (CurrentMonsters.at(i) == monstersList.at(j).ShowName() && CurrentMonstersAlive.at(i) == true) {
						cout << "Monster: " << monstersList.at(j).ShowName() << " has: " << CurrentMonstersHealth.at(i) << " health " << endl;
					}
				}
			}
			cout << "ACTIONS: attack, defend, heal, run" << endl;
			cin >> playerIn;
			if (playerIn == "attack") {
				hitMonster = false;
				cout << "Currently alive monsters are: ";
				for (i = 0; i < CurrentMonsters.size(); i++) {
					if (CurrentMonstersAlive.at(i) == true) {
						cout << " " << i << ") " << CurrentMonsters.at(i) << ", ";
					}
				}
				cout << endl;
				cout << "Choose a monster to attack!" << endl;
				while (hitMonster == false) {
					cin >> playerInChoice;
					if (playerInChoice >= CurrentMonsters.size() || playerInChoice < 0) {
						cout << "Monster does not exist." << endl;
					}
					else {
						if (CurrentMonstersAlive.at(playerInChoice) == true) {
							hitMonster = true;
							cout << "You attack for: " << player.GetPlayerAttack() << endl;
							cout << "The monster takes " << player.GetPlayerAttack() << " damage!" << endl;
							CurrentMonstersHealth.at(playerInChoice) = CurrentMonstersHealth.at(playerInChoice) - player.GetPlayerAttack();
						}
						else {
							cout << "That monster is dead." << endl;
						}
					}
				}
				
				
				
				//monsterHealth = monsterHealth - playerAttack;
				/*if (monsterHealth <= 0) {
					cout << "You win!" << endl;
					combatOngoing = false;
				}*/
				//Check for monsters Alive in for loop
				/*someMonstersAlive = false;
				for (i = 0; i < CurrentMonsters.size(); i++) {
					if (CurrentMonstersAlive.at(i) == true) {
						//Select Target
						CurrentMonstersHealth.at(i) = CurrentMonstersHealth.at(i) - player.GetPlayerAttack();
					}*/
				someMonstersAlive = false;
				for (i = 0; i < CurrentMonsters.size(); i++) {
					if (CurrentMonstersHealth.at(i) <= 0) {
						if (CurrentMonstersdDeadThisTurn.at(i) == false) {
							CurrentMonstersAlive.at(i) = false;
							cout << "The " << CurrentMonsters.at(i) << " is dead!" << endl;
							monstersPosition.at(CurrentMonstersPosition.at(i)).addPosition(-1);
							player.PlayerXPAdd(CurrentMonstersXP.at(i));
							CurrentMonstersdDeadThisTurn.at(i) = true;
							/*if (CurrentMonstersHasKey.at(i) == 1) {
								notTakeItem = false;
								for (i = 0; i < items.size(); i++) {
									if (items.at(i).GetItemNumber() == 0) {
										for (k = 0; k < player.playerInventory.size(); k++) {
											//if statement here
											if (player.playerInventory.at(k) == "" && notTakeItem == true) {
												player.playerInventory.at(k) = items.at(i).GetItemName();
												notTakeItem = false;
												cout << items.at(i).GetItemName() << " added to inventory." << endl;
												//ItemsList.at(i).InitializeItemPosition(-1);

											}
										}

									}
								}
								if (notTakeItem == false) {
									cout << "No room in inventory, a key falls to the floor." << endl;

								}
								if (notTakeItem == true) {
									cout << "No room in inventory." << endl;
									break;
								}
							}*/
						}
					}
					else{
						someMonstersAlive = true;
					}
				}
			
				for (i = 0; i < CurrentMonsters.size(); i++) {
					if (CurrentMonstersAlive.at(i) == true) {
						//Have monsters attack in here in sucession
						cout << CurrentMonsters.at(i) <<" attacks for: " << CurrentMonstersAttack.at(i) << endl;
						
						cout << "You take: " << CurrentMonstersAttack.at(i) << endl;
						//Randomize Damage a little at some point
						//playerHealth = playerHealth - CurrentMonstersAttack.at(i);
						player.PlayerHealthDamage(CurrentMonstersAttack.at(i));
						combatOngoing = true;
					}
				}
				if (someMonstersAlive == false) {
					cout << "You win the fight!" << endl;
					combatOngoing = false;
					monstersHere = false;
					//double check
					player.CheckLevelUp(levels);
					break;
				}


			}
			else if (playerIn == "defend") {
				cout << "Defending..." << endl;

				for (i = 0; i < CurrentMonsters.size(); i++) {
					if (CurrentMonstersAlive.at(i) == true) {
						//Have monsters attack in here in sucession
						cout << CurrentMonsters.at(i) << " attacks for: " << CurrentMonstersAttack.at(i) << endl;

						
						//Randomize Damage a little at some point
						//playerHealth = playerHealth - CurrentMonstersAttack.at(i);
						//Have defense subtract from attack
						damageTaken = CurrentMonstersAttack.at(i) - player.GetPlayerDefense();
						if (damageTaken <= 0) {
							damageTaken = 0;
						}
						cout << "You take: " << damageTaken << " damage." << endl;
						player.PlayerHealthDamage(damageTaken);
						combatOngoing = true;
					}
				}
			}
			else if (playerIn == "heal") {
				cout << "Checking for healing potion..." << endl;

				for (i = 0; i < player.playerInventory.size(); i++) {
					if (player.playerInventory.at(i) == "PotionHP") {
						hasPotion = true;
						potionPos = i;
					}
				}
				if (hasPotion == true) {
					cout << "Healing damage..." << endl;
					for (i = 0; i < items.size(); i++) {
						if (items.at(i).GetItemName() == "PotionHP"&& gotPotion ==false) {
							amtHealed = items.at(i).GetItemSpecialVal();
							gotPotion = true;
							hasPotion = false;
							player.playerInventory.at(potionPos) = "";
						}
					}
					cout << "Healed for: " << amtHealed << endl;	
					player.PlayerHealthHeal(amtHealed);
				}
				else {
					cout << "No healing potion!" << endl;
				}
			}
			else if (playerIn == "run") {
				cout << "You run away!" << endl;
				combatOngoing = false;
				monstersHere = true;
				player.CheckLevelUp(levels);
				GetRandomValidRoom(rooms, currentRoom, roomsWidth);
				
			}
			else {
				cout << "Please input a correct command!" << endl;
			}
			if (player.GetPlayerHealth() <= 0) {
				cout << "You have lost all health! Game Over!" << endl;
				combatOngoing = false;
				break;
				playerAlive = false;
			}
		}
		
	return;
}



//Removed: vector<string> roomDesc,
void adventureGame(std::vector<MonstersRPG> monsterList, vector<int> rooms, int roomsWidthIn, int roomsHeightIn, int victoryRoom, vector<WorldMonsters> monstersPosition, vector<string> roomDesc, vector<Items> ItemsList, vector<Leveling> levels, int startingRoom) {

	PlayerRPG player;
	player.InitializeAttack(5);
	player.InitializeHealth(15);
	player.InitializeXP(0);
	player.InitializePlayerLevel(0);
	player.InitializePlayerDefense(1);
	player.InitializePlayerInventory();
	string playerNameIn = "";
	cout << "What is your name adventurer?" << endl;
	getline(cin, playerNameIn);
	player.InitializePlayerName(playerNameIn);
	bool playerAlive = true;
	int roomsWidth = roomsWidthIn;
	int roomsHeigh = roomsHeightIn;
	
	//N, S, E, W
	//0 = no door, 1 = open door, 2 = locked
	
	//Figure out a way to check for locked number of doors
	int currentlyLockedDoors = 0;
	int i = 0;
	for (i = 0; i < rooms.size(); i++) {
		if (rooms.at(i) == 2) {
			currentlyLockedDoors++;
		}
	}

	bool gameOn = true;
	bool gameWon = false;
	string playerIn = "";
	int currentRoom = startingRoom;
	string currentRoomDescription = "";
	cout << "Welcome to the dungeon " << player.GetPlayerName() << "." << endl;
	int playerItemSel = -1;
	bool roomValid = false;

	bool foundItem = false;

	bool hasItem = false;
	int k = 0;
	bool playerItemSelTrue = false;
	bool notTakeItem = true;
	

	int monsterCheck;
	bool monstersHere = false;

	//Setup locks for doors
	string doorLockedN = "";
	string doorLockedS = "";
	string doorLockedE = "";
	string doorLockedW = "";
	bool hasKey = false;
	bool lockedDoorCurr = false;
	int keyPos = -1;
	int itemInRoom = 0;

	bool hasPotion = true;
	int potionPos = 0;
	int amtHealed = 0;
	bool gotPotion = false;

	vector<int> currentItems(0);
	while (gameOn != false) {
		cout << "Please input an action. Available actions are: move, attack, look, open, take, inv, quit." << endl;
		cin >> playerIn;
		system("cls");
		if (playerIn == "move") {
			cout << "Which direction would you like to move? Directions are N, S, E, W." << endl;
			cin >> playerIn;
			
			//With movement add way to move character to room

			//Check for width and height of map and subtract accordingly
			
			//Add check for Event and it's variables
			//Int: eventRoom, Int: eventType, Int: SpecVar1, Int: SpecVar2, Int: SpecVar3, String eventDescription, String eventResolvedDescription
			if (playerIn == "N" || playerIn == "n") {
				if (rooms.at(currentRoom) == 0) {
					cout << "No door exists." << endl;
					//Not sure why I was doing this function, do some think tanking
					//checkRoomValid(rooms.at(currentRoom), 0, roomValid);
				}
				else if (rooms.at(currentRoom) == 1) {
					cout << "Moving to next room..." << endl;
					moveToRoom(0, currentRoom, roomsWidth);
					roomDescription(currentRoom, roomDesc);

				}
				else if (rooms.at(currentRoom) == 2) {
					cout << "Door locked!" << endl;
				}
			}
			else if (playerIn == "S" || playerIn == "s") {
				if (rooms.at(currentRoom + 1) == 0) {
					cout << "No door exists." << endl;
				}
				else if (rooms.at(currentRoom + 1) == 1) {
					cout << "Moving to next room..." << endl;
					moveToRoom(1, currentRoom, roomsWidth);
					roomDescription(currentRoom, roomDesc);

				}
				else if (rooms.at(currentRoom + 1) == 2) {
					cout << "Door locked!" << endl;
				}
			}
			else if (playerIn == "E" || playerIn == "e") {
				if (rooms.at(currentRoom + 2) == 0) {
					cout << "No door exists." << endl;
				}
				else if (rooms.at(currentRoom + 2) == 1) {
					cout << "Moving to next room..." << endl;
					moveToRoom(2, currentRoom, roomsWidth);
					roomDescription(currentRoom, roomDesc);

				}
				else if (rooms.at(currentRoom + 2) == 2) {
					cout << "Door locked!" << endl;
				}
			}
			else if (playerIn == "W" || playerIn == "w") {
				if (rooms.at(currentRoom + 3) == 0) {
					cout << "No door exists." << endl;
				}
				else if (rooms.at(currentRoom + 3) == 1) {
					cout << "Moving to next room..." << endl;
					moveToRoom(3, currentRoom, roomsWidth);
					roomDescription(currentRoom, roomDesc);
				}
				else if (rooms.at(currentRoom + 3) == 2) {
					cout << "Door locked!" << endl;
				}
			}
			else {
				cout << "Please input a correct value." << endl;
			}
		}
		else if (playerIn == "attack") {
			cout << "Checking for monsters." << endl;
			//Check for monsters in room
			monstersHere = false;
			for (i = 0; i < monstersPosition.size(); i++) {
				monsterCheck = monstersPosition.at(i).getPosition();
				if (monsterCheck == currentRoom) { //Contains monsters
					cout << "Begin combat!" << endl;
					monstersHere = true;
					
				}
			}
			if (monstersHere == false) {
				cout << "No monsters here silly!" << endl;
			}
			if (monstersHere == true) {
				rpgBattle(monstersPosition, monsterList, currentRoom, playerAlive, player, monstersHere, levels, ItemsList,rooms, roomsWidth);
			}
		}
		else if (playerIn == "look") {
			roomDescription(currentRoom, roomDesc);
			checkForItem(currentRoom, ItemsList);
			//Add code for Saying what monsters are in the room
			for (i = 0; i < monstersPosition.size(); i++) {
				if (monstersPosition.at(i).getPosition() == currentRoom) {
					cout << "A " << monstersPosition.at(i).getName() << " sits in the room." << endl;
					monstersHere = true;
				}
			}
			if (monstersHere = true) {
				cout << "Oh no! The monster attacks!" << endl;
				rpgBattle(monstersPosition, monsterList, currentRoom, playerAlive, player, monstersHere, levels, ItemsList, rooms, roomsWidth);
			}

			//Previous look code
			//currentRoomDescription = roomDesc.at(currentRoom);
			//cout << currentRoomDescription << endl;
		}
		else if (playerIn == "open") {
			doorLockedN = "";
			doorLockedS = "";
			doorLockedE = "";
			doorLockedW = "";
			hasKey = false;
			keyPos = -1;
			lockedDoorCurr = false;
			for (i = 0; i < player.playerInventory.size(); i++) {
				if (player.playerInventory.at(i) == "Key") {
					hasKey = true;
					keyPos = i;
				}
			}

			if (rooms.at(currentRoom) == 2) {
				doorLockedN = "N";
				lockedDoorCurr = true;
			}
			if (rooms.at(currentRoom + 1) == 2) {
				doorLockedS = "S";
				lockedDoorCurr = true;
			}
			if (rooms.at(currentRoom + 2) == 2) {
				doorLockedE = "E";
				lockedDoorCurr = true;
			}
			if (rooms.at(currentRoom + 3) == 2) {
				doorLockedW = "W";
				lockedDoorCurr = true;
			}
			if (hasKey == true) {

				if (lockedDoorCurr == true) {
					cout << "Currently locked doors are: " << doorLockedN << " " << doorLockedS << " " << doorLockedE << " " << doorLockedW << endl;
					cout << "Choose a door to open: N, S, E, W. Press any other key to not open a door.";
					cin >> playerIn;

					if (doorLockedN == "N" && (playerIn == "N" || playerIn == "n")) {
						//adjust value for Rooms.at(currRoom)
						rooms.at(currentRoom) = 1;
						player.playerInventory.at(keyPos) = "";
						cout << "Door to the north opened." << endl;
					}
					else if (doorLockedS == "S" && (playerIn == "S" || playerIn == "s")) {
						rooms.at(currentRoom + 1) = 1;
						player.playerInventory.at(keyPos) = "";
						cout << "Door to the south opened." << endl;
					}
					else if (doorLockedE == "E" && (playerIn == "E" || playerIn == "e")) {
						rooms.at(currentRoom + 2) = 1;
						player.playerInventory.at(keyPos) = "";
						cout << "Door to the east opened." << endl;
					}
					else if (doorLockedW == "W" && (playerIn == "W" || playerIn == "w")) {
						rooms.at(currentRoom + 3) = 1;
						player.playerInventory.at(keyPos) = "";
						cout << "Door to the west opened." << endl;
					}
					else {
								
					}
				}
				else {
					cout << "No locked doors in this room!" << endl;
				}
			}
			else {
				cout << "You don't have a key!" << endl;
			}
		}
		//For inventory functions, take the name, 
		//then to check the position of the name in the master arrays for a for loop to find a matching string name
		//Add choose to pickup

		else if (playerIn == "take") {
			playerItemSel = -1;
			notTakeItem = true;
			playerItemSelTrue = false;
			itemInRoom = 0;
			currentItems.resize(0);
			//Do second for loop here to put in next available space
			cout << "Items here are: ";
			for (i = 0; i < ItemsList.size(); i++) {
				
				if(ItemsList.at(i).GetItemPos() == currentRoom && ItemsList.at(i).GetItemName() != ""){
					cout << " " << itemInRoom << ") " << ItemsList.at(i).GetItemName() << ", ";
					itemInRoom = itemInRoom++;
					currentItems.push_back(i);
				}
			}
			cout << "What item do you want to pick up?" << endl;
			while (playerItemSelTrue == false) {

				cin >> playerItemSel;
				if (playerItemSel >= itemInRoom) {
					cout << "Please select a value that exists." << endl;
				}
				else {
					//Fix this statement
					for (i = 0; i < ItemsList.size(); i++) {
						if (ItemsList.at(i).GetItemNumber() == currentItems.at(playerItemSel)) {
							for (k = 0; k < player.playerInventory.size(); k++) {
								//if statement here
								if (player.playerInventory.at(k) == "" && notTakeItem == true) {
									player.playerInventory.at(k) = ItemsList.at(i).GetItemName();
									notTakeItem = false;
									cout << ItemsList.at(i).GetItemName() << " added to inventory." << endl;
									ItemsList.at(i).InitializeItemPosition(-1);
									foundItem = true;
									playerItemSelTrue = true;
								}
							}
							
						}
					}
					if (notTakeItem == true) {
						cout << "No room in inventory." << endl;
						break;
					}
					if (playerItemSelTrue == false) {
						cout << "That value has nothing in it!" << endl;
					}
				}
			}
			//Why is this here?
			/*
			for (i = 0; i < ItemsList.size(); i++) {
				if (ItemsList.at(i).GetItemPos() == currentRoom) {
					
					
				}
			}*/
		}
		else if (playerIn == "inv") {
			playerItemSelTrue = false;
			hasItem = false;
			//Setup way to ask what item in what slot
			//1)stick,2)key
			cout << "What item would you like to inspect?" << endl;
			for (i = 0; i < player.playerInventory.size(); i++) {
				if (player.playerInventory.at(i) != "") {
					hasItem = true;
				}
			}
			if (hasItem == true) {
				cout << "Current items are: ";
				for (i = 0; i < player.playerInventory.size(); i++) {
					if (player.playerInventory.at(i) != "") {
						cout << i << ") " << player.playerInventory.at(i) << ",";
					}
				}
				cout << endl;
			}
			else {
				cout << "You have no items." << endl;
			}
			//Wait for player input
			if (hasItem == true) {
				while (playerItemSelTrue == false) {

					cin >> playerItemSel;
					if (playerItemSel < 0 || playerItemSel > 3) {
						cout << "Please select a value that exists." << endl;
					}
					else {
						//Fix this statement
						for (i = 0; i < ItemsList.size(); i++) {
							if (ItemsList.at(i).GetItemName() == player.playerInventory.at(playerItemSel)) {
								cout << ItemsList.at(i).GetItemDesc() << endl; 
								playerItemSelTrue = true;
							}
						}
						if (playerItemSelTrue == false) {
							cout << "That value has nothing in it!" << endl;
						}
					}
				}
			}
		}
		else if (playerIn == "drop") {
			playerItemSelTrue = false;
			hasItem = false;
			//Setup way to ask what item in what slot
			//1)stick,2)key
			cout << "What item would you like to drop?" << endl;
			for (i = 0; i < player.playerInventory.size(); i++) {
				if (player.playerInventory.at(i) != "") {
					hasItem = true;
				}
			}
			if (hasItem == true) {
				cout << "Current items are: ";
				for (i = 0; i < player.playerInventory.size(); i++) {
					if (player.playerInventory.at(i) != "") {
						cout << i << ") " << player.playerInventory.at(i) << ",";
					}
				}
				cout << endl;
			}
			else {
				cout << "You have no items." << endl;
			}
			//Wait for player input
			if (hasItem == true) {
				while (playerItemSelTrue == false) {

					cin >> playerItemSel;
					if (playerItemSel < 0 || playerItemSel > 3) {
						cout << "Please select a value that exists." << endl;
					}
					else {
						//Fix this statement
						for (i = 0; i < ItemsList.size(); i++) {
							if (ItemsList.at(i).GetItemName() == player.playerInventory.at(playerItemSel)&& playerItemSelTrue==false) {
								cout << player.playerInventory.at(playerItemSel) << " dropped on the floor. " << endl;
								player.playerInventory.at(playerItemSel) = "";
								ItemsList.at(i).InitializeItemPosition(currentRoom);
								playerItemSelTrue = true;
								
							}
						}
						if (playerItemSelTrue == false) {
							cout << "That value has nothing in it!" << endl;
						}
					}
				}
			}
		}

		else if (playerIn == "use") {
			playerItemSelTrue = false;
			hasItem = false;
			//Setup way to ask what item in what slot
			//1)stick,2)key
			cout << "What item would you like to use?" << endl;
			for (i = 0; i < player.playerInventory.size(); i++) {
				if (player.playerInventory.at(i) != "") {
					hasItem = true;
				}
			}
			if (hasItem == true) {
				cout << "Current items are: ";
				for (i = 0; i < player.playerInventory.size(); i++) {
					if (player.playerInventory.at(i) != "") {
						cout << i << ") " << player.playerInventory.at(i) << ",";
					}
				}
				cout << endl;
			}
			else {
				cout << "You have no items." << endl;
			}

			if (hasItem == true) {
				while (playerItemSelTrue == false) {

					cin >> playerItemSel;
					if (playerItemSel < 0 || playerItemSel > 3) {
						cout << "Please select a value that exists." << endl;
					}
					else {
						//Fix this statement
						for (i = 0; i < ItemsList.size(); i++) {
							if (ItemsList.at(i).GetItemName() == player.playerInventory.at(playerItemSel)) {
								if (ItemsList.at(i).GetItemType() == 0) {
									//Nothing
								}
								if (ItemsList.at(i).GetItemType() == 1) {
									//Health potion
									cout << "Checking for healing potion..." << endl;

									for (i = 0; i < player.playerInventory.size(); i++) {
										if (player.playerInventory.at(i) == "PotionHP") {
											hasPotion = true;
											potionPos = i;
										}
									}
									if (hasPotion == true) {
										cout << "Healing damage..." << endl;
										for (i = 0; i < ItemsList.size(); i++) {
											if (ItemsList.at(i).GetItemName() == "PotionHP"&& gotPotion == false) {
												amtHealed = ItemsList.at(i).GetItemSpecialVal();
												gotPotion = true;
												hasPotion = false;
												player.playerInventory.at(potionPos) = "";
											}
										}
										cout << "Healed for: " << amtHealed << endl;
										player.PlayerHealthHeal(amtHealed);
									}
									else {
										cout << "No healing potion!" << endl;
									}
								}
								if (ItemsList.at(i).GetItemType() == 2) {
									//Weapon
									player.EquipPlayerWeapon(ItemsList.at(i).GetItemName());
									cout << "Equipped " << ItemsList.at(i).GetItemName() << " to weapon slot." << endl;
								}
								if (ItemsList.at(i).GetItemType() == 3) {
									//Armor
									player.EquipPlayerArmor(ItemsList.at(i).GetItemName());
									cout << "Equipped " << ItemsList.at(i).GetItemName() << " to armor slot." << endl;
								}
								if (ItemsList.at(i).GetItemType() == 4) {
									//Lever / button
									//Add check for event that needs button?
								}
								
							}
						}
						if (playerItemSelTrue == false) {
							cout << "That value has nothing in it!" << endl;
						}
					}
				}
			}

		}

		else if (playerIn == "quit") {
			cout << "Thanks for playing " << player.GetPlayerName() << "!" << endl;
			gameOn = false;
		}

		else {
			cout << "Please input a correct action." << endl;
		}

		if (playerAlive != true) {
			cout << "Game Over " << player.GetPlayerName() << ". Try again next time." << endl;
			gameOn = false;
		}
		if (currentRoom == victoryRoom) {
			gameWon = true;
		}
		if (gameWon == true) {
			cout << "You have escaped! You Win " << player.GetPlayerName() << "! Play again soon!" << endl;
			gameOn = false;
		}
	}
	return;
}



int main() {
	int width = 100;
	int height = 75;

	Console::SetWindowSize(width, height);
	srand(time(NULL));
	//int randomNumber = (rand() % 8) + 1;
	//Example of 100: int r = (rand() % 100) + 1;

	/**PlayRPG startGame;
	PlayerRPG player;
	MonstersRPG monster1;
	MonstersRPG monster2;**/

	//In here need to initialize a way to get all monsters in battle
	//setup array listing of some basic monsters and pull from that

	//Create test input vectors
	//Remove this in cleanup
	vector<string> monsterNames(1);
	vector<int> monsterHP(1);
	vector<int> monsterDmg(1);
	int i = 0;
	int amountMonsters = 0;
	string monsterNameIn;
	int monsterHPIn;
	int monsterDmgIn;
	int monsterXPIn;
	monsterNames.at(0) = "TestBoy";
	monsterHP.at(0) = 2;
	monsterDmg.at(0) = 1;
	
	
	//Imported from employee pay project. Fixing.
	// Need an input file variable reference
	ifstream fin;
	//Need to init ofstream
	//ofstream monstersIn;
	//Sets string for user input
	string fileName;
	string fileTitle;

	cout << "Got here." << endl;

	//fileName = "C:\\Users\\Isaac\\Documents\\monstersA.txt";
	fileTitle = "monstersA.txt";
	//cin >> fileName;
	//cout << fileName;
	//Had an error where fin.open would overload, put actual fileName in seperate string
	//Takes last section of fileName to find file name
	//fileTitle = fileName.c_str();

	//Opens file
	fin.open(fileTitle);

	/**while (!fin.eof()) {
		fin >> monsterNameIn;
		monsterNames.push_back(monsterNameIn);
		fin >> monsterHPIn;
		monsterHP.push_back(monsterHPIn);
		fin >> monsterDmgIn;
		monsterDmg.push_back(monsterDmgIn);

		amountMonsters++;
	}

	for (i = 0; i < amountMonsters; i++) {
		cout << monsterNames.at(i) << " ";
		cout << monsterHP.at(i) << " ";
		cout << monsterDmg.at(i) << endl;
	}
	**/
	//Monsters in
	std::vector<MonstersRPG> monsterList(1);
	i = 0;
	int j = 1;
	while (!fin.eof()) {	
		fin >> monsterNameIn;
		monsterList.at(i).InitializeName(monsterNameIn);
		fin >> monsterHPIn;
		fin >> monsterDmgIn;
		fin >> monsterXPIn;
		monsterList.at(i).InitializeHealth(monsterHPIn);
		monsterList.at(i).InitializeAttack(monsterDmgIn);
		monsterList.at(i).InitializeXP(monsterXPIn);
		// >> monsterList.GetHP(monsterHPIn);
		//fin >> monsterList.GetDmg(monsterDmg);

		//monsterList.at(i) = monsterList.GetName(monsterNameIn);
		if (!fin.eof()) {
			i++;
			j++;
			monsterList.resize(j);
		}
	}
	int x = 0;
	//for(x = 0; x < monsterList.size(); x++) {
		//Fix this to be display name code
	//	monsterList.at(x).DisplayName();
	//}
	fin.close();

	//Monster Positioning
	fileTitle = "monsterPositionFileA.txt";
	fin.open(fileTitle);
	string monsterNameCall;
	int monsterPositionCall;
	int hasKey;
	i = 0;
	j = 1;
	vector<WorldMonsters> monstersPosition(1);
	while (!fin.eof()) {
		fin >> monsterNameCall;
		fin >> monsterPositionCall;
		fin >> hasKey;
		monstersPosition.at(i).addName(monsterNameCall);
		monstersPosition.at(i).addPosition(monsterPositionCall);
		monstersPosition.at(i).addHasKey(hasKey);
		if (!fin.eof()) {
			i++;
			j++;
			monstersPosition.resize(j);
		}
	}
	//for (i = 0; i < monstersPosition.size(); i++) {
	//	cout << monstersPosition.at(i).getName() << endl;
	//}
	fin.close();

	//Rooms in
	vector<int> rooms(1);
	int y = 0;
	int z = 1;
	int roomsWidthIn = 0;
	int roomsHeightIn = 0;
	int victoryRoom = 0;
	int startingRoom = 0;
	int currentRoomInput = -1;
	//cout << "Please input room file" << endl;
	string roomFile = "roomsA.txt";
	//cin >> fileName;
	//Takes last section of fileName to find file name
	//fileTitle = fileName.c_str();
	//Opens file
	fin.open(roomFile);
	fin >> roomsWidthIn;
	fin >> roomsHeightIn;
	fin >> victoryRoom;
	fin >> startingRoom;
	while (!fin.eof()) {
		fin >> currentRoomInput;
		rooms.at(y) = currentRoomInput;
		if (!fin.eof()) {
			y++;
			z++;
			rooms.resize(z);
			currentRoomInput = 0;
		}
	}
	//for (i = 0; i < rooms.size(); i++) {
	//	cout << rooms.at(i);
	//}
	fin.close();
	//Come back to this with dad

	vector<string> roomDesc(4);
	int a = 0;
	int b = 4;
	roomFile = "roomsDescriptionA.txt";
	string descriptionIn = "";
	fin.open(roomFile);
	while (!fin.eof()) {
		//fin getline >> descriptionIn;
		fin >> std::quoted(descriptionIn);
		roomDesc.at(a) = descriptionIn;
		roomDesc.at(a + 1) = "";
		roomDesc.at(a + 2) = "";
		roomDesc.at(a + 3) = "";

		if (!fin.eof()) {
			b = b + 4;
			a = a + 4;
			roomDesc.resize(b);
			descriptionIn = "";
		}
		
	}
	fin.close();
	//for (i = 0; i < roomDesc.size(); i++) {
	//	cout << roomDesc.at(i) << endl;
	//}

	//Item Descriptions, Item Lists, Item World Descriptiors
	vector<Items> ItemsList(1);
	a = 0;
	b = 1;
	roomFile = "itemsA.txt";
	string itemName = "";
	int itemPos = 0;
	string itemDesc = "";
	string itemWorldDesc = "";
	int itemType = 0;
	int itemSpecVal = 0;
	int itemNum = 0;
 	fin.open(roomFile);

	while (!fin.eof()) {
		fin >> std::quoted(itemName);	
		fin >> itemPos;	
		fin >> itemType;	
		fin >> itemSpecVal;
		fin >> std::quoted(itemDesc);
		fin >> std::quoted(itemWorldDesc);
		ItemsList.at(a).InitializeItemName(itemName);
		ItemsList.at(a).InitializeItemPosition(itemPos);
		ItemsList.at(a).InitializeItemType(itemType);
		ItemsList.at(a).InitializeSpecialVal(itemSpecVal);
		ItemsList.at(a).InitializeItemDescription(itemDesc);
		ItemsList.at(a).InitializeItemWorldDescription(itemWorldDesc);
		ItemsList.at(a).InitializeItemNumber(itemNum);
		if (!fin.eof()) {
			a = a + 1;
			b = b + 1;
			ItemsList.resize(b);
			itemName = "";
			itemPos = 0;
			itemDesc = "";
			itemWorldDesc = "";
			itemPos = 0;
			itemType = 0;
			itemNum++;
		}
			
	}
	fin.close();

	//Leveling in
	vector<Leveling> levels(1);
	fileTitle = "playerLevelsA.txt";
	a = 0;
	b = 1;
	int levelIn = 0;
	int hpIn = 0;
	int attackIn = 0;
	int defenseIn = 0;
	int xpIn = 0;
	fin.open(fileTitle);
	while (!fin.eof()) {
		fin >> levelIn;
		fin >> hpIn;
		fin >> attackIn;
		fin >> defenseIn;
		fin >> xpIn;
		levels.at(a).InitializeLevel(levelIn);
		levels.at(a).InitializeHealth(hpIn);
		levels.at(a).InitializeAttack(attackIn);
		levels.at(a).InitializeDefense(defenseIn);
		levels.at(a).InitializeXpNeeded(xpIn);
		if (!fin.eof()) {
			a = a + 1;
			b = b + 1;
			levels.resize(b);
			levelIn = 0;
			hpIn = 0;
			attackIn = 0;
			defenseIn = 0;
			xpIn = 0;
		}
	}
	fin.close();
/*
	vector<Events> eventsList(1);
	int eventRoom = 0;
	int eventType = 0;
	int SpecVar1 = 0;
	int SpecVar2 = 0;
	int SpecVar3 = 0;
	string eventDescription = "";
	string eventResolvedDescription = "";
	a = 0;
	b = 0;
	fileTitle = "eventsA.txt";
	fin.open(fileTitle);
	while (!fin.eof()) {
		fin >> eventRoom;
		fin >> eventType;
		fin >> SpecVar1;
		fin >> SpecVar2;
		fin >> SpecVar3;
		fin >> eventDescription;
		fin >> eventResolvedDescription;

		eventsList.at(a).InitializeEventRoom(eventRoom);
		eventsList.at(a).InitializeEventType(eventType);
		eventsList.at(a).InitializeSpecVar1(SpecVar1);
		eventsList.at(a).InitializeSpecVar2(SpecVar2);
		eventsList.at(a).InitializeSpecVar3(SpecVar3);
		eventsList.at(a).InitializeEventDescription(eventDescription);
		eventsList.at(a).InitializeEventResolvedDescription(eventResolvedDescription);
		if (!fin.eof()) {
			a = a + 1;
			b = b + 1;
			eventsList.resize(b);
			int eventRoom = 0;
			int eventType = 0;
			int SpecVar1 = 0;
			int SpecVar2 = 0;
			int SpecVar3 = 0;
			string eventDescription = "";
			string eventResolvedDescription = "";
		}
	}
	*/
	//cout << "Ready to play? Let's go!" << endl;
	
	adventureGame(monsterList, rooms, roomsWidthIn, roomsHeightIn, victoryRoom, monstersPosition, roomDesc, ItemsList, levels, startingRoom);



	return 0;
}