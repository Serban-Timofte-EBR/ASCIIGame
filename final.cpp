#include"final.h"
using namespace std;
int main()
{
wallet player_wallet("Player", 20, 20);
wallet bot_wallet("Bot", 20, 20);
print_the_field();
int checker1 = 0;
cout<< "Now you will choose the position of your shooters!"<<endl;
cout<< "First, write the number of the row you want to put your shooter"<<endl;
cout<< "Press enter"<<endl;
cout<< "Write the number of the column!"<<endl;
int row1 = get_cin_by_user();
int column1 = get_cin_by_user();
cout<< "You set the position of your first shooter!"<<endl;
int row2 = get_cin_by_user();
int column2 = get_cin_by_user();
cout<<"You set the position of your second shooter!"<<endl;
int row3 = get_cin_by_user();
int column3 = get_cin_by_user();
cout<<"You set the position of the third shooter!"<<endl;
int player_position1 = choose_place(row1, column1);
int player_position2 = choose_place(row2, column2);
int player_position3 = choose_place(row3, column3);
vector<int> enemy_shooters_positions = get_enemy_positions();
int damage_map[5][5];
int i,j;
srand ( (unsigned)time( NULL ) );
for ( i = 0; i <= 4 ;i++){
for( j = 0; j <= 4; j++){

Faculty of Engineering, Environment and Computing
4007CEM Computer Science Activity Led Learning Project 2
Assessment Template

Details on the assessment are presented in the Assessment Brief in the Assessment Section of the 4007CEM Aula.

int d = rand() %100 + 10;
damage_map[i][j] = d;
}
}
string sqlFile = "shooter_game.sqlite";
sqlite::sqlite db( sqlFile );
auto cur = db.get_statement();
cout<<"----------------------------------------------------"<<endl;
cout<<"The next step is to choose the weapons!"<<endl;
cout<<"If you choose an invalid weapon, your damage will be 0 for that
weapon!"<<endl;
cout<<"----------------------------------------------------"<<endl;
cout<<"Your choise list!"<<
cur->set_sql( "SELECT weapon_name AS 'Your weapons' FROM Weapons1;")
cur->prepare();
while (cur -> step()){
cout<<cur->get_text(0)<<" "<<get_int(1)<<endl;
}
cout<<"Choose your weapon 1 from previous list!"<<endl;
string weapon1 = cin_weapons_options();
int damage_weapon1_player = get_damage_of_weapon1(weapon1);
loudout Loudout1(weapon1, damage_weapon1_player, 0, 0);
cout<<"Your choise list for the second weapon!"<<endl;
cur->set_sql("SELECT weapon_name AS 'Your weapons' FROM Weapons2");
cur -> prepare();
while(cur->step()){
cout<<cur->get_text(0)<<" "<<get_int(1)<<endl;
}
cout<<"Choose your weapon 2 from previous list!"<<endl;
string weapon2 = cin_weapons_options();
int damage_weapon2_player = get_damage_of_weapon2(weapon2);
loudout Loudout2(weapon2, damage_weapon2_player, 0, 0);
cout<<"Your choise list for the third weapon"<<endl;

Faculty of Engineering, Environment and Computing
4007CEM Computer Science Activity Led Learning Project 2
Assessment Template

Details on the assessment are presented in the Assessment Brief in the Assessment Section of the 4007CEM Aula.

cur->set_sql("SELECT weapon_name AS 'Your weapons' FROM Weapons3");
cur->prepare();
while(cur->step()){
cout<<get_text(0)<<" "<<get_int(1)<<endl;
}
cout<<"Choose your weapon 3 from previous list!"<<endl;
string weapon3 = cin_weapons_options();
int damage_weapon3_player = get_damage_of_weapon3(weapon3);
loudout Loudout3(weapon3, damage_weapon3_player, 0, 0);
return 0;
}
