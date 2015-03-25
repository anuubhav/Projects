#include "main_window.h"
#include "data.h"
#include <string>

MainWindow::MainWindow(Data* ds_original)
{
	ds = ds_original;

	//Title
	setWindowTitle("Amazon by Beff Jezos");

	//overall layout
	overallLayout = new QHBoxLayout();

	// // Search 
	// Layout
	searchLayout = new QVBoxLayout();
	overallLayout->addLayout(searchLayout);

	// Search Terms
	searchTermDisplay = new QLabel("Search Terms");
	searchLayout->addWidget(searchTermDisplay);

	searchTermInput = new QLineEdit();
	searchLayout->addWidget(searchTermInput);


	//add search button
	searchButton = new QPushButton("Search");
	//connect(search, SIGNAL(clicked()), this, SLOT(addPokemon()));
	searchLayout->addWidget(searchButton);

	//create AND/OR buttons

	andOrLayout = new QHBoxLayout();
	overallLayout->addLayout(andOrLayout);
	andButton = new QRadioButton("and", this);
	orButton = new QRadioButton("or", this);
	overallLayout->addWidget(andButton);
	overallLayout->addWidget(orButton);



	//set overall layout
	setLayout(overallLayout);



}

MainWindow::~MainWindow()
{




}

/*void MainWindow::Search()
{
	string search = searchTermInput->text().toStdString();
	



} */