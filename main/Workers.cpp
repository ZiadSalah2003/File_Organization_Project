#include <string.h>
#include "Workers.h" 

Workers::Workers()
{
	age = 0;
	id = 0;
	Name[0] = 0;
}

//Workers::Workers(short shId, char name[])
//{
//	id = shId;
//	strcpy_s(Name, name);
//}
void Workers::getdata() {
	cout << "Enter id\n";
	cin >> id;

	cout << "Enter name\n";
	cin.ignore();
	cin.getline(Name, 20);
	cout << "Enter age\n";
	cin >> age;

}
// initialize a VariableLengthRecord to be used for Workerss
void Workers::InitRecord(VariableLengthRecord& record)
{
	record.init(3);
	record.AddField(0, 'D', '|');  // Fixed :  F , Length Indicator : L , Delimited  D
	record.AddField(1, 'D', '|');
	record.AddField(2, 'D', '|');

}

int Workers::Pack(VariableLengthRecord& record)
{
	// pack the fields into a VariableLengthRecord, return  ( 1 )TRUE if all succeed, FALSE o/w
	int result, recordSize = 0;   // Lenght Indicator  id(short) = 120 , name = AMES , Delimiter = 1 = > 7

	recordSize = 4 + strlen(Name) + 1;

	record.Clear(recordSize);

	result = record.Pack(0, (void*)&id, sizeof(short));

	result = result && record.Pack(1, (void*)Name, strlen(Name));
	result = result && record.Pack(2, (void*)&age, sizeof(short));
	return result;
}

int Workers::Unpack(VariableLengthRecord& record)
{
	int result;
	result = record.Unpack(0, (char*)&id);
	result = result && record.Unpack(1, Name, true);
	result = result && record.Unpack(2, (char*)&age);
	return result;
}

void Workers::Print()
{
	cout << "Workers:"
		<< "\tId '" << id << "'\n"
		<< "\tName '" << Name << "'\n"
		<< "\tAge '" << age << "'\n";
}
bool Workers::searchbyid(short s)
{

	if (s == id) {
		return true;
	}
	else { return false; }
}
void Workers::Updatedata() {

	cout << "Enter New Name\n";
	cin >> Name;
	cout << "Enter New age\n";
	cin >> age;

}