#include "Book.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Workers.h"
using namespace std;

bool v = 1;
bool check_header() {
	ifstream file("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::in | ios::binary);
	string test;
	getline(file, test);
	if (test.empty()) {
		v = 1;
	}
	else { v = 0; }
	file.close();
	return v;
}
bool check_header2() {
	ifstream file("C:\\Users\\El-HanDasia\\Desktop\\workers.txt", ios::in | ios::binary);
	string test;
	getline(file, test);
	if (test.empty()) {
		v = 1;
	}
	else { v = 0; }
	file.close();
	return v;
}


//void AddNewStudent() {
//	Book Book;
//	VariableLengthRecord outRecord, inRecord;
//
//	cout << "Enter id\n";
//	cin >> Book.id;
//	cout << "Enter name\n";
//
//	cin >> Book.Name;
//
//	Book.InitRecord(outRecord);
//	cout << "pack student " << Book.Pack(outRecord) << endl;
//#pragma region Writing (Packing)
//	ofstream TestOut("C:\\Users\\PC\\Desktop\\New folder (3)\\deltext.txt", ios::out | ios::binary | ios::app);
//	if (v)
//		outRecord.WriteHeader(TestOut), v = false;  // Only Once.
//	outRecord.Write(TestOut);
//	Book.Print(cout);
//
//	TestOut.close();
//#pragma endregion
//
//}
//void ShowAllData() {
//	Book Book;
//	VariableLengthRecord outRecord, inRecord;
//#pragma region Reading (UnPacking)
//
//	ifstream TestIn("C:\\Users\\PC\\Desktop\\New folder (3)\\deltext.txt", ios::in | ios::binary);
//	inRecord.ReadHeader(TestIn);
//
//	while (inRecord.Read(TestIn)) {
//		//        cout <<"read "<<inRecord.Read(TestIn)<<endl;
//		cout << "unpack " << Book.Unpack(inRecord) << endl;
//		Book.Print(cout);
//
//	}
//	TestIn.close();
//#pragma endregion
//
//}
void main()
{


main:
	char x;
	cout << "\t\t MENU\n";
	cout << "1.Add\n2.Update\n3.Delete\n4.Show All Data\n5.Search\n6.Exit\n";
	cin >> x;
	if (x >= '1' && x <= '6') {

		switch (x)
		{
		case '1': {
			add:
			cout << "1.Add new book\n2.Add new worker\n";
			int ch;
			cin >> ch;
			if (ch == 1) {
				Book book;
				VariableLengthRecord outRecord, inRecord;

				book.getdata();
				book.InitRecord(outRecord);
				cout << "pack new book " << book.Pack(outRecord) << endl;
#pragma region Writing (Packing)
				ofstream TestOut("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::out | ios::binary | ios::app);
				if (check_header()) {
					outRecord.WriteHeader(TestOut);
				}// Only Once.
				outRecord.Write(TestOut);
				book.Print(cout);

				TestOut.close();
#pragma endregion

				goto main;
			}
			else if (ch == 2) {
				Workers worker;
				VariableLengthRecord outRecord, inRecord;

				worker.getdata();
				worker.InitRecord(outRecord);
				cout << "pack new book " << worker.Pack(outRecord) << endl;
#pragma region Writing (Packing)
				ofstream TestOut("C:\\Users\\El-HanDasia\\Desktop\\workers.txt", ios::out | ios::binary | ios::app);
				if (check_header2()) {
					outRecord.WriteHeader(TestOut);
				}// Only Once.
				outRecord.Write(TestOut);
				worker.Print();

				TestOut.close();
#pragma endregion

				goto main;
			}
			else {
				cout << "Enter 1 or 2\n"; goto add;
			}
		}
		case '2': {
			update:
			cout << "1.Update book's data\n2.Update worker's data\n";
			int ch; cin >> ch;
			if (ch == 1) {
				bool srch = 0;
				cout << "Enter the name of book you want to update\n";
				string na;
				cin.ignore();
				getline(cin, na);
				Book book;
				VariableLengthRecord  Record;
#pragma region Reading (UnPacking)

				fstream Test("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::in | ios::out | ios::binary);
				Record.ReadHeader(Test);
				/*ofstream TestOut("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::out | ios::binary );*/
				while (Record.Read(Test)) {

					book.Unpack(Record);
					if (book.searchbyname(na)) {
						srch = 0;
						book.Updatedata();

						Test.seekp(-Record.rsize(), ios::cur);
						book.Pack(Record);

						Record.Write(Test);
						book.Print(cout);
						break;
					}
					else { srch = 1; }


				}
				if (srch) {
					cout << "Not Found ! \n";
				}
				Test.close();
				goto main;
			}
			else if (ch == 2) {
				bool srch = 0;
				cout << "Enter the id of the worker you want to update his data\n";
				short idd;
				
				cin >> idd;
				Workers worker;
				VariableLengthRecord  Record;
   #pragma region Reading (UnPacking)

				fstream Test("C:\\Users\\El-HanDasia\\Desktop\\workers.txt", ios::in | ios::out | ios::binary);
				Record.ReadHeader(Test);
				/*ofstream TestOut("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::out | ios::binary );*/
				while (Record.Read(Test)) {

					worker.Unpack(Record);
					if (worker.searchbyid(idd)) {
						srch = 0;
						worker.Updatedata();

						Test.seekp(-Record.rsize(), ios::cur);
						worker.Pack(Record);

						Record.Write(Test);
						worker.Print();
						break;
					}
					else { srch = 1; }


				}
				if (srch) {
					cout << "Not Found ! \n";
				}
				Test.close();
				goto main;

			}
			else { cout << "Enter 1 or 2\n"; goto update; }

		}
		case '3': {
			deletee:
			cout << "1.Delete book by name\n2.Delete worker by id\n";
			int ch; cin >> ch;
			if (ch == 1) {
				bool srch = 0;
				cout << "Enter the name of book you want\n";
				string na;
				cin.ignore();
				getline(cin, na);
				Book book;
				VariableLengthRecord  Record;
#pragma region Reading (UnPacking)

				fstream Test("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::in | ios::out | ios::binary);
				Record.ReadHeader(Test);
				/*ofstream TestOut("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::out | ios::binary );*/
				while (Record.Read(Test)) {

					book.Unpack(Record);
					if (book.searchbyname(na)) {
						srch = 0;
					
						book.Print(cout);
						Test.seekp(-Record.delsize(), ios::cur);
						Test.write("*", 1);
						
						break;
					}
					else { srch = 1; }


				}
				if (srch) {
					cout << "Not Found ! \n";
				}
				Test.close();
				goto main;
			}
			else if (ch == 2) {
				bool srch = 0;
				cout << "Enter the id of the worker you want to update his data\n";
				short idd;

				cin >> idd;
				Workers worker;
				VariableLengthRecord  Record;
#pragma region Reading (UnPacking)

				fstream Test("C:\\Users\\El-HanDasia\\Desktop\\workers.txt", ios::in | ios::out | ios::binary);
				Record.ReadHeader(Test);
				/*ofstream TestOut("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::out | ios::binary );*/
				while (Record.Read(Test)) {

					worker.Unpack(Record);
					if (worker.searchbyid(idd)) {
						srch = 0;
					
						worker.Print();
						Test.seekp(-Record.delsize(), ios::cur);
						int g = 0;
						Test.write((char*)&g, 1);
						
						
						break;
					}
					else { srch = 1; }


				}
				if (srch) {
					cout << "Not Found ! \n";
				}
				Test.close();
				goto main;
			}
			else {
				cout << "Enter 1 or 2\n"; goto deletee;
			}
		
		}
		case '4': {
			show:
			cout << "1.Show all books\n2.Show all workers\n";
			int ch;
			cin >> ch;
			if (ch == 1) {
				Book book;
				VariableLengthRecord  inRecord;
#pragma region Reading (UnPacking)

				ifstream TestIn("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::in | ios::binary);
				inRecord.ReadHeader(TestIn);

				while (inRecord.Read(TestIn)) {
					cout << "unpack " << book.Unpack(inRecord) << endl;
					if (book.Name[0] != '*') {
						
						book.Print(cout);
					}
				}
				TestIn.close();
				goto main;
			}
			else if (ch == 2) {
				Workers worker;
				VariableLengthRecord  inRecord;
#pragma region Reading (UnPacking)

				ifstream TestIn("C:\\Users\\El-HanDasia\\Desktop\\workers.txt", ios::in | ios::binary);
				inRecord.ReadHeader(TestIn);

				while (inRecord.Read(TestIn)) {

					cout << "unpack " << worker.Unpack(inRecord) << endl;
					if (worker.id != 0) {

						worker.Print();
					}
				

				}
				TestIn.close();
				goto main;
			}
			else { cout << "Enter 1 or 2\n"; goto show; }
		}
		case '5': {
			search:
			cout << "1.Search for book by name\n2.Search for worker by id\n";
			int ch; cin >> ch;
			if (ch == 1) {
				bool srch = 0;
				cout << "Enter the name of book you want\n";
				string na;
				cin.ignore();
				getline(cin, na);
				Book book;
				VariableLengthRecord outRecord, inRecord;
#pragma region Reading (UnPacking)

				ifstream TestIn("C:\\Users\\El-HanDasia\\Desktop\\deltext.txt", ios::in | ios::binary);
				inRecord.ReadHeader(TestIn);

				while (inRecord.Read(TestIn)) {

					book.Unpack(inRecord);
					if (book.searchbyname(na)) {
						srch = 0;
						book.Print(cout);
						break;
					}
					else { srch = 1; }


				}
				if (srch) {
					cout << "Not Found ! \n";
				}
				TestIn.close();
				goto main;
			}
			else if (ch == 2) {
				bool srch = 0;
				cout << "Enter the id of worker you want\n";
				short idd;
				cin >> idd;
				
				Workers worker;
				VariableLengthRecord outRecord, inRecord;
#pragma region Reading (UnPacking)

				ifstream TestIn("C:\\Users\\El-HanDasia\\Desktop\\workers.txt", ios::in | ios::binary);
				inRecord.ReadHeader(TestIn);

				while (inRecord.Read(TestIn)) {

					worker.Unpack(inRecord);
					if (worker.searchbyid(idd)) {
						srch = 0;
						worker.Print();
						break;
					}
					else { srch = 1; }


				}
				if (srch) {
					cout << "Not Found ! \n";
				}
				TestIn.close();
				goto main;
			}
			else { cout << "Enter 1 or 2\n"; goto search; }
		}
		case '6': {
			break;
		}
		default:
			goto main;
		}
	}
	else {
		cout << "Enter number from 1 to 6\n";
		goto main;
	}


}