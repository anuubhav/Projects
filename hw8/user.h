#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

/**
 * Implements User functionality and information storage
 *  You should not need to derive anything from User at this time
 */
class User{
 public:
  User();
  User(std::string name, int age, double balance, int type);
  virtual ~User();

  int getAge() const;
  double getBalance() const;
  std::string getName() const;
  void deductAmount(double amt);
  virtual void dump(std::ostream& os);
  int hashPassword(std::string passwordInput);
  void setPassword(int password);
  int getPassword();
  void setAge(int age);
  void setBalance(double balance);
  void setName(std::string name);
 private:
  std::string name_;
  int age_;
  double balance_;
  int type_;
  int encryptedPassword;
};
#endif
