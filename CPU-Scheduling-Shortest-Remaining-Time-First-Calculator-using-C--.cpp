#include<iostream>
#include<sstream>
#include<string>
#include<conio.h>
#include <iomanip>
using namespace std;




int main() {
	
	int choice;
	
	do{
	if (choice != 1) {
	
	cout<<"\n\n\n                    Hello! \n\n";
	getch();
	cout <<"                    ================================================================================            "<<endl;
	cout<<"                      00       00  0000000  00        000000     000000     00     00   0000000   00            " <<endl;
	cout<<"                      00  00   00  00       00       00    00  00      00  0000   0000  00        00            " <<endl;
	cout<<"                      00 00 00 00  0000000  00       00        00      00  00 00 00 00  0000000   00            " <<endl;
	cout<<"                      0000   0000  00       00       00    00  00      00  00   00  00  00                      " <<endl;
	cout<<"                      00       00  0000000  0000000   000000     000000    00       00  0000000   00            " <<endl;
	cout <<"                    ================================================================================            "<<endl;
	getch();
	cout<<"\n                                  Press ENTER To Start SHORTEST REMAINING TIME FIRST!";
	getch();
	system("cls");
	
	
	cout <<"\n\n            Btw, Here's our Group! \n";
	getch();
	cout <<"            ===========================================================================================         "<<endl;
	cout <<"            ||                                                                                       ||         "<<endl;
	cout <<"            ||-------------------------|GROUP 3: SHORTEST REMAINING TIME FIRST |---------------------||         "<<endl;
	cout <<"            ||                                                                                       ||         "<<endl;
	cout <<"            ===========================================================================================         "<<endl;
	cout <<"              =======================================================================================           "<<endl;
	cout <<"              ||+                                                                                 +||           "<<endl;
	cout <<"              ||+                                JAMCO, MARK LOUIE A.                             +||           "<<endl;
	cout <<"              ||+                               MAHAIT, JASMINE JOYCE N.                          +||           "<<endl;
	cout <<"              ||+                                GOLINGAN, NORELYN A.                             +||           "<<endl;
	cout <<"              ||+                               MALIGOS, JONAS KENNETH                            +||           "<<endl;
	cout <<"              ||+                              MARIANO, CHRISTIANE MAE O.                         +||           "<<endl;
	cout <<"              ||+                                   ALDIE, CARLO                                  +||           "<<endl;
	cout <<"              ||+                               BUSTAMANTE, MATT JERSON                           +||           "<<endl;
	cout <<"              ||+                                                                                 +||           "<<endl;
	cout <<"              =======================================================================================           "<<endl;
    cout <<"                                              -Press Enter To Proceed!-";	
	getch();
	system("cls");
	
}
	
	int a[100], b[100], x[100];
	int waiting[100], turnaround[100], completion[100];
    int i, smallest, count = 0, time, n;
    double avg = 0, tt = 0, end;
	
	cout <<"            ===========================================================================================         "<<endl;
	cout <<"            ||-------------------------|GROUP 3: SHORTEST REMAINING TIME FIRST |---------------------||         "<<endl;
	cout <<"            ===========================================================================================         "<<endl<<endl;
    cout << "                                 >>> Please Enter the number of Processes: "; // input
    cin >> n;
    cout <<"              =======================================================================================           "<<endl;
    
    
    cout << "\n\n";
    cout <<"              ---------------------------------------------------------------------------------------           "<<endl;
    cout <<"              =======================================================================================           "<<endl;
    for (i = 0; i < n; i++) {
    cout <<"                                 >>> Enter ARRIVAL TIME of Process"<<i + 1<<": "; //input
    cin >> a[i];
    }
    cout <<"              =======================================================================================           "<<endl;
    cout << "\n\n";
    cout <<"              =======================================================================================           "<<endl;
    for (i = 0; i < n; i++) {
    cout <<"                                 >>> Enter BURST TIME of Process"<<i + 1<<": "; //input
        cin >> b[i];
    }
    cout <<"              =======================================================================================           "<<endl<<endl<<endl;
    cout <<"   -------------------------------------------------------------------------------------------------------------"<<endl<<endl<<endl;
    
    
    
    
    
    
    
    for (i = 0; i < n; i++)
        x[i] = b[i];

    b[99] = 9999;
    
    
    string topganttChart = " _";
    string botganttChart = " |";
    string ganttChart = " | ";
    
    for (time = 0; count != n; time++) {
        smallest = 99;
        for (i = 0; i < n; i++) {
            if (a[i] <= time && b[i] < b[smallest] && b[i] > 0)
                smallest = i;
        }
		if (smallest != 99) {
			
			
			
        // Update Gantt Chart string
        stringstream ss;
		ss << "P" << smallest + 1 << " | ";
		ganttChart += ss.str();
		
		
		// Update Gantt Top
        stringstream top;
        top << "____";
        topganttChart += top.str();
        topganttChart += "_";  
        
        // Update Gantt Bot
        stringstream bot;
        bot << "----";
        botganttChart += bot.str();
        botganttChart += "|";  
	
	
	
        
        b[smallest]--;
        
        if (b[smallest] == 0) {
            count++;
            end = time + 1;
            completion[smallest] = end;
            waiting[smallest] = end - a[smallest] - x[smallest];
            turnaround[smallest] = end - a[smallest];
        }    
      }
   }
   cout <<"            ===========================================================================================         "<<endl;
   cout <<"            ||------------------------------------| GANTT CHART |------------------------------------||         "<<endl;
   cout <<"            ===========================================================================================         "<<endl<<endl;
   
   // Print the 1st timeline
    int minArrivalTime1 = a[0];
    for (i = 1; i < n; i++) {
    if (a[i] < minArrivalTime1) {
        minArrivalTime1 = a[i];
    }
   }


    cout << "       ";
    for (int i = minArrivalTime1; i <= end; i++) {
    if (i < 10) {
        cout << i << "    "; // Single-digit numbers
    } else {
        cout << i << "   "; // Two-digit numbers
    }
   }
   cout << endl;


   cout << "      " << topganttChart << endl;
   cout << "      " << ganttChart << endl;
   cout << "      " << botganttChart << endl;
    
    
    // Print the 2nd timeline
   int minArrivalTime = a[0];
   for (i = 1; i < n; i++) {
    if (a[i] < minArrivalTime) {
        minArrivalTime = a[i];
    }
}
    // Print the timeline with only the first number and completion times
cout << "       ";
for (int i = minArrivalTime; i <= end; i++) {
    bool isCompletionTime = false;
    for (int j = 0; j < n; j++) {
        if (completion[j] == i) {
            isCompletionTime = true;
            break;
        }
    }

    if (i == minArrivalTime || isCompletionTime) {
        if (i < 10) {
            cout << i << "    "; // Single-digit numbers
        } else {
            cout << i << "   "; // Two-digit numbers
        }
    } else {
        cout << "     "; // Spaces for non-significant times
    }
}
cout << endl;

    cout <<"                                                                                                                "<<endl;
    cout <<"   -------------------------------------------------------------------------------------------------------------"<<endl;
    cout <<"          Process   |  Burst Time  |  Arrival Time  |   Waiting Time |  Turn Around Time  |  Completion Time    "<<endl;
	cout <<"   -------------------------------------------------------------------------------------------------------------"<<endl;
	
    for (i = 0; i < n; i++) {
    
    cout.width(12);cout <<  right  << "P"                              << i+1 <<"       | ";
	cout.width(6);cout  << right  <<x[i]                                      <<"       | ";
	cout.width(9);cout  << right  << a[i]                                     <<"      | ";
	cout.width(8);cout  << right  << waiting[i]                               <<"       | ";
	cout.width(10);cout << right  << turnaround[i]                            <<"         |    ";
	cout.width(6);cout  << right  << completion[i]                            << endl;
	
    avg = avg + waiting[i];
    tt = tt + turnaround[i];
    }
    cout <<"   -------------------------------------------------------------------------------------------------------------"<<endl<<endl;	
    cout <<"                                   Total Waiting time = " << avg <<    "   ||    Average Waiting time = " << avg / n  << endl;
    cout <<"                                   Total Turnaround time = " <<tt<<    "   ||   Average Turnaround time = " << tt / n << endl;

   cout << "\n  >>Would you like to calculate another? Please Type 1 if YES! : ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
        }

    } while (choice == 1);

    return 0;
}

