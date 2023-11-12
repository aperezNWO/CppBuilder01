///////////////////////////////////////////////////////////////////////////
// REGEX MANAGER
///////////////////////////////////////////////////////////////////////////

#include "RegExManager.h"

//
RegExManager::RegExManager()
{
	this->ReadConfigFile();
	this->GetXml();
}
//
RegExManager::~RegExManager()
{

}
//
int RegExManager::GetXml()
{
	// C:\Users\pablo.perez\dev\iis\mcsd\wwwroot\xml\cdcatalog.xml
	// Specify the relative path to the file in the subdirectory
	// std::string filePath = "subdirectory/myfile.txt";
	// string filePath      = "wwwroot/xml/cdcatalog.xml";
	// string filePath      = "cdcatalog.xml";

	string filePath        = this->configMap["XMLPATH"];

	// Open the file
	std::ifstream inputFile(filePath);

	// Check if the file is successfully opened
	if (!inputFile.is_open()) {
		std::cerr << "Error opening file: " << filePath << std::endl;
		return 1; // Return an error code
	}

	// Read and print the contents of the file
	std::string line;
	while (std::getline(inputFile, line)) {
		//std::cout << line << std::endl;
		this->xmlItems.push_back(line);
	}

	// Close the file
	inputFile.close();

	return 0;
}
//
string RegExManager::RegExEval(char* p_tagSearch, char* p_textSearch)
{
		//
		this->DeleteFile("cdCatalog_1.xml");
		//
		for (auto _xmlItem = this->xmlItems.begin(); _xmlItem != this->xmlItems.end(); ++_xmlItem) {
			  //
			  stringstream  ss;
			  //
			  ss << *_xmlItem;
			  //
			  this->SaveToFile(ss.str(),"cdCatalog_1.xml");
		}

	//
	std::string text = "<br/>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<country>UK</country>";
	//
	std::regex countryRegex(R"((<country.*>)(.*UK.*)(<\/country>))");
	//
	std::smatch countryMatch;
	//
	string textMatch = "";
	//
	if (std::regex_search(text, countryMatch, countryRegex)) {
		//
		for (auto _textMatch = countryMatch.begin(); _textMatch != countryMatch.end(); ++_textMatch) {
			  //
			  stringstream  ss;
			  //
			  ss << *_textMatch << ((_textMatch != countryMatch.end())? "¦" : "");
			  //
			  string _tempValues  = ss.str();
			  //
			  textMatch          += _tempValues;
		}
	}
	//
	return textMatch;
}
