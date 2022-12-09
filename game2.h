game2_4007.h
#ifndef GAME2_4007_H_INCLUDED
#define GAME2_4007_H_INCLUDED
#include <iostream>
#include <windows.h>
#include <string>
#include <algorithm>

using namespace std;
void Fight();
void Fight_navBar();
void Going();
void increase_lvl();
void Intro();
class Character
{
public:
string name, race, gender;
int level, xp, nextLevel, health, total_health, maxHealth, heal;
string racePlayer[5] = {"human", "elf", "martian", "alien", "musk"};
Character()
{
name = "";
race = "";
gender = "";
level=0, xp=0, health=0, total_health=0, maxHealth=0, nextLevel=0, heal=0;
}
~Character()
{
name = "";
race = "";
gender = "";
}
void createCharac()
{
int counter=0;
level = 1;
xp = 0;
nextLevel = 76;
cout<<"Create your character!"<<endl;
Sleep(800);
system("cls");
cout<<"Character name: ";
cin>>name;
system("cls");
cout<<"Character races: ";
cout<<""<<endl;
cout<<"........................."<<endl;

for(int i=0; i<5; i++)
{
cout<<racePlayer[i]<<endl;
}
cout<<"........................."<<endl;
cout<<"Choose the race"<<endl;
cin>>race;

if(race == "human")
{
health = 100;
}
else if(race == "elf")
{
health = 80;
}
else if(race == "martian")
{
health = 140;
}
else if(race == "alien")
{
health = 90;
}
else if(race == "musk")
{
health = 250;
}
else
{
health = 99;
}
system("cls");
cout<<"Character gender: ";
cin>>gender;
system("cls");
total_health = health;
maxHealth = total_health;
for(int i=0; i<=counter; i++)
{

if(i == 0)
{
cout<<"Creating character."<<endl;
}
if(i == 1)
{
cout<<"Creating character.."<<endl;
}
if(i == 2)
{
cout<<"Creating character..."<<endl;
}
if(i == 3)
{
cout<<"Stilling your character...."<<endl;
break;
}
Sleep(300);
system("cls");
counter += 1;
}
race[0] = toupper(race[0]);
name[0] = toupper(name[0]);
gender[0] = toupper(gender[0]);
}
void chillFCT()
{
cout<<"You are setting up a tent for this night!"<<endl;
if(total_health<=99)
{
total_health = total_health + 10*level;
if(total_health > 100)
{
total_health = 100;
}
}
else{cout<<"You have to have until 99 health to heal! Enjoy your
chill!"<<endl;}
cout<<"Resting gave you more heal! Health is now "<<total_health<<endl;
}
void navBar()
{
Sleep(500);

system("cls");
cout<<"Name: "<<name<< " Life: "<<total_health<<" Race:
"<<race<<" Gender: "<<gender<<
"\nLevel: "<<level<<" XP: "<<xp<<" Xp
Request: "<<nextLevel<<endl;
Going();
}
void gameOver()
{
if(total_health<=0)
{
cout<<"You are dead!"<<endl;
Sleep(1000);
system("cls");
cout<<"Game over!"<<endl;
exit(0);
}
}
};
class Monster : public Character
{
public:
int monster_hp;
int monsterXp;
int monstLvl;
string monsterList[6] = {"Wizard", "Golin", "Demon", "Dwarf", "Witch", "Orge"};
int monsterIND = 5;
string currentMonster = "";
Monster()
{
monster_hp = 0;
monsterXp = 0;
monstLvl = 0;
}
void createMonster()
{
monster_hp = 20;
monstLvl = (rand()%3) + level;
monster_hp = (rand()%30) * monstLvl;
monsterXp = monster_hp;
if(monster_hp == 0)
{
createMonster();

}
if(monstLvl == 0)
{
createMonster();
}
}
};
Character user;
Monster enemy;
void Intro()
{
cout<<"Do you remember what happend yesterday?"<<endl;
Sleep(1500);
system("cls");
cout<<"You started a small walk";
Sleep(800);
cout<<"in the forest a little bit too late in the night!"<<endl;
Sleep(2000);
system("cls");
cout<<"You know that are many strange creatures in the this forest near you house
and the night scared you!"<<endl;
Sleep(3000);
system("cls");
cout<<"Somebody called you from back!!!"<<endl;
Sleep(2000);
cout<<"You should be really scared!"<<endl;
Sleep(2000);
system("cls");
cout<<"You started to run deep in the forest!"<<endl;
Sleep(1000);
cout<<"Stupid move, right?"<<endl;
Sleep(1000);
cout<<"Of course, you forgot how to return home!"<<endl;
Sleep(2000);
system("cls");
cout<<"Your advanture starts here! Keep focus!"<<endl;
Sleep(2000);
system("pause");
}
void Going()
{

int option;
cout<<""<<endl;
cout<<""<<endl;
cout<<""<<endl;
cout<<"1. Go ahead"<<endl;
cout<<"2. Chill & Heal"<<endl;
cout<<"3. Go back"<<endl;
cout<<""<<endl;
cout<<""<<endl;
cin>>option;
if(option == 1)
{
int inter = rand()%100 + 1;
cout<<"You begin moving ahead..."<<endl;
if(inter>=50)
{
enemy.createMonster();
string enemy_name = enemy.monsterList[rand()%enemy.monsterIND];
cout<<"A "<<enemy_name<<"! Prepare to fight!"<<endl;
enemy.currentMonster = enemy_name;
Sleep(1100);
Fight();
}
cout<<"Your road is safe for the moment"<<endl;
Sleep(1100);
user.navBar();
}
else if(option == 2)
{
user.chillFCT();
Sleep(1100);
user.navBar();
}
else if(option == 3)
{
int inter = rand()%100 + 1;
cout<<"You are going back..."<<endl;
if(inter>=50)
{
enemy.createMonster();
string iName = enemy.monsterList[rand()%enemy.monsterIND];
cout<<"A "<<iName<<"! Prepare to fight!"<<endl;
enemy.currentMonster = iName;
Sleep(1100);
Fight();
}
cout<<"No enemy, but keep focus and prepare for a battle any time!"<<endl;

Sleep(1100);
user.navBar();
}
else
{
cout<<"Wrong choice!"<<endl;
Sleep(700);
Going();
}
}
void Fight_navBar()
{
Sleep(500);
system("cls");
cout<<"Name: "<<user.name<<" | Monster Name:
"<<enemy.currentMonster<<endl;
cout<<"Health: "<<user.total_health<<" | Monster Health:
"<<enemy.monster_hp<<endl;
cout<<"Level: "<<user.level<<" | Monster Level: "<<enemy.monstLvl<<"
| Monster Xp: "<<enemy.monsterXp<<endl;
}
void Fight()
{
Fight_navBar();
int player_option;
int player_damage = 5 * user.level /2;
int monster_damage = 4 * enemy.monstLvl / 2;
if(user.total_health >= 1 && enemy.monster_hp>= 1)
{
cout<<""<<endl;
cout<<"1. Attack"<<endl;
cout<<"2. Defend"<<endl;
cout<<"3. Try to save yourself!"<<endl;
cout<<""<<endl;
cin>>player_option;
if(player_option == 1)
{
cout<<"Attacking...you did "<<player_damage<<"! The current enemy HP is
"<<enemy.monster_hp - player_damage<<endl;
enemy.monster_hp = enemy.monster_hp - player_damage;
Sleep(1200);
Fight_navBar();
if(enemy.monster_hp >= 1)
{
cout<<""<<endl;

cout<<"Monster is attacking you!"<<endl;
user.total_health = user.total_health - monster_damage;
cout<<"You are "<<user.total_health<<" HP!"<<endl;
if(user.total_health <= 0)
{
user.total_health = 0;
system("cls");
cout<<"You are dead! The "<<enemy.currentMonster<<" was more

powerful!"<<endl;
Sleep(300);

cout<<"Game over!"<<endl;
exit(0);

}
}
else if(enemy.monster_hp <= 0)
{
enemy.monster_hp = 0;
increase_lvl();
cout<<""<<endl;
cout<<"Monster is dead!"<<endl;
cout<<"You Xp level will increase with: "<<enemy.monsterXp<<endl;
Sleep(1200);
user.navBar();
}
Sleep(1200);
Fight();
}
else if(player_option == 2)
{
cout<<"Blocking!"<<endl;
int i = rand()%100 + 1;
if(i >= 50)
{
cout<<"You blocked the attack!"<<endl;
user.heal = user.level * 5;
cout<<"You heal yourself! Your heal is "<<user.heal<<endl;
user.total_health = user.total_health + user.heal;
Sleep(1200);
Fight();
}
else
{
cout<<"Fail!"<<endl;
user.total_health = user.total_health - monster_damage;
cout<<"You are under attack! Damage of "<<monster_damage<<". Current
HP: "<<user.total_health<<endl;
Sleep(1200);
Fight();
}
}

else if(player_option == 3)
{
cout<<"You tried to save yourself....running!"<<endl;
int y = rand()%100 + 1;
if(y >= 50)
{
cout<<"You escaped!"<<endl;
user.navBar();
}
else
{
cout<<"You failed!"<<endl;
cout<<"Monster attacked you!"<<endl;
user.total_health = user.total_health - monster_damage - 5;
cout<<"You suffered really big damages! Your taken damage is
"<<monster_damage + 5 <<". You are "<<user.total_health<<" HP!"<<endl;
Sleep(1200);
Fight();
}
}
else
{
cout<<"Wrong input!"<<endl;
Sleep(500);
Fight();
}
}
else
{
user.gameOver();
}
}
void increase_lvl()
{
user.xp = user.xp + enemy.monsterXp;
if(user.xp>=user.nextLevel)
{
cout<<"Congrats! Level up!"<<endl;
user.level +=1;
user.nextLevel = 85;
user.total_health = user.total_health + 25;
user.maxHealth = user.total_health;
Sleep(1500);
user.xp = 0;
user.navBar();
}
}

#endif // GAME2_4007_H_INCLUDED
