#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <map>
#include <random>
#include <vector>
#include <string>
#include "libsqlite.hpp"
#include <sqlite3.h>
using namespace std;
int table[5][5] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17,
18, 19, 20}, {21, 22, 23, 24, 25}};
class loudout
{
public:
string name;
int damage;
int extra_damage;
int extraPower_index;
loudout( string _name, int _damage, int _extra_damage, int _extraPower_index)
{
name = _name;
damage = _damage;
extra_damage = _extra_damage;
extraPower_index = _extraPower_index;
}

void modify_extra_damage(int add_extra_damage)
{
extra_damage = add_extra_damage;
}
};
// wallet will store the financial situation for each player and the functions will
// be use to get money after one round and to buy utilities from marketplace!
class wallet
{
public:
int start_money;
string name;
int total_money;
wallet(string _name, int _start_money, int _total_money)
{
name = _name;
start_money = _start_money;
total_money = _total_money;
}
void add_money( int money_add )
{
cout<<"You won in this round "<<money_add<<" pounds!"<<endl;
total_money = total_money + money_add;
cout<<"Balance: "<<total_money<<" pounds"<<endl;
}
void buy( int money_spend )
{
cout<<"You spend on utilities "<<money_spend<<" pounds!"<<endl;
total_money = total_money - money_spend;
cout<<"Balance: "<<total_money<<" pounds"<<endl;
}
};
// Saving class will offer a 40% discount for the first saved sum and 20% discount
//for the adding money!
class Saving : public wallet
{
public:
int moreSave;
Saving(int _moreSave) : wallet("Saving", 0, 0)
{
moreSave = _moreSave;
}

void saving_per_round(int money_add)
{
total_money = total_money + money_add + 0.2*money_add;
}
void extra_save()
{
total_money = total_money + 0.4*moreSave;
}
};
//You can get a loan for the battle! You credit will increse with 10% every round
//until you cover it! You can get a new credit until a total credit of 1000 pounds!
class Credit : public wallet
{
public:
int credit_amount;
Credit( int _credint_amount ) : wallet("Credit", 0, 0)
{
credit_amount = _credint_amount;
}
void increase_credit()
{
if(credit_amount > 0)
{
credit_amount = 0.1*credit_amount;
}
}
void cover_cover_credit(int amount)
{
credit_amount = credit_amount - amount;
}
void get_new_credit( int new_credit )
{
credit_amount = credit_amount + new_credit;
if(credit_amount > 1000)
{
credit_amount = credit_amount - new_credit;
}
}
};
void print_the_field(){
cout<< "The field is diplayed here"<<endl;
cout<<"tt_______________________________"<<endl;

cout<<"tt| | | | | |n"<<endl;
cout<<"tt| "<<table[0][0]<<" | "<<table[0][1]<<" | "<<table[0][2]<<" |
"<<table[0][3]<<" | "<<table[0][4]<<" |"<<"n"<<endl;
cout<<"tt|_____|_____|_____|_____|_____|n"<<endl;
cout<<"tt| | | | | |n"<<endl;
cout<<"tt| "<<table[1][0]<<" | "<<table[1][1]<<" | "<<table[1][2]<<" |
"<<table[1][3]<<" | "<<table[1][4]<<" |"<<"n"<<endl;
cout<<"tt|_____|_____|_____|_____|_____|n"<<endl;
cout<<"tt| | | | | |n"<<endl;
cout<<"tt| "<<table[2][0]<<" | "<<table[2][1]<<" | "<<table[2][2]<<" |
"<<table[2][3]<<" | "<<table[2][4]<<" |"<<"n"<<endl;
cout<<"tt|_____|_____|_____|_____|_____|n"<<endl;
cout<<"tt| | | | | |n"<<endl;
cout<<"tt| "<<table[3][0]<<" | "<<table[3][1]<<" | "<<table[3][2]<<" |
"<<table[3][3]<<" | "<<table[3][4]<<" |"<<"n"<<endl;
cout<<"tt|_____|_____|_____|_____|_____|n"<<endl;
cout<<"tt| | | | | |n"<<endl;
cout<<"tt| "<<table[4][0]<<" | "<<table[4][1]<<" | "<<table[4][2]<<" |
"<<table[4][3]<<" | "<<table[4][4]<<" |"<<"n"<<endl;
cout<<"tt| | | | | |n"<<endl;
cout<<"tt|_____|_____|_____|_____|_____|n"<<endl;
};
int choose_place( int row, int column)
{
int player_position = table[row-1][column-1];
cout<<"Your position is "<<player_position<<endl;
return player_position;
}
vector<int> get_enemy_positions(){
int enemy_position1, enemy_position2, enemy_position3 = 0;
vector<int> enemy_positions;
while(enemy_position1 == enemy_position2 || enemy_position1 == enemy_position3 ||
enemy_position2 == enemy_position3)
{
random_device rd;
default_random_engine randGenerator( rd() );
uniform_int_distribution<int> distribution(0, 4);
int i1 = distribution( randGenerator );
int j1 = distribution( randGenerator );
int i2 = distribution( randGenerator );
int j2 = distribution( randGenerator );
int i3 = distribution( randGenerator );
int j3 = distribution( randGenerator );
enemy_position1 = table[i1][j1];
enemy_position2 = table[i2][j2];
enemy_position3 = table[i3][j3];

}
enemy_positions.push_back(enemy_position1);
enemy_positions.push_back(enemy_position2);
enemy_positions.push_back(enemy_position3);
return enemy_positions;
}

bool locate_in_vector(vector<int>vec, int input)
{ for (int i=0; i<vec.size(); i++)
{ if (input == vec[i])
return true;
}
return false;
}

//battle 1 because we use weapon 1
void battle1(int player_first_position, int player_second_position, int
player_third_position, vector<int> bot_positions, int position_health[5][5], int
player_damage, int bot_damage)
{
int health_value, new_health;
cout<<"Player attacks first!"<<endl;
cout<<"Input the row and the column where you will shoot!"<<endl;
int attack_row;
int attack_column;
cin>>attack_row;
cin>> attack_column;
int attacked_position_value = table[attack_row-1][attack_column-1];
health_value = position_health[attack_row-1][attack_column-1];
if(locate_in_vector(bot_positions, attacked_position_value) == true)
{
new_health = health_value - player_damage;
health_value = new_health;
if(new_health <= 0)
{
cout<<"Killed!"<<endl;
//delete from bot_positions
}
}
else{
cout<<"Miss!!!"<<endl;
}

int bot_attack_pos = -1;
int health_value2, index1, index2;
while(locate_in_vector(bot_positions, bot_attack_pos) == false)
{
random_device rd;
default_random_engine randGenerator( rd() );
uniform_int_distribution<int> distribution(0, 4);
int i = distribution( randGenerator );
int j = distribution( randGenerator );
bot_attack_pos = table[i][j];
health_value2 = position_health[i][j];
index1 = i;
index2 = j;
}
if(player_first_position == bot_attack_pos)
{
cout<<"The enemy shooted you in position number "<<bot_attack_pos<<"!"<<endl;
health_value2 = health_value2 - bot_damage;
position_health[index1][index2] = health_value2;
if(health_value2 <= 0)
{
cout<<"You're shooter is dead"<<endl;
player_first_position = -1;
}
}
else if(player_second_position == bot_attack_pos)
{
cout<<"The enemy shooted you in position number "<<bot_attack_pos<<"!"<<endl;
health_value2 = health_value2 - bot_damage;
position_health[index1][index2] = health_value2;
if(health_value2 <= 0)
{
cout<<"You're shooter is dead"<<endl;
player_second_position = -1;
}
}
else if(player_third_position == bot_attack_pos)
{
cout<<"The enemy shooted you in position number "<<bot_attack_pos<<"!"<<endl;
health_value2 = health_value2 - bot_damage;
position_health[index1][index2] = health_value2;
if(health_value2 <= 0)
{
cout<<"You're shooter is dead"<<endl;
player_third_position = -1;

}
}
}
int see_health_extraAbility(int position_health[5][5], int row, int column)
{
int health = position_health[row][column];
return health;
}
bool see_player(vector<int> bot_positions, int row, int column )
{
int pos = table[row][column];
if(locate_in_vector(bot_positions, pos) == true)
{
return true;
}
else
{
return false;
}
}
int extra_shoot20(int player_damage)
{
int new_damage = player_damage + 0.2*player_damage;
return new_damage;
}
int increase_earning(int damage)
{
int initial_revenue = damage / 10;
int new_revenue = 0.5*initial_revenue;
return new_revenue;
}
void split_battle1(int player_first_position, int player_second_position, int
player_third_position, vector<int> bot_positions,int position_health[5][5], int
player_damage, int bot_damage)
{
int health_value, new_health;
cout<<"Player attacks first!"<<endl;
cout<<"Input the row and the column where you will shoot!"<<endl;
int attack_row1;
int attack_column1;
cin>>attack_row1;
cin>> attack_column1;
int attacked_position_value = table[attack_row1-1][attack_column1-1];

health_value = position_health[attack_row1-1][attack_column1-1];
int attack_row2;
int attack_column2;
cin>>attack_row2;
cin>>attack_column2;
int attacked_position_value2 = table[attack_row2-1][attack_column2-1];
int health_value_second = position_health[attack_row2-1][attack_column2-1];

int attack_row3;
int attack_column3;
cin>>attack_row3;
cin>>attack_column3;
int attacked_position_value3 = table[attack_row3-1][attack_column3-1];
int health_value_third = position_health[attack_row3-1][attack_column3-1];

if(locate_in_vector(bot_positions, attacked_position_value) == true)
{
new_health = health_value - player_damage;
position_health[attack_row1-1][attack_column1-1] = new_health;
if(new_health <= 0)
{
cout<<"Killed!"<<endl;
//delete from bot_positions
}
}
else{
cout<<"Miss!!!"<<endl;
}
if(locate_in_vector(bot_positions, attacked_position_value2) == true)
{
int new_health2 = health_value_second - player_damage;
position_health[attack_row2-1][attack_column2-1] = new_health;
if(new_health <= 0)
{
cout<<"Killed!"<<endl;
//delete from bot_positions
}
}
else{
cout<<"Miss!!!"<<endl;
}
if(locate_in_vector(bot_positions, attacked_position_value2) == true)
{
int new_health3 = health_value_third - player_damage;

position_health[attack_row3-1][attack_column3-1] = new_health3;
if(new_health <= 0)
{
cout<<"Killed!"<<endl;
//delete from bot_positions
}
}
else{
cout<<"Miss!!!"<<endl;
}

int bot_attack_pos = -1;
int health_value2;
while(locate_in_vector(bot_positions, bot_attack_pos) == false)
{
random_device rd;
default_random_engine randGenerator( rd() );
uniform_int_distribution<int> distribution(0, 4);
int i = distribution( randGenerator );
int j = distribution( randGenerator );
bot_attack_pos = table[i][j];
health_value2 = position_health[i][j];
if(player_first_position == bot_attack_pos)
{
cout<<"The enemy shooted you in position number "<<bot_attack_pos<<"!"<<endl;
health_value2 = health_value2 - bot_damage;
position_health[i][j] = health_value2;
if(health_value2 <= 0)
{
cout<<"You're shooter is dead"<<endl;
player_first_position = -1;
}
}
else if(player_second_position == bot_attack_pos)
{
cout<<"The enemy shooted you in position number "<<bot_attack_pos<<"!"<<endl;
health_value2 = health_value2 - bot_damage;
position_health[i][j] = health_value2;
if(health_value2 <= 0)
{
cout<<"You're shooter is dead"<<endl;
player_second_position = -1;
}
}
else if(player_third_position == bot_attack_pos)

{
cout<<"The enemy shooted you in position number "<<bot_attack_pos<<"!"<<endl;
health_value2 = health_value2 - bot_damage;
position_health[i][j] = health_value2;
if(health_value2 <= 0)
{
cout<<"You're shooter is dead"<<endl;
player_third_position = -1;
}
}
}
}
int cin_weapons_options()
{
string weapon;
cin>>weapon;
return weapon;
}
int get_damage_of_weapon1(string weapon){
try
{
cur->set_sql("SELECT damage FROM Weapons1 WHERE weapon_name = ?");
cur->prepare();
cur->bind( 1, weapon );
while(cur->step()){
int damage_weapon_1_player = get_int(1);
}
return damage_weapon_1_player;
}
catch(...)
{
return 0;
}
}
int get_damage_of_weapon2(string weapon)
{
cur->set_sql( "SELECT damage FROM Weapons2 WHERE weapon_name = ?");
cur->prepare();
cur->bind(1, weapon);
while(cur->step()){
int damage_weapon_2_player = get_int(1);


}
return damage_weapon_2_player;
}
int get_damage_of_weapon3(string weapon)
{
cur->set_sql("SELECT damage AS FROM Weapons3");
cur->prepare();
cur->bind(1, weapon);
while(cur->step()){
int damage_weapon_3_player = get_int(1);
}
return damage_weapon_3_player;
}
shooter_game.sqlite
CREATE TABLE Weapons1(
weapon_name VARCHAR(20) PRIMARY KEY NOT NULL,
damage NUMBER(3) NOT NULL
);
CREATE TABLE Weapons2(
weapon_name VARCHAR(20) PRIMARY KEY NOT NULL,
damage NUMBER(3) NOT NULL
);
CREATE TABLE Weapons3(
weapon_name VARCHAR(20) PRIMARY KEY NOT NULL,
damage NUMBER(3) NOT NULL
);
