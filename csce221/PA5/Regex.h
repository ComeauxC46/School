/*========================================================================================================================================
Chris Comeaux
cmc236
Section 507
cmc236@tamu.edu
==========================================================================================================================================*/

//Regex.h
#include <regex>
using namespace std;

/*CONTAINS ALL REGEX RAW EXPRESSTIONS*/

/*--------------------------------------------------
Holdes the Matches returned
----------------------------------------------------*/
smatch match;

/*--------------------------------------------------
Extracts the names
----------------------------------------------------*/
regex name {R"(^\w+\s+\w+)"};

/*--------------------------------------------------
Extracts the emails
----------------------------------------------------*/
regex email {R"([.a-zA-Z]*@[.a-zA-Z]*\.[.a-z]*+)"};

/*--------------------------------------------------
Extracts the UIN
----------------------------------------------------*/
regex uin {R"(\d{9})"};

/*--------------------------------------------------
Extracts the grades
----------------------------------------------------*/
regex grade {R"((\d{2,3}[\r\n]+)|(\d{2,3}$))"};

	