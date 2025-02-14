#include<iostream>
#include<vector>
#include <fstream>
#include<string>
#include<sstream>
#include<algorithm>
#include<iomanip>
using namespace std;

class process {

private:
	string name;
	int pid;
	string session_name;
	int session_id;
	long memusage;

public:
	process(string n, int p, string sn, int sid, int mem) :name(n), pid(p), session_name(sn), session_id(sid), memusage(mem) {};
	string getname() { return name; }
	int getpid() { return pid; }
	long getmemusage() { return memusage; }
	string getsession_name() { return session_name; }
	int getsession_id() { return session_id; }
};


class process_list {

private:
	vector<process>processes;
public:
	process_list() {};


	void loadfromos() {
		system("tasklist > tasklist.txt"); // Redirect the output of the tasklist command to a file named "tasklist.txt"
		ifstream file("tasklist.txt");
		string line;
		for (int i = 0; i < 3 && getline(file, line); i++);
		while (getline(file, line)) {
			if (line.empty()) { continue; }
			stringstream ss(line);
			string name;
			int pid;
			string session_name;
			int session_id;
			long memusage;
			string memory;


			getline(ss, name, ' ');
			while (!ss.eof()) {
				string temp;
				ss >> temp;
				if (all_of(temp.begin(), temp.end(), ::isdigit)) {
					pid = stoi(temp);
					break;
				}
				name += " " + temp;
			}

			ss >> session_name >> session_id >> memory;



			memory.erase(remove(memory.begin(), memory.end(), ','), memory.end());
			if (!memory.empty() && memory.back() == 'k') { memory.pop_back(); }
			memusage = stol(memory);

			processes.emplace_back(name, pid, session_name, session_id, memusage);

		}
		file.close();
	}

	void sort_name() {
		sort(processes.begin(), processes.end(), [](process& x, process& y) {return x.getname() < y.getname(); });
	}

	void sort_pid() {
		sort(processes.begin(), processes.end(), [](process& x, process& y) {return x.getpid() < y.getpid(); });
	}

	void sort_memusage() {
		sort(processes.begin(), processes.end(), [](process& x, process& y) {return x.getmemusage() > y.getmemusage(); });
	}

	void display() {


		cout << left << setw(30) << "Image Name"
			<< setw(10) << "PID"
			<< setw(20) << "Session Name"
			<< setw(10) << "Session#"
			<< setw(15) << "Mem Usage (K)" << endl;
		cout << string(85, '-') << endl;

		for (process& a : processes) {
			cout << left << setw(30) << a.getname()
				<< setw(10) << a.getpid()
				<< setw(20) << a.getsession_name()
				<< setw(10) << a.getsession_id()
				<< right << setw(15) << a.getmemusage() << " K" << endl;
		}
	}
};


void display_menu(process_list& a) {

	cout << "Task manager menu :" << endl;




	while (true) {

		cout << "\n*************************************************************" << endl;
		cout << "0)Show unsorted processes." << endl;
		cout << "1)Show processes sorted by name." << endl;
		cout << "2)Show processes sorted by id." << endl;
		cout << "3)Show processes sorted by memory usage." << endl;
		cout << "4) EXIT" << endl;

		int choice;

		cin >> choice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "ERROR : INVALID INPUT TRY A VALID ONE" << endl;
			continue;
		}


		switch (choice) {
		case 0:
			a.display();
			break;
		case 1:
			a.sort_name();
			a.display();
			break;
		case 2:
			a.sort_pid();
			a.display();
			break;
		case 3:
			a.sort_memusage();
			a.display();
			break;
		case 4:
			cout << " EXITING PROGRAMM..." << endl;
			exit(0);
		default:
			cout << " Enter a valid number please." << endl;
		}

	}

}


int main() {

	process_list a;
	a.loadfromos();
	display_menu(a);
	return 0;
}