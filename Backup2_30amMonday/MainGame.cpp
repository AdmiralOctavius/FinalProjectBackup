/****************
Name: Isaac Bennett
Course: CIT 163-202
Due Date: 4/24/2017
*****************
Files for assignment: MainGame.cpp, monstersA.txt, monsterPositionFileA.txt, roomsA.txt, roomsDescription.txt
Files continued: ItemsA.txt, ItemsDescriptionA.txt, ItemsWorldDescriptionA.txt, ItemPositionA.txt, playerLevels.txt, 
Purpose of file: Adventure Game program
*****************/
//Major note: all text files need to be in same folder as MainGame.cpp

//Importation list
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

//Namespace calls
using namespace std;
using namespace System;

//Class Leveling, sets the level requirements and rewards for leveling up
class Leveling {
public:
	//Setters
	void InitializeLevel(int levelIn);
	void InitializeHealth(int healthIn);
	void InitializeAttack(int attackIn);
	void InitializeDefense(int defenseIn);
	void InitializeXpNeeded(int xpNeededIn);
	//Getters
	int GetXpNeeded();
	int GetHealth();
	int GetAttack();
	int GetDefense();
private:
	//Various variables
	int level;
	int health;
	int attack;
	int defense;
	int xpNeeded;
};

//Get health variable
int Leveling::GetHealth() {
	return health;
}

//Get attack variable
int Leveling::GetAttack() {
	return attack;
}

//Get defense variable
int Leveling::GetDefense() {
	return defense;
}

//Get Xp needed for next level
int Leveling::GetXpNeeded() {
	return xpNeeded;
}

//Set level
void Leveling::InitializeLevel(int levelIn) {
	level = levelIn;
	return;
}

//Set health
void Leveling::InitializeHealth(int healthIn) {
	health = healthIn;
	return;
}

//Set attack
void Leveling::InitializeAttack(int attackIn) {
	attack = attackIn;
	return;
}

//Set defense
void Leveling::InitializeDefense(int defenseIn) {
	defense = defenseIn;
	return;
}

//Set XpNeeded
void Leveling::InitializeXpNeeded(int xpNeededIn){
	xpNeeded = xpNeededIn;
	return;
}


//Class Player, contains variables for the player and functions to access this
class PlayerRPG {
	public:
		//Constructor
		PlayerRPG();

		//Public variable playerInventory
		vector<string> playerInventory;
	
		//Various functions
		//Setters
		void InitializeHealth(int playerHealthIn);
		void InitializeAttack(int playerAttackIn);
		void InitializeXP(int playerXPIn);
		void InitializePlayerLevel(int playerLevelIn);
		void InitializePlayerDefense(int playerDefenseIn);
		void InitializePlayerInventory();
		void InitializePlayerName(string playerNameIn);
		//Getters
		int GetPlayerHealth();
		int GetPlayerAttack();
		int GetPlayerXP();
		int GetPlayerDefense();
		string GetPlayerName();
		string GetPlayerInventoryAt(int position);
		string GetPlayerEquipWeapon();
		string GetPlayerEquipArmor();
		//Modifiers or checkers
		void PlayerHealthDamage(int amountDamaged);
		void PlayerHealthHeal(int amountHealed);
		void PlayerXPAdd(int amountXP);
		void CheckLevelUp(vector<Leveling> levels);
		void EquipPlayerWeapon(string itemWeaponIn);
		void EquipPlayerArmor(string itemArmorIn);
		

	private:
		//Player variables
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

//Constructor
PlayerRPG::PlayerRPG() : playerInventory(4) {
	return;
}

//Set player health cap
void PlayerRPG::InitializeHealth(int playerHealthIn) {
	playerHealth = playerHealthIn;
	playerMaxHealth = playerHealthIn;
	return;
}

//Set player attack
void PlayerRPG::InitializeAttack(int playerAttackIn) {
	playerAttack = playerAttackIn;
	return;
}


//Set player Xp
void PlayerRPG::InitializeXP(int playerXPIn) {
	playerXP = playerXPIn;
	return;
}

//Set player level
void PlayerRPG::InitializePlayerLevel(int playerLevelIn) {
	playerLevel = playerLevelIn;
	return;
}

//Set player defense
void PlayerRPG::InitializePlayerDefense(int playerDefenseIn) {
	playerDefense = playerDefenseIn;
	return;
}

// Set playerInventory
void PlayerRPG::InitializePlayerInventory() {
	playerInventory.at(0) = "";
	playerInventory.at(1) = "";
	playerInventory.at(2) = "";
	playerInventory.at(3) = "";
	return;
}

//Set playerName
void PlayerRPG::InitializePlayerName(string playerNameIn) {
	playerName = playerNameIn;
	return;
}

//Get currently equipped weapon
string PlayerRPG::GetPlayerEquipWeapon() {
	return playerEquipWeapon;
}

//Get currently equipped armor
string PlayerRPG::GetPlayerEquipArmor() {
	return playerEquipArmor;
}
//Get player health
int PlayerRPG::GetPlayerHealth() {
	return playerHealth;
}

//Get player attack
int PlayerRPG::GetPlayerAttack() {
	return playerAttack;
}

//Get player Xp
int PlayerRPG::GetPlayerXP() {
	return playerXP;
}

//Get player defense
int PlayerRPG::GetPlayerDefense() {
	return playerDefense;
}

//Get playerName
string PlayerRPG::GetPlayerName() {
	return playerName;
}

//Get player inventory at given position
string PlayerRPG::GetPlayerInventoryAt(int position) {
	return playerInventory.at(position);
}

//Damage player for amount given
void PlayerRPG::PlayerHealthDamage(int amountDamaged) {
	playerHealth = playerHealth - amountDamaged;
	return;
}

//Heal player's health for amount given
void PlayerRPG::PlayerHealthHeal(int amtHealed) {
	playerHealth = playerHealth + amtHealed;
	return;
}

//Add xp to player's total
void PlayerRPG::PlayerXPAdd(int amountXP) {
	playerXP = playerXP + amountXP;
	return;
}

//Check for player level up
void PlayerRPG::CheckLevelUp(vector<Leveling> levels) {
	//Compare player xp with Class levels
	//If greater than next level xp requirement level up
	if (playerXP >= levels.at(playerLevel+1).GetXpNeeded()) {
		//Set new max values
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

//Set the current weapon
void PlayerRPG::EquipPlayerWeapon(string itemWeaponIn) {
	playerEquipWeapon = itemWeaponIn;
	return;
}

//Set the current armor
void PlayerRPG::EquipPlayerArmor(string itemArmorIn) {
	playerEquipArmor = itemArmorIn;
	return;
}


//Class MonstersRPG, sets various variables and has some setters
class MonstersRPG {

	public:
		//Setters
		void InitializeXP(int monsterXPIn);
		void InitializeName(string monsterNameIn);
		void InitializeAttack(int monsterAttackIn);
		void InitializeHealth(int monsterHPIn);
		//Getters
		int GetMonsterHealth();
		int GetMonsterAttack();
		string ShowName();
		int GetXP();

	private:
		//Variables
		int monsterHealth;
		int monsterAttack;
		string monsterName;
		int monsterXPValue;
};

//Set xp value
void MonstersRPG::InitializeXP(int monsterXPIn) {
	monsterXPValue = monsterXPIn;
	return;
}

//Set monster name
void MonstersRPG::InitializeName(string monsterNameIn) {
	monsterName = monsterNameIn;
	return;
}

//Set monster attack
void MonstersRPG::InitializeAttack(int monsterAttackIn) {
	monsterAttack = monsterAttackIn;
	return;
}

//Set monster health
void MonstersRPG::InitializeHealth(int monsterHPIn) {
	monsterHealth = monsterHPIn;
	return;
}

//Get health
int MonstersRPG::GetMonsterHealth() {
	return monsterHealth;
}

//Get attack
int MonstersRPG::GetMonsterAttack() {
	return monsterAttack;
}

//Get name
string MonstersRPG::ShowName() {
	return monsterName;
}

//Get xp
int MonstersRPG::GetXP() {
	return monsterXPValue;
}


//Class WorldMonsters, sets monsters position in the world
class WorldMonsters {
	public:
		//Setters
		void addName(string monsterNameCall);
		void addPosition(int monsterPositionCall);
		//Getters
		string getName();
		int getPosition();
	private:
		//Variables
		string monsterName;
		int monsterPosition;
		int hasKey;
};

//Set name
void WorldMonsters::addName(string monsterNameCall) {
	monsterName = monsterNameCall;
	return;
}

//Set position
void WorldMonsters::addPosition(int monsterPositionCall) {
	monsterPosition = monsterPositionCall;
	return;
}

//Get name
string WorldMonsters::getName() {
	return monsterName;
}

//Get position
int WorldMonsters::getPosition() {
	return monsterPosition;
}

//Class Items, setups list of items and their variables
class Items {
	public:
		//Setters
		void InitializeItemName(string ItemNameIn);
		void InitializeItemPosition(int ItemPositionIn);
		void InitializeItemType(int ItemTypeIn);
		void InitializeItemDescription(string ItemDescriptionIn);
		void InitializeItemWorldDescription(string ItemWorldDescriptionIn);
		void InitializeSpecialVal(int ItemSpecialValIn);
		void InitializeItemNumber(int ItemNumIn);

		//Getters
		string GetItemName();
		int GetItemPos();
		int GetItemType();
		string GetItemDesc();
		string GetItemWorldDesc();
		int GetItemSpecialVal();
		int GetItemNumber();

	private:
		//Variables
		string ItemName;
		int ItemPosition; 
		int ItemType;
		string ItemDescription;
		string ItemWorldDescription;
		int ItemSpecialVal;
		int ItemNumber;
		
};

//Set item name
void Items::InitializeItemName(string ItemNameIn) {
	ItemName = ItemNameIn;
	return;
}

//Set item position
void Items::InitializeItemPosition(int ItemPositionIn) {
	ItemPosition = ItemPositionIn;
	return;
}

//Set item type
void Items::InitializeItemType(int ItemTypeIn) {
	ItemType = ItemTypeIn;
	return;
}

//Set item's in inventory description
void Items::InitializeItemDescription(string ItemDescriptionIn) {
	ItemDescription = ItemDescriptionIn;
	return;
}

//Set item's world description
void Items::InitializeItemWorldDescription(string ItemWorldDescriptionIn) {
	ItemWorldDescription = ItemWorldDescriptionIn;
	return;
}

//Set items's special variable
void Items::InitializeSpecialVal(int ItemSpecValIn) {
	ItemSpecialVal = ItemSpecValIn;
	return;
}

//Set item number
void Items::InitializeItemNumber(int ItemNumIn) {
	ItemNumber = ItemNumIn;
	return;
}

//Get item name
string Items::GetItemName() {
	return ItemName;
}

//Get item position
int Items::GetItemPos() {
	return ItemPosition;
}

//Get item description
string Items::GetItemDesc() {
	return ItemDescription;
}

//Get item world description
string Items::GetItemWorldDesc() {
	return ItemWorldDescription;
}

//Get item special val
int Items::GetItemSpecialVal() {
	return ItemSpecialVal;
}

//Get item type
int Items::GetItemType() {
	return ItemType;
}

//Get item number
int Items::GetItemNumber() {
	return ItemNumber;
}


//Move between rooms code
void moveToRoom(int roomDirection, int& currentRoom, int width) {
	//North = 0
	if (roomDirection == 0) {
		//North means we have to go up a row
		//Take width of current row and multiply by four, subtract that from currentRoom
		currentRoom = currentRoom - (width * 4);
	}
	//South = 1
	else if (roomDirection == 1) {
		//South means we go down a row
		//Take width and multiply by four, add that to currentRoom
		currentRoom = currentRoom + (width * 4);
	}
	//East = 2
	else if (roomDirection == 2) {
		//East is simply add 4 to get to next room value
		currentRoom = currentRoom + 4;
	}
	//West = 3
	//Same as East, West subtracts 4 to get to the next room value
	else if (roomDirection == 3) {
		currentRoom = currentRoom - 4;
	}
	return;
}

//Gives description of current room
void roomDescription(int currentRoom, vector<string> description) {

	cout << description.at(currentRoom) << endl;
	return;
}

//Checks for item in current room, for look code
void checkForItem(int currentRoom, vector<Items> ItemsList) {
	int i = 0;
	for (i = 0; i < ItemsList.size(); i++) {
		if (currentRoom == ItemsList.at(i).GetItemPos() && ItemsList.at(i).GetItemName() != "") {
			cout << ItemsList.at(i).GetItemWorldDesc() << endl;
		}
	}
}

//Checks for item's description in player's inventory
void checkPlayInventory(int selectedItem, vector<string> playerInventory, vector<int> ItemsList, vector<string> ItemDescriptionList) {

	cout << ItemDescriptionList.at(selectedItem) << endl;
}

//Gets a random room for battle runaway code
void GetRandomValidRoom(vector<int>rooms, int& currentRoom, int roomsWidth) {
	//N = 0, S = 1, E = 2, W = 3
	//Set variables
	int randomPick = 0;
	int randomRoom = 0;
	bool pickValid = false;
	//While the random number isn't valid
	while (pickValid == false) {
		//Gives Number Between 1 and 4
		randomPick = (rand() % 4);
		//Adds random number to code
		randomRoom = randomPick + currentRoom;
		//Checks random number against rooms vector to find a valid room
		if (rooms.at(randomRoom) == 1) {
			//If room is valid move to that room
			moveToRoom(randomPick, currentRoom, roomsWidth);
			pickValid = true;
		}
	}
}

//Rpg Battling code
void rpgBattle(vector<WorldMonsters>& monstersPosition, vector<MonstersRPG> monstersList, int& currentRoom, bool& playerAlive, PlayerRPG& player, bool& monstersHere, vector<Leveling> levels, vector<Items> items, vector<int> rooms, int roomsWidth) {


	//Variables
	//Variables for player input
	string playerIn = "";
	int playerInChoice = 0;

	//If the combat is going
	bool combatOngoing = true;

	//Variables for for loops
	int i = 0;
	int j = 0;
	int k = 0;

	//Setup vectors for the monsters in this battle
	vector<string> CurrentMonsters(0);
	vector<int> CurrentMonstersHealth(0);
	vector<int> CurrentMonstersAttack(0);
	vector<bool> CurrentMonstersAlive(0);
	vector<int> CurrentMonstersPosition(0);
	vector<int> CurrentMonstersXP(0);
	vector<bool> CurrentMonstersdDeadThisTurn(0);

	//Some monsters still alive in battle
	bool someMonstersAlive = false;
	//Damage done
	int damageTaken = 0;
	//If player hit a monster
	bool hitMonster = false;

	//If player has potion
	bool hasPotion = true;
	//Potion's position
	int potionPos = 0;
	//Amount potion heals
	int amtHealed = 0;
	//If got a potion, second check to not use all health potions
	bool gotPotion = false;

	//Setup Monsters in this battle
	for (i = 0; i < monstersPosition.size(); i++) {
		if (currentRoom == monstersPosition.at(i).getPosition()&& monstersPosition.at(i).getName()!="") {
			for (j = 0; j < monstersList.size(); j++) {
				if (monstersPosition.at(i).getName() == monstersList.at(j).ShowName()) {
					CurrentMonsters.push_back(monstersList.at(j).ShowName());
					CurrentMonstersHealth.push_back(monstersList.at(j).GetMonsterHealth());
					CurrentMonstersAttack.push_back(monstersList.at(j).GetMonsterAttack());
					CurrentMonstersAlive.push_back(true);
					someMonstersAlive = true;
					CurrentMonstersPosition.push_back(i);
					CurrentMonstersXP.push_back(monstersList.at(j).GetXP());
					CurrentMonstersdDeadThisTurn.push_back(false);
				}
			}
		}
	}

	//If the monsters in this battle are all dead already
	if (someMonstersAlive == false) {
		combatOngoing = false;
		cout << "No monsters here!" << endl;
		return;
	}

	cout << "Combat has begun! What will you do?" << endl;

	while (combatOngoing != false) {
		//Clear screen for cleaning
		system("cls");

		//Display player and monster health
		cout << "Your Health is: " << player.GetPlayerHealth() << endl;
		for (i = 0; i < CurrentMonsters.size(); i++) {
			for (j = 0; j < monstersList.size(); j++) {
				if (CurrentMonsters.at(i) == monstersList.at(j).ShowName() && CurrentMonstersAlive.at(i) == true) {
					cout << "Monster: " << monstersList.at(j).ShowName() << " has: " << CurrentMonstersHealth.at(i) << " health " << endl;
				}
			}
		}

		//Give player actions they have available
		cout << "ACTIONS: attack, defend, heal, run" << endl;
		cin >> playerIn;

		//If player inputs attack
		if (playerIn == "attack") {
			hitMonster = false;
			cout << "Currently alive monsters are: ";
			//Display the current monsters
			for (i = 0; i < CurrentMonsters.size(); i++) {
				if (CurrentMonstersAlive.at(i) == true) {
					cout << " " << i << ") " << CurrentMonsters.at(i) << ", ";
				}
			}
			cout << endl;
			cout << "Choose a monster to attack!" << endl;

			//While loop to choose a monster
			while (hitMonster == false) {
				cin >> playerInChoice;
				//Check for valid input
				if (playerInChoice >= CurrentMonsters.size() || playerInChoice < 0) {
					cout << "Monster does not exist." << endl;
				}
				else {
					//If the monster is alive damage it
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

			//Check if a monster has died during this combat
			//Give player xp and remove monster from map
			someMonstersAlive = false;
			for (i = 0; i < CurrentMonsters.size(); i++) {
				if (CurrentMonstersHealth.at(i) <= 0) {
					if (CurrentMonstersdDeadThisTurn.at(i) == false) {
						CurrentMonstersAlive.at(i) = false;
						cout << "The " << CurrentMonsters.at(i) << " is dead!" << endl;
						monstersPosition.at(CurrentMonstersPosition.at(i)).addPosition(-1);
						player.PlayerXPAdd(CurrentMonstersXP.at(i));
						CurrentMonstersdDeadThisTurn.at(i) = true;
					}
				}
				else{
					someMonstersAlive = true;
				}
			}
			
			//If there are monsters alive they attack
			for (i = 0; i < CurrentMonsters.size(); i++) {
				if (CurrentMonstersAlive.at(i) == true) {
					//Have monsters attack in here in sucession
					cout << CurrentMonsters.at(i) <<" attacks for: " << CurrentMonstersAttack.at(i) << endl;
					cout << "You take: " << CurrentMonstersAttack.at(i) << endl;
					player.PlayerHealthDamage(CurrentMonstersAttack.at(i));
					combatOngoing = true;
				}
			}

			//If no monsters are alive, player wins combat
			if (someMonstersAlive == false) {
				cout << "You win the fight!" << endl;
				combatOngoing = false;
				monstersHere = false;
				//double check
				player.CheckLevelUp(levels);
				break;
			}


		}

		//If player inputs defend
		else if (playerIn == "defend") {
			cout << "Defending..." << endl;

			//Monsters attack
			for (i = 0; i < CurrentMonsters.size(); i++) {
				if (CurrentMonstersAlive.at(i) == true) {
					//Monsters attack in order
					cout << CurrentMonsters.at(i) << " attacks for: " << CurrentMonstersAttack.at(i) << endl;
					//Have defense subtract from attack
					damageTaken = CurrentMonstersAttack.at(i) - player.GetPlayerDefense();
					//If damage taken would be below 0, make just 0
					if (damageTaken <= 0) {
						damageTaken = 0;
					}
					cout << "You take: " << damageTaken << " damage." << endl;
					player.PlayerHealthDamage(damageTaken);
					combatOngoing = true;
				}
			}
		}

		//If player inputs heal
		else if (playerIn == "heal") {
			cout << "Checking for healing potion..." << endl;
			//Check for a healing potion in inventory
			for (i = 0; i < player.playerInventory.size(); i++) {
				if (player.playerInventory.at(i) == "PotionHP") {
					hasPotion = true;
					potionPos = i;
				}
			}

			//If player has a potion heal
			if (hasPotion == true) {
				cout << "Healing damage..." << endl;
				for (i = 0; i < items.size(); i++) {
					//Make sure to not get a health potion twice with gotPotion
					if (items.at(i).GetItemName() == "PotionHP"&& gotPotion ==false) {
						amtHealed = items.at(i).GetItemSpecialVal();
						gotPotion = true;
						hasPotion = false;
						player.playerInventory.at(potionPos) = "";
					}
				}
				//Heal for amtHealed
				cout << "Healed for: " << amtHealed << endl;	
				player.PlayerHealthHeal(amtHealed);
			}
			//Fail if no healing potion
			else {
				cout << "No healing potion!" << endl;
			}
		}

		//If player inputs run
		else if (playerIn == "run") {
			cout << "You run away!" << endl;
			combatOngoing = false;
			monstersHere = true;
			player.CheckLevelUp(levels);
			//Have player run into a random room that has a valid doorway
			GetRandomValidRoom(rooms, currentRoom, roomsWidth);
				
		}

		//If the value is wrong
		else {
			cout << "Please input a correct command!" << endl;
		}

		//If the player has lost all health
		if (player.GetPlayerHealth() <= 0) {
			cout << "You have lost all health! Game Over!" << endl;
			combatOngoing = false;
			break;
			playerAlive = false;
		}
	}
		
	return;
}


//Main adventure game code
void adventureGame(std::vector<MonstersRPG> monsterList, vector<int> rooms, int roomsWidthIn, int roomsHeightIn, int victoryRoom, vector<WorldMonsters> monstersPosition, vector<string> roomDesc, vector<Items> ItemsList, vector<Leveling> levels, int startingRoom) {

	//Variables and initializing things
	//Setup player variables
	PlayerRPG player;
	player.InitializeAttack(5);
	player.InitializeHealth(15);
	player.InitializeXP(0);
	player.InitializePlayerLevel(0);
	player.InitializePlayerDefense(1);
	player.InitializePlayerInventory();
	string playerNameIn = "";

	//Get player name
	cout << "What is your name adventurer?" << endl;
	getline(cin, playerNameIn);
	player.InitializePlayerName(playerNameIn);
	cout << "Welcome to the dungeon " << player.GetPlayerName() << "." << endl;

	//Setup staring position of player
	int currentRoom = startingRoom;

	bool playerAlive = true;
	int roomsWidth = roomsWidthIn;
	int i = 0;
	bool gameOn = true;
	bool gameWon = false;
	string playerIn = "";
	string currentRoomDescription = "";
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

	//Potion variables
	bool hasPotion = true;
	int potionPos = 0;
	int amtHealed = 0;
	bool gotPotion = false;

	//Vector for items in a certain room
	vector<int> currentItems(0);
	

	//Main game loop
	while (gameOn != false) {
		cout << "Please input an action. Available actions are: move, attack, look, open, take, inv, quit." << endl;
		cin >> playerIn;
		system("cls");

		//If player input is move
		if (playerIn == "move") {
			cout << "Which direction would you like to move? Directions are N, S, E, W." << endl;
			cin >> playerIn;
			
			//Check for direction input
			//If direction input is valid, and direction has an open doorway, move player
			if (playerIn == "N" || playerIn == "n") {
				if (rooms.at(currentRoom) == 0) {
					cout << "No door exists." << endl;
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
			//Fail if incorrect value
			else {
				cout << "Please input a correct value." << endl;
			}
		}

		//If player input is attack
		else if (playerIn == "attack") {
			cout << "Checking for monsters." << endl;
			//Check for monsters in room
			monstersHere = false;
			for (i = 0; i < monstersPosition.size(); i++) {
				monsterCheck = monstersPosition.at(i).getPosition();
				if (monsterCheck == currentRoom) {
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

		//If player input is look
		else if (playerIn == "look") {
			//Give room description and any items in room
			roomDescription(currentRoom, roomDesc);
			checkForItem(currentRoom, ItemsList);
			//Check for any monsters in room
			for (i = 0; i < monstersPosition.size(); i++) {
				if (monstersPosition.at(i).getPosition() == currentRoom) {
					cout << "A " << monstersPosition.at(i).getName() << " sits in the room." << endl;
					monstersHere = true;
				}
			}
			//If there is a monster in the room, jump the player and start combat
			if (monstersHere = true) {
				cout << "Oh no! The monster attacks!" << endl;
				rpgBattle(monstersPosition, monsterList, currentRoom, playerAlive, player, monstersHere, levels, ItemsList, rooms, roomsWidth);
			}
		}

		//If player input is open
		else if (playerIn == "open") {
			//Start process of unlocking the door
			doorLockedN = "";
			doorLockedS = "";
			doorLockedE = "";
			doorLockedW = "";
			hasKey = false;
			keyPos = -1;
			lockedDoorCurr = false;
			//Check for a key in player inventory
			for (i = 0; i < player.playerInventory.size(); i++) {
				if (player.playerInventory.at(i) == "Key") {
					hasKey = true;
					keyPos = i;
				}
			}
			//Check doors to see if they are locked
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

			//If the player has a key
			if (hasKey == true) {
				//If there is a locked door
				if (lockedDoorCurr == true) {
					//Display locked doors
					cout << "Currently locked doors are: " << doorLockedN << " " << doorLockedS << " " << doorLockedE << " " << doorLockedW << endl;
					cout << "Choose a door to open: N, S, E, W. Press any other key to not open a door.";
					cin >> playerIn;

					//Check player in to open door in that direction
					//Removes key from inventory
					if (doorLockedN == "N" && (playerIn == "N" || playerIn == "n")) {
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
					//If player does not want to open a door
					else {
						cout << "Not opening a door right now." << endl;
					}
				}
				//If there are no locked doors
				else {
					cout << "No locked doors in this room!" << endl;
				}
			}
			//If player does not have a key
			else {
				cout << "You don't have a key!" << endl;
			}
		}

		//If player input is take
		else if (playerIn == "take") {
			//Set variables needed to base
			playerItemSel = -1;
			notTakeItem = true;
			playerItemSelTrue = false;
			itemInRoom = 0;
			currentItems.resize(0);

			cout << "Items here are: ";
			//Check for items in room
			for (i = 0; i < ItemsList.size(); i++) {
				if(ItemsList.at(i).GetItemPos() == currentRoom && ItemsList.at(i).GetItemName() != ""){
					cout << " " << itemInRoom << ") " << ItemsList.at(i).GetItemName() << ", ";
					itemInRoom = itemInRoom++;
					currentItems.push_back(i);
				}
			}
			cout << "What item do you want to pick up?" << endl;
			//While loop for player input
			while (playerItemSelTrue == false) {
				cin >> playerItemSel;
				//Fails if player does not select a item in the room
				if (playerItemSel >= itemInRoom) {
					cout << "Please select a value that exists." << endl;
				}
				else {
					//Iterates through items list to find matching item values
					for (i = 0; i < ItemsList.size(); i++) {
						if (ItemsList.at(i).GetItemNumber() == currentItems.at(playerItemSel)) {
							for (k = 0; k < player.playerInventory.size(); k++) {
								//Ensure the player does not create a duplicate item in inventory
								if (player.playerInventory.at(k) == "" && notTakeItem == true) {
									//Set player inventory to contain item
									player.playerInventory.at(k) = ItemsList.at(i).GetItemName();
									notTakeItem = false;
									cout << ItemsList.at(i).GetItemName() << " added to inventory." << endl;
									//Set item to not exist in world
									ItemsList.at(i).InitializeItemPosition(-1);
									foundItem = true;
									playerItemSelTrue = true;
								}
							}
							
						}
					}
					//If inventory is full, break
					if (notTakeItem == true) {
						cout << "No room in inventory." << endl;
						break;
					}
					//If player inputs an incorrect value
					if (playerItemSelTrue == false) {
						cout << "That value has nothing in it!" << endl;
					}
				}
			}
		}

		//If player input is inv
		else if (playerIn == "inv") {
			playerItemSelTrue = false;
			hasItem = false;
			
			//Displays items in inventory
			cout << "What item would you like to inspect?" << endl;
			for (i = 0; i < player.playerInventory.size(); i++) {
				if (player.playerInventory.at(i) != "") {
					hasItem = true;
				}
			}

			//If player has an item at all
			if (hasItem == true) {
				cout << "Current items are: ";
				for (i = 0; i < player.playerInventory.size(); i++) {
					if (player.playerInventory.at(i) != "") {
						cout << i << ") " << player.playerInventory.at(i) << ",";
					}
				}
				cout << endl;
			}
			//Fail id player has no items
			else {
				cout << "You have no items." << endl;
			}
			//Wait for player input
			if (hasItem == true) {
				//While loop until player input is valid
				while (playerItemSelTrue == false) {
					cin >> playerItemSel;
					//Check if player in is valid
					if (playerItemSel < 0 || playerItemSel > 3) {
						cout << "Please select a value that exists." << endl;
					}
					//If valid
					else {
						//Display item's description
						for (i = 0; i < ItemsList.size(); i++) {
							if (ItemsList.at(i).GetItemName() == player.playerInventory.at(playerItemSel)) {
								cout << ItemsList.at(i).GetItemDesc() << endl; 
								playerItemSelTrue = true;
							}
						}
						//If the inventory position selected has nothing in it
						if (playerItemSelTrue == false) {
							cout << "That value has nothing in it!" << endl;
						}
					}
				}
			}
		}

		//If player input is drop
		else if (playerIn == "drop") {
			playerItemSelTrue = false;
			hasItem = false;
			cout << "What item would you like to drop?" << endl;
			//Checks if player has any items
			for (i = 0; i < player.playerInventory.size(); i++) {
				if (player.playerInventory.at(i) != "") {
					hasItem = true;
				}
			}
			//If player has items
			if (hasItem == true) {
				cout << "Current items are: ";
				//Display items
				for (i = 0; i < player.playerInventory.size(); i++) {
					if (player.playerInventory.at(i) != "") {
						cout << i << ") " << player.playerInventory.at(i) << ",";
					}
				}
				cout << endl;
			}
			//If player has no items
			else {
				cout << "You have no items." << endl;
			}
			//If player has an item
			if (hasItem == true) {
				//While loop until player selection is true
				while (playerItemSelTrue == false) {
					cin >> playerItemSel;
					//If value is invalid
					if (playerItemSel < 0 || playerItemSel > 3) {
						cout << "Please select a value that exists." << endl;
					}
					//If value is valid
					else {
						for (i = 0; i < ItemsList.size(); i++) {
							//Ensure duplicate item is not dropped
							if (ItemsList.at(i).GetItemName() == player.playerInventory.at(playerItemSel)&& playerItemSelTrue==false) {
								cout << player.playerInventory.at(playerItemSel) << " dropped on the floor. " << endl;
								player.playerInventory.at(playerItemSel) = "";
								ItemsList.at(i).InitializeItemPosition(currentRoom);
								playerItemSelTrue = true;
								
							}
						}
						//If selected item slot is empty
						if (playerItemSelTrue == false) {
							cout << "That value has nothing in it!" << endl;
						}
					}
				}
			}
		}

		//If player input is use
		else if (playerIn == "use") {
			playerItemSelTrue = false;
			hasItem = false;
			cout << "What item would you like to use?" << endl;
			//Check if player has items
			for (i = 0; i < player.playerInventory.size(); i++) {
				if (player.playerInventory.at(i) != "") {
					hasItem = true;
				}
			}
			//If player has items, display them
			if (hasItem == true) {
				cout << "Current items are: ";
				for (i = 0; i < player.playerInventory.size(); i++) {
					if (player.playerInventory.at(i) != "") {
						cout << i << ") " << player.playerInventory.at(i) << ",";
					}
				}
				cout << endl;
			}
			//If player has no items
			else {
				cout << "You have no items." << endl;
			}

			//If Items
			if (hasItem == true) {
				//While loop to wait on player input
				while (playerItemSelTrue == false) {
					cin >> playerItemSel;
					//If player input is invalid
					if (playerItemSel < 0 || playerItemSel > 3) {
						cout << "Please select a value that exists." << endl;
					}
					//If valid playerinput
					else {
						//Loop through and check item type
						for (i = 0; i < ItemsList.size(); i++) {
							if (ItemsList.at(i).GetItemName() == player.playerInventory.at(playerItemSel)) {
								if (ItemsList.at(i).GetItemType() == 0) {
									//Nothing
								}
								if (ItemsList.at(i).GetItemType() == 1) {
									//Health potion
									cout << "Checking for healing potion..." << endl;
									//Check for healing potion
									for (i = 0; i < player.playerInventory.size(); i++) {
										if (player.playerInventory.at(i) == "PotionHP") {
											hasPotion = true;
											potionPos = i;
										}
									}
									//If it is a healing potion, heal
									//Heal player and remove it from inventory
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
									//If weapon equip it
									player.EquipPlayerWeapon(ItemsList.at(i).GetItemName());
									cout << "Equipped " << ItemsList.at(i).GetItemName() << " to weapon slot." << endl;
								}

								if (ItemsList.at(i).GetItemType() == 3) {
									//Armor
									//If armor equip it
									player.EquipPlayerArmor(ItemsList.at(i).GetItemName());
									cout << "Equipped " << ItemsList.at(i).GetItemName() << " to armor slot." << endl;
								}
							}
						}
						//If the item value is false
						if (playerItemSelTrue == false) {
							cout << "That value has nothing in it!" << endl;
						}
					}
				}
			}

		}

		//If player input is quit
		else if (playerIn == "quit") {
			cout << "Thanks for playing " << player.GetPlayerName() << "!" << endl;
			gameOn = false;
		}

		//If player input is invalid
		else {
			cout << "Please input a correct action." << endl;
		}

		//If player died during combat
		if (playerAlive != true) {
			cout << "Game Over " << player.GetPlayerName() << ". Try again next time." << endl;
			gameOn = false;
		}

		//If player made it to the goal room
		if (currentRoom == victoryRoom) {
			gameWon = true;
		}

		//If player has won
		if (gameWon == true) {
			cout << "You have escaped! You Win " << player.GetPlayerName() << "! Play again soon!" << endl;
			//End game loop
			gameOn = false;
		}
	}
	return;
}


//Main Thread to setup files
int main() {

	//Window width and height
	int width = 100;
	int height = 75;
	//Set window height
	Console::SetWindowSize(width, height);

	//Seed random with time
	srand(time(NULL));
	
	//Setup Variables
	int i = 0;

	//Setup input stream
	ifstream fin;
	string fileName;
	string fileTitle;

	//Set file to open
	fileTitle = "monstersA.txt";
	//Opens file
	fin.open(fileTitle);

	//Below is code that utilizes while loops and .eof (End of file) commands
	//Simple process is: open file, any starting variables, 
	//while not end of file take in new variables, set variables, resize vector to be 1 larger, repeat until done.

	//Monsters in
	//Setup vector of class objects from MonstersRPG
	std::vector<MonstersRPG> monsterList(1);
	i = 0;
	int j = 1;
	string monsterNameIn;
	int monsterHPIn;
	int monsterDmgIn;
	int monsterXPIn;
	while (!fin.eof()) {	
		fin >> monsterNameIn;
		monsterList.at(i).InitializeName(monsterNameIn);
		fin >> monsterHPIn;
		fin >> monsterDmgIn;
		fin >> monsterXPIn;
		monsterList.at(i).InitializeHealth(monsterHPIn);
		monsterList.at(i).InitializeAttack(monsterDmgIn);
		monsterList.at(i).InitializeXP(monsterXPIn);
		
		if (!fin.eof()) {
			i++;
			j++;
			monsterList.resize(j);
		}
	}
	fin.close();


	//Monster Positioning
	//Setup vector of class objects from WorldMonsters
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
		if (!fin.eof()) {
			i++;
			j++;
			monstersPosition.resize(j);
		}
	}
	fin.close();


	//Rooms in
	//Setup vector of integers that makeup the rooms
	vector<int> rooms(1);
	int y = 0;
	int z = 1;
	int roomsWidthIn = 0;
	int roomsHeightIn = 0;
	int victoryRoom = 0;
	int startingRoom = 0;
	int currentRoomInput = -1;
	string roomFile = "roomsA.txt";
	fin.open(roomFile);
	//Variables in rooms file that only appear once
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
	fin.close();


	//Setup vector of strings that makeup the room descriptions
	vector<string> roomDesc(4);
	int a = 0;
	int b = 4;
	roomFile = "roomsDescriptionA.txt";
	string descriptionIn = "";
	fin.open(roomFile);
	while (!fin.eof()) {
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


	//Item Descriptions, Item Lists, Item World Descriptiors
	//Setup vector of class objects from Items
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
	//Setup vector of class objects from Levels
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


	//Call adventureGame, start main game
	adventureGame(monsterList, rooms, roomsWidthIn, roomsHeightIn, victoryRoom, monstersPosition, roomDesc, ItemsList, levels, startingRoom);



	return 0;
}