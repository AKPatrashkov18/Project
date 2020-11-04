#include <iostream>
#include <string>
using namespace std;
void checkForWrongInput(double variable) //Makes you enter a new option until you have entered a correct one
{
	while (cin.fail())
	{
		cout << "Enter a number, please!" << endl;
		cin.clear();
		cin.ignore(256, '\n');
		cin >> variable;
	}
}

void differenceOfSets(int numOfElements_A, int numOfElements_B, string setA[], string setB[]) {//This function find the diffrence of the given sets
	bool flag = true;
	cout << "A - B = ";
	for (int i = 0; i < numOfElements_A; i++)
	{
		flag = true;
		for (int j = 0; j < numOfElements_B; j++)
		{
			if (setA[i] == setB[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << setA[i] << " ";
		}
	}
	cout << endl;
	cout << "B - A = ";
	for (int i = 0; i < numOfElements_B; i++)
	{
		flag = true;
		for (int j = 0; j < numOfElements_A; j++)
		{
			if (setB[i] == setA[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << setB[i] << " ";
		}
	}
	cout << endl << endl;
}

void intersectionOfSets(int numOfElements_A, int numOfElements_B, string setA[], string setB[]) {//This function show the intersection of the given sets
	bool flag = true;
	bool flag1 = true;
	cout << "\nIntersection of A and B = ";
	for (int i = 0; i < numOfElements_A ; i++)
	{
		flag = true;
		for (int j = 0; j < numOfElements_B; j++)
		{
			if (setA[i] == setB[j])
			{
				flag = false;
				flag1 = false;
				break;
			}
		}
		if (!flag)
		{
			cout << setA[i]<<" ";
		}
	}
	if (flag1)
	{
		cout << "There are not any equal elements";
	}
	cout << endl;
}

void findSubsets(int numOfElements_A, int numOfElements_B, string setA[], string setB[]) {//This function find subsets

	int counter=0;
	if (numOfElements_A > numOfElements_B)
	{
		for (int i = 0; i < numOfElements_B; i++)
		{
			for (int j = 0; j < numOfElements_A; j++)
			{
				if (setB[i]==setA[j])
				{
					counter++;
					break;
				}
			}
		}
		if (counter == numOfElements_B)
		{
			cout << "\nSet B is subset of A";
		}
		else
		{
			cout << "\nThere are not any subsets";
		}
	}
	else
	{
		for (int i = 0; i < numOfElements_A; i++)
		{
			for (int j = 0; j < numOfElements_B; j++)
			{
				if (setA[i] == setB[j])
				{
					counter++;
				}
			}
		}
		if (counter == numOfElements_A)
		{
			cout << "\nSet A is subset of B";
		}
		else
		{
			cout << "\nThere are not any subsets";
		}
	}
}

void unionOfSets(int numOfElements_A,int numOfElements_B ,string setA[],string setB[]) {//This function finds the union of the sets

	bool flag;
	cout << endl << endl;
	cout << "A+B = ";
	for (int i = 0; i < numOfElements_A; i++)
	{
		cout << setA[i] << " ";
	}

	for (int i = 0; i < numOfElements_B; i++)
	{
		flag = true;
		for (int j = 0; j < numOfElements_A; j++)
		{
			if (setB[i] == setA[j])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			cout << setB[i] << " ";
		}
	}
}

void createSet(string setA[], string setB[]) {//This function create sets
	system("cls");
	int numOfElements_A, numOfElements_B;
	cout << "Enter the size of set A: ";
	cin >> numOfElements_A;
	cout << "Enter the elements of the set A: ";
	for (int i = 0; i < numOfElements_A; i++)
	{
		cin >> setA[i];
	}
	cout << endl;
	cout << "Enter the size of set B: "; cin >> numOfElements_B;
	cout << "Enter the elements of the set B: ";
	for (int i = 0; i < numOfElements_B; i++)
	{
		cin >> setB[i];
	}
	unionOfSets(numOfElements_A, numOfElements_B, setA, setB);
	findSubsets(numOfElements_A, numOfElements_B, setA, setB);
	intersectionOfSets(numOfElements_A, numOfElements_B, setA, setB);
	differenceOfSets(numOfElements_A, numOfElements_B, setA, setB);
}

void moreAboutSets() { //This function shows more about sets
	cout << "Set are any collection of objects (elements), which may be mathematical (e.g., numbers, functions) or not (e.g. letters,symbols)." << endl;
	cout << "\nThere are 4 operations with sets:" << endl;
	cout << "     1. Union - The union of A and B is defined as the set that consists of all elements belonging to either set A or set B (or both)." << endl;
	cout << "     2. Subsets - A set B is included in, or is a subset of, a set A if every element of set B is an element of set A." << endl;
	cout << "     3. Intersection - The intersection of A and B is defined as the set composed of all elements that belong to both A and B." << endl;
	cout << "     4. Difference - The difference of set A and set B are the elements of set A that are not elements of set B." << endl;
	cout << endl;
}

bool mainMenu(string setA[], string setB[] ){ //This funcition shows the main menu
	
	int choice;
	cout << "Oparations with sets.\n\n";
	cout << "1. More about Sets\n";
	cout << "2. Create sets\n";
	cout << "9. Exit" << endl << endl;
	cout << "Enter your choice: ";
	cin >> choice;
	checkForWrongInput(choice);
	cout << endl << endl;
	switch (choice)
	{
		case 1:moreAboutSets();
			break;
	
		case 2:createSet(setA,setB);
			break;

		case 9:return 0;

		default:cout << "Try with available number!\n\n";
			break;
	}
	return 1;
}

int main()
{
	system("color b");
	string setA[100];
	string setB[100];
	bool sMenu = true;
	do
	{
		sMenu = mainMenu(setA, setB);
		

	} while (sMenu);
}