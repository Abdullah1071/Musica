#include <iostream> 
#include <fstream> 
#include <string>

using namespace std;


class MúsicaLyricsSearch
{
private:
	bool SearchCheck = false;
	string SongName[2];
public:
	void PatternFound(string Text, string pattern);
	string SearchPattern();
};

string MúsicaLyricsSearch::SearchPattern()
{
	ifstream OpenFile;
	ofstream SongNotFound;
	string lyrics;
	int length;
	cout << endl << "SEARCH SONG BY LYRICS: ";
	getline(cin >> ws, lyrics);
	length = lyrics.length();

	for (int i = 0; i < length; i++)
	{
		if (lyrics[i] >= 65 && lyrics[i] <= 92)
		{
			lyrics[i] = lyrics[i] + 32;
		}
	}

	OpenFile.open("MúsicaLyrics.txt");
	if (OpenFile.is_open())
	{
		while (getline(OpenFile, SongName[0],'|'))
		{
			getline(OpenFile, SongName[1], '|');
			PatternFound(SongName[1], lyrics);
			if (SearchCheck == true)
			{
				break;
			}
			else
			{
				continue;
			}
		}
		OpenFile.close();
	}
	else
	{
		cout << endl << "FAILED TO OPEN THE FILE";
	}
	if (SearchCheck == true)
	{
		return SongName[0];
	}
	else 
	{
		string notfound = "SONG NOT FOUND";
		return notfound;
		
	}
}

void MúsicaLyricsSearch::PatternFound(string Text, string pattern)
{
	size_t Found = Text.find(pattern, 0);
	while (Found != string::npos)
	{
		Found = Text.find(pattern, Found + 1);
		SearchCheck = true;
	}
}
