#include "Lab10.h"
#include "domain.h"
#include "validator.h"
#include "repo.h"
#include "controller.h"
#include "guiLab11.h"
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	string choice;
	ifstream file("choose.txt");

	file >> choice;

	if ( choice == "fileRepository" )
	{
		TaskRepository *baseRepository = new FileRepository();
		TaskRepository *fileRepository = new FileRepository();
		RepositoryValidator *repoValidator = new RepositoryValidator();
		TaskControllerModeA mainController(baseRepository, fileRepository, repoValidator);

		gui newGui{ mainController };
		newGui.show();

		/*baseRepository->readFromFile("input.txt");
		MyModel model{ *baseRepository };
		ServantView *view = new ServantView{ &model };
		view->show();*/


		return a.exec();
	}
	else
	{
		TaskRepository *baseRepository = new InMemoryRepo();
		TaskRepository *fileRepository = new InMemoryRepo();
		RepositoryValidator *repoValidator = new RepositoryValidator();
		TaskControllerModeA mainController(baseRepository, fileRepository, repoValidator);

		gui newGui{ mainController };
		newGui.show();

		return a.exec();
		}
	file.close();
}
