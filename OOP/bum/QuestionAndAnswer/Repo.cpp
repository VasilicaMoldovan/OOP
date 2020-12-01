#include "Repo.h"
#include<fstream>
void Repo::readData()
{
	std::string name;
	std::ifstream fin("u.txt");
	while (fin >> name)
	{
		this->addUser(name);
	}

	std::string rand, text, asker;
	int id, ans;
	std::ifstream gin("q.txt");
	getline(gin, rand, '#');
	int count = 0;
	count++;
	while (rand != "")
	{
		if (count == 1)
			id = stoi(rand);
		if (count == 2)
			text = rand;
		if (count == 3)
			asker = rand;
		if (count == 4)
		{
			count = 0;
			ans = stoi(rand);
			this->addQuestion(id, text, asker, ans);
			getline(gin, rand);
		}

		getline(gin, rand, '#');
		count++;
	}

	std::string text2, user, r;
	int id2, qid, votes;
	int cnt = 0;
	std::ifstream hin("a.txt");
	getline(hin, r, '#');
	cnt++;
	while (r != "")
	{
		if (cnt == 1)
			id2 = stoi(r);
		if (cnt == 2)
			qid = stoi(r);
		if (cnt == 3)
			user = r;
		if (cnt == 4)
			text2 = r;
		if (cnt == 5)
		{
			cnt = 0;
			votes = stoi(r);
			this->addAnswer(id2, qid, user, text2, votes);
			getline(hin, r);
		}

		getline(hin, r, '#');
		cnt++;
		
	}



}
void Repo::saveData()
{
	std::ofstream gout("q.txt");
	for (auto i : questions)
		gout << i.getId() << '#' << i.getText() << '#' << i.getAsker()<<'#'<<i.getAns() << '#' << "\n";

	std::ofstream hout("a.txt");
	for (auto i : answers)
		hout << i.getId() << '#' << i.getQid() << '#' << i.getUser() << '#' << i.getText() << '#' << i.getVotes() << '#' << "\n";
}
Repo::Repo()
{
	this->readData();
}


Repo::~Repo()
{
	this->saveData();
}
