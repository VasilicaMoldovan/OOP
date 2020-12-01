#include "guiLab11.h"
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <time.h>
#include <QPushButton>
#include <QApplication>
#include <qmessagebox.h>
//#include "TaskDelegate.h"


gui::gui(TaskControllerModeA controllerRefurbishments) :controllerRefurbishments{ controllerRefurbishments }, numberOfNexts{0}, filename{""}, csvPath{""}, mode{0}
{
	this->model = new MyModel{ *controllerRefurbishments.getListOfChores() };
	this->model->reset();
	this->construct();
	this->connectSignalsAndSlots();
	this->setPictureTableView();
}

gui::~gui() 
{
}

void gui::setPictureTableView()
{
	this->view->setServant();
}

void gui::construct()
{
	QHBoxLayout *newLayout = new QHBoxLayout{ this };

	QVBoxLayout *layoutModeA = new QVBoxLayout{};
	QVBoxLayout *connectingLayout = new QVBoxLayout{};
	QVBoxLayout *layoutModeB = new QVBoxLayout{};

	//mode A
	QLabel *modeALabel = new QLabel();
	modeALabel->setText("Mode A Refurbishments");
	QFont modeAFont("Verdana", 10);
	modeALabel->setFont(modeAFont);
	layoutModeA->addWidget(modeALabel);

	//mode B
	QLabel *modeBLabel = new QLabel();
	modeBLabel->setText("Mode B Refurbishments");
	QFont modeBFont("Verdana", 10);
	modeBLabel->setFont(modeBFont);
	layoutModeB->addWidget(modeBLabel);

	this->refurbishmentData = new QListWidget{};
	this->refurbishmentData->setSelectionMode(QAbstractItemView::SingleSelection);
	this->modeBData = new QListWidget{};
	this->modeBData->setSelectionMode(QAbstractItemView::SingleSelection);

	layoutModeA->addWidget(this->refurbishmentData);
	layoutModeB->addWidget(this->modeBData);

	QVBoxLayout *left = new QVBoxLayout{};
	QVBoxLayout *right = new QVBoxLayout{};

	layoutModeA->addLayout(left);
	layoutModeB->addLayout(right);

	QHBoxLayout *modeAButtonsLayout = new QHBoxLayout{};
	QHBoxLayout *modeBButtonsLayout = new QHBoxLayout{};

	addButton = new QPushButton{ "Add new task" };
	addButton->setFont(modeAFont);
	modeAButtonsLayout->addWidget(addButton);
	removeButton = new QPushButton{ "Remove a task" };
	removeButton->setFont(modeAFont);
	modeAButtonsLayout->addWidget(removeButton);
	updateButton = new QPushButton{ "Update a task" };
	updateButton->setFont(modeAFont);
	modeAButtonsLayout->addWidget(updateButton);
	undoButton = new QPushButton{ "Undo" };
	undoButton->setFont(modeAFont);
	modeAButtonsLayout->addWidget(undoButton);
	redoButton = new QPushButton{ "Redo" };
	redoButton->setFont(modeAFont);
	modeAButtonsLayout->addWidget(redoButton);
	savePathButton = new QPushButton{ "Save path" };
	savePathButton->setFont(modeBFont);
	modeBButtonsLayout->addWidget(savePathButton);
	nextButton = new QPushButton{ "Next" };
	nextButton->setFont(modeBFont);
	modeBButtonsLayout->addWidget(nextButton);
	saveButton = new QPushButton{ "Save a task" };
	saveButton->setFont(modeBFont);
	modeBButtonsLayout->addWidget(saveButton);
	listButton = new QPushButton{ "List" };
	listButton->setFont(modeBFont);
	modeBButtonsLayout->addWidget(listButton);
	mylistButton = new QPushButton{ "Mylist" };
	mylistButton->setFont(modeBFont);
	modeBButtonsLayout->addWidget(mylistButton);
	changeMode = new QPushButton{ ">>" };
	changeMode->setFont(modeBFont);
	connectingLayout->addWidget(changeMode);

	QHBoxLayout *exitButtonLayout = new QHBoxLayout{};
	exitButton = new QPushButton{ "Exit" };
	exitButton->setFont(modeAFont);
	exitButton->setMaximumWidth(170);
	exitButtonLayout->addWidget(exitButton);

	QWidget *taskDataWidget = new QWidget{};
	QFormLayout *modeARefurbishments = new QFormLayout{taskDataWidget};
	QWidget *modeBDataWidget = new QWidget{};
	QFormLayout *modeBRefurbishments = new QFormLayout{ modeBDataWidget };
	
	QFont font{ "Verdana", 10 };

	this->title = new QLineEdit{};
	QLabel *titleLabel = new QLabel{ "&Title: " };
	titleLabel->setBuddy(this->title);
	this->type = new QLineEdit{};
	QLabel *typeLabel = new QLabel{ "&Type: " };
	typeLabel->setBuddy(this->type);
	this->date = new QLineEdit{};
	QLabel *dateLabel = new QLabel{ "&Date: " };
	dateLabel->setBuddy(this->date);
	this->numberOfRepetitions = new QLineEdit{};
	QLabel *numberOfRepetitionsLabel = new QLabel{ "&Number of repetitions: " };
	numberOfRepetitionsLabel->setBuddy(this->numberOfRepetitions);
	this->mirrorImage = new QLineEdit{};
	QLabel *mirrorImageLabel = new QLabel{ "&Vision: " };
	mirrorImageLabel->setBuddy(this->mirrorImage);
	this->fileName = new QLineEdit{};
	QLabel *pathToFileLabel = new QLabel{ "&File path: " };
	pathToFileLabel->setBuddy(this->fileName);
	this->csvHtmlPath = new QLineEdit{};
	QLabel *pathToCSVHtmlLabel = new QLabel{ "&Html or CSV path: " };
	pathToCSVHtmlLabel->setBuddy(this->csvHtmlPath);

	titleLabel->setFont(font);
	typeLabel->setFont(font);
	dateLabel->setFont(font);
	numberOfRepetitionsLabel->setFont(font);
	mirrorImageLabel->setFont(font);
	pathToFileLabel->setFont(font);
	pathToCSVHtmlLabel->setFont(font);
	this->typeB = new QLineEdit{};
	QLabel *newType = new QLabel{ "&Type: " };
	newType->setBuddy(this->typeB);
	this->timesPerformed = new QLineEdit{};
	QLabel *timesPerformedLabel = new QLabel{ "&Times performed: " };
	timesPerformedLabel->setBuddy(this->timesPerformed);
	newType->setFont(font);
	timesPerformedLabel->setFont(font);
	
	modeARefurbishments->addRow(titleLabel, this->title);
	modeARefurbishments->addRow(typeLabel, this->type);
	modeARefurbishments->addRow(dateLabel, this->date);
	modeARefurbishments->addRow(numberOfRepetitionsLabel, this->numberOfRepetitions);
	modeARefurbishments->addRow(mirrorImageLabel, this->mirrorImage);
	modeBRefurbishments->addRow(newType, this->typeB);
	modeBRefurbishments->addRow(timesPerformedLabel, this->timesPerformed);
	modeBRefurbishments->addRow(pathToFileLabel, this->fileName);
	modeBRefurbishments->addRow(pathToCSVHtmlLabel, this->csvHtmlPath);

	left->addWidget(taskDataWidget);
	right->addWidget(modeBDataWidget);

	left->addLayout(modeARefurbishments);
	left->addLayout(modeAButtonsLayout);
	left->addLayout(exitButtonLayout);
	right->addLayout(modeBRefurbishments);
	right->addLayout(modeBButtonsLayout);
	
	layoutModeA->addLayout(left);
	
	newLayout->addLayout(layoutModeA);
	newLayout->addLayout(connectingLayout);
	newLayout->addLayout(layoutModeB);
	
}

void gui::addTask(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage)
{
	if (mode == 0) {
		try
		{
			this->controllerRefurbishments.addNewRefurbishment(Refurbishment{ title, type, date, numberOfRepetitions, mirrorImage });
		}
		catch (RefurbishmentException& error)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", error.getErrorMessage().c_str());
			return;
		}
		this->controllerRefurbishments.writeRepoToFile();
		emit taskUpdatedSignal();
	}
}

void gui::deleteTaskSlot(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage)
{
	if (mode == 0) {
		try
		{
			this->controllerRefurbishments.deleteRefurbishment(Refurbishment{ title, type, date, numberOfRepetitions, mirrorImage });
		}
		catch (RefurbishmentException& error)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", error.getErrorMessage().c_str());
			return;
		}
		this->controllerRefurbishments.writeRepoToFile();
		this->populateTasksList();
		emit taskUpdatedSignal();
	}
}

void gui::updateTask(const std::string& title, const std::string& type, const std::string& date, const int& numberOfRepetitions, const std::string& mirrorImage)
{
	if (mode == 0) {
		try
		{
			this->controllerRefurbishments.updateExistingRefurbishment(Refurbishment{ title, type, date, numberOfRepetitions, mirrorImage });
		}
		catch (RefurbishmentException& error)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", error.getErrorMessage().c_str());
			return;
		}
		this->controllerRefurbishments.writeRepoToFile();
		emit taskUpdatedSignal();
	}
}

void gui::changeModeSlot()
{
	mode++;
	mode = mode % 2;
}

void gui::nextTask()
{
	if (mode == 1) {
		if (this->modeBData->count() > 0)
			this->modeBData->clear();

		Refurbishment task = this->controllerRefurbishments.seeNextChore(numberOfNexts);
		QString taskInList = QString::fromStdString(task.toString());
		QFont font{ "Verdana", 10 };
		QListWidgetItem *newTask = new QListWidgetItem{ taskInList };
		newTask->setFont(font);
		this->modeBData->addItem(newTask);

		this->modeBData->setCurrentRow(0);

		this->numberOfNexts++;
		if (this->numberOfNexts == this->controllerRefurbishments.getNumberOfRefurbishments())
			this->numberOfNexts = 0;
	}
}

void gui::saveTask(const std::string& title)
{
	if (mode == 1) {
		this->controllerRefurbishments.saveCurrentChore(title);
		this->controllerRefurbishments.writeToCSVHtmlFile(csvPath);
		this->model->rowInserted();
	}
}

void gui::listTasks(const std::string& type, const int& timesPerformed)
{
	if (mode == 1) {
		if (this->modeBData->count() > 0)
			this->modeBData->clear();
		int n = 0;
		std::vector<Refurbishment> auxiliaryVector = this->controllerRefurbishments.listAllChoresOfTypeAndProperty(type, timesPerformed, n);

		for (auto task : auxiliaryVector)
		{
			QString taskInList = QString::fromStdString(task.toString());
			QFont font{ "Verdana", 11 };
			QListWidgetItem *newTask = new QListWidgetItem{ taskInList };
			newTask->setFont(font);
			this->modeBData->addItem(newTask);
		}

		this->refurbishmentData->setCurrentRow(0);
	}
}

void gui::mylistTasks()
{
	if (mode == 1)
	{
		model->reset();
		model = new MyModel{ *this->controllerRefurbishments.getListOfChores() };
		view = new ServantView{ &*model };
		view->show();
		
		this->controllerRefurbishments.openFile();
	}
}

void gui::savePathTask(const std::string& file, const std::string& csvFile)
{
	this->filename = file;
	this->csvPath = csvFile;
	if (file != "")
		this->controllerRefurbishments.setRepositoryType("txt");
	char aux[200];
	strcpy(aux, csvFile.c_str());
	if (aux[strlen(aux) - 1] == 'l')
		this->controllerRefurbishments.setRepositoryType("html");
	else
		this->controllerRefurbishments.setRepositoryType("csv");
	this->controllerRefurbishments.savePath(csvFile);
	this->controllerRefurbishments.readRepositoryFromFile(file);

	this->populateTasksList();
}

void gui::undoRefurbishment()
{
	if (mode == 0)
	{
		try {
			this->controllerRefurbishments.undoTask("A");
		}
		catch (RefurbishmentException& error)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", error.getErrorMessage().c_str());
			return;
		}
		emit taskUpdatedSignal();
	}
	else
	{
		try {
			this->controllerRefurbishments.undoTask("B");
		}
		catch (RefurbishmentException& error)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", error.getErrorMessage().c_str());
			return;
		}
		this->controllerRefurbishments.writeToCSVHtmlFile(csvPath);
		this->model->reset();
	}
}

void gui::redoRefurbishment()
{
	if (mode == 0)
	{
		try {
			this->controllerRefurbishments.redoTask("A");
		}
		catch (RefurbishmentException& error)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", error.getErrorMessage().c_str());
			return;
		}
		emit taskUpdatedSignal();
	}
	else
	{
		try {
			this->controllerRefurbishments.redoTask("B");
		}
		catch (RefurbishmentException& error)
		{
			QMessageBox messageBox;
			messageBox.critical(0, "Error", error.getErrorMessage().c_str());
			return;
		}
		this->controllerRefurbishments.writeToCSVHtmlFile(csvPath);
		this->model->reset();
	}
}

int gui::getSelectedIndex()
{
	if (this->refurbishmentData->count() == 0)
		return -1;

	// get selected index
	QModelIndexList index = this->refurbishmentData->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		this->title->clear();
		this->type->clear();
		this->date->clear();
		this->numberOfRepetitions->clear();
		this->mirrorImage->clear();
		return -1;
	}

	int newIndex = index.at(0).row();
	return newIndex;
}

void gui::connectSignalsAndSlots()
{

	QShortcut *undoShortcut= new QShortcut(QKeySequence("Ctrl+Z"), this);
	QShortcut *redoShortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);

	QObject::connect(undoShortcut, SIGNAL(activated()), this, SLOT(undoRefurbishment()));
	QObject::connect(redoShortcut, SIGNAL(activated()), this, SLOT(redoRefurbishment()));


	// when the vector of genes is updated - re-populate the list
	//QObject::connect(this, SIGNAL(genesUpdatedSignal()), this, SLOT(populateGenesList()));
	QObject::connect(this, &gui::taskUpdatedSignal, this, &gui::populateTasksList);

	// add a connection: function listItemChanged() will be called when an item in the list is selected
	QObject::connect(this->refurbishmentData, &QListWidget::itemSelectionChanged, this, [this]() {this->listRefurbishmentChanged(); });

	// add button connections
	QObject::connect(this->savePathButton, &QPushButton::clicked, this, &gui::savePathHandler);
	QObject::connect(this->addButton, &QPushButton::clicked, this, &gui::addButtonHandler);
	QObject::connect(this->removeButton, &QPushButton::clicked, this, &gui::deleteButtonHandler);
	QObject::connect(this->updateButton, &QPushButton::clicked, this, &gui::updateButtonHandler);
	QObject::connect(this->exitButton, &QPushButton::clicked, this, &QCoreApplication::quit);
	QObject::connect(this->changeMode, &QPushButton::clicked, this, &gui::changeModeButtonHandler);
	QObject::connect(this->nextButton, &QPushButton::clicked, this, &gui::nextButtonHandler);
	QObject::connect(this->saveButton, &QPushButton::clicked, this, &gui::saveButtonHandler);
	QObject::connect(this->listButton, &QPushButton::clicked, this, &gui::listButtonHandler);
	QObject::connect(this->mylistButton, &QPushButton::clicked, this, &gui::mylistButtonHandler);
	QObject::connect(this->undoButton, &QPushButton::clicked, this, &gui::undoHandler);
	QObject::connect(this->redoButton, &QPushButton::clicked, this, &gui::redoHandler);

	// connect the addGene signal to the addGene slot, which adds a gene to vector
	QObject::connect(this, SIGNAL(savePathSignal(const std::string&, const std::string&)), 
		this, SLOT(savePathTask(const std::string&, const std::string&)));

	QObject::connect(this, SIGNAL(addSignal(const std::string&, const std::string&, const std::string&, const int&, const std::string&)),
		this, SLOT(addTask(const std::string&, const std::string&, const std::string&, const int&, const std::string&)));
	
	QObject::connect(this, SIGNAL(deleteSignal(const std::string&, const std::string&, const std::string&, const int&, const std::string&)),
		this, SLOT(deleteTaskSlot(const std::string&, const std::string&, const std::string&, const int&, const std::string&)));

	QObject::connect(this, SIGNAL(updateSignal(const std::string&, const std::string&, const std::string&, const int&, const std::string&)),
		this, SLOT(updateTask(const std::string&, const std::string&, const std::string&, const int&, const std::string&)));

	QObject::connect(this, SIGNAL(changeModeSignal()), this, SLOT(changeModeSlot()));

	QObject::connect(this, SIGNAL(nextSignal()),this, SLOT(nextTask()));

	QObject::connect(this, SIGNAL(saveSignal(const std::string&)), this, SLOT(saveTask(const std::string&)));

	QObject::connect(this, SIGNAL(listSignal(const std::string&, const int&)), this, SLOT(listTasks(const std::string&, const int&)));

	QObject::connect(this, SIGNAL(mylistSignal()), this, SLOT(mylistTasks()));

	QObject::connect(this, SIGNAL(undoSignal()), this, SLOT(undoRefurbishment()));

	QObject::connect(this, SIGNAL(redoSignal()), this, SLOT(redoRefurbishment()));
}

void gui::listRefurbishmentChanged()
{
	int index = this->getSelectedIndex();
	if (index == -1)
		return;

	// get the song at the selected index
	if (index >= this->controllerRefurbishments.getNumberOfRefurbishments())
		return;
	Refurbishment task = this->controllerRefurbishments.getRefurbishmentFromPosition(index);

	this->title->setText(QString::fromStdString(task.getTitle()));
	this->type->setText(QString::fromStdString(task.getType()));
	this->date->setText(QString::fromStdString(task.getDate()));
	this->numberOfRepetitions->setText(QString::fromStdString(std::to_string(task.getNumberOfRepetitions())));
	this->mirrorImage->setText(QString::fromStdString(task.getMirrorImage()));
}

void gui::addButtonHandler()
{
	// read data from the textboxes and add the new gene
	QString taskTitle = this->title->text();
	QString taskType = this->type->text();
	QString taskDate = this->date->text();
	QString taskRepetitions = this->numberOfRepetitions->text();
	QString taskMirrorImage = this->mirrorImage->text();

	// emit the addGene signal
	emit addSignal(taskTitle.toStdString(), taskType.toStdString(), taskDate.toStdString(), atoi(taskRepetitions.toStdString().c_str()), taskMirrorImage.toStdString());
}

void gui::updateButtonHandler()
{// read data from the textboxes and add the new gene
	QString taskTitle = this->title->text();
	QString taskType = this->type->text();
	QString taskDate = this->date->text();
	QString taskRepetitions = this->numberOfRepetitions->text();
	QString taskMirrorImage = this->mirrorImage->text();

	// emit the addGene signal
	emit updateSignal(taskTitle.toStdString(), taskType.toStdString(), taskDate.toStdString(), atoi(taskRepetitions.toStdString().c_str()), taskMirrorImage.toStdString());
}

void gui::changeModeButtonHandler()
{
	emit changeModeSignal();
}

void gui::nextButtonHandler()
{
	emit nextSignal();
}

void gui::saveButtonHandler()
{
	// get the selected index and delete the gene
	int index = this->getSelectedIndex();

	if (index < 0 || index >= this->controllerRefurbishments.getNumberOfRefurbishments())
		return;

	Refurbishment task = this->controllerRefurbishments.getRefurbishmentFromPosition(index);

	// emit the signal: the genes were updated
	//emit deleteSignal(taskTitle.toStdString(), taskType.toStdString(), taskDate.toStdString(), atoi(taskRepetitions.toStdString().c_str()), taskMirrorImage.toStdString());
	emit saveSignal(task.getTitle());
}

void gui::listButtonHandler()
{
	QString taskType = this->typeB->text();
	QString taskTimesPerformed = this->timesPerformed->text();
	// emit the addGene signal
	emit listSignal(taskType.toStdString(), atoi(taskTimesPerformed.toStdString().c_str()));
}

void gui::mylistButtonHandler()
{
	emit mylistSignal();
}

void gui::savePathHandler()
{
	QString file = this->fileName->text();
	QString path = this->csvHtmlPath->text();

	emit savePathSignal(file.toStdString(), path.toStdString());
}

void gui::undoHandler()
{
	emit undoSignal();
}

void gui::redoHandler()
{
	emit redoSignal();
}

void gui::deleteButtonHandler()
{
	// get the selected index and delete the gene
	int index = this->getSelectedIndex();

	if (index < 0 || index >= this->controllerRefurbishments.getNumberOfRefurbishments())
		return;

	Refurbishment task = this->controllerRefurbishments.getRefurbishmentFromPosition(index);
	
	//this->controllerRefurbishments.deleteFromPosition(index);
	//emit taskUpdatedSignal();
	emit deleteSignal(task.getTitle(), task.getType(), task.getDate(), task.getNumberOfRepetitions(), task.getMirrorImage());
	
}


void gui::populateTasksList()
{
	//this->controllerRefurbishments.readRepositoryFromFile(this->filename);
	if (this->refurbishmentData->count() > 0)
		this->refurbishmentData->clear();

	for (auto task : this->controllerRefurbishments.getAllRefurbishments())
	{
		QString taskInList = QString::fromStdString(task.toString());
		QFont font{ "Verdana", 9 };
		QListWidgetItem *newTask = new QListWidgetItem{ taskInList };
		newTask->setFont(font);
		this->refurbishmentData->addItem(newTask);
	}

	if (this->controllerRefurbishments.getNumberOfRefurbishments() > 0)
		this->refurbishmentData->setCurrentRow(0);
}
