#include <iostream>
#include <string>
#include <Windows.h>
#include "MúsicaLyricsSearch.h"
#include "MúsicaSongSearch.h"

using namespace std;

class MúsicaCategoryOptions
{
private :
	string SongName, Artists, Genre, Year;
	int tracker = 0;
	MúsicaLyricsSearch LyricsSearch;
	MúsicaSongSearch SongSearch;
public:
	void MúsicaAdminOptions();
	void MúsicaUserOptions();
	string LowerToUpperCase(string LTU);
	
};
void MúsicaCategoryOptions::MúsicaAdminOptions()
{
	int choice;
	string notfound;
	ifstream SongNotFound;
	AddSongInMúsica Add;
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << "\t\t\t\t1. ADD SONG";
		cout << endl << "\t\t\t\t2. REMOVE SONG";
		cout << endl << "\t\t\t\t3. SEARCH SONG BY LYRICS";
		cout << endl << "\t\t\t\t4. SEARCH BY NAME";
		cout << endl << "\t\t\t\t5. SEARCH BY YEAR";
		cout << endl << "\t\t\t\t6. SEARCH BY ARTIST";
		cout << endl << "\t\t\t\t7. SEARCH BY LANGUAGE";
		cout << endl << "\t\t\t\t8. SEARCH BY ALBUM";
		cout << endl << "\t\t\t\t9. SONGS NOT FOUND BY USER";
		cout << endl << "\t\t\t\t10. EXIT";
		cout << endl << endl << "ENTER CHOICE:  ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			Add.AddSong();
			break;
		case 2:
			Add.RemoveSong();
			break;
		case 3:
			tracker = 1;
			SongName = LyricsSearch.SearchPattern();
			SongName = LowerToUpperCase(SongName);
			SongSearch.Search(SongName, tracker);
			getchar();
			tracker = 0;
			break;
		case 4:
			tracker = 1;
			cout << endl << "SONGNAME: ";
			getline(cin >> ws, SongName);
			SongName = LowerToUpperCase(SongName);
			system("cls");
			SongSearch.Search(SongName,tracker);
			getchar();
			tracker = 0;
			break;
		case 5:
			tracker = 2;
			cout << endl << "YEAR: ";
			getline(cin >> ws, Year);
			system("cls");
			SongSearch.Search(Year,tracker);
			getchar();
			getchar();
			tracker = 0;
			break;
		case 6:
			tracker = 3;
			cout << endl << "ARTIST: ";
			getline(cin >> ws, SongName);
			SongName = LowerToUpperCase(SongName);
			system("cls");
			SongSearch.Search(SongName, tracker);
			getchar();
			tracker = 0;
			break;
		case 7:
			tracker = 4;
			cout << endl << "LANGUAGE: ";
			getline(cin >> ws, SongName);
			SongName = LowerToUpperCase(SongName);
			system("cls");
			SongSearch.Search(SongName, tracker);
			getchar();
			tracker = 0;
			break;
		case 8:
			tracker = 5;
			cout << endl << "ALBUM: ";
			getline(cin >> ws, SongName);
			SongName = LowerToUpperCase(SongName);
			system("cls");
			SongSearch.Search(SongName, tracker);
			getchar();
			tracker = 0;
			break;
		case 9:
			system("cls");
			SongNotFound.open("MúsicaSongsNotFound.txt");
			cout << endl << "SONGS THAT ARE NOT PRESENT IN DATASET ARE AS FOLLOWS:- " << endl;
			while (!SongNotFound.eof())
			{
				getline(SongNotFound, notfound, '|');
				cout << endl << notfound;
			}
			getchar();
			getchar();
			break;
		case 10:
			return;

		}
	}
}
void MúsicaCategoryOptions::MúsicaUserOptions()
{
	int choice;
	while (1)
	{
		system("cls");
		cout << endl << endl << endl << "\t\t\t\t1. SEARCH SONG BY LYRICS";
		cout << endl << "\t\t\t\t2. SEARCH BY NAME";
		cout << endl << "\t\t\t\t3. SEARCH BY YEAR";
		cout << endl << "\t\t\t\t4. SEARCH BY ARTIST";
		cout << endl << "\t\t\t\t5. SEARCH BY LANGUAGE";
		cout << endl << "\t\t\t\t6. SEARCH BY ALBUM";
		cout << endl << "\t\t\t\t7. EXIT";
		cout << endl << endl << "ENTER CHOICE:  ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			tracker = 1;
			SongName = LyricsSearch.SearchPattern();
			SongSearch.Search(SongName, tracker);
			getchar();
			tracker = 0;
			break;
		case 2:
			tracker = 1;
			cout << endl << "SONGNAME: ";
			getline(cin >> ws, SongName);
			SongName = LowerToUpperCase(SongName);
			SongSearch.Search(SongName, tracker);
			getchar();
			tracker = 0;
			break;
		case 3:
			tracker = 2;
			cout << endl << "YEAR: ";
			getline(cin >> ws, Year);
			SongSearch.Search(Year, tracker);
			tracker = 0;
			break;
		case 4:
			tracker = 3;
			cout << endl << "ARTIST: ";
			getline(cin >> ws, SongName);
			SongName = LowerToUpperCase(SongName);
			system("cls");
			SongSearch.Search(SongName, tracker);
			getchar();
			tracker = 0;
			break;
		case 5:
			tracker = 4;
			cout << endl << "LANGUAGE: ";
			getline(cin >> ws, SongName);
			SongName = LowerToUpperCase(SongName);
			system("cls");
			SongSearch.Search(SongName, tracker);
			getchar();
			tracker = 0;
			break;
		case 6:
			tracker = 5;
			cout << endl << "ALBUM: ";
			getline(cin >> ws, SongName);
			SongName = LowerToUpperCase(SongName);
			system("cls");
			SongSearch.Search(SongName, tracker);
			getchar();
			tracker = 0;
			break;
		case 7:
			return;
		}
	}
}




string MúsicaCategoryOptions::LowerToUpperCase(string LTUC)
{
	int length = LTUC.length();
	for (int i = 0; i < length; i++)
	{
		if (LTUC[i] >= 97 && LTUC[i] <= 122)
		{
			LTUC[i] = LTUC[i] - 32;
		}
	}
	return LTUC;
}
