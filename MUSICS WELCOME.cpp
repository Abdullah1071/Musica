#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include "MúsicaCategoryOptions.h"

using namespace std;

class MúsicaWelcome
{
public:
	void Ask();
	void SignIn();
	void SignUp();
	void Design();
};


void MúsicaWelcome::Ask()
{
	int Choice;
	while (1)
	{
		cout << endl << endl << endl << "\t\t\t\t\t1. SIGN IN" << endl;
		cout << endl << "\t\t\t\t\t2. SIGN UP" << endl;
		cout << endl << "ENTER CHOICE: ";
		cin >> Choice;
		if (Choice == 1)
		{
			SignIn();
			return;
		}
		else if (Choice == 2)
		{
			system("cls");
			SignUp();
			return;
		}
		else
		{
			continue;
		}
	}
}


void MúsicaWelcome::SignUp()
{
	int SignInChoice, ID;
	string check1, check2, check3, check4;
	string UserName, Password, ConfirmPassword;
	ofstream MúsicaSignInData;
	MúsicaSignInData.open("MúsicaSignIn.txt", std::ios_base::app);
	ifstream IDCheck;
	IDCheck.open("MúsicaSignIn.txt");
	while (!IDCheck.eof())
	{
		getline(IDCheck, check1, '|');
		ID = (int)atof(check1.c_str());
		getline(IDCheck, check2, '|');
		getline(IDCheck, check3, '|');
		getline(IDCheck, check4);
	}

	++ID;

	cout << endl << endl << endl << "\t\t\t\t\tUSERNAME: ";
	cin >> UserName;
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << "\t\t\t\t\tPASSWORD: ";
		cin >> Password;
		cout << endl << "\t\t\t\t\tCONFIRM PASSWORD: ";
		cin >> ConfirmPassword;
		if (Password == ConfirmPassword)
		{
			if (MúsicaSignInData.is_open())
			{
				MúsicaSignInData << "\n" << ID << "|";
				MúsicaSignInData << "User" << "|";
				MúsicaSignInData << UserName << "|";
				MúsicaSignInData << Password;
				MúsicaSignInData.close();
			}
			cout << endl << "\t\t\t\t\tYOU SIGNED UP SUCCESSFULLY" << endl;
			getchar();
			break;
		}
		else
		{
			cout << endl << "\t\t\t\t\tPASSWORD NOT MATCHED" << endl;
			cout << endl << "\t\t\t\t\tPLEASE RE-ENTER PASSWORD";
			getchar();
			continue;
		}
	}
	cout << endl << "\t\t\t\t\tWANT TO SIGN IN?" << endl;
	cout << endl << "\t\t\t\t\t1. YES" << endl;
	cout << endl << "\t\t\t\t\t2. NO" << endl;
	cout << endl << "ENTER CHOICE: ";
	cin >> SignInChoice;
	if (SignInChoice == 1)
	{
		SignIn();
	}
	else if (SignInChoice == 2)
	{
		return;
	}
}

void MúsicaWelcome::SignIn()
{
	MúsicaCategoryOptions Options;
	int SignInChoice, SignUpChoice, i = 0, count = 0, Erase = 0;
	const int size = 100;
	char PasswordInput[size], tempchar;
	string Password, UserName;
	string CheckUserName, CheckPassword, CheckAdmin, CheckID;
	string CheckPasswordStore[size], CheckUserNameStore[size], CheckAdminStore[size], CheckIDStore[size];
	ifstream in;
	in.open("MúsicaSignIn.txt");
	while (getline(in, CheckID, '|'))
	{
		getline(in, CheckAdmin, '|');
		getline(in, CheckUserName, '|');
		getline(in, CheckPassword);
		CheckIDStore[i] = CheckID;
		CheckAdminStore[i] = CheckAdmin;
		CheckUserNameStore[i] = CheckUserName;
		CheckPasswordStore[i] = CheckPassword;
		i++;
	}
	while (1)
	{
		count = 0;
		system("cls");
		cout << endl << endl << endl << "\t\t\t\t\tSIGN IN";
		cout << endl << "\t\t\t\t\tAS ";
		cout << endl << "\t\t\t\t\t1. ADMIN";
		cout << endl << "\t\t\t\t\t2. USER" << endl;
		cout << endl << "ENTER CHOICE: ";
		cin >> SignInChoice;
		if (SignInChoice == 1)
		{
			cout << endl << "\t\t\t\tCHOOSED ADMIN TO LOGN";
		}
		else if (SignInChoice == 2)
		{
			cout << endl << "\t\t\t\tCHOOSED USER TO LOGIN";
		}
		cout << endl << endl;
		getchar();
		system("cls");
	UserName:
		system("cls");
		cout << endl << endl << endl << "\t\t\t\t\tUSERNAME: ";
		cin >> UserName;
		for (int i = 0; i < size; i++)
		{
			if ((CheckUserNameStore[i] == UserName) && (CheckAdminStore[i] == "Admin") && (SignInChoice == 1))
			{
				count = 1;
				break;
			}
			else if ((CheckUserNameStore[i] == UserName) && (CheckAdminStore[i] != "Admin") && (SignInChoice == 1))
			{
				count = 2;
				break;
			}
			else if ((CheckUserNameStore[i] == UserName) && (CheckAdminStore[i] == "User") && (SignInChoice == 2))
			{
				count = 3;
				break;
			}
			else if ((CheckUserNameStore[i] == UserName) && (CheckAdminStore[i] != "User") && (SignInChoice == 2))
			{
				count = 4;
				break;
			}
		}
		if (count == 1)
		{
			break;
		}
		else if (count == 2)
		{
			cout << endl << "USERNAME IS INCORRECT" << endl;
			getchar();
			continue;
		}
		else if (count == 3)
		{
			break;
		}
		else if (count == 4)
		{
			cout << endl << "LOGIN AGAIN AS USER" << endl;
			getchar();
			continue;
		}
		else
		{
			cout << endl << "\t\t\t\t\tUSERNAME NOT EXIST" << endl << endl;
			cout << "\t\t\t\t\t1. SIGN IN AGAIN?" << endl;
			cout << endl << "\t\t\t\t\t2. SIGN UP" << endl;
			cout << endl << "ENTER CHOICE: ";
			cin >> SignUpChoice;
			if (SignUpChoice == 1)
			{
				goto UserName;
			}
			else if (SignUpChoice == 2)
			{
				SignUp();
				return;
			}
		}
	}
	while (1)
	{
		Password = "";
		Erase = 0, count = 0, i = 0;
		cout << endl << endl << "\t\t\t\t\tPASSWORD: ";
		for (i = 0;;)
		{
			tempchar = _getch();
			if ((tempchar >= 'a' && tempchar <= 'z') || (tempchar >= 'A' && tempchar <= 'Z') || (tempchar >= '0' && tempchar <= '9'))
			{
				PasswordInput[i] = tempchar;
				Password = Password + PasswordInput[i];
				++i;
				cout << "*";
			}
			else if (tempchar == '\b' && i >= 1)
			{
				Erase = 1;
				Password.erase(Password.end() - Erase);
				cout << "\b \b";
				--i;
			}
			else if (tempchar == '\r')
			{
				PasswordInput[i] = '\0';
				break;
			}
		}
		cout << endl;
		for (int i = 0; i < size; i++)
		{
			if ((CheckAdminStore[i] == "Admin") && (CheckUserNameStore[i] == UserName) && (CheckPasswordStore[i] == Password))
			{
				count = 1;
				break;
			}
			else if ((CheckAdminStore[i] == "User") && (CheckUserNameStore[i] == UserName) && (CheckPasswordStore[i] == Password))
			{
				count = 2;
				break;
			}
		}
		if (count == 1)
		{
			cout << endl << "\t\t\t\tWELCOME   " << UserName << "   TO MUSICA" << endl;
			getchar();
			Options.MúsicaAdminOptions();

			break;
		}
		else if (count == 2)
		{
			cout << endl << "\t\t\t\tWELCOME   " << UserName << "   TO MUSICA" << endl;
			getchar();
			Options.MúsicaUserOptions();

			break;
		}
		else
		{
			cout << endl << "\t\t\t\t\tPASSWORD INCORRECT" << endl;
			cout << endl << "\t\t\t\t\tPLEASE RE-ENTER PASSWORD" << endl;
			system("cls");
			getchar();
			continue;
		}
	}
}
