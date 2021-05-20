#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class AddSongInMúsica
{
private:
	string SongName, Artists, Featured, Album, Genre, Language, Year;
public:
	string getSongName();
	string getArtist();
	string getFeatured();
	string getAlbum();
	string getGenre();
	string getLanguage();
	string getYear();


	void setSongName(string SongName);
	void setArtists(string Artist);
	void setFeatured(string Featured);
	void setAlbum(string Album);
	void setGenre(string Genre);
	void setLanguage(string Language);
	void setYear(string Year);

	void AddSong();
	void RemoveSong();
	void AddSongInFile(string SongName, string Artists, string Featured, string Album, string Genre, string Language, string Year);
};

void AddSongInMúsica::setSongName(string SongName)
{
	this->SongName = SongName;
}
void AddSongInMúsica::setArtists(string Artists)
{
	this->Artists = Artists;
}
void AddSongInMúsica::setFeatured(string Featured)
{
	this->Featured = Featured;
}
void AddSongInMúsica::setAlbum(string Album)
{
	this->Album = Album;
}
void AddSongInMúsica::setGenre(string Genre)
{
	this->Genre = Genre;
}
void AddSongInMúsica::setLanguage(string Language)
{
	this->Language = Language;
}
void AddSongInMúsica::setYear(string Year)
{
	this->Year = Year;
}



string AddSongInMúsica::getSongName()
{
	return SongName;
}
string AddSongInMúsica::getArtist()
{
	return Artists;
}
string AddSongInMúsica::getFeatured()
{
	return Featured;
}
string AddSongInMúsica::getAlbum()
{
	return Album;
}
string AddSongInMúsica::getGenre()
{
	return Genre;
}
string AddSongInMúsica::getLanguage()
{
	return Language;
}
string AddSongInMúsica::getYear()
{
	return Year;
}




void AddSongInMúsica::AddSong()
{
	cout << "SONGNAME:  ";
	getline(cin >> ws, SongName);
	setSongName(SongName);
	cout << endl << "ARTISTS:  ";
	getline(cin >> ws, Artists);
	setArtists(Artists);
	cout << endl << "FEATURED:  ";
	getline(cin >> ws, Featured);
	setFeatured(Featured);
	cout << endl << "ALBUM:  ";
	getline(cin >> ws, Album);
	setAlbum(Album);
	cout << endl << "GENRE:  ";
	getline(cin >> ws, Genre);
	setGenre(Genre);
	cout << endl << "LANGUAGE:  ";
	getline(cin >> ws, Language);
	setLanguage(Language);
	cout << endl << "YEAR:  ";
	getline(cin >> ws, Year);
	cin.ignore();
	setYear(Year);

	AddSongInFile(SongName, Artists, Featured, Album, Genre, Language, Year);
}

void AddSongInMúsica::AddSongInFile(string SongName, string Artists,string Featured, string Album, string Genre, string Language, string Year)
{
	ofstream MúsicaSongData;
	MúsicaSongData.open("MúsicaSongsData.txt", std::ios_base::app);
	if (MúsicaSongData.is_open())
	{
		MúsicaSongData << '\n';
		MúsicaSongData << SongName << '|';
		MúsicaSongData << Artists << '|';
		MúsicaSongData << Featured << '|';
		MúsicaSongData << Album << '|';
		MúsicaSongData << Genre << '|';
		MúsicaSongData << Language << '|';
		MúsicaSongData << Year;
		MúsicaSongData.close();
	}
	cout << endl << "\t\t\t\tSONGS ADDED SUCCESSFULLY" << endl;
	getchar();
	getchar();
}

void AddSongInMúsica::RemoveSong()
{
	string DeleteSongName;
	ifstream Delete;
	Delete.open("MúsicaSongsData.txt");
	ofstream WriteDeleted;
	WriteDeleted.open("MúsicaSongsUData.txt");
	cout << endl << "ENTER NAME OF SONG: ";
	getline(cin >> ws, DeleteSongName);


	while (!Delete.eof())
	{
		getline(Delete, SongName, '|');
		getline(Delete, Artists, '|');
		getline(Delete, Featured, '|');
		getline(Delete, Album, '|');
		getline(Delete, Genre, '|');
		getline(Delete, Language, '|');
		getline(Delete, Year);

		if (SongName != DeleteSongName)
		{
			WriteDeleted << SongName << '|';
			WriteDeleted << Artists << '|';
			WriteDeleted << Featured << '|';
			WriteDeleted << Album << '|';
			WriteDeleted << Genre << '|';
			WriteDeleted << Language << '|';
			WriteDeleted << Year << '\n';
		}
		else
		{
			cout << endl << "SONG HAS BEEN SUCCESSFULLY DELETED" << endl;
		}
	}
	Delete.close();
	WriteDeleted.close();
	remove("MúsicaSongsData.txt");
	rename("MúsicaSongsUData.txt", "MúsicaSongsData.txt");
	getchar();
	getchar();
}
