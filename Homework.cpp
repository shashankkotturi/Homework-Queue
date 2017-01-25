#include "Homework.h"

/*struct Assignment 
{
	char  course[12];  	// CHE 102, MATH 117, etc.
	int	  assnNum; 		// Assignment Number
	int   dueMonth;		// Month due (1-12)
	int   dueDay;		// Day due (1-31)
	char* description;	// Assignment description
};
 
struct HomeworkQueue 
{
     const Assignment* assgn;
     HomeworkQueue* next;
};*/

bool isEarlier(const Assignment* a1, const Assignment* a2) {
	
	if (a1 -> dueMonth < a2 -> dueMonth)
		return true;
	else if (a1 -> dueMonth > a2 -> dueMonth)
		return false;
	else
	{
		if (a1 -> dueDay < a2 -> dueDay)
			return true;
		else if (a1 -> dueDay >= a2 -> dueDay)
			return false;
	}
	
}


bool enqueue(const Assignment* assignment, HomeworkQueue*& queue) {
	
	// Checking for the right length
	int length = 0;
	for (int i = 0; assignment -> course[i] != 0; i++)
		length++;
	
	// If length is more than 11 characters...there's no space for null character
	if (length < 1 || length > 11)
		return false;
	
	HomeworkQueue *input = new HomeworkQueue;
	input -> assgn = assignment;
	input -> next = 0;
	
	// If assignment days and months are invalid
	if (assignment -> dueDay < 1 || assignment -> dueDay > 31)
		return false;
	if (assignment -> dueMonth < 1 || assignment -> dueMonth > 12)
		return false;
	
	// When list is empty
	// Changing the original pointer to point to the input as it is the first element
	if (queue == 0)
	{
		queue = input;
		return true;
	}
	
	// Inserting at the front of the list
	// Changing the original pointer to point to the input as it is the first element
	if (isEarlier (assignment, queue -> assgn))
	{
		input -> next = queue;
		queue = input;
		return true;
	}
	
	// Inserting in the middle or at the end of the list
	// Using a temp pointer as you don't want to change the original head pointer
	HomeworkQueue *temp = queue;
	
	while ((temp -> next != 0) && (!isEarlier (assignment, temp -> next -> assgn)))
	{
		temp = temp -> next;
	}
	
	// Inserting in the list
	input -> next = temp -> next;
	temp -> next = input;
	return true;
	
}

const Assignment* dequeue(HomeworkQueue*& queue) {
	// When there's no elements in the list
	if (queue == 0)
		return 0;
	
	HomeworkQueue * temp = queue;
	
	// When there's only one element in the list
	if (queue -> next == 0)
	{
		queue = 0;
		return temp -> assgn;
	}
	
	// Deleting an item from the list
	queue = queue -> next;
	return temp -> assgn;
}