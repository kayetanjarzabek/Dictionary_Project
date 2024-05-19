#include "DictionaryWord.h"
#include "Colors.h"

using namespace std;
using json = nlohmann::json;
using namespace Colors;

string DictionaryWord::toLowerCase(string word)
{
	string temp = "";

	if (word.length() == 0)
	{
		return ""; //Return an empty string for later checks
	}

	for (int i = 0; i < word.length(); i++)
	{
		temp.append(1, tolower(word[i])); //Append to the temp string each individual char to lowercase if needed
	}

	return temp;
}

DictionaryWord::DictionaryWord()
{
	this->word = "N/A";
}

void DictionaryWord::setOs()
{
	//curl RAII cleanup
	curlpp::Cleanup myCleanup; //When created, makes sure necessary cleanup operations are done before curlpp is used

	//Send request and get a result.
	//Shortcut to get it in a string stream with os ostringstream
	this->os << curlpp::options::Url(this->getUrl()); //Store raw json in os
}

void DictionaryWord::appendUrl()
{
	if (word.length() <= 0)
	{
		return;
	}
	else
	{
		this->url = this->url.append(getWord()); //Appends onto the string url with the word the user passes for each instance
	}
}

void DictionaryWord::setJsonData()
{
	this->jsonData = json::parse(this->os.str());
}

void DictionaryWord::parseJsonData() //This is causing the most issues in debugging. Hard to get all the necessary data
{
	//Check if the JSON data is empty
	if (this->jsonData.empty())
	{
		throw string("No data found for the word. Please try again.\n");
	}

	//Check for error case. This solves the abort() error in the end user under condition 1
	if (this->jsonData.contains("title") && this->jsonData["title"] == "No Definitions Found")
	{
		throw string("No data found for the word. Please try again.\n");
	}

	//Iterate over each entry in the JSON array
	for (const auto& entry : this->jsonData)
	{
		//Extract meanings for each entry
		for (const auto& meaning : entry["meanings"])
		{
			//Part of speech
			this->partsOfSpeech.push_back(meaning["partOfSpeech"].get<string>());

			//Definitions
			if (meaning.find("definitions") != meaning.end())
			{
				for (const auto& definition : meaning["definitions"])
				{
					this->definitions.push_back(definition["definition"].get<string>());

					//Examples which are nested under definitions in the raw JSON
					if (definition.find("example") != definition.end())
					{
						for (const auto& example : definition["example"])
						{
							this->examples.push_back(example.get<string>());
						}
					}
				}
			}

			//Synonyms and Antonyms
			if (meaning.find("synonyms") != meaning.end())
			{
				for (const auto& synonym : meaning["synonyms"])
				{
					this->synonyms.push_back(synonym.get<string>());
				}
			}

			if (meaning.find("antonyms") != meaning.end())
			{
				for (const auto& antonym : meaning["antonyms"])
				{
					this->antonyms.push_back(antonym.get<string>());
				}
			}
		}

		//Phonetic information
		for (const auto& phonetic : entry["phonetics"])
		{
			if (phonetic.contains("audio"))
			{
				this->pronounciationUrl = phonetic["audio"].get<string>();
				break; //Stop after the first pronunciation URL (if multiple are present)
			}
		}
	}
}

void DictionaryWord::print()
{
	cout << BRIGHT_YELLOW << "Word: " << RESET << this->getWord() << endl;
	
	//Definition
	cout << BOLD << BRIGHT_YELLOW << "Definition: " << RESET;
	if (!definitions.empty())
	{
		cout << this->definitions[0] << endl;
	}
	else
	{
		cout << BRIGHT_RED << "Sorry, cannot obtain the definition." << RESET << endl;
	}

	//Part of Speech
	cout << BOLD << BRIGHT_YELLOW << "Part of Speech: " << RESET;
	if (!partsOfSpeech.empty())
	{
		cout << this->partsOfSpeech[0] << endl;
	}
	else
	{
		cout << BRIGHT_RED << "Sorry, cannot obtain the part of speech." << RESET << endl;
	}

	//Synoynms
	cout << BOLD << BRIGHT_YELLOW << "Synonyms: " << RESET;
	if (!synonyms.empty())
	{
		for (int i = 0; i < synonyms.size(); i++)
		{
			cout << synonyms[i] << ", ";
		}
		cout << endl;
	}
	else
	{
		cout << BRIGHT_RED << "Sorry, cannot obtain the synonyms." << RESET << endl;
	}

	//Antonyms
	cout << BOLD << BRIGHT_YELLOW << "Antonyms: " << RESET;
	if (!antonyms.empty())
	{
		for (int i = 0; i < antonyms.size(); i++)
		{
			cout << antonyms[i] << ", ";
		}
		cout << endl;
	}
	else
	{
		cout << BRIGHT_RED << "Sorry, cannot obtain the antonyms." << RESET << endl;
	}

	//Example
	cout << BOLD << BRIGHT_YELLOW << "Example: " << RESET;
	if (!examples.empty())
	{
		cout << this->examples[0] << endl;
	}
	else
	{
		cout << BRIGHT_RED << "Sorry, cannot obtain the example." << RESET << endl;
	}
}


