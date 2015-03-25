#include "main_window.h"
#include "msort.h"
#include "data.h"
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iostream>

struct ProdStrComp {
    bool operator()(Product& lhs, Product& rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs.getName() < rhs.getName(); 
    }
  };

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
	
	//set overall layout
	setLayout(overallLayout);
	overallLayout->addStretch();

	//Alphabetical && Rating Sorting
	sortLayout = new QHBoxLayout();
	alphaButton = new QPushButton("Sort Alphabetically");
	reviewButton = new QPushButton("Sort by Review");
	sortLayout->addWidget(alphaButton);
	sortLayout->addWidget(reviewButton);
	overallLayout->addLayout(sortLayout);
	connect(alphaButton, SIGNAL(clicked()), this, SLOT(alphaSort()));
	connect(reviewButton, SIGNAL(clicked()), this, SLOT(reviewSort()));
	//adding the list after the sort buttons
	overallLayout->addWidget(searchListWidget);
}

MainWindow::~MainWindow()
{




}

void MainWindow::AndOrSearch()
{
	vector<string> hits_string;
	hits.clear();

	string searchText = searchTermInput->text().toStdString();
	stringstream str(searchText);
	string temp;
	searchListWidget->clear();
	while (str >> temp)
	{
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

void MainWindow::alphaSort()
{
	ProdStrComp comp1;
	mergeSort(hits, comp1);


}

void MainWindow::reviewSort()
{



}