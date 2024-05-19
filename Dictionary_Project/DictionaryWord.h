#pragma once
#include <string>
#include <nlohmann/json.hpp> //JSON library, nlohmann/json
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp>
#include <cctype> //For toupper() and tolower()
#include <sstream>
#include <iostream>
#include <vector>
#include <cstdlib> //For system()
#include <windows.h>  //Colored Output

using namespace std;
using json = nlohmann::json;

//cout << getUrl() << endl
//cout << this->os.str() << endl;

class DictionaryWord
{
private:
	string word = "N/A";
	vector<string> definitions;
	vector<string> partsOfSpeech;
	vector<string> examples;
	vector<string> synonyms;
	vector<string> antonyms;
	string pronounciationUrl = "N/A";
	string url = "https://api.dictionaryapi.dev/api/v2/entries/en/"; //49 length
	json jsonData;
	ostringstream os; //Figure out the default/empty to store
public:
	//Destructor that destroys and then calls nullptr for json before destroying itself
	static string toLowerCase(string word);
	DictionaryWord(); //Default Constructor
	DictionaryWord(string w) : word(w) { appendUrl(); setOs(); setJsonData(); parseJsonData(); }; //Overloaded Constructor 1
	void setWord(string w) { this->word = w; }
	void setOs();
	void setJsonData();
	void appendUrl();
	void parseJsonData();
	void print();
	string getWord() const { return this->word; }
	vector<string> getDefinition() const { return this->definitions; }
	vector<string> getPartsOfSpeech() const { return this->partsOfSpeech; }
	vector<string> getExample() const { return this->examples; }
	vector<string> getSynonyms() const { return this->synonyms; }
	vector<string> getAntonyms() const { return this->antonyms; }
	string getPronounciationUrl() const { return this->pronounciationUrl; }
	string getUrl() const { return this->url; }
	json getJsonObj() const { return this->jsonData; }


};