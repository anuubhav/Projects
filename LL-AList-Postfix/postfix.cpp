#include <iostream>
#include "stackdbl.h"
#include "llistdbl.h"
//#include <stdlib.h>
#include <sstream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


double calculate(string& expr, bool& success)
{
success = true;
StackDbl* stack = new StackDbl();	
stringstream strm; 
strm.str(expr);
//what the stringstream prints to is character
string character;
double number =0;
//math is any operator: + - / *
string math = "";
double result =0;
double conclusion;
//second_success is just to make sure that all test conditions are met
bool second_success = true;


while (second_success )
{
	while (strm >> character)
	{
		
			//if the first character of the string is a digit
			if (isdigit(character[0]))
			{

				number = atof(character.c_str());
				
				stack->push(number);
			}

			
			else // operator
			{
				
				
				if (character == "+")
				{
					double a = 0;
					double b =0;
					if (stack->empty())
						{
							success = false;
							second_success = false;
						}
					else 
						{
						a= stack->top();
						stack->pop();
						}
					if (stack->empty())
						{
							success = false;
							second_success = false;
						}						
					else
						{ 
						b = stack->top();
						stack->pop();
						result = b + a;
						stack->push(result);
						}
				}


				else if (character == "-")
				{
					double a = 0;
					double b =0;
					if (stack->empty())
						{
							success = false;
							second_success = false;
							
						}
					else
						{
						 a = stack->top();
						stack->pop();
						}
					if (stack->empty())
						{
							success = false;
							second_success = false;
							
						}
					else{
						 b = stack->top();
						stack->pop();
						result = b - a;
						stack->push(result);
						}
				}

				else if (character == "*")
				{
					double a = 0;
					double b =0;
					if (stack->empty())
						{
							success = false;
							second_success = false;
							
						}
					else{
						 a = stack->top();
						stack->pop();
						}		
					if (stack->empty())
						{
							success = false;
							second_success = false;
							
						}
					
					else{
						 b = stack->top();
						stack->pop();
						result = b * a;
						stack->push(result);
						}	
				}


				else if (character == "/")
				{
					double a = 0;
					double b =0;
					if (stack->empty())
						{
							success = false;
							second_success = false;
							
						}

					else {
						 a = stack->top();
						stack->pop();
						}
					if (stack->empty())
						{
							success = false;
							second_success = false;						
						}
					else{
						 b = stack->top();
						stack->pop();
						result = b / a;
						stack->push(result);
						}
				}

				else 
					{success = false;
						second_success = false;
					}
			}


		
	}
	second_success= false;

}
if (success != false && !stack->empty() )
{
	conclusion= stack->top();
	stack->pop();
	if (!stack->empty())
		{success = false;}

	else {
		return conclusion;}
}





return 0;




}

int main(int argc, char* argv[])
{
	ifstream in_file;
	ofstream out_file;
	in_file.open(argv[1]);
	out_file.open(argv[2]);
	
	bool success = true;
	string calculation;
	double result = 0;
	while (getline(in_file, calculation))
	{
		result = calculate(calculation, success);
		if (success == true) out_file << result  << endl;
		else {out_file << "invalid" << endl;}
		success = true;
	}

	calculation.clear();

	return 0;

}
