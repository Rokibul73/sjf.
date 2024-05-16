#include <iostream>
using namespace std;

int main() {

	int processes[100][4];
	int i, j, num_processes, total = 0, index, temp;
	float avg_waiting_time, avg_turnaround_time;

	cout << "Enter number of processes: ";
	cin >> num_processes;

	cout << "Enter Burst Time:" << endl;

	for (i = 0; i < num_processes; i++) {
		cout << "P" << i + 1 << ": ";
		cin >> processes[i][1];
		processes[i][0] = i + 1;
	}

	for (i = 0; i < num_processes; i++) {
		index = i;
		for (j = i + 1; j < num_processes; j++)
			if (processes[j][1] < processes[index][1])
				index = j;
		temp = processes[i][1];
		processes[i][1] = processes[index][1];
		processes[index][1] = temp;

		temp = processes[i][0];
		processes[i][0] = processes[index][0];
		processes[index][0] = temp;
	}

	processes[0][2] = 0;

	for (i = 1; i < num_processes; i++) {
		processes[i][2] = 0;
		for (j = 0; j < i; j++)
			processes[i][2] += processes[j][1];
		total += processes[i][2];
	}

	avg_waiting_time = (float)total / num_processes;
	total = 0;
	cout << "P    BT    WT    TAT" << endl;

	for (i = 0; i < num_processes; i++) {
		processes[i][3] = processes[i][1] + processes[i][2];
		total += processes[i][3];
		cout << "P" << processes[i][0] << "    " << processes[i][1] << "    " << processes[i][2] << "    " << processes[i][3] << endl;
	}

	avg_turnaround_time = (float)total / num_processes;
	cout << "Average Waiting Time= " << avg_waiting_time << endl;
	cout << "Average Turnaround Time= " << avg_turnaround_time << endl;
}
