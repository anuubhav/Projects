#include "main_window.h"
#include "msort.h"
#include "data.h"
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>

struct ProdStrComp {
    bool operator()(Product* lhs, Product* rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs->getName() < rhs->getName(); 
    }
  };

struct ProdReviewComp{
	bool operator()(Product* lhs, Product* rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs->getAvgReview() > rhs->getAvgReview();
    }
};
struct ReviewDateComp{
	bool operator()(Review* lhs, Review* rhs) 
    { // Uses string's built in operator< 
      // to do lexicographic (alphabetical) comparison
      return lhs->getDate() < rhs->getDate();
	}

};

MainWindow::MainWindow(Data* ds_original)
{
	ds = ds_original;

	//Title
	setWindowTitle("Amazon by Make Jetzman");

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
	


	//Alphabetical && Rating Sorting
	sortLayout = new QHBoxLayout();
	sortFiller = new QHBoxLayout();
	sortButtons = new QHBoxLayout();

	//Sort Buttons && Add Review
	alphaButton = new QPushButton("Sort A->Z");
	reviewButton = new QPushButton("Sort by Avg Review");
	showReviewButton = new QPushButton("Show Reviews");
	addReviewButton = new QPushButton("Add Review");

	//Sort Layout and connections
	sortLayout->addLayout(sortButtons);
	sortLayout->addLayout(sortFiller);
	sortButtons->addWidget(alphaButton);
	sortButtons->addWidget(reviewButton);
	sortFiller->addWidget(showReviewButton);
	sortFiller->addWidget(addReviewButton);
	overallLayout->addLayout(sortLayout);
	connect(alphaButton, SIGNAL(clicked()), this, SLOT(alphaSort()));
	connect(reviewButton, SIGNAL(clicked()), this, SLOT(reviewSort()));
	

	// // USERS AND REVIEWS
	secondLayout = new QHBoxLayout();
	reviewListWidget = new QListWidget();


	//users combo box
	usersBox = new QComboBox();
	set<User*>::iterator it;
	allUsers = ds->getUsers();
	
	for (it = allUsers.begin(); it!= allUsers.end(); ++it)
	{
		string name = (*it)->getName();
		usersBox->addItem(QString::fromStdString(name));


	}
	
	//showing the reviews
	connect(showReviewButton, SIGNAL(clicked()), this, SLOT(showReviews()));
	connect(addReviewButton, SIGNAL(clicked()), this, SLOT(addReview()));
	

	//adding the list after the sort buttons
	secondLayout->addWidget(searchListWidget);

	//adding reviews after the list
	secondLayout->addWidget(reviewListWidget);

	overallLayout->addLayout(secondLayout);


	//all the buttons
	thirdLayout = new QHBoxLayout();
	addToCartButton = new QPushButton("Add to Cart");
	viewCartButton = new QPushButton("View Cart");
	thirdLayout->addWidget(usersBox);
	thirdLayout->addWidget(addToCartButton);
	thirdLayout->addWidget(viewCartButton);
	overallLayout->addLayout(thirdLayout);
	viewCartDisplay = new QLabel("Cart");
	viewCartLayout = new QWidget();
	viewCartList = new QListWidget();
	checkoutButton = new QPushButton("Checkout");
	deleteItemButton = new QPushButton("Delete Item");
	FirstCartLayout = new QVBoxLayout();
	SecondCartLayout = new QHBoxLayout();


	//map viewcart && add to cart
	connect(addToCartButton, SIGNAL(clicked()), this, SLOT(addToCart()));
	connect(viewCartButton, SIGNAL(clicked()), this, SLOT(viewCart()));
	

	//map buttons within viewcart
	connect(checkoutButton, SIGNAL(clicked()), this, SLOT(checkout()));
	connect(deleteItemButton, SIGNAL(clicked()), this, SLOT(removeFromCart()));



	//add review
	addReviewDisplay = new QLabel("Add a Review");
	addReviewLayout = new QWidget();
	rating = new QLabel("Rating");
	ratingInput = new QLineEdit();
	date_label = new QLabel("Date: YYYY-MM-DD");
	date_input = new QLineEdit();
	//dateEdit = new QDateEdit();
	firstReviewLayout = new QFormLayout();
	review_label = new QLabel("Review Text");
	reviewText = new QTextEdit();
	submitReviewButton = new QPushButton("Submit Review");
	connect(submitReviewButton, SIGNAL(clicked()), this, SLOT(submitReview()));
	


	//save and quit
	endLayout = new QHBoxLayout();
	saveForm = new QFormLayout();
	saveButton = new QPushButton("Save Database");
	quitButton = new QPushButton("Quit Program");
	saveLayout = new QWidget();
	databaseLabel = new QLabel("Enter Output File");
	file_input = new QLineEdit();
	submitFileButton = new QPushButton("Save");

	endLayout->addWidget(saveButton);
	endLayout->addWidget(quitButton);

	overallLayout->addLayout(endLayout);

	connect(saveButton, SIGNAL(clicked()), this, SLOT(saveDatabase()));
	connect(submitFileButton, SIGNAL(clicked()), this, SLOT(exportDatabase()));
	connect(quitButton, SIGNAL(clicked()), this, SLOT(quitProgram()));



	//set overall layout
	setLayout(overallLayout);
	overallLayout->addStretch();
}

MainWindow::~MainWindow()
{






}

void MainWindow::AndOrSearch()
{
	vector<string> hits_string;
	hits.clear();

	string searchText = searchTermInput->text().toStdString();
	searchText = convToLower(searchText);
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
	searchListWidget->clear();
	vector<Product*>::iterator it;
	ProdStrComp comp1;
	mergeSort(hits, comp1);

		for (it = hits.begin(); it!= hits.end(); ++it)
		{
			string info = (*it)->displayString();
			searchListWidget->addItem(QString::fromStdString(info));

		}


}

void MainWindow::reviewSort()
{

	searchListWidget->clear();
	vector<Product*>::iterator it;
	ProdReviewComp comp1;
	mergeSort(hits, comp1);

		for (it = hits.begin(); it!= hits.end(); ++it)
		{
			string info = (*it)->displayString();
			searchListWidget->addItem(QString::fromStdString(info));

		}


}

void MainWindow::addToCart()
{

	//current item
	if (QListWidgetItem* item =  searchListWidget->currentItem())
	{
		string text = item->text().toStdString();
		
		QString name = usersBox->currentText();
		string user = name.toStdString();
		
		


		istringstream iss(text);
		std::string title;
		getline(iss, title);

		Product* itemToAdd = ds->getProdObj(title);
		vector<Product*> hits;
		hits.push_back(itemToAdd);

		ds->addToCart(user, hits[0]);
	}

	

}

void MainWindow::viewCart()
{
	viewCartList->clear();
	QString name = usersBox->currentText();
	string user = name.toStdString();

	vector<Product*>cart = ds->getCart(user);
	vector<Product*>::iterator it;
	for (it = cart.begin(); it!= cart.end(); ++it)
		{
			
			string info = (*it)->displayString();
			viewCartList->addItem(QString::fromStdString(info));

		}
	

	//layout of the widget
	FirstCartLayout->addWidget(viewCartDisplay);
	FirstCartLayout->addWidget(viewCartList);
	SecondCartLayout->addWidget(checkoutButton);
	SecondCartLayout->addWidget(deleteItemButton);
	FirstCartLayout->addLayout(SecondCartLayout);
	viewCartLayout->setLayout(FirstCartLayout);
	viewCartLayout->show();
}

void MainWindow::checkout()
{

	QString name = usersBox->currentText();
	string username = name.toStdString();

	vector<Product*>cart = ds->getCart(username);
	User* user = ds->getUser(username);
	for (unsigned int i=0; i<cart.size(); i++)
	{
		 double price = cart[i]->getPrice();
          if (user->getBalance() > price && cart[i]->getQty() > 0)
          {
            user->deductAmount(price);
            cart[i]->subtractQty(1);
           ds->deleteFromCart(user, cart[i]);
           viewCartList->takeItem(viewCartList->currentRow());
          }

          else
          {
            ++i;
          }
	}
}

void MainWindow::removeFromCart()
{

	//getting current item
	if (QListWidgetItem* item =  viewCartList->currentItem())
	{
		string text = item->text().toStdString();

		//getting the username
		QString name = usersBox->currentText();
		string username = name.toStdString();

		//getting user object
		vector<Product*>cart = ds->getCart(username);
		User* user = ds->getUser(username);
		




		istringstream iss(text);
		std::string title;
		getline(iss, title);

		//Product* itemToRemove = ds->getProdObj(title);
		int index = 0;

		for (unsigned int i=0; i<cart.size(); i++)
		{
			if (cart[i]->getName() == title)
			{
				index = i;

			}

		}

		ds->deleteFromCart(user, cart[index]);
		viewCartList->takeItem(index);         
	}
}


void MainWindow::showReviews()
{

if (QListWidgetItem* item =  searchListWidget->currentItem())
{
	ReviewDateComp comp1;
	reviewListWidget->clear();

	string text = item->text().toStdString();
	istringstream iss(text);
	std::string title;
	getline(iss, title);
	Product* itemToGetReviews = ds->getProdObj(title);
	vector<Review*> reviews = itemToGetReviews->getReviews();

	//sorts the reveiews by date
	mergeSort(reviews, comp1);

	//adding to the list
	vector<Review*>::iterator it;
	for (it = reviews.begin(); it!= reviews.end(); ++it)
			{
				
				string info = (*it)->getInfo();
				reviewListWidget->addItem(QString::fromStdString(info));

			}


}

}

void MainWindow::addReview()
{
	//FIX SO REVIEW ONLY ADDED IF ITEM SELECTED

//gets item to add review for
if (QListWidgetItem* item =  searchListWidget->currentItem())
{
	string text = item->text().toStdString();

	//layout of the widget
	firstReviewLayout->addWidget(addReviewDisplay);
	firstReviewLayout->addWidget(rating);
	firstReviewLayout->addWidget(ratingInput);
	firstReviewLayout->addWidget(date_label);
	firstReviewLayout->addWidget(date_input);
	firstReviewLayout->addWidget(review_label);
	firstReviewLayout->addWidget(reviewText);
	firstReviewLayout->addWidget(submitReviewButton);



	addReviewLayout->setLayout(firstReviewLayout);
	addReviewLayout->show();
}


	
}

void MainWindow::submitReview()
{

	//gets item to add review for
	QListWidgetItem* item =  searchListWidget->currentItem();
	string text = item->text().toStdString();


	istringstream iss(text);
	std::string title;
	getline(iss, title);

	Product* itemToAddReviewFor = ds->getProdObj(title);

	//getting date as a string
	
	string date_string = date_input->text().toStdString();



	string rating = ratingInput->text().toStdString();
	int rating_i;
	istringstream (rating ) >> rating_i;
	string reviewText_ = reviewText->toPlainText().toStdString();
	string name = itemToAddReviewFor->getName();

	//creating the user's new review
	Review* r= new Review(name, rating_i, date_string, reviewText_);
	r->prodName = name;
	r->rating = rating_i;
	r->date = date_string;
	r->reviewText = reviewText_; 

	//adding the user's new review
	 itemToAddReviewFor->addReview(r);

	addReviewLayout->close();
	//(prodName, rating_i, date_string, reviewText);
}

void MainWindow::saveDatabase()
{

	saveForm->addWidget(databaseLabel);
	saveForm->addWidget(file_input);
	saveForm->addWidget(submitFileButton);


	saveLayout->setLayout(saveForm);
	saveLayout->show();



}

void MainWindow::exportDatabase()
{
	//where the database will be
	string file = file_input->text().toStdString();
	ofstream ofile(file.c_str());
	ds->dump(ofile);
	ofile.close();
	saveLayout->close();


}


void MainWindow::quitProgram()
{
exit(0);

}