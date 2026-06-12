#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//constant size array and congestion limit
const int SIZE = 5;
const int CONGESTION_LIMIT = 300;

//structure declaration
struct Traffic
{
	int vehiclesCounts;
};

//function header
void classifyTrafficFlow(Traffic[]);
int totalVehicles(Traffic[]);
float averageVehicles(Traffic[]);
int peakTrafficPeriod(Traffic[]);
void congestionPeriod(Traffic[]);

int main()
{
	//declaration
	Traffic roadA[SIZE];
	Traffic roadB[SIZE];
	string fileName = "Traffic_Data.txt";
		
	//Comfirmation of creating file
	ofstream outFile;
	outFile.open(fileName,ios::out);
	
	if (!outFile)
	{
		cout << "Unable to open file. " << endl;
		exit(1);
	}
	

	//Insert data Road A and Road B into text file
	cout << "===== ENTER TRAFFIC DATA =====" << endl;
	cout << "The data will be save into " << fileName << endl << endl << endl;


	//Data Road A
	cout << "===== ROAD A =====" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			int tempDataMemory = 0;
			cout << "The vehicle count at period " << i + 1 << " is : ";
			cin >> tempDataMemory;
			outFile << tempDataMemory << endl;
		}


	//Data Road B
	cout << endl << endl << "===== ROAD B =====" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			int tempDataMemory = 0;
			cout << "The vehicle count at period " << i + 1 << " is : ";
			cin >> tempDataMemory;
			outFile << tempDataMemory << endl;
		}
		
	outFile.close();
	cout << endl << "All data is been saved into " << fileName << endl;


	//Take data from file to array
	ifstream inFile;
	inFile.open(fileName, ios::in);


	//Comfirmation of reading file
	if (!inFile)
	{
		cout << "Unable to read file. " << endl;
		exit(1);
	}


	//Data A to array roadA
	for (int i = 0; i < SIZE; i++)
	{
		inFile >> roadA[i].vehiclesCounts;
	}


	//Data B to array roadB
	for (int i = 0; i < SIZE; i++)
	{
		inFile >> roadB[i].vehiclesCounts;
	}
	inFile.close();


	//Process of ROAD A
	int totalRoadA = 0;
	float aveRoadA = 0;
	int peakRoadA = 0;

	totalRoadA = totalVehicles(roadA);
	aveRoadA = averageVehicles(roadA);
	peakRoadA = peakTrafficPeriod(roadA);

	//Process of ROAD B
	int totalRoadB = 0;
	float aveRoadB = 0;
	int peakRoadB = 0;

	totalRoadB = totalVehicles(roadB);
	aveRoadB = averageVehicles(roadB);
	peakRoadB = peakTrafficPeriod(roadB);


	//Output report Road A
	cout << endl << endl << endl << "===== ROAD A REPORT =====" << endl;
	cout << "Total Vehicles : " << totalRoadA << endl;
	cout << "Average Vehicles : " << fixed << setprecision(2) << aveRoadA << endl;
	cout << "Peak Traffic Period : " << peakRoadA << endl;
	cout << endl << "Traffic Classification : " << endl;
	classifyTrafficFlow(roadA);
	cout << endl << "Traffic Congenstion Period : " << endl; 
	congestionPeriod(roadA);


	//Output report Road B
	cout << endl << endl << "===== ROAD B REPORT =====" << endl;
	cout << "Total Vehicles : " << totalRoadB << endl;
	cout << "Average Vehicles : " << fixed << setprecision(2) << aveRoadB << endl;
	cout << "Peak Traffic Period : " << peakRoadB << endl;
	cout << endl << "Traffic Classification : " << endl;
	classifyTrafficFlow(roadB) ;
	cout << endl << "Traffic Congenstion Period : " << endl;
	congestionPeriod(roadB);


	//Comparision of Road A and Road 
	cout << endl << endl << "===== COMPARISION TRAFFIC FLOW BOTH ROAD =====" << endl;
	if (totalRoadA > totalRoadB)
	{
		cout << "Road A having heavily traffic flow than road B " << endl << endl;
	}
	else if (totalRoadA < totalRoadB)
	{
		cout << "Road B having heavily traffic flow than road A " << endl << endl;
	}
	else 
	{
		cout << "Both road having same traffic flow " << endl << endl;
	}
	return 0;
}



// Function classify traffic flow
void classifyTrafficFlow(Traffic road[])
{ 
	for (int i = 0; i < SIZE; i++)
	{
		cout << "period " << i + 1 << " : ";
		if (road[i].vehiclesCounts < 100)
			cout << " Light " << endl;
		else if (road[i].vehiclesCounts < 200)
			cout << " Moderate " << endl;
		else
			cout << " Heavy " << endl;
	}
	return;
}

// Function total vehicles count
int totalVehicles(Traffic road[])
{
	int total = 0;
	for (int i = 0; i < SIZE; i++)
	{
		total += road[i].vehiclesCounts;
	}
	return total;
}

// Function average vehicles
float averageVehicles(Traffic road[])
{
	float total = 0;
	float average = 0;
	for (int i = 0; i < SIZE; i++)
	{
		total += road[i].vehiclesCounts;
	}
	average = total / SIZE;
	return average;
}

// Function peak traffic flow
int peakTrafficPeriod(Traffic road[])
{
	int peak = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (road[i].vehiclesCounts > road[peak].vehiclesCounts)
			peak = i;
	}
	return peak + 1;
}

// Function congestion
void congestionPeriod(Traffic road[])
{
	bool congestionFound = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (road[i].vehiclesCounts >= CONGESTION_LIMIT)
		{
			cout << "Congestion detected at period " << i + 1 << endl;
			congestionFound = true;
		}
	}
	if (!congestionFound)
		cout << "Congestion not detected " << endl;

	return;
}