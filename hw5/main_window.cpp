#include "main_window.h"
#include "data.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

MainWindow::MainWindow(Data* ds_original)
{
	ds = ds_original;

	//Title
	setWindowTitle("Amazon by Rark Medekopp");

	//overall layout
	overallLayout = new QVBoxLayout();

	// // Search 
	// Layout
	searchLayout = new QHBoxLayout();
	overallLayout->addLayout(searchLayout);

	// Search Terms
	searchTermDisplay = new QLabel("Search Terms");
	searchLayout->addWidget(searchTermDisplay);

	searchTermInput = new QLineEdit();
	searchLayout->addWidget(searchTermInput);
	searchLayout->addStretch();


	//add search button
	searchButton = new QPushButton("Search");
	connect(searchButton, SIGNAL(clicked()), this, SLOT(AndOrSearch()));
	searchLayout->addWidget(searchButton);

	//create AND/OR buttons

	//andOrLayout = new QHBoxLayout();
	//overallLayout->addLayout(andOrLayout);
	andButton = new QRadioButton("AND", this);
	orButton = new QRadioButton("OR", this);
	searchLayout->addWidget(andButton);
	searchLayout->addWidget(orButton);


	//showing the searches
	searchListWidget = new QListWidget();
	overallLayout->addWidget(searchListWidget);
	//set overall layout
	setLayout(overallLayout);
	overallLayout->addStretch();


}

MainWindow::~MainWindow()
{




}

void MainWindow::AndOrSearch()
{
	vector<Product*> hits;
	vector<string> hits_string;
	string searchText = searchTermInput->text().toStdString();
	stringstream str(searchText);
	string temp;
	while (str >> temp)
	{
		
		
		cout << "temp is: " << temp << endl;
		hits_string.push_back(temp);

	}
	
	if (andButton->isChecked())
	{
		vector<Product*>::iterator it;
		searchText = convToLower(searchText);
		//hits_string.push_back(searchText);
		hits = ds->search(hits_string,0);
		for (it = hits.begin(); it!= hits.end(); ++it)
		{
			
			string info = (*it)->displayString();
			searchListWidget->addItem(QString::fromStdString(info));

		}
	}	

	else if (orButton->isChecked())
	{
		vector<Product*>::iterator it;
		searchText = convToLower(searchText);
		//hits_string.push_back(searchText);
		hits = ds->search(hits_string, 1);

		for (it = hits.begin(); it!= hits.end(); ++it)
		{
			string info = (*it)->displayString();
			searchListWidget->addItem(QString::fromStdString(info));

		}

		
	}
} 