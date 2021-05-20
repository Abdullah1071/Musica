#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <Windows.h>
#include "AddSongInMúsica.h"

using namespace std;

class HashToLinkedList_Node
{
public:
	AddSongInMúsica Song;
	HashToLinkedList_Node* next;
	HashToLinkedList_Node()
	{

	}
	HashToLinkedList_Node(AddSongInMúsica Song, HashToLinkedList_Node* next = NULL)
	{
		this->Song = Song;
		this->next = next;
	}
};
class MúsicaSongSearch
{
private:
	HashToLinkedList_Node** Hashtable;
	const int TABLE_SIZE = 100;
	bool SearchCheck = false;
public:
	MúsicaSongSearch();
	~MúsicaSongSearch();
	int HashFunction(string SongName);
	void AddSongInHashMap(AddSongInMúsica Song, int track);
	void Search(string SongName, int track);
	void ReadMúsicaSongData(int track);
	string EasySearch(string search, int tracker);
	void patternfound(string Search, string pattern);
	void PrintTagLine();
	void MúsicaPLayOptions(string SongName);
	void Play_Wishlist();

};
MúsicaSongSearch::MúsicaSongSearch()
{
	Hashtable = new HashToLinkedList_Node * [TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; i++)
		Hashtable[i] = NULL;
}
MúsicaSongSearch::~MúsicaSongSearch()
{
	for (int i = 0; i < TABLE_SIZE; ++i)
	{
		HashToLinkedList_Node* Entry = Hashtable[i];
		while (Entry != NULL)
		{
			HashToLinkedList_Node* previous = Entry;
			Entry = Entry->next;
			delete previous;
		}
	}
	delete[] Hashtable;
}

int MúsicaSongSearch::HashFunction(string CalHash)
{
	int length = CalHash.length();
	int Hash = 0;
	for (int i = 0; i < length; i++)
	{
		Hash = Hash + CalHash[i];
	}
	Hash = Hash % TABLE_SIZE;
	return Hash;
}


void MúsicaSongSearch::AddSongInHashMap(AddSongInMúsica Song, int track)
{
	int hash_val;
	if (track == 1)
	{
		hash_val = HashFunction(Song.getSongName());
	}
	else if (track == 2)
	{
		hash_val = HashFunction(Song.getYear());
	}
	else if (track == 3)
	{
		hash_val = HashFunction(Song.getArtist());
	}
	else if (track == 4)
	{
		hash_val = HashFunction(Song.getLanguage());
	}
	else if (track == 5)
	{
		hash_val = HashFunction(Song.getAlbum());
	}
	HashToLinkedList_Node* previous = NULL;
	HashToLinkedList_Node* Entry = Hashtable[hash_val];
	while (Entry != NULL)
	{
		previous = Entry;
		Entry = Entry->next;
	}
	if (Entry == NULL)
	{
		Entry = new HashToLinkedList_Node(Song);
		if (previous == NULL)
		{
			Hashtable[hash_val] = Entry;
		}
		else
		{
			previous->next = Entry;
		}
	}
	else
	{
		Entry->Song = Song;
	}
}

void MúsicaSongSearch::Search(string Search, int track)
{
	ofstream SongNotFound;
	int counter = 0;
	bool flag = false;
	//Search = EasySearch(Search, track);
	ReadMúsicaSongData(track);
	int hash_val = HashFunction(Search);
	HashToLinkedList_Node* Entry = Hashtable[hash_val];
	PrintTagLine();
	while (Entry != NULL)
	{
		if (track == 1)
		{
			if (Entry->Song.getSongName() == Search)
			{
				cout << setw(23) << Entry->Song.getSongName() << setw(17) << Entry->Song.getArtist() << setw(52) <<
					Entry->Song.getFeatured() << setw(28) << Entry->Song.getAlbum() << setw(15) <<
					Entry->Song.getGenre() << setw(15) << Entry->Song.getYear() << setw(15) << Entry->Song.getLanguage() << endl;
				flag = true;
				MúsicaPLayOptions(Search);
			}
			else
			{
				cout << endl << "THIS SONGS IS PRESENT" << endl;
				SongNotFound.open("MúsicaSongsNotFound.txt");
				if (SongNotFound.is_open())
				{
					SongNotFound << Search << "|";
				}
				break;
			}
		}
		else if (track == 2)
		{
			if (Entry->Song.getYear() == Search)
			{
				cout << setw(23) << Entry->Song.getSongName() << setw(17) << Entry->Song.getArtist() << setw(52) <<
					Entry->Song.getFeatured() << setw(28) << Entry->Song.getAlbum() << setw(15) <<
					Entry->Song.getGenre() << setw(15) << Entry->Song.getYear() << setw(15) << Entry->Song.getLanguage() << endl;
				flag = true;
			}
			else
			{
				break;
			}
		}
		else if (track == 3)
		{
			if (Entry->Song.getArtist() == Search)
			{
				cout << setw(23) << Entry->Song.getSongName() << setw(17) << Entry->Song.getArtist() << setw(52) <<
					Entry->Song.getFeatured() << setw(28) << Entry->Song.getAlbum() << setw(15) <<
					Entry->Song.getGenre() << setw(15) << Entry->Song.getYear() << setw(15) << Entry->Song.getLanguage() << endl;
				flag = true;
			}
			else
			{
				break;
			}
		}
		else if (track == 4)
		{
			if (Entry->Song.getLanguage() == Search)
			{
				cout << setw(23) << Entry->Song.getSongName() << setw(17) << Entry->Song.getArtist() << setw(52) <<
					Entry->Song.getFeatured() << setw(28) << Entry->Song.getAlbum() << setw(15) <<
					Entry->Song.getGenre() << setw(15) << Entry->Song.getYear() << setw(15) << Entry->Song.getLanguage() << endl;
				flag = true;
			}
			else
			{
				break;
			}
		}
		else if (track == 5)
		{
			if (Entry->Song.getAlbum() == Search)
			{
				cout << setw(23) << Entry->Song.getSongName() << setw(17) << Entry->Song.getArtist() << setw(52) <<
					Entry->Song.getFeatured() << setw(28) << Entry->Song.getAlbum() << setw(15) <<
					Entry->Song.getGenre() << setw(15) << Entry->Song.getYear() << setw(15) << Entry->Song.getLanguage() << endl;
				flag = true;
			}
			else
			{
				break;
			}
		}
		Entry = Entry->next;
	}
	if (!flag)
	{
		cout << endl << "NOTHING FOUND" << endl;
	}
	return;
}

void MúsicaSongSearch::PrintTagLine()
{
	cout << endl << setw(23) << "SONGNAME" << setw(17) << "ARTIST" << setw(52) << "FEATURED" << setw(28) << "ALBUM" << setw(15) <<
		"GENRE" << setw(15) << "YEAR" << setw(15) << "LANGUAGE" << endl << endl;
}


void MúsicaSongSearch::ReadMúsicaSongData(int track)
{
	int i = 0;
	string SongName, Artists, Featured, Album, Genre, Language, Year;
	AddSongInMúsica Song;
	ifstream file;
	file.open("MúsicaSongsData.txt");
	while (!file.eof())
	{
		getline(file, SongName, '|');
		Song.setSongName(SongName);
		getline(file, Artists, '|');
		Song.setArtists(Artists);
		getline(file, Featured, '|');
		Song.setFeatured(Featured);
		getline(file, Album, '|');
		Song.setAlbum(Album);
		getline(file, Genre, '|');
		Song.setGenre(Genre);
		getline(file, Language, '|');
		Song.setLanguage(Language);
		getline(file, Year);
		Song.setYear(Year);
		AddSongInHashMap(Song, track);

		i++;
	}
}


string MúsicaSongSearch::EasySearch(string search, int tracker)
{
	int i = 0;
	string checksearch;
	string SongName, Artists, Featured, Album, Genre, Language, Year;
	const int size = 120;
	string SongNameArr[size], ArtistsArr[size], AlbumArr[size], LanguageArr[size], YearArr[size];
	ifstream file;
	file.open("MúsicaSongsData.txt");
	while (!file.eof())
	{
		getline(file, SongName, '|');
		SongNameArr[i] = SongName;
		getline(file, Artists, '|');
		ArtistsArr[i] = Artists;
		getline(file, Featured, '|');
		getline(file, Album, '|');
		AlbumArr[i] = Album;
		getline(file, Genre, '|');
		getline(file, Language, '|');
		LanguageArr[i] = Language;
		getline(file, Year);
		YearArr[i] = Year;
		i++;
	}

	if (tracker == 1)
	{
		i = 0;
		while (i < size)
		{
			checksearch = SongNameArr[i];
			patternfound(checksearch, search);
			if (SearchCheck == true)
			{
				break;
			}
			else
			{
				i++;
				continue;
			}
		}
		return SongNameArr[i];
	}
	else if (tracker == 2)
	{
		i = 0;
		while (i < size)
		{
			patternfound(YearArr[i], search);
			if (SearchCheck == true)
			{
				break;
			}
			else
			{
				i++;
				continue;
			}
		}
		return YearArr[i];
	}
	else if (tracker == 3)
	{
		i = 0;
		while (i < size)
		{
			patternfound(ArtistsArr[i], search);
			if (SearchCheck == true)
			{
				break;
			}
			else
			{
				i++;
				continue;
			}
		}
		return ArtistsArr[i];
	}
	else if (tracker == 4)
	{
		i = 0;
		while (i < size)
		{
			patternfound(LanguageArr[i], search);
			if (SearchCheck == true)
			{
				break;
			}
			else
			{
				i++;
				continue;
			}
		}
		return LanguageArr[i];
	}
	else if (tracker == 5)
	{
		i = 0;
		while (i < size)
		{
			patternfound(AlbumArr[i], search);
			if (SearchCheck == true)
			{
				break;
			}
			else
			{
				i++;
				continue;
			}
		}
		return AlbumArr[i];
	}

	return "THIS SONG IS NOT PRESENT";
}

void MúsicaSongSearch::patternfound(string Search, string pattern)
{
	size_t Found = Search.find(pattern, 0);
	while (Found != string::npos)
	{
		Found = Search.find(pattern, Found + 1);
		SearchCheck = true;
	}
}


void MúsicaSongSearch::MúsicaPLayOptions(string SongName)
{
	int choice;
	LPCSTR songname;
	getchar();
	system("cls");
	cout << endl << "\t\t\t\t1. WANT TO PLAY THIS SONG";
	cout << endl << "\t\t\t\t2. WANT TO ADD THIS SONG INTO YOUR WISHLIST";
	cout << endl << endl << "ENTER CHOICE: ";
	cin >> choice;
	switch (choice)
	{
	case 1:
		songname = SongName.c_str();
		PlaySound(TEXT(songname), NULL, SND_SYNC);
		return;
	case 2:
		cout << endl << "\t\t\t\tSONG ADDED TO YOUR WISHLIST";
		return;
	case 3:
		cout << endl << "\t\t\t\tTHANKS FOR USING" << endl;
		return;
	}
