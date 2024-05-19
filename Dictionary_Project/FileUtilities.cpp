#include "FileUtilities.h"

FileUtilities::FileUtilities()
{
	//Default Constructor
}

void FileUtilities::setFileName()
{
    //https://stackoverflow.com/questions/997946/how-to-get-current-time-and-date-in-c
    
    //Get the start time
    auto start = system_clock::now();
    //Get the end time
    auto end = system_clock::now();
    //Calculate elapsed time
    duration<double> elapsed_seconds = end - start;
    // Convert end time to time_t
    time_t end_time = chrono::system_clock::to_time_t(end);
    //Convert time_t to tm struct using localtime_s
    tm local_tm;
    localtime_s(&local_tm, &end_time);
    //Create a buffer and use strftime to format the tm struct to a readable format without spaces
    char buffer[20]; // Adjust size according to the desired format
    strftime(buffer, sizeof(buffer), "%Y%m%d%H%M%S", &local_tm);


    //cout << "finished computation at " << buffer << std::endl;
	//cout << "DictionaryWords" << string(buffer) << ".txt\n"; //Prints "DictionaryWordsYYYYMMDDHHMMSS.txt\n
	this->fileName = "DictionaryWords" + string(buffer) + ".txt"; //"DictionaryWordsYYYYMMDDHHMMSS.txt\n
}

void FileUtilities::saveAll(const vector<DictionaryWord*>& dictionaryList)
{
	setFileName(); //Set the file name for the upcoming ofstream object
	ofstream outputFile(this->fileName); //Open the file for output

	//Check if the outputFile Object even exists
    if(!outputFile)
    {
		throw string("Error: Cannot open the file for output.\n");
        return; //Check later to see if this properly exits the conditional and function
    }

	outputFile << "Dictionary Project by Kayetan" << endl;
	setCurrentDate();
	outputFile << this->currentDate << endl;
	outputFile << "Total words saved: " << dictionaryList.size() << endl;
	outputFile << "----------------------------------------" << endl;

	//Iterate over all the dictionary objects within the list provided from the endUser
    for (int i = 0; i < dictionaryList.size(); i++) 
	{ //Reimplement code from DictionaryWord::print() to output to the file
		outputFile << "Word: " << dictionaryList[i]->getWord() << endl;

		//Definition
		outputFile << "Definition: ";
		if (!dictionaryList[i]->getDefinition().empty())
		{
			outputFile << dictionaryList[i]->getDefinition()[0] << endl;
		}
		else
		{
			outputFile << "Sorry, cannot obtain the definition." << endl;
		}

		//Part of Speech
		outputFile << "Part of Speech: ";
		if (!dictionaryList[i]->getPartsOfSpeech().empty())
		{
			outputFile << dictionaryList[i]->getPartsOfSpeech()[0] << endl;
		}
		else
		{
			outputFile << "Sorry, cannot obtain the part of speech." << endl;
		}

		//Synonyms
		outputFile << "Synonyms: ";
		if (!dictionaryList[i]->getSynonyms().empty())
		{
			for (int j = 0; j < dictionaryList[i]->getSynonyms().size(); j++)
			{
				outputFile << dictionaryList[i]->getSynonyms()[j] << ", ";
			}
			outputFile << endl;
		}
		else
		{
			outputFile << "Sorry, cannot obtain the synonyms." << endl;
		}

		//Antonyms
		outputFile << "Antonyms: ";
		if (!dictionaryList[i]->getAntonyms().empty())
		{
			for (int j = 0; j < dictionaryList[i]->getAntonyms().size(); j++)
			{
				outputFile << dictionaryList[i]->getAntonyms()[j] << ", ";
			}
			outputFile << endl;
		}
		else
		{
			outputFile << "Sorry, cannot obtain the antonyms." << endl;
		}

		//Example
		outputFile << "Example: ";
		if (!dictionaryList[i]->getExample().empty())
		{
			outputFile << dictionaryList[i]->getExample()[0] << endl;
		}
		else
		{
			outputFile << "Sorry, cannot obtain the example." << endl;
		}

		outputFile << " ----------------------------------------" << endl;
    }
}

void FileUtilities::openFile()
{
	//Open the file for the user to view
	system(("notepad " + this->fileName).c_str());
}

void FileUtilities::setCurrentDate()
{
	//Get the current time
	time_t now = time(nullptr);
	//Convert the current time to a local time struct
	struct tm time_info;
	localtime_s(&time_info, &now);
	//Format the current time as a string
	char buffer[80];
	strftime(buffer, 80, "%Y-%m-%d", &time_info);
	string current_date(buffer);
	
	this->currentDate = current_date;
}
