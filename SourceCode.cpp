#include <fstream>
#include <string>
#include<string.h>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct login
{
	string username;
	login *next;
};

struct CosmeticsInfo
{
	int Id;
	string name, address, cNo;
	string Pcompany, Email;
	string quantity;
	string price;
	string product_name;
	double t_amount;
	CosmeticsInfo *next;
};
CosmeticsInfo *head = NULL;
CosmeticsInfo *temp = NULL;
CosmeticsInfo *temp2 = NULL;

struct FurnitureInfo
{
	int Id;
	string name, address, cNo;
	string Pcompany, Email;
	string quantity;
	string price;
	string product_name;
	double t_amount;
	FurnitureInfo *next1;
};
FurnitureInfo *head1 = NULL;
FurnitureInfo *temp1 = NULL;
FurnitureInfo *temp22 = NULL;




void Menu()
{
	ifstream menu;
	string Menu;
	menu.open("Menu.txt");
	while (!menu.eof())
	{
		getline(menu, Menu);
		cout << Menu << endl;
	}
	menu.close();
}



void welcomenote()
{
	cout << "\n\n\n\n\n";
	Sleep(100);
	cout << "\n\t\t   *\3*\3* W..E..L..C..O..M..E*\3*\3*";
	Sleep(50);
	cout << "\n\n\t\t   *******\3*\3*\3*\3*T..O*\3*\3*\3*\3***";
	Sleep(50);
	cout << "\n\n\t\t   *\3*\3*\3*\3*\3*\3*M";
	Sleep(50);
	cout << "E";
	Sleep(50);
	cout << "R";
	Sleep(50);
	cout << "C";
	Sleep(50);
	cout << "E";
	Sleep(50);
	cout << "L";
	Sleep(50);
	cout << "A*\3*\3*\3*\3**";
	Sleep(50);
	cout << "\n\n\t\tC.O.S.M.E.T.I.C.S & F.U.R.N.I.T.U.R.E";
	Sleep(900);
	cout << "\n\n RUNNING BY";
	Sleep(50);
	cout << "\n\n 1. H";
	Sleep(50);
	cout << "if";
	Sleep(50);
	cout << "sa";
	Sleep(50);
	cout << "\n\n 2. M";
	Sleep(50);
	cout << "ar";
	Sleep(50);
	cout << "ia";
	cout << "\n\n 3. O";
	Sleep(50);
	cout << "me";
	Sleep(50);
	cout << "ma";
	Sleep(50);
	cout << "\n\n 4. K";
	Sleep(50);
	cout << "ainat";
	Sleep(2500);
	cout << "  ";
}

void loginverification()
{
	login *node1;
	node1 = new login;
enteragain:
	cout << endl;
	cout << "Enter username:\n" << endl;
	cin >> node1->username;
	{
		if (node1->username == "admin")
		{
			char ch;
			string pass;
		password:
			pass = "";
			cout << "\nEnter password:\n";
			ch = _getch();
			while (ch != 13)
			{
				pass.push_back(ch);
				cout << '*';
				ch = _getch();
			}
			if (pass == "hifsa")
			{
				cout << "\nAccess granted \3\n";
				cout << "Thanku for the visit\n\n";
			}
			else
				goto enteragain;
		}
		else
			goto enteragain;

	}
}

void InsertToFileCosmetics()
{
	ofstream OF;
	OF.open("CosmeticsInfo.txt");
	temp = head;
	while (temp != NULL)
	{
		OF << temp->Id << endl;
		OF << temp->name << endl;
		OF << temp->cNo << endl;
		OF << temp->address << endl;
		OF << temp->product_name << endl;
		OF << temp->Pcompany << endl;
		OF << temp->Email << endl;
		OF << temp->price << endl;
		OF << temp->quantity << endl;
		OF << temp->t_amount << endl;
		temp = temp->next;
	}
	OF.close();
}

void InsertToFileFurniture()
{
	ofstream OF;
	OF.open("FurnitureInfo.txt");
	temp1 = head1;
	while (temp1 != NULL)
	{
		OF << temp1->Id << endl;
		OF << temp1->name << endl;
		OF << temp1->cNo << endl;
		OF << temp1->address << endl;
		OF << temp1->product_name << endl;
		OF << temp1->Pcompany << endl;
		OF << temp1->Email << endl;
		OF << temp1->price << endl;
		OF << temp1->quantity << endl;
		OF << temp1->t_amount << endl;
		temp1 = temp1->next1;
	}
	OF.close();
}

void InsertCosmeticsOrder(int ID, string name, string address, string cNo, string Pcompany, string Email, string price, string quantity, double amount, string p_name)
{

	CosmeticsInfo *obj = new CosmeticsInfo;
	obj->Id = ID;
	obj->name = name;
	obj->address = address;
	obj->cNo = cNo;
	obj->Pcompany = Pcompany;
	obj->Email = Email;
	obj->price = price;
	obj->quantity = quantity;
	obj->t_amount = amount;
	obj->product_name = p_name;
	obj->next = NULL;
	if (head == NULL)
	{
		head = obj;
		cout << "\n   Your Order ID: " << ID << endl;
		InsertToFileCosmetics();

	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = obj;

		cout << "\n   Your Order ID: " << ID;
		InsertToFileCosmetics();

	}

}

void InsertFurnitureOrder(int ID, string name, string address, string cNo, string Pcompany, string Email, string price, string quantity, double amount, string p_name)
{

	FurnitureInfo *obj = new FurnitureInfo;
	obj->Id = ID;
	obj->name = name;
	obj->address = address;
	obj->cNo = cNo;
	obj->Pcompany = Pcompany;
	obj->Email = Email;
	obj->price = price;
	obj->quantity = quantity;
	obj->t_amount = amount;
	obj->product_name = p_name;
	obj->next1 = NULL;
	if (head1 == NULL)
	{
		head1 = obj;

		cout << "\n   Your Order ID: " << ID;
		InsertToFileFurniture();
	}
	else
	{
		temp1 = head1;
		while (temp1->next1 != NULL)
		{
			temp1 = temp1->next1;
		}
		temp1->next1 = obj;

		cout << "\n   Your Order ID: " << ID;
		InsertToFileFurniture();
	}
}

void DisplayCosmeticsOrder()
{
	cout << endl;
	if (head == NULL)
	{
		cout << "   NO RECORD FOUND. " << endl;
	}
	else
	{
		temp = head;
		while (temp != NULL)
		{
			cout << endl;
			cout << "   ID:           " << temp->Id << endl;
			cout << "   Name:         " << temp->name << endl;
			cout << "   Contact No:   " << temp->cNo << endl;
			cout << "   Address:      " << temp->address << endl;
			cout << "   Product Name: " << temp->product_name << endl;
			cout << "   Product Comapny:" << temp->Pcompany << endl;
			cout << "   Email:  " << temp->Email << endl;
			cout << "   Price:       " << temp->price << endl;
			cout << "   Quantity:     " << temp->quantity << endl;
			cout << "   Amount:       (price+tax) x Quantity " << endl << endl;
			cout << "   Total Amount: " << temp->price << " + rs 10 * " << temp->quantity << " = " << temp->t_amount << endl;
			cout << endl;
			temp = temp->next;
		}
	}
}

void DisplayFurnitureOrder()
{
	cout << endl;
	if (head1 == NULL)
	{
		cout << "   NO RECORD FOUND. " << endl;
	}
	else
	{
		temp1 = head1;
		while (temp1 != NULL)
		{
			cout << endl;
			cout << "   ID:           " << temp1->Id << endl;
			cout << "   Name:         " << temp1->name << endl;
			cout << "   Contact No:   " << temp1->cNo << endl;
			cout << "   Address:      " << temp1->address << endl;
			cout << "   Product Name: " << temp1->product_name << endl;
			cout << "   Product company:" << temp1->Pcompany << endl;
			cout << "   Email		  " << temp1->Email << endl;
			cout << "   Price:        " << temp1->price << endl;
			cout << "   Quantity:     " << temp1->quantity << endl;
			cout << "   Amount:       (price+tax) x Quantity" << endl << endl;
			cout << "   Total Amount: " << temp1->price << " + rs 10 tax * " << temp1->quantity << " = " << temp1->t_amount << endl;
			cout << endl;
			temp1 = temp1->next1;
		}
	}
}


void SearchCosmetics(int Id)
{
	temp = head;
	int flag = 0;
	if (head == NULL)
	{
		cout << endl;
		cout << "   No Record Found. " << endl;
		//return false;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->Id == Id)
			{
				cout << endl;
				cout << "   ID: " << Id << " Found. " << endl;
				cout << "   Details:    " << endl << endl;
				cout << "   Name:         " << temp->name << endl;
				cout << "   Contact No:   " << temp->cNo << endl;
				cout << "   Address:      " << temp->address << endl;
				cout << "   Product Name: " << temp->product_name << endl;
				cout << "   Product company:" << temp->Pcompany << endl;
				cout << "   Email: 			 " << temp->Email << endl;
				cout << "   Price :       " << temp->price << endl;
				cout << "   Quantity:     " << temp->quantity << endl;
				cout << "   Amount:       (price+tax) x Quantity " << endl << endl;
				cout << "   Total Amount: " << temp->price << " + rs 10 tax *" << temp->quantity << " = " << temp->t_amount << endl;
				break;
			}
			else
			{
				if (temp->next == NULL)
				{
					cout << "\n   " << Id << " ID Not Found. " << endl;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
	}
}

void SearchFurniture(int Id)
{
	temp1 = head1;
	int flag = 0;
	if (head1 == NULL)
	{
		cout << endl;
		cout << "   No Record Found. " << endl;
	}
	else
	{
		while (temp1 != NULL)
		{
			if (temp1->Id == Id)
			{
				cout << "   ID: " << Id << " Found. " << endl;
				cout << "   Details:    " << endl << endl;
				cout << "   Name:         " << temp1->name << endl;
				cout << "   Contact No:   " << temp1->cNo << endl;
				cout << "   Address:      " << temp1->address << endl;
				cout << "   Product Name: " << temp1->product_name << endl;
				cout << "   Product company" << temp1->Pcompany << endl;
				cout << "   Email:		  " << temp1->Email << endl;
				cout << "   Price :       " << temp1->price << endl;
				cout << "   Quantity:     " << temp1->quantity << endl;
				cout << "   Amount:       (price+tax) x Quantity " << endl << endl;
				cout << "   Total Amount: " << temp1->price << " + Rs10 tax* " << temp1->quantity << " = " << temp1->t_amount << endl;
				break;
			}
			else
			{
				if (temp1->next1 == NULL)
				{
					cout << "\n   " << Id << " ID Not Found. " << endl;
					break;
				}
				else
				{
					temp1 = temp1->next1;
				}
			}
		}
	}
}

void UpdateCosmeticsOrder(int ID)
{
	CosmeticsInfo CI;
	CosmeticsInfo *obj = new CosmeticsInfo;
	if (head == NULL)
	{
		cout << "   NO RECORD FOUND. " << endl;
	}
	else
	{
		temp = head;
		while (temp != NULL)
		{
			if (temp->Id == ID)
			{
				cin.ignore();
				cout << "   Enter Name: ";
				getline(cin, CI.name);
				cout << "   Enter Contact No: ";
				getline(cin, CI.cNo);
				cout << "   Enter Address: ";
				getline(cin, CI.address);
				cout << "   Enter Product Name: ";
				getline(cin, CI.product_name);
				cout << "   Enter Product company: ";
				getline(cin, CI.Pcompany);
				cout << "   Enter Email: ";
				getline(cin, CI.Email);
				cout << "   Enter Price: ";
				getline(cin, CI.price);
				cout << "   Enter Quantity: ";
				getline(cin, CI.quantity);
				double price = atoi(CI.price.c_str());
				double quantity = atoi(CI.quantity.c_str());
				double amount = (price + 10)* quantity;

				temp->name = CI.name;
				temp->address = CI.address;
				temp->cNo = CI.cNo;
				temp->Pcompany = CI.Pcompany;
				temp->address = CI.address;
				temp->product_name = CI.product_name;
				temp->Email = CI.Email;
				temp->price = CI.price;
				temp->quantity = CI.quantity;
				temp->t_amount = amount;
				cout << "\n   Update Successfully. " << endl;
				break;
			}
			else
			{
				if (temp->next == NULL)
				{
					cout << "\n   " << ID << " ID Not Found. " << endl;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
	}
}

void UpdateFurnitureOrder(int ID)
{

	FurnitureInfo FI;
	FurnitureInfo *obj = new FurnitureInfo;
	if (head1 == NULL)
	{
		cout << "   NO RECORD FOUND. " << endl;
	}
	else
	{
		temp1 = head1;
		while (temp1 != NULL)
		{
			if (temp1->Id == ID)
			{
				cin.ignore();
				cout << "   Enter Name: ";
				getline(cin, FI.name);
				cout << "   Enter Contact No: ";
				getline(cin, FI.cNo);
				cout << "   Enter Address: ";
				getline(cin, FI.address);
				cout << "   Enter Product Name: ";
				getline(cin, FI.product_name);
				cout << "   Enter Product company: ";
				getline(cin, FI.Pcompany);
				cout << "   Enter Email: ";
				getline(cin, FI.Email); \
					cout << "   Enter Price: ";
				getline(cin, FI.price);
				cout << "   Enter Quantity: ";
				getline(cin, FI.quantity);
				double price = atoi(FI.price.c_str());
				double quantity = atoi(FI.quantity.c_str());
				double amount = (price + 10)* quantity;
				temp1->name = FI.name;
				temp1->address = FI.address;
				temp1->cNo = FI.cNo;
				temp1->Pcompany = FI.Pcompany;
				temp1->address = FI.address;
				temp1->product_name = FI.product_name;
				temp1->Email = FI.Email;
				temp1->price = FI.price;
				temp1->quantity = FI.quantity;
				temp1->t_amount = amount;
				cout << "\n   Update Successfully. " << endl;
				break;
			}
			else
			{
				if (temp1->next1 == NULL)
				{
					cout << "\n   " << ID << " ID Not Found. " << endl;
					break;
				}
				else
				{
					temp1 = temp1->next1;
				}
			}
		}
	}
}

void DeleteCosmeticsOrder(int id)
{
	temp = head;
	temp2 = NULL;
	while (temp != NULL)
	{
		if (temp->Id == id)
		{
			if (head->Id == id)
			{
				head = temp->next;
				delete(temp);
				cout << "\n   ID Information Deleted. " << endl;
				break;
			}
			temp2->next = temp->next;
			delete(temp);
			cout << "\n   ID Infomation Deleted. " << endl;
			break;
		}
		else
		{
			if (temp->next == NULL)
			{
				cout << "\n   " << id << " ID not found. " << endl;
				break;
			}
			else
			{
				temp2 = temp;
				temp = temp->next;
			}
		}
	}
}

void DeleteFurnitureOrder(int id)
{
	temp1 = head1;
	temp22 = NULL;
	while (temp1 != NULL)
	{
		if (temp1->Id == id)
		{
			if (head1->Id == id)
			{
				head1 = temp1->next1;
				delete(temp1);
				cout << "\n   ID Information Deleted. " << endl;
				break;
			}
			temp22->next1 = temp1->next1;
			delete(temp1);
			cout << "\n   ID Information Deleted. " << endl;
			break;
		}
		else
		{
			if (temp1->next1 == NULL)
			{
				cout << "\n   " << id << " ID not found. " << endl;
				break;
			}
			else
			{
				temp22 = temp1;
				temp1 = temp1->next1;
			}
		}
	}
}

void LoadtoLLCosmetics(CosmeticsInfo*obj)
{

	if (head == NULL)
	{
		head = obj;
	}
	else
	{
		temp = head;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = obj;
	}
}

void LoadtoLLFurniture(FurnitureInfo*obj)
{

	if (head1 == NULL)
	{
		head1 = obj;
	}
	else
	{
		temp1 = head1;
		while (temp1->next1 != NULL)
		{
			temp1 = temp1->next1;
		}
		temp1->next1 = obj;
	}
}

void DisplayfromFileCosmetics()
{

	ifstream read("CosmeticsInfo.txt");
	string line;
	head = NULL;
	while (!read.eof())
	{
		CosmeticsInfo *obj = new CosmeticsInfo;
		obj->next = NULL;
		getline(read, line);
		if (!line.empty())
		{
			int id = atoi(line.c_str());
			obj->Id = id;
			getline(read, line);
			obj->name = line;
			getline(read, line);
			obj->address = line;
			getline(read, line);
			obj->cNo = line;
			getline(read, line);
			obj->product_name = line;
			getline(read, line);
			obj->Pcompany = line;
			getline(read, line);
			obj->Email = line;
			getline(read, line);
			obj->price = line;
			getline(read, line);
			obj->quantity = line;
			getline(read, line);
			double amount = atoi(line.c_str());
			obj->t_amount = amount;
			LoadtoLLCosmetics(obj);
		}
	}
}

void DisplayfromFileFurniture()
{
	ifstream read("FurnitureInfo.txt");
	string line;
	head1 = NULL;
	while (!read.eof())
	{
		FurnitureInfo *obj = new FurnitureInfo;
		obj->next1 = NULL;
		getline(read, line);
		if (!line.empty())
		{
			int a = atoi(line.c_str());
			obj->Id = a;
			getline(read, line);
			obj->name = line;
			getline(read, line);
			obj->address = line;
			getline(read, line);
			obj->cNo = line;
			getline(read, line);
			obj->product_name = line;
			getline(read, line);
			obj->Pcompany = line;
			getline(read, line);
			obj->Email = line;
			getline(read, line);
			obj->price = line;
			getline(read, line);
			obj->quantity = line;
			getline(read, line);
			double amount = atoi(line.c_str());
			obj->t_amount = amount;
			LoadtoLLFurniture(obj);
		}
	}
}

bool SearchCosmeticsInsert(int Id)
{
	temp = head;
	if (head == NULL)
	{
		return false;
	}
	else
	{
		while (temp != NULL)
		{
			if (temp->Id == Id)
			{
				return true;
				break;
			}
			else
			{
				if (temp->next == NULL)
				{
					return false;
					break;
				}
				else
				{
					temp = temp->next;
				}
			}
		}
	}
}

bool SearchFurnitureInsert(int Id)
{
	temp1 = head1;
	if (head1 == NULL)
	{
		return false;
	}
	else
	{
		while (temp1 != NULL)
		{
			if (temp1->Id == Id)
			{
				return true;
				break;
			}
			else
			{
				if (temp1->next1 == NULL)
				{
					return false;
					break;
				}
				else
				{
					temp1 = temp1->next1;
				}
			}
		}
	}
}

void Panel()
{
	system("cls");
	cout << endl;
	cout << "                ***********************************************************************************              " << endl;
	cout << "                *                                  COSMETICS & FURNITURE                          *              " << endl;
	cout << "                ***********************************************************************************              " << endl;
	cout << endl << endl;
	cout << "   1) Place Order: \n" << endl;
	cout << "   2) Display Cosmetics Order: \n" << endl;
	cout << "   3) Display Furniture Order: \n" << endl;
	cout << "   4) Search Order: \n" << endl;
	cout << "   5) Update Order: \n" << endl;
	cout << "   6) Delete Order: \n" << endl;
	cout << "   7) Generate Slip: \n" << endl;
	cout << "   8) Exit: " << endl;
	cout << endl;
	cout << "      Enter Choice: ";
}

void GenerateSlip()
{
}






int main()
{
	login s;
	system("color 4F");

	Menu();
	loginverification();
	system("cls");

	system("color E0");
	welcomenote();
	system("cls");

	system("color B1");

	DisplayfromFileCosmetics();
	DisplayfromFileFurniture();
	int CosID = 1;
	int FurID = 500;
	CosmeticsInfo CI;
	FurnitureInfo FI;

	ifstream last;
	string cosmetic_list, Furniture_list;
	last.open("cosmetics_list.txt");
	ifstream las;
	las.open("Furniture_list.txt");

	SYSTEMTIME a;
	GetLocalTime(&a);

jump:

	Panel();
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		system("color 0A");
		system("cls");
		cout << "\n   PLACE ORDER: " << endl;
		int choose;
		cout << endl;
		cout << "   1) Cosmetics: " << endl;
		cout << "   2) Furniture: " << endl;
		cout << endl;
		cout << "      Enter Choice: ";
		cin >> choose;
		if (choose == 1)
		{

			while (!last.eof())
			{
				getline(last, cosmetic_list);


				cout << cosmetic_list << endl;
			}
			last.close();
			cout << endl;
			cout << "   Enter Details: " << endl;
			cin.ignore();
			cout << "   Enter Name: ";
			getline(cin, CI.name);
			cout << "   Enter Contact No: ";
			getline(cin, CI.cNo);
			cout << "   Enter Address: ";
			getline(cin, CI.address);
			cout << "   Enter Product Name: ";
			getline(cin, CI.product_name);
			cout << "   Enter Product company: ";
			getline(cin, CI.Pcompany);
			cout << "   Enter Email: ";
			getline(cin, CI.Email);
			cout << "   Enter Price : ";
			getline(cin, CI.price);
			cout << "   Enter Quantity: ";
			getline(cin, CI.quantity);
			while (SearchCosmeticsInsert(CosID) == true)
			{
				CosID++;
				SearchCosmeticsInsert(CosID);
			}
			double price = atoi(CI.price.c_str());
			double quantity = atoi(CI.quantity.c_str());
			double amount = (price + 10) * quantity;
			InsertCosmeticsOrder(CosID, CI.name, CI.address, CI.cNo, CI.Pcompany, CI.Email, CI.price, CI.quantity, amount, CI.product_name);
			InsertToFileCosmetics();
		}
		else if (choose == 2)
		{

			while (!las.eof())
			{
				getline(las, Furniture_list);


				cout << Furniture_list << endl;
			}
			las.close();
			cout << endl;
			cout << "   Enter Details: " << endl;
			cin.ignore();
			cout << "   Enter Name: ";
			getline(cin, FI.name);
			cout << "   Enter Contact No: ";
			getline(cin, FI.cNo);
			cout << "   Enter Address: ";
			getline(cin, FI.address);
			cout << "   Enter Product Name: ";
			getline(cin, FI.product_name);
			cout << "   Enter Product company: ";
			getline(cin, FI.Pcompany);
			cout << "   Enter Email: ";
			getline(cin, FI.Email);
			cout << "   Enter Price : ";
			getline(cin, FI.price);
			cout << "   Enter Quantity: ";
			getline(cin, FI.quantity);
			while (SearchFurnitureInsert(FurID) == true)
			{
				FurID++;
				SearchFurnitureInsert(FurID);
			}
			double price = atoi(FI.price.c_str());
			double quantity = atoi(FI.quantity.c_str());
			double amount = price * quantity * 700;
			InsertFurnitureOrder(FurID, FI.name, FI.address, FI.cNo, FI.Pcompany, FI.Email, FI.price, FI.quantity, amount, FI.product_name);
			InsertToFileCosmetics();
		}
	}
	else if (choice == 2)
	{
		system("color 1F");
		system("cls");
		cout << "\n   COSMETICS ORDERS: " << endl;
		DisplayCosmeticsOrder();
	}
	else if (choice == 3)
	{
		system("color 5F");
		system("cls");
		cout << "\n   FURNITURE ORDERS: " << endl;
		DisplayFurnitureOrder();
	}
	else if (choice == 4)
	{
		system("color 27");
		system("cls");
		int cho;
		cout << endl;
		cout << "   SEARCH ORDER: " << endl;
		cout << "   1) Cosmetics. " << endl;
		cout << "   2) Furniture. " << endl;
		cout << endl;
		cout << "   Enter Choice: ";
		cin >> cho;
		int search;
		if (cho == 1)
		{
			cout << "   Enter the ID to Search:  ";
			cin >> search;
			SearchCosmetics(search);
		}
		else if (cho == 2)
		{
			cout << "   Enter the ID to Search:  ";
			cin >> search;
			SearchFurniture(search);
		}

	}
	else if (choice == 5)
	{
		system("color 4F");
		system("cls");
		int choices;
		cout << "\n   UPDATE ORDER: " << endl;
		cout << "   1) Cosmetics. " << endl;
		cout << "   2) Furniture. " << endl;
		cout << endl;
		cout << "   Enter Choice: ";
		cin >> choices;
		int id;
		if (choices == 1)
		{
			cout << endl;
			cout << "   Enter ID to Update: ";
			cin >> id;
			UpdateCosmeticsOrder(id);
			InsertToFileCosmetics();
		}
		else if (choices == 2)
		{
			cout << endl;
			cout << "   Enter ID to Update: ";
			cin >> id;
			UpdateFurnitureOrder(id);
			InsertToFileFurniture();
		}
	}
	else if (choice == 6)
	{
		system("color F0");
		system("cls");
		int choicez;
		cout << "\n   DELETE ORDER: " << endl;
		cout << "   1)COSMETICS: " << endl;
		cout << "   2)FURNITURE: " << endl;
		cout << endl;
		cout << "   Enter Choice: ";
		cin >> choicez;
		if (choicez == 1)
		{
			cout << "   Enter ID to delete: ";
			int id;
			cin >> id;
			DeleteCosmeticsOrder(id);
			InsertToFileCosmetics();
		}
		else if (choicez == 2)
		{
			cout << "   Enter ID to delete: ";
			int id;
			cin >> id;
			DeleteFurnitureOrder(id);
			InsertToFileFurniture();
		}
	}
	else if (choice == 7)
	{
		system("color 1F");
		system("cls");
		cout << "\n   GENERATE SLIP: " << endl;
		int slip_Id, chh;
		cout << endl;
		cout << "   1) COSMETICS: " << endl;
		cout << "   2) FURNITURE: " << endl << endl;
		cout << "   Enter choice: ";
		cin >> chh;
		if (chh == 1)
		{
			cout << "   Enter ID to Generate your slip: ";
			cin >> slip_Id;
			SearchCosmetics(slip_Id);
			if (SearchCosmeticsInsert(slip_Id) == true)
			{
				cout << "   Order Date: " << a.wDay << "-" << a.wMonth << "-" << a.wYear << endl;

				cout << "\n   BILL PAID. " << endl;
			}
		}
		else if (chh == 2)
		{
			cout << "   Enter ID to Generate your slip: ";
			cin >> slip_Id;
			cout << endl;
			SearchFurniture(slip_Id);
			if (SearchFurnitureInsert(slip_Id) == true)
			{
				cout << "   Order Date: " << a.wDay << "-" << a.wMonth << "-" << a.wYear << endl;

				cout << "\n   BILL PAID. " << endl;
			}
		}
	}
	else if (choice == 8)
	{
		system("cls");
		system("color 1F");
		string Exit;
		ifstream op;
		op.open("Exit.txt");
		while (!op.eof())
		{
			getline(op, Exit);


			cout << Exit << endl;
		}
		op.close();
		system("exit");
		exit(0);

	}


	_getch();
	goto jump;
	return 0;
}



