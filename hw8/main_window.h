#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QRadioButton>
#include <QListWidget>
#include <QGroupBox>
#include <QString>
#include <QDateEdit>
#include <QDate>
#include <QFormLayout>
#include <string>
#include <vector>
#include "data.h"

class MainWindow : public QWidget
{
	Q_OBJECT
public:
	MainWindow(Data* ds_original);
	~MainWindow();


private slots:
	void AndOrSearch();
	void alphaSort();
	void reviewSort();
	void addToCart();
	void viewCart();
	void checkout();
	void removeFromCart();
	void showReviews();
	void addReview();
	void submitReview();
	void saveDatabase();
	void exportDatabase();
	void quitProgram();
	void showProgram();
	void addUser();
	void login();
private:

	vector<Product*> hits;
	set<User*> allUsers;
	//stores all of the data
  	Data* ds;

  	//login screen
  	QVBoxLayout* loginLayout;
  	QLabel* usernameLabel;
  	QLabel* passwordLabel;
  	QLineEdit* usernameInput;
  	QLineEdit* passwordInput;
  	QHBoxLayout* loginButtonLayout;
  	QPushButton* quitLoginButton;
  	QPushButton* loginButton;
  	QPushButton* newUserButton;
  	QMessageBox* nonUniqueUser;
  	QMessageBox* wrongPassword;
	//main layout
	QWidget* programLayout;
	QVBoxLayout* overallLayout;

	//search
	QHBoxLayout* searchLayout;
	QLabel* searchTermDisplay;
	QLineEdit* searchTermInput;
	QPushButton* searchButton;
	QRadioButton* andButton;
	QRadioButton* orButton;
	QHBoxLayout* andOrLayout;
	QListWidget* searchListWidget;
	
	//sorting
	QHBoxLayout* sortLayout;
	QHBoxLayout* sortFiller;
	QHBoxLayout* sortButtons;
	QPushButton* alphaButton;
	QPushButton* showReviewButton;
	QPushButton* reviewButton;
	
	//display result layouts
	QHBoxLayout* secondLayout;
	QListWidget* reviewListWidget;
	//all the users
	QComboBox* usersBox;

	//third layout, with all the buttons
	QHBoxLayout* thirdLayout;
	QPushButton* addToCartButton;
	QPushButton* viewCartButton;

	//reveiws
	QPushButton* addReviewButton;

	//viewcart
	QLabel* viewCartDisplay;
	QWidget* viewCartLayout;
	QListWidget* viewCartList;
	QPushButton* checkoutButton;
	QPushButton* deleteItemButton;
	QVBoxLayout* FirstCartLayout;
	QHBoxLayout* SecondCartLayout;

	//addReview features
	QLabel* addReviewDisplay;
	QWidget* addReviewLayout;
	QLabel* rating;
	QLineEdit* ratingInput;
	QLabel* date_label;
	//QDateEdit* dateEdit;
	QLineEdit* date_input;
	QFormLayout* firstReviewLayout;
	QLabel* review_label;
	QTextEdit* reviewText;
	QPushButton* submitReviewButton;

	//save and quit
	QHBoxLayout* endLayout; //to store the buttons
	QFormLayout* saveForm;
	QPushButton* saveButton;
	QPushButton* quitButton;
	QWidget* saveLayout;
	QLabel* databaseLabel;
	QLineEdit* file_input;
	QPushButton* submitFileButton;
	QLabel* saveWarning;
};	