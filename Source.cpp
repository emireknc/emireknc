/*This code completely belongs to me but you can use it as you want. I know its so basic but this is my first "program". Anyways hope this helps people.
Have a great day guys.By the way please read program info part before read here. If you still confused about some code blocks or algorithm don't hesitate to communicate with me */


//Libraries
#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {

	//In here, there is our names and surnames cluster . 
	vector<string> names = { /*In here, type different names (more names, more variations*/ };
	vector<string> surnames = { /*And here, type different surnames(like names, more surnames equals more variations*/ };


	//Assignment of values;
	int classsize, homewrk1, homewrk2, quiz1, quiz2, mdtrmexam, homewrk1prcnt, homewrk2prcnt, quiz1prcnt, quiz2prcnt, mdtrmexamprcnt, passscore;
	int passedstudent = 0, cntpassedstudent = 0, finalscore;
	float aa = 0, ba = 0, bb = 0, cb = 0, cc = 0, dc = 0, dd = 0, fd = 0, ff = 0;
	float succesrate, allstudntscore = 0, classcoreaverage = 0, finalprcnt;

	//I am using "vector" to save each student's grade because later, I'm gonna calculate the standard deviation of the class.
	vector<int>studentscore;

	//At here user will type class size.
	cout << "Please insert class size: ";
	cin >> classsize;

	//I am gonna use Do-while loop because I want to sure about that user typed correct values.
	do {

		cout << endl << "Please make sure the typed percentage values sum equals 100" << endl;
		cout << endl << "Type 1st homework percentage: ";
		cin >> homewrk1prcnt;
		cout << endl << "Type 2nd homework percentage: ";
		cin >> homewrk2prcnt;
		cout << endl << "Type 1st quiz percentage: ";
		cin >> quiz1prcnt;
		cout << endl << "Type 2nd quiz percentage: ";
		cin >> quiz2prcnt;
		cout << endl << "Type midterm exam percentage: ";
		cin >> mdtrmexamprcnt;

	} while (homewrk1prcnt + homewrk2prcnt + quiz1prcnt + quiz2prcnt + mdtrmexamprcnt != 100);

	//In this section, I request from the user the percent of all midterm assignments and quizzes in the final grade.
	cout << endl << endl << "Please type pass score: ";
	cin >> passscore;
	//Here again, I used Do-while loop to make sure that the user entered a valid values.
	do
	{
		cout << endl << "Please enter the percentage of final exam score (Make sure you enter out of 100): ";
		cin >> finalprcnt;

	} while (finalprcnt >= 100);

	//I redefine the value entered by the user to make it easier for  me in future mathematical operations.
	finalprcnt = finalprcnt / 100;

	float highestscore = 0, lowestscore = 100;


	//The for loop here ensures that the program runs as long as the class size.
	for (int i = 1; i <= classsize; ++i) {

		//Here, I ensure that random names and surnames are selected from the previously created cluster of names.
		cout << i << ".Student" << endl;
		int name = rand() % names.size();
		int surname = rand() % surnames.size();
		cout << "Student's name: " << names[name] << endl << "Student's surname: " << surnames[surname] << endl;

		//By using if-else loops, I ensure that student's scores are distributed in certain percentages as desired.
		if (i <= classsize * 0.2) {

			//Random determination of scores: 
			homewrk1 = rand() % 21 + 80;
			homewrk2 = rand() % 21 + 80;
			quiz1 = rand() % 21 + 80;
			quiz2 = rand() % 21 + 80;
			mdtrmexam = rand() % 21 + 80;
			finalscore = rand() % 21 + 80;

			//Calculation of the student's success grade.
			succesrate = ((((homewrk1 * homewrk1prcnt + homewrk2 * homewrk2prcnt + quiz1 * quiz1prcnt + quiz2 * quiz2prcnt + mdtrmexam * mdtrmexamprcnt)) / 100) * finalprcnt + finalscore * (1 - finalprcnt));

			//I pass all the notes created here through this if-else decision mechanism and ensure that the highest and lowest notes are saved.
			if (succesrate > highestscore) {
				highestscore = succesrate;
			}
			else if (lowestscore > succesrate) {
				lowestscore = succesrate;
			}

			//Here, I am assigning each success grade achieved to the previously created vector folder.
			for (int i = 0; i <= classsize; i++) {

				studentscore.push_back(succesrate);
			}

			//Printing the student's grades.
			cout << "Student's 1st homework score:  " << homewrk1 << endl;
			cout << "Student's 2nd homework score:  " << homewrk2 << endl;
			cout << "Student's 1st quiz score:  " << quiz1 << endl;
			cout << "Student's 2nd quiz score:  " << quiz2 << endl;
			cout << "Student's midterm exam score:  " << mdtrmexam << endl;
			cout << "Student's final exam score:   " << finalscore << endl;
			cout << "Student's end-of-year score:  : " << succesrate << endl;

			//The use of if-else decision mechanism here is to show the grade received by the student with the letter system. (The lettering mechanism in each loop is the same.)
			if (succesrate >= 90) {

				cout << "Letter equivalent of the student's end-of-year grade: AA" << endl;
				aa++;
			}
			else if (succesrate < 90 and succesrate >= 85) {

				cout << "Letter equivalent of the student's end-of-year grade: BA" << endl;
				ba++;
			}
			else if (succesrate < 85 and succesrate >= 80) {

				cout << "Letter equivalent of the student's end-of-year grade: BB" << endl;
				bb++;
			}
			else if (succesrate < 80 and succesrate >= 75) {

				cout << "Letter equivalent of the student's end-of-year grade: CB" << endl;
				cb++;
			}
			else if (succesrate < 75 and succesrate >= 65) {

				cout << "Letter equivalent of the student's end-of-year grade: CC" << endl;
				cc++;
			}
			else if (succesrate < 65 and succesrate >= 58) {

				cout << "Letter equivalent of the student's end-of-year grade: DC" << endl;
				dc++;
			}
			else if (succesrate < 58 and succesrate >= 50) {

				cout << "Letter equivalent of the student's end-of-year grade: DD" << endl;
				dd++;
			}
			else if (succesrate < 50 and succesrate >= 40) {

				cout << "Letter equivalent of the student's end-of-year grade: FD" << endl;
				fd++;
			}
			else {

				cout << "Letter equivalent of the student's end-of-year grade: FF" << endl;
				ff++;
			}

			//Here, I use another if else loop to if the student's grade is higher than the entered passing score, then print the student passed, otherwise, print he/she failed.
			if (succesrate > passscore) {

				cout << "Student's passing status: Passed." << endl << endl;
				passedstudent++;

			}
			else {

				cout << "Student's passing status: Can't passed." << endl << endl;
				cntpassedstudent++;
			}
		}
		else if (classsize * 0.2 < i and i <= classsize * 0.7) {

			//Random determination of scores: 
			homewrk1 = rand() % 31 + 50;
			homewrk2 = rand() % 31 + 50;
			quiz1 = rand() % 31 + 50;
			quiz2 = rand() % 31 + 50;
			mdtrmexam = rand() % 31 + 50;
			finalscore = rand() % 31 + 50;

			//Calculation of the student's success grade.
			succesrate = ((((homewrk1 * homewrk1prcnt + homewrk2 * homewrk2prcnt + quiz1 * quiz1prcnt + quiz2 * quiz2prcnt + mdtrmexam * mdtrmexamprcnt)) / 100) * finalprcnt + finalscore * (1 - finalprcnt));

			//I pass all the notes created here through this if-else decision mechanism and ensure that the highest and lowest notes are saved.
			if (succesrate > highestscore) {
				highestscore = succesrate;
			}
			else if (lowestscore > succesrate) {
				lowestscore = succesrate;
			}

			//Here, I am assigning each success grade achieved to the previously created vector folder.
			for (int i = 0; i <= classsize; i++) {

				studentscore.push_back(succesrate);
			}

			//Printing the student's grades.
			cout << "Student's 1st homework score:  " << homewrk1 << endl;
			cout << "Student's 2nd homework score:  " << homewrk2 << endl;
			cout << "Student's 1st quiz score:  " << quiz1 << endl;
			cout << "Student's 2nd quiz score:  " << quiz2 << endl;
			cout << "Student's midterm exam score:  " << mdtrmexam << endl;
			cout << "Student's final exam score:   " << finalscore << endl;
			cout << "Student's end-of-year score:  : " << succesrate << endl;

			if (succesrate >= 90) {

				cout << "Letter equivalent of the student's end-of-year grade: AA" << endl;
				aa++;
			}
			else if (succesrate < 90 and succesrate >= 85) {

				cout << "Letter equivalent of the student's end-of-year grade: BA" << endl;
				ba++;
			}
			else if (succesrate < 85 and succesrate >= 80) {

				cout << "Letter equivalent of the student's end-of-year grade: BB" << endl;
				bb++;
			}
			else if (succesrate < 80 and succesrate >= 75) {

				cout << "Letter equivalent of the student's end-of-year grade: CB" << endl;
				cb++;
			}
			else if (succesrate < 75 and succesrate >= 65) {

				cout << "Letter equivalent of the student's end-of-year grade: CC" << endl;
				cc++;
			}
			else if (succesrate < 65 and succesrate >= 58) {

				cout << "Letter equivalent of the student's end-of-year grade: DC" << endl;
				dc++;
			}
			else if (succesrate < 58 and succesrate >= 50) {

				cout << "Letter equivalent of the student's end-of-year grade: DD" << endl;
				dd++;
			}
			else if (succesrate < 50 and succesrate >= 40) {

				cout << "Letter equivalent of the student's end-of-year grade: FD" << endl;
				fd++;
			}
			else {

				cout << "Letter equivalent of the student's end-of-year grade: FF" << endl;
				ff++;
			}

			if (succesrate > passscore) {

				cout << "Student's passing status: Passed." << endl << endl;
				passedstudent++;

			}
			else {

				cout << "Student's passing status: Can't passed." << endl << endl;
				cntpassedstudent++;
			}
		}
		else if (i > classsize * 0.7) {

			//Random determination of scores: 
			homewrk1 = rand() % 51;
			homewrk2 = rand() % 51;
			quiz1 = rand() % 51;
			quiz2 = rand() % 51;
			mdtrmexam = rand() % 51;
			finalscore = rand() % 51;

			//Calculation of the student's success grade.
			succesrate = ((((homewrk1 * homewrk1prcnt + homewrk2 * homewrk2prcnt + quiz1 * quiz1prcnt + quiz2 * quiz2prcnt + mdtrmexam * mdtrmexamprcnt)) / 100) * finalprcnt + finalscore * (1 - finalprcnt));
			
			//I pass all the notes created here through this if-else decision mechanism and ensure that the highest and lowest notes are saved.
			if (succesrate > highestscore) {
				highestscore = succesrate;
			}
			else if (lowestscore > succesrate) {
				lowestscore = succesrate;
			}

			//Here, I am assigning each success grade achieved to the previously created vector folder.
			for (int i = 0; i <= classsize; i++) {

				studentscore.push_back(succesrate);
			}

			//Printing the student's grades.
			cout << "Student's 1st homework score:  " << homewrk1 << endl;
			cout << "Student's 2nd homework score:  " << homewrk2 << endl;
			cout << "Student's 1st quiz score:  " << quiz1 << endl;
			cout << "Student's 2nd quiz score:  " << quiz2 << endl;
			cout << "Student's midterm exam score:  " << mdtrmexam << endl;
			cout << "Student's final exam score:   " << finalscore << endl;
			cout << "Student's end year score:  : " << succesrate << endl;
		
			if (succesrate >= 90) {

				cout << "Letter equivalent of the student's end-of-year grade: AA" << endl;
				aa++;
			}
			else if (succesrate < 90 and succesrate >= 85) {

				cout << "Letter equivalent of the student's end-of-year grade: BA" << endl;
				ba++;
			}
			else if (succesrate < 85 and succesrate >= 80) {

				cout << "Letter equivalent of the student's end-of-year grade: BB" << endl;
				bb++;
			}
			else if (succesrate < 80 and succesrate >= 75) {

				cout << "Letter equivalent of the student's end-of-year grade: CB" << endl;
				cb++;
			}
			else if (succesrate < 75 and succesrate >= 65) {

				cout << "Letter equivalent of the student's end-of-year grade: CC" << endl;
				cc++;
			}
			else if (succesrate < 65 and succesrate >= 58) {

				cout << "Letter equivalent of the student's end-of-year grade: DC" << endl;
				dc++;
			}
			else if (succesrate < 58 and succesrate >= 50) {

				cout << "Letter equivalent of the student's end-of-year grade: DD" << endl;
				dd++;
			}
			else if (succesrate < 50 and succesrate >= 40) {

				cout << "Letter equivalent of the student's end-of-year grade: FD" << endl;
				fd++;
			}
			else {

				cout << "Letter equivalent of the student's end-of-year grade: FF" << endl;
				ff++;
			}

			if (succesrate > passscore) {

				cout << "Student's passing status: Passed." << endl << endl;
				passedstudent++;

			}
			else {

				cout << "Student's passing status: Can't passed." << endl << endl;
				cntpassedstudent++;
			}

		}

		/*Here-end pf the loops-, I collect the students' scores to calculate and print the average of the class later. The reason that this isnt in the for loop, 
          not to lose the random notes that occur each time. otherwise it would only collect the last formed note. */
		 
		  allstudntscore = allstudntscore + succesrate;
	}

	//Here I write the operations required to calculate the standard deviation in the for loop.
	classcoreaverage = allstudntscore / classsize;
	int sdeviation1, sdeviation2 = 0, sdeviation3;
	float stndrddevtion;
	for (int i = 0; i < classsize; i++)
	{
		sdeviation3 = studentscore[i] - classcoreaverage;
		sdeviation1 = sdeviation3 * sdeviation3;
		sdeviation2 = sdeviation2 + sdeviation1;
	}
	stndrddevtion = sqrt(sdeviation2 / (classsize - 1));

	//Printing general information about grades.
	cout << endl << endl << endl << "Number of students that passed the class: " << passedstudent << endl;
	cout << "Number of students that cannot passed the class: " << cntpassedstudent << endl;
	cout << "Highest grade in the class: " << highestscore << endl;
	cout << "Lowest grade in the class:" << lowestscore << endl;
	cout << "Average end-of-year score:  " << classcoreaverage << endl;
	cout << "Standard deviation of the class:" << stndrddevtion << endl << endl << endl;

	//As can be understood, what is done here is to print out how many students received which letter grade and their percentages in the class.
	cout << "Number of students receiving AA: " << aa << "  " << "Percentile: %" << aa / classsize * 100 << endl;
	cout << "Number of students receiving BA: " << ba << "  " << "Percentile: %" << ba / classsize * 100 << endl;
	cout << "Number of students receiving BB: " << bb << "  " << "Percentile: %" << bb / classsize * 100 << endl;
	cout << "Number of students receiving CB: " << cb << "  " << "Percentile: %" << cb / classsize * 100 << endl;
	cout << "Number of students receiving CC: " << cc << "  " << "Percentile: %" << cc / classsize * 100 << endl;
	cout << "Number of students receiving DC: " << dc << "  " << "Percentile: %" << dc / classsize * 100 << endl;
	cout << "Number of students receiving DD: " << dd << "  " << "Percentile: %" << dd / classsize * 100 << endl;
	cout << "Number of students receiving FD: " << fd << "  " << "Percentile: %" << fd / classsize * 100 << endl;
	cout << "Number of students receiving FF: " << ff << "  " << "Percentile: %" << ff / classsize * 100 << endl;

}