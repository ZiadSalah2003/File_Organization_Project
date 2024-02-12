#include <iostream>
//#include "fixtext.h"
//#include "lentext.h"
#include "varlen.h"

using namespace std;

class Book
{

public:
	// fields
	float	price;
	int	qty;
	char Name[20];
	char category[20];

	//operations
	Book();
	//Book(short shId, char name[]);
	void getdata();

	void InitRecord(VariableLengthRecord&); //set Record  Configuration
	bool searchbyname(string s);
	int Pack(VariableLengthRecord&);	//  From ObjectBook  to  Record =>  Write


	int Unpack(VariableLengthRecord&);  // From Record to  Object Book  => Read

	void Updatedata();
	void Print(ostream& stream);

};