#include "QuestionAndAnswer.h"
#include "qmessagebox.h"
bool cmp(Question a, Question b)
{
	return a.getAns() > b.getAns();

}
void QuestionAndAnswer::afisare()
{
	ui.listWidget->clear();
	std::vector<Question>v = repo.returnQuestions();
	sort(v.begin(), v.end(), cmp);
	for (auto i : v)
	{
		std::string print = std::to_string(i.getId()) + ", " + i.getText() + " " + i.getAsker() + ", " + std::to_string(i.getAns());
		new QListWidgetItem(print.c_str(), ui.listWidget);
	}

}
void QuestionAndAnswer::print(int qui)
{
	ui.listWidget_2->clear();

	std::vector<Answer>answ;
	answ = repo.giveAnswer(qui);

	for (auto i : answ)
	{
		std::string print = std::to_string(i.getId()) + ", " + i.getText() + ", " + i.getUser() + ", " + std::to_string(i.getVotes());
		new QListWidgetItem(print.c_str(), ui.listWidget_2);
	}

}

void QuestionAndAnswer::handleAdd()
{
	std::string text;
	int id;
	id = repo.returnQuestions().size();
	//int ok = 1;
	text = ui.lineEdit->text().toStdString();
	if (text == "")
	{
		QMessageBox q;
		q.critical(0, "ERROR", "Please ask a question");
		//ok = 0;
	}
	else
	{
		id++;
		repo.addQuestion(id, text, user.getName(),0);
		this->afisare();
	}
}

void QuestionAndAnswer::handleSelect(QListWidgetItem* h)
{
	int nr = ui.listWidget->currentIndex().row();
	std::vector<Question>v = repo.returnQuestions();
	sort(v.begin(), v.end(), cmp);
	int qui = v[nr].getId();

	std::vector<Answer>answ;
	answ= repo.giveAnswer(qui);

	this->print(qui);
	
}
void QuestionAndAnswer::handleAnswer()
{
	std::string text;
	int nr = ui.listWidget->currentIndex().row();
	std::vector<Question>v = repo.returnQuestions();
	int quid = v[nr].getId();
	int id = repo.returnAnswer().size();
	text = ui.lineEdit->text().toStdString();
	if (text == "")
	{
		QMessageBox q2;
		q2.critical(0, "ERROR", "Please add answer");
		
	}
	else
	{
		id++;
		repo.addAnswer(id, quid, user.getName(),text, 0);
		repo.updateQuestion(quid);
		this->print(quid);
		this->afisare();
		
	}
}
/*void QuestionAndAnswer::handleUpvote()
{
	int nr = ui.listWidget_2->currentIndex().row();
	std::vector<Answer>a = repo.returnAnswer();
	sort(a.begin(), a.end(), cmp);
	repo.updateAnswer(a[nr].getId(), 1);
	
}*/
QuestionAndAnswer::QuestionAndAnswer(Repo& repos, User u, QWidget *parent)
	: QMainWindow(parent),repo(repos),user(u)
{
	ui.setupUi(this);
	this->afisare();

	connect(ui.addQbutton, SIGNAL(clicked()), this, SLOT(handleAdd()));
	connect(ui.listWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(handleSelect(QListWidgetItem*)));
	connect(ui.addAbutton, SIGNAL(clicked()), this, SLOT(handleAnswer()));
	//connect(ui.upVoteButton, SIGNAL(clicked()), this, SLOT(handleUpvote()));
}
