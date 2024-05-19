#include "DictionaryWord.h"
#include "Colors.h"
#include "FileUtilities.h"

using namespace std;
using json = nlohmann::json;
using namespace Colors;

//Function Prototype Declerations
void displayMenu();
void clearScreen();
//---

int main()
{
	//Variables
	FileUtilities *fileUtil = new FileUtilities; //Create a FileUtilities object on the heap
	fileUtil->setFileName(); //Set the file name for the FileUtilities object
	vector<DictionaryWord*> dictionaryList; //Initialize a list of DictionaryWord objects
	string userInput = "";
	string userChoice = "";
	char userInputChar = ' ';
	//---

	do
	{
		displayMenu();
		cin >> userInputChar;
		userInputChar = tolower(userInputChar); //This is here for the quit case. Any numbers passed as chars will be unaffected 

		switch (userInputChar)
		{
		case '1': //Define a Word
			clearScreen();
			cout << BRIGHT_YELLOW << "Please enter a word to define: " << RESET;
			cin >> userInput;
			cout << endl;

			try
			{
				dictionaryList.push_back(new DictionaryWord(userInput)); //Create a new DictionaryWord object and adding it to the list
				clearScreen();

				dictionaryList.back()->print(); //Print the most recent object/definition in the list
			}
			catch (const string& error) //Solves the issue if the user enters a word that doesn't exist
			{
			cout << BRIGHT_RED << "Error: " << error << RESET << endl;
			}

			cout << "\nPlease hit enter to continue." << endl;
			cin.ignore(); //Double cin.ignore() one to avoid the whitespace from the previous cin>> and the other to wait for the user to hit enter
			cin.ignore();	
			clearScreen();
			break;
		case '2': //File Utility/Save All
			clearScreen();
			try
			{
				fileUtil->saveAll(dictionaryList); //Save all the words in the list to the file
			}
			catch (const string& error)
			{
				cout << BRIGHT_RED << "Error: " << error << RESET << endl;
			}
			cout << BRIGHT_YELLOW << "Attempting to save to - " << RESET << fileUtil->getFileName() << endl;
			fileUtil->openFile(); //Open the file for the user to view

			cout << "\nPlease hit enter to continue." << endl;
			cin.ignore(); //Double cin.ignore() one to avoid the whitespace from the previous cin>> and the other to wait for the user to hit enter
			cin.ignore();
			clearScreen();
			break;
		case '3': //License Info
			clearScreen();
			cout << BRIGHT_YELLOW << "This project uses Free Dictionary API found at: " << RESET << "https://dictionaryapi.dev/" << endl;
			cout << BRIGHT_YELLOW << "The licenses for the libraries used in this project can be found in the README.md file." << RESET << endl;

			cout << "\nPlease hit enter to continue." << endl;
			cin.ignore(); //Double cin.ignore() one to avoid the whitespace from the previous cin>> and the other to wait for the user to hit enter
			cin.ignore();
			clearScreen();
			break;
		case 'q':
			clearScreen();
			cout << BLINK << "Thank you for trying Kayetan's Dictionary Project!" << RESET << endl;
			break;
		default:
			cout << "Invalid input. Please try again.\n";
		}
	} while (tolower(userInputChar) != 'q');


	//Cleanup
	delete fileUtil; //Delete the FileUtilities object from the heap
	for (int i = 0; i < dictionaryList.size(); i++) //Delete all the DictionaryWord objects from the heap
	{
		delete dictionaryList[i];
	}
	//---

	return 0;
}


//Standalone EndUser Funtion Definitions -
void displayMenu() //List is subject to change and is currently a template
{
	cout << BRIGHT_YELLOW << "Dictionary Project by " << RESET << BLINK << BRIGHT_CYAN << "Kayetan" << RESET << BOLD << BRIGHT_YELLOW << ":" << RESET << endl;
	cout << BRIGHT_YELLOW << "1. " << RESET << "Define a Word" << RESET << endl;
	cout << BRIGHT_YELLOW << "2. " << RESET << "Save All to a Text File" << RESET << endl;
	cout << BRIGHT_YELLOW << "3. " << RESET << "Additional Information" << RESET << endl;
	cout << BRIGHT_YELLOW << "q. " << RESET << "Quit" << RESET << endl;
	cout << "Enter your choice: ";
	cout << endl;
}

void clearScreen() //Clear the console screen when called
{
	//https://stackoverflow.com/questions/6486289/how-can-i-clear-console
	#ifdef _WIN32 //Check if compiling on Windows
	system("cls"); //Clear the console screen on Windows
	#else
	system("clear"); //Clear the console screen on Unix-like systems
	#endif
}


//-------

/*
To Do:
3. Check if everything can be parsed from JSON such as pronounciation, mp3s, etc,etc
6. Start Creating UIs
*/


/*
	//Vital part of program
		//RAII cleanup
		curlpp::Cleanup myCleanup; //When created, makes sure necessary cleanup operations are done before curlpp is used

		//Send request and get a result.
		//Shortcut to get it in a string stream with os ostringstream

		ostringstream os;
		os << curlpp::options::Url("https://api.dictionaryapi.dev/api/v2/entries/en/hello");

		string jsonString = os.str(); //All the json data for a specific word stored here in this string

		cout << jsonString << endl;

		//Parse JSON response
		//json jsonData = json::parse(jsonString);
		json* jsonData = new json();
		*jsonData = json::parse(jsonString);

		cout << "Word: " << (*jsonData)[0]["word"].get<string>() << endl; //.get<string>() allows you to avoid the double "" issue and directly get strings from the parsed json values/data
		cout << "Meaning: " << (*jsonData)[0]["meanings"][0]["definitions"][0]["definition"].get<string>() << endl;//Dereference the json object to get necessary values
		cout << "Meaning: " << (*jsonData)[0]["meanings"][1]["definitions"][0]["definition"].get<string>() << endl;
*/