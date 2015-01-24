#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;
struct Item
{
    Item(int v, Item* n) {
        val = v;
        next = n;
    }
    int val;
    Item* next;
};
void readLists(char *filename, Item*& head1, Item*& head2);
Item* helper(Item* head1, Item* head2, Item* current);
Item* concatenate(Item* head1, Item* head2);  // returns head pointer to new list
void removeEvens(Item*& head);
double avg_helper(Item* head, double average, int counter);
double findAverage(Item* head);


void readLists(char* filename, Item*& head1, Item*& head2)
{
    //create a string to store values from text file
    string string_vals;
    //open the filename that the user inputs
    ifstream in_file;
    in_file.open(filename);

    //read one line from text file,
    getline(in_file, string_vals);

    //stringstream created to read in the values
    //each data element is value for a node
    stringstream str;
    str << string_vals;

    //temp pointers to traverse lists 1 & 2
    Item* temp1;
    Item* temp2;


    //while there are items left in the stringstream
    while (str)

    {

        int val = 0;
        //inserting value into node
        str >> val;
        

        //while the head is not the tail

        if (head1 == NULL)
        {
            head1 = new Item(val,NULL);
            temp1 = head1;
        }

        else
        {
            //create the next item
            //move through the list
            if (str) 
            {temp1->next = new Item(val, NULL);} 
             temp1 = temp1->next;

        }
               
    }
    //read in from text file
    getline(in_file, string_vals);

    //stringstream created to read in the values
    //each data element is value for a node
    stringstream str_two;
    str_two << string_vals;

    while (str_two)
    {
        int val =0;
        //insert value into node
        str_two >> val;
        
        //while head is not hte tail
        if (head2 == NULL)
        {
            head2= new Item(val, NULL);
            temp2= head2;
        }
        else 
        {
            //create the next item
            //move through the list
            if (str_two) 
            {temp2->next = new Item(val, NULL);}   //create the next item
            temp2 = temp2->next;
        } 

        
    }
    
}



Item* helper(Item* head1, Item* head2, Item* current)
{
    
    //if head1 is an empty list
    if (head1->next == NULL) {
        current = head2;
    }
    //if head2 is an empty list
    if (head2->next == NULL) {
        current = head1;
    }
    //connect the two lists
    if (current->next == NULL)
    {
        current->next = head2;
        return head1;
    }
    //run through the whole list
    helper(head1, head2, current->next);


}

Item* concatenate(Item* head1, Item* head2)
{
    //checking if the first list is empty
    if (head1->next == NULL)
    	//return the second list
    	{return head2;}
    //checking if the second list is empty
    if (head2->next == NULL)
    	//return the first list
    	{return head1;} 
    return helper(head1, head2, head1);





}
void removeEvens(Item*& head)
{
    Item* temp;
    if (head->next == NULL) 
        {return;}
    //if head is even
    if (head->val%2 ==0)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    //delete even values
    if (head->next->val%2 ==0)
        {   temp = head->next;
            head->next = head->next->next;
            delete temp;
        }

removeEvens(head->next);



}


 double avg_helper(Item* head, double average, int counter)
{

    if (head== NULL)
    {
        average = average/counter;
        return average;
    }
    //# of items increased by 1
    counter++;
    //running total increased
    average=average + head->val;

    avg_helper(head->next, average, counter);

   


}

 double findAverage(Item* head)
 {


    avg_helper(head, 0.0, 0);



 }
void printList(ostream& ofile, Item* head)
{
    if(head == NULL)
        ofile << endl;
    else {
        ofile << head->val << " ";
        printList(ofile, head->next);
    }
}


int main(int argc, char* argv[])
{
    //initial heads
    Item* head_one = NULL;
    Item* head_two = NULL;
    readLists(argv[1], head_one, head_two);
    ofstream out_file;
    out_file.open(argv[2]);
    head_one = concatenate(head_one,head_two);
    printList(out_file, head_one);
    removeEvens(head_one);
    printList(out_file, head_one);
    double final_average = findAverage(head_one);
    printList(out_file, head_one);
    out_file << final_average << endl;
    
    while (head_one)
    {
        Item* temp = head_one;
        head_one = head_one->next;
        delete temp;


    }
    
    
    delete head_one;
    //delete head_two;

}