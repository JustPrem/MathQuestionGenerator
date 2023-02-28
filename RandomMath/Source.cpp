#include <iostream>
#include <random>
#include <string>
using namespace std;

// Generates the Question and answer.
void GenerateQuestion(string* _question, int* _answer)
{
	// Generate Values.
	int val1;
	int val2;

	do
	{
		val1 = rand() % 50;
		val2 = rand() % 50;
	} while (val1 - val2 < 0);

	// Generate Operator.
	string mathOperator;

	// Generate Answer and Operator.
	switch (rand() % 3)	// Get the Operator, 0 = Plus, 1 = Minus, 2 = Multiply.
	{
		case 0: // Plus
		{
			mathOperator = " + ";
			*_answer = val1 + val2;
			break;
		}
		case 1: // Minus.
		{
			mathOperator = " - ";
			*_answer = val1 - val2;
			break;
		}
		case 2: // Multiply.
		{
			mathOperator = " * ";
			*_answer = val1 * val2;
			break;
		}
	}

	// Generate Question.
	*_question = "Question: " + to_string(val1) + mathOperator + to_string(val2);
}

void main()
{
	// Initialise Variables.
	string mQuestion;
	int mAnswer;
	int mScore = 0;
	int mStreak = 0;

	// Initialise Answer Variable.
	int mUserInput = 0;

	do
	{
		GenerateQuestion(&mQuestion, &mAnswer);
		system("cls");

		// Validate
		if (cin.fail())
		{
			cout << "ERROR: Please use whole numbers above 0!" << endl;
			cin.clear();
			cin.ignore(80, '\n');
		}

		// Display the question.
		cout << endl << "Instructions: Enter a number and press enter, enter -1 to exit." << endl << endl;
		cout << "Current Streak: " << mStreak << endl;
		cout << "Current Score: " << mScore << endl << endl;
		cout << mQuestion << endl << "Answer: ";
		cin >> mUserInput;

		if (!cin.fail() && mUserInput == mAnswer)
		{
			mScore++;

			if (mStreak < mScore)
			{
				mStreak = mScore;
			}
		}
		else
		{
			mScore = 0;
		}
	} 
	while (mUserInput != -1);
}