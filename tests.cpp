#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include "creating_table.cpp"
TEST_CASE("Choose place function")
{
cont int outOfRange = 25
const int minimum_normal = 1;
const int maximum_normal = 5;
WHEN( "Are normal values")
{
REQUIRE( choose_place(3, 4) == 14 );
REQUIRE(choose_place( 5, 3) == 23 );
REQUIRE( choose_place( 4, 2 ) == 17 );

REQUIRE( choose_place( 1, 3 ) == 3 );
}
WHEN( "Limit cases" )
{
INFO( "Limit min index is " << minimum_normal - 1 );
INFO( "Limit max index is "<< maximum_normal - 1);
REQUIRE( choose_place(minimum_normal - 1, minimum_normal - 1) == 0 );
REQUIRE( choose_place(minimum_normal - 1, maximum_normal - 1) == 5 );
REQUIRE( choose_place(maximum_normal - 1, minimum_normal - 1) == 21 );
REQUIRE( choose_place(maximum_normal - 1, maximum_normal - 1) == 25 );
}
WHEN( "Out of normal range means recount" )
{
INFO( "If a value is bigger than 5 the algorithm will pass to the next value!" )
REQUIRE( choose_place(minimum_normal, maximum_normal) == 11);
REQUIRE( choose_place(minimum_normal - 1, maximum_normal) == 6 );
REQUIRE( choose_place(3, maximum_normal) == 21);
}
WHEN( "Out of range" )
{
REQUIRE( choose_place(minimum_normal - 1, maximum_normal) > outOfRange );
REQUIRE( choose_place(minimum_normal - 1, 25) > outOfRange );
}
}
/** We could make things easier by specifying the limits of the range
* and then basing everything off those variables **/
TEST_CASE( "Weapons1" )
{
WHEN( "The weapon is in DB" )
{
REQUIRE( get_damage_of_weapon1("Eagle") == 20 );
REQUIRE( get_damage_of_weapon1("Fiveseven") == 14);
REQUIRE( get_damage_of_weapon1("USP") == 16);
REQUIRE( get_damage_of_weapon1("Tec") == 12);
REQUIRE( get_damage_of_weapon1("Dual") == 14);
REQUIRE( get_damage_of_weapon1("Alfa") == 13);
}
WHEN( "The weapon is not in DB" )
{
REQUIRE( get_damage_of_weapon1("Carpati") == 0 );
REQUIRE( get_damage_of_weapon1("Pistol") == 0);
}
}
TEST_CASE( "Weapons1" )
{

WHEN( "The weapon is in DB" )
{
REQUIRE( get_damage_of_weapon1("MAC") == 23 );
REQUIRE( get_damage_of_weapon1("Nova") == 25);
REQUIRE( get_damage_of_weapon1("MP7") == 19);
REQUIRE( get_damage_of_weapon1("DBS") == 29);
REQUIRE( get_damage_of_weapon1("UMP") == 28);
REQUIRE( get_damage_of_weapon1("PP") == 22);
}
}
TEST_CASE( "Weapons1" )
{
WHEN( "The weapon is in DB" )
{
REQUIRE( get_damage_of_weapon1("AK47") == 36 );
REQUIRE( get_damage_of_weapon1("AUG") == 28);
REQUIRE( get_damage_of_weapon1("Negev") == 20);
REQUIRE( get_damage_of_weapon1("AWP") == 45);
REQUIRE( get_damage_of_weapon1("Scar") == 40);
REQUIRE( get_damage_of_weapon1("Beril") == 27);
}
}
