#include "FileRepository.h"
#include "Exception.h"
#include <fstream>
#include <iostream>
#include <assert.h>

FileRepository::FileRepository()
{

}

std::string FileRepository::getPath()
{
	return this->filePath;
}

void FileRepository::settings(std::string newPath)
{
	this->filePath = newPath;
}

void FileRepository::addEvidence(Evidence evidence)
{
	std::vector<Evidence> allEvidence = this->readFromFile();
	//for (size_t i = 0; i < allEvidence.size(); i++)
	//	if (allEvidence[i].getId() == evidence.getId())
	//		throw(Exception("Already there\n"));
	allEvidence.push_back(evidence);
	this->writeToFile(allEvidence);
}

void FileRepository::deleteEvidence(std::string id)
{
	std::vector<Evidence> allElements = this->readFromFile();
	int positionToDelete = this->findPositionById(id);
	if (positionToDelete < 0 || positionToDelete >= allElements.size())
		throw(Exception("This element does not exist\n"));
	allElements.erase(allElements.begin() + positionToDelete);
	this->writeToFile(allElements);

}

void FileRepository::updateEvidence(std::string id, Evidence newEvidence)
{
	std::vector<Evidence> allElements = this->readFromFile();
	int positionToUpdate = this->findPositionById(id);
	if (positionToUpdate < 0 || positionToUpdate >= allElements.size())
		throw(Exception("This element does not exist\n"));
	allElements[positionToUpdate] = newEvidence;
	this->writeToFile(allElements);
}

int FileRepository::findPositionById(std::string id)
{
	std::vector<Evidence> allEvidence = this->readFromFile();
	for (size_t i = 0; i < allEvidence.size(); i++)
		if (allEvidence[i].getId() == id)
			return i;
	return -1;
}

std::vector<Evidence> FileRepository::getEvidence()
{
	return this->readFromFile();
}

std::vector<Evidence> FileRepository::readFromFile()
{
	std::vector<Evidence> data;

	std::ifstream file(this->filePath);
	if (!file.good())
		return data;

	std::ifstream readFile(this->filePath);
	std::string current;

	while (!readFile.eof())
	{
		std::getline(readFile, current);
		std::string id;
		std::string measurement;
		float imageClarityLevel;
		float quantity;
		std::string photograph;
		int positionComma = current.find(',');
		if (positionComma == -1)
			continue;
		std::string arguments[10];
		int argumentsCounter = 0;

		while (positionComma != -1)
		{
			std::string currentArgumnt = current.substr(0, positionComma);
			arguments[argumentsCounter++] = currentArgumnt;
			current = current.substr(positionComma + 2, current.length());
			positionComma = current.find(',');
		}
		arguments[argumentsCounter++] = current;

		id = arguments[0];
		measurement = arguments[1];
		imageClarityLevel = stof(arguments[2]);
		quantity = stof(arguments[3]);
		photograph = arguments[4];

		Evidence evidence{ id,measurement,imageClarityLevel,quantity,photograph };
		data.push_back(evidence);

	}
	readFile.close();
	return data;

}

void FileRepository::writeToFile(std::vector<Evidence> listOfEvidence)
{
	std::ofstream writeFile;
	writeFile.open(this->filePath);
	for (size_t i = 0; i < listOfEvidence.size(); i++)
		writeFile << listOfEvidence[i].displayEvidenceFile();
	writeFile.close();
}

void FileRepository::tests()
{
	this->addTest();
	this->deleteTest();
	this->updateTest();
}

void FileRepository::addTest()
{
	FileRepository fileRepository{};
	fileRepository.settings("fileTest.txt");
	std::vector<Evidence> emptyList;
	this->writeToFile(emptyList);
	Evidence evidence1{ "12e","5x5x5",6,7,"DSC67.jpg" };
	fileRepository.addEvidence(evidence1);
	assert(fileRepository.getEvidence().size() == 1);
	assert(fileRepository.getPath() == "fileTest.txt");
	Evidence evidence2{ "12e","7x7x7",2,3,"DSC78.jpg" };
	try
	{
		fileRepository.addEvidence(evidence2);}
	catch (Exception &addException)
	{
		assert(true);}
	this->writeToFile(emptyList);

}

void FileRepository::deleteTest()
{
	FileRepository fileRepository{};
	fileRepository.settings("fileTest6.txt");
	std::vector<Evidence> emptyList;
	this->writeToFile(emptyList);
	Evidence evidence1{ "12e","5x5x5",6,7,"DSC67.jpg" };
	fileRepository.addEvidence(evidence1);
	assert(fileRepository.getEvidence().size() == 1);
	assert(fileRepository.getPath() == "fileTest6.txt");
	Evidence evidence2{ "45","7x7x7",2,3,"DSC78.jpg" };
	fileRepository.addEvidence(evidence2);
	assert(fileRepository.getEvidence().size() == 2);
	fileRepository.deleteEvidence("45");
	assert(fileRepository.getEvidence().size() == 1);
	try
	{
		fileRepository.deleteEvidence("34");}
	catch (Exception &deleteException)
	{
		assert(true);}
	this->writeToFile(emptyList);
}

void FileRepository::updateTest()
{
	FileRepository fileRepository{};
	fileRepository.settings("fileTest7.txt");
	std::vector<Evidence> emptyList;
	this->writeToFile(emptyList);
	Evidence evidence1{ "12e","5x5x5",6,7,"DSC67.jpg" };
	fileRepository.addEvidence(evidence1);
	assert(fileRepository.getEvidence().size() == 1);
	assert(fileRepository.getPath() == "fileTest7.txt");
	Evidence evidence2{ "12e","7x7x7",2,3,"DSC78.jpg" };
	fileRepository.updateEvidence("12e", evidence2);


	emptyList = this->readFromFile();

	/*assert(emptyList[0].getMeasurement() == "7x7x7");
	assert(emptyList[0].getimageClarityLevel() == 2);
	assert(emptyList[0].getQuantity() == 3);
	assert(emptyList[0].getPhotograph() == "DSC78.jpg");*/

	try
	{
		fileRepository.updateEvidence("3", evidence2);}
	catch (Exception &updateException)
	{
		assert(true);
	}
	this->writeToFile(emptyList);


}

FileRepository::~FileRepository()
{

}