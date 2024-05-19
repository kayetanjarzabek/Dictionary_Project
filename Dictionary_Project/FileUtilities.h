#pragma once
#include "Colors.h"
#include "DictionaryWord.h"
#include <chrono>
#include <ctime> 
#include <fstream> //fileIO
#include <cstdlib> // For system()

using namespace std;
using namespace chrono;
using namespace Colors;

class FileUtilities
{
private:
	string fileName = "DictionaryWords.txt"; //This is the default text file that will be used to store the words the user inputs
	string currentDate = "";
public:
	FileUtilities(); //Default Constructor
	void setFileName(); //No parameters to pass as the file name will be determined by the user's time upon being called
	string getFileName() const { return this->fileName; }
	void saveAll(const vector<DictionaryWord*>& dictionaryList); //Save all the words in the list to the file
	void openFile(); //Open the file directly for the user to view
	void setCurrentDate(); //Set the current date for the user to view	
	string getCurrentDate() const { return this->currentDate; }
};