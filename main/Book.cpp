#include <string.h>
#include "Book.h" 

Book::Book()
{
	qty = 0;
	price = 0;
	Name[0] = 0;
	category[0] = 0;
}

//Book::Book(short shId, char name[])
//{
//	id = shId;
//	Name = new char[];
//}
void Book::getdata() {
	cout << "Enter name\n";
	cin.ignore();
	cin.getline(Name, 20);
	cout << "Enter category\n";

	cin.getline(category, 20);
	cout << "Enter Price\n";
	cin >> price;
	cout << "Enter quantity\n";
	cin >> qty;
}
// initialize a VariableLengthRecord to be used for Books
void Book::InitRecord(VariableLengthRecord& record)
{
	record.init(4);
	record.AddField(0, 'D', '|');  // Fixed :  F , Length Indicator : L , Delimited  D
	record.AddField(1, 'D', '|');
	record.AddField(2, 'D', '|');
	record.AddField(3, 'D', '|');
}

bool Book::searchbyname(string s)
{

	if (s == Name) {
		return true;
	}
	else { return false; }
}

int Book::Pack(VariableLengthRecord& record)
{
	// pack the fields into a VariableLengthRecord, return  ( 1 )TRUE if all succeed, FALSE o/w
	int result, recordSize = 0;   // Lenght Indicator  id(short) = 120 , name = AMES , Delimiter = 1 = > 7

	recordSize = 8 + strlen(Name) + strlen(category) + 1;

	record.Clear(recordSize);

	result = record.Pack(0, (void*)&Name, strlen(Name));
	result = result && record.Pack(1, (void*)&category, strlen(category));
	result = result && record.Pack(2, (void*)&price, sizeof(price));
	result = result && record.Pack(3, (void*)&qty, sizeof(qty));

	return result;
}

int Book::Unpack(VariableLengthRecord& record)
{
	int result;
	result = record.Unpack(0, Name, true);
	result = result && record.Unpack(1, category, true);
	result = result && record.Unpack(2, (char*)&price);
	result = result && record.Unpack(3, (char*)&qty);
	return result;
}

void Book::Print(ostream& stream)
{
	stream << "book : "
		<< "\tPrice '" << price << "'\n"
		<< "\tName '" << Name << "'\n"
		<< "\tCategory '" << category << "'\n"
		<< "\tQuantity '" << qty << "'\n";
}
void Book::Updatedata() {

	cout << "Enter New Price\n";
	cin >> price;
	cout << "Enter New quantity\n";
	cin >> qty;

}