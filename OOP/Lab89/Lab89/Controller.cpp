#include "Controller.h"
#include "Exception.h"
#include "FileRepository.h"
#include "MemoryRepository.h"
#include <assert.h>
#include <iostream>

Controller::Controller(Repository *repository,
	Repository *userRepository,
	EvidenceValidator validator) :
	repository{ repository }, userRepository{ userRepository },
	validator{ validator } {}

std::string Controller::addEvidenceToMyList(Evidence evidence)
{
	try
	{
		this->userRepository->addEvidence(evidence);
	}
	catch (Exception &addException)
	{
		return addException.get_message();}
	return "yes";
}

std::string Controller::addEvidenceToRepository(const std::string &id, const std::string &measurement,
	const float &imageClarityLevel, const float &quantity,
	const std::string &photograph)
{
	Evidence evidence{ id,measurement,imageClarityLevel,quantity,photograph };
	try
	{
		this->validator.validate(evidence);
	}
	catch (Exception &invalidInput)
	{
		return invalidInput.get_message();}
	try
	{
		this->repository->addEvidence(evidence);
	}
	catch (Exception &add)
	{
		return add.get_message();}
	return "yes";

}

std::string Controller::deleteEvidenceFromRepository(std::string id)
{
	try
	{
		this->repository->deleteEvidence(id);
	}
	catch (Exception &deleteProblem)
	{
		return deleteProblem.get_message();}
	return "yes";

}

std::string Controller::updateEvidence(const std::string &id, const std::string &measurement,
	const float &imageClarityLevel, const float &quantity,
	const std::string &photograph)
{
	Evidence newEvidence{ id,measurement,imageClarityLevel,quantity,photograph };
	try
	{
		this->validator.validate(newEvidence);
	}
	catch (Exception &invalidInput)
	{
		return invalidInput.get_message();}
	try
	{
		this->repository->updateEvidence(id, newEvidence);
	}
	catch (Exception &update)
	{
		return update.get_message();}
	return "yes";

}

std::vector<Evidence> Controller::getAllEvidence()
{
	return this->repository->getEvidence();
}
std::vector<Evidence> Controller::getMyListOfEvidence()
{
	return this->userRepository->getEvidence();
}

void Controller::setFileName(std::string newName)
{
	this->repository->settings(newName);
}

void Controller::tests()
{
	this->testAdd();
	this->testDelete();
	this->testUpdate();
}

void Controller::testAdd()
{
	EvidenceValidator validator{};
	MemoryRepository repository{};
	MemoryRepository userRepository{};
	Controller controller{ &repository,&userRepository,validator };
	controller.setFileName("test.txt");
	Evidence evidence1{ "12e", "5x5x5", 9, 8, "DSC78.jpg" };
	std::string message = controller.addEvidenceToRepository("12e", "5x5x5", 9, 8, "DSC78.jpg");
	assert(message == "yes");
	std::string message1 = controller.addEvidenceToRepository("12e", "5x5x5", 9, 8, "DSC78.jpg");
	assert(message1 == "Already there\n");

	try
	{
		controller.addEvidenceToRepository("", "5x5x5", -9, -8, "DSC78.jpg");}
	catch (EvidenceException &inputException)
	{
		assert(true);
	}

	std::string message4 = controller.addEvidenceToMyList(evidence1);
	assert(message4 == "yes");
	std::string message5 = controller.addEvidenceToMyList(evidence1);
	assert(message5 == "Already there\n");



}

void Controller::testDelete()
{
	EvidenceValidator validator{};
	MemoryRepository repository{};
	MemoryRepository userRepository{};
	Controller controller{ &repository,&userRepository,validator };
	std::string message = controller.addEvidenceToRepository("12e", "5x5x5", 9, 8, "DSC78.jpg");
	assert(message == "yes");
	std::string message1 = controller.addEvidenceToRepository("134r", "5x5x5", 9, 8, "DSC78.jpg");
	assert(message1 == "yes");
	assert(controller.getAllEvidence().size() == 2);
	std::string message2 = controller.deleteEvidenceFromRepository("12e");
	assert(message2 == "yes");
	assert(controller.getAllEvidence().size() == 1);
	std::string message4 = controller.deleteEvidenceFromRepository("78");
	assert(message4 == "This element does not exist\n");


}

void Controller::testUpdate()
{
	EvidenceValidator validator{};
	MemoryRepository repository{};
	MemoryRepository userRepository{};
	Controller controller{ &repository,&userRepository,validator };
	std::string message = controller.addEvidenceToRepository("12e", "5x5x5", 9, 8, "DSC78.jpg");
	assert(message == "yes");
	assert(controller.getAllEvidence().size() == 1);
	std::string message1 = controller.updateEvidence("12e", "5x9x5", 9, 8, "DSC78.jpg");
	assert(message1 == "yes");
	std::string message4 = controller.updateEvidence("78", "7x7x7", 7, 4, "DSC89.jpg");
	assert(message4 == "This element does not exist\n");
	try
	{
		controller.updateEvidence("12e", "", -7, -5, "");}
	catch (EvidenceException &inputException)
	{
		assert(true);
	}

}