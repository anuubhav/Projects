#include "user.h"
#include <cmath>
using namespace std;

User::User() : name_("unknown"), age_(0), balance_(0.0), type_(1)
{

}
User::User(std::string name, int age, double balance, int type) : 
  name_(name), age_(age), balance_(balance), type_(type)
{

}

User::~User()
{

}


int User::getAge() const
{
  return age_;
}

std::string User::getName() const
{
  return name_;
}

double User::getBalance() const
{
  return balance_;
}

void User::deductAmount(double amt)
{
  balance_ -= amt;
}

void User::dump(std::ostream& os)
{
  os << name_ << " " << age_ << " " << balance_ << " " << type_ << endl;
}

int User::hashPassword(std::string passwordInput)
{

	long long password = 0;
	unsigned int digitHolder[4];
	/*for (int i=0; i< 4; i++)
	{
		digitHolder[i] = 0;

	}*/
	long long iterator =1;

	for (int i=passwordInput.size()-1; i >=0; i--)
	{	
		long long temp = passwordInput[i];
		long long tempLong = temp* iterator;
		password += tempLong;
		iterator *= 128;

	}

	//array of values
	for (int i=0; i< 4; i++)
	{
		digitHolder[3-i] = password % 65521;
		password = password / 65521;
	}

	int finalPassword = (45912 * digitHolder[0] + 35511 * digitHolder[1] + 65169 * digitHolder[2] + 4625 * digitHolder[3]) % 65521;
	return finalPassword;
	

}

void User::setPassword(int password)
{	
	encryptedPassword = password;


}

int User::getPassword()
{

	return encryptedPassword;
}

void User::setAge(int age)
{

	age_ = age;

}

void User::setBalance(double balance)
{
	balance_ = balance;

}