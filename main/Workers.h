#include <iostream>
//#include "fixtext.h"
//#include "lentext.h"
#include "varlen.h"

using namespace std;

class Workers
{
public:
	// fields
	short	id, age;
	char	Name[20];

	//operations
	Workers();
	Workers(short shId, char name[]);

	void InitRecord(VariableLengthRecord&); //set Record  Configuration

	int Pack(VariableLengthRecord&);	//  From ObjectPerson  to  Record =>  Write


	int Unpack(VariableLengthRecord&);  // From Record to  Object Person  => Read
	void getdata();
	bool searchbyid(short s);
	void Print();
	void Updatedata();

};