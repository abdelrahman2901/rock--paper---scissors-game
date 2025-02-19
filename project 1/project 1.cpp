	#include <iostream>
	#include <string>
	#include <cstdlib>
	using namespace std;
	enum engamecontants{paper =0 , scissors =1,rock=2};
	string getChoiceName(engamecontants choice) {
		switch (choice) {
		case paper: return "Paper";
		case scissors: return "Scissors";
		case rock: return "Rock";
		default: return "Invalid";
		}
	}
	int askuser(string messege) {
		int number;
		cout << messege<<endl;
		cin >> number;
		return number;
	}
	engamecontants getrandomchoice() {
		int randomvalue = rand() % 3;
		return static_cast<engamecontants>(randomvalue);
	}
	void startgame(int &number) {                       
		
		int tiedpoints = 0;
		int userpoints = 0;
		int computerpoints = 0;
		for (int i = 1; i <= number;i++) {
			cout << "\t\t\t___________ROUND [" << i << "]___________" << endl;
			
			int userchoice = askuser(" (1) for rock , (2) for scissors , (3) for paper ");
			engamecontants computerchoice = getrandomchoice();
			engamecontants userchoiceEnum = static_cast<engamecontants>(userchoice - 1);
			if (userchoiceEnum == engamecontants::rock && computerchoice == engamecontants::scissors) {
				
				cout << "user choice : " << getChoiceName(userchoiceEnum) << endl;
				cout << "computer choice : " << getChoiceName(computerchoice) << endl;
				cout << "you won \n";
				system("color 2F");
				userpoints++;
			}
			else if (userchoiceEnum == engamecontants::rock && computerchoice == engamecontants::paper) {
				
				cout << "user choice : " << getChoiceName(userchoiceEnum) << endl;
				cout << "computer choice : " << getChoiceName(computerchoice) << endl;
				cout << "computer won, try again \n\a";
				system("color 4F");
				computerpoints++;
			}
			else if (userchoiceEnum == engamecontants::scissors && computerchoice == engamecontants::paper) {
				
				cout << "user choice : " << getChoiceName(userchoiceEnum) << endl;
				cout << "computer choice : " << getChoiceName(computerchoice) << endl;
				cout << "you won \n";
				system("color 2F");
				userpoints++;
			}
			else if (userchoiceEnum == engamecontants::scissors && computerchoice == engamecontants::rock) {
				
				cout << "user choice : " << getChoiceName(userchoiceEnum) << endl;
				cout << "computer choice : " << getChoiceName(computerchoice) << endl;
				cout << "computer won ,try again \n\a";
				system("color 4F");
				computerpoints++;
			}
			else if (userchoiceEnum == engamecontants::paper && computerchoice == engamecontants::rock) {
				
				cout << "user choice : " << userchoice << endl;
				cout << "computer choice : " << computerchoice << endl;
				cout << "you won \n";
				system("color 2F");

				userpoints++;
			}
			else if (userchoiceEnum == engamecontants::paper && computerchoice == engamecontants::scissors) {
				cout << "user choice : " << getChoiceName(userchoiceEnum) << endl;
				cout << "computer choice : " << getChoiceName(computerchoice) << endl;
				cout << "computer won , try again \a\n";
				system("color 4F");
				computerpoints++;
			}
			else {
				cout << "user choice : " << userchoice << endl;
				cout << "computer choice : " << computerchoice << endl;
				cout << "tied ^^ \n";
				tiedpoints++;
				
			}
			
		}
		system("cls");
		system("color 0F");
		cout << "\t\t\t-----------------RESULTS----------------\n";
		cout << "\t\t\tUser Point = " << userpoints << endl;
		cout << "\t\t\tComputer Point = " << computerpoints << endl;
		cout << "\t\t\ttied Points = " << tiedpoints << endl;
		if (userpoints > computerpoints)
			cout<<"\t\t\tFinal winner : " << "user won";
		else if (userpoints < computerpoints)
			cout << "\t\t\tFinal winner : " << "computer won ";
		else	
		cout << "\t\t\tFinal winner : " << "no one has win \n";
		cout << "\n\t\t\t----------------------------------------\n\n\n";
		
		}
	void gameoveror() {
		while (true){
		bool choice;
		    cout << "\n\t\t--------------------------------------------\n";
			cout << "\n\t\t\t      G A M E O V E R  \n\n";
			cout << "\t\t--------------------------------------------\n";
			cout << "do you want to play again ? (1) if yes , (0) if no " << endl;
			cin >> choice;
			if (choice == true) {
				int Number = askuser("how many rounds you want to play ? ");
				startgame(Number);
			}
			else {
				cout << "thank you for playing ";
				break;
			}
		} 
	}
int main()
	{
		srand((unsigned)time(NULL));
		
		int number = askuser("how many rounds you want to play ?");
		startgame(number);
		
		gameoveror();
	
	}
