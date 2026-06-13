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
	//array declaration using CONST SIZE
	Traffic roadA[SIZE];
	Traffic roadB[SIZE];
	string fileName = "Traffic_Data.txt"; // Define the fileName
		
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
		for (int i = 0; i < SIZE; i++) //using loop to user input 5 period of data
		{
			int tempDataMemory = 0;
			cout << "The vehicle count at period " << i + 1 << " is : ";
			cin >> tempDataMemory;
			outFile << tempDataMemory << endl; //data will be save into text file
		}


	//Data Road B
	cout << endl << endl << "===== ROAD B =====" << endl; //doing same thing as Road A
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
		cout << "Unable to read file. " << endl; //check if file to open properly
		exit(1);
	}

	//Data A to array roadA
	for (int i = 0; i < SIZE; i++)
	{
		inFile >> roadA[i].vehiclesCounts; //taking data from text file into array
	}

	//Data B to array roadB
	for (int i = 0; i < SIZE; i++)
	{
		inFile >> roadB[i].vehiclesCounts;
	}
	inFile.close();


	//Process of ROAD A
	int totalRoadA = 0;
	float aveRoadA = 0; //initialized for upcoming processes
	int peakRoadA = 0;

	totalRoadA = totalVehicles(roadA);
	aveRoadA = averageVehicles(roadA); //data returned by the function
	peakRoadA = peakTrafficPeriod(roadA);

	//Process of ROAD B
	int totalRoadB = 0;
	float aveRoadB = 0; // initialized for upcoming processes
	int peakRoadB = 0;

	totalRoadB = totalVehicles(roadB);
	aveRoadB = averageVehicles(roadB); //data returned by the function
	peakRoadB = peakTrafficPeriod(roadB);


	//Output report Road A
	cout << endl << endl << endl << "===== ROAD A REPORT =====" << endl;
	cout << "Total Vehicles : " << totalRoadA << endl;
	cout << "Average Vehicles : " << fixed << setprecision(2) << aveRoadA << endl; //using setprecision to control decimal places up to 2
	cout << "Peak Traffic Period : " << peakRoadA << endl;
	cout << endl << "Traffic Classification : " << endl;
	classifyTrafficFlow(roadA); //calling out data from the function
	cout << endl << "Traffic Congestion Period : " << endl; 
	congestionPeriod(roadA); //calling out data from the function


	//Output report Road B
	cout << endl << endl << "===== ROAD B REPORT =====" << endl;
	cout << "Total Vehicles : " << totalRoadB << endl;
	cout << "Average Vehicles : " << fixed << setprecision(2) << aveRoadB << endl; //using setprecision to control decimal places up to 2
	cout << "Peak Traffic Period : " << peakRoadB << endl;
	cout << endl << "Traffic Classification : " << endl;
	classifyTrafficFlow(roadB) ; //calling out data from the function
	cout << endl << "Traffic Congestion Period : " << endl;
	congestionPeriod(roadB); //calling out data from the function


	//Comparison of Road A and Road 
	cout << endl << endl << "===== COMPARISON TRAFFIC FLOW BOTH ROAD =====" << endl;
	if (totalRoadA > totalRoadB) //using else if to compare both road
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
	for (int i = 0; i < SIZE; i++) //using for loop to determine each period of traffic flow
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
	for (int i = 0; i < SIZE; i++) //using loop to sum up all period of vehicles counts
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
	for (int i = 0; i < SIZE; i++) //using loop to sum up all period of vehicles counts 
	{
		total += road[i].vehiclesCounts;
	}
	average = total / SIZE; // finding the average of vehicles
	return average;
}

// Function peak traffic flow
int peakTrafficPeriod(Traffic road[])
{
	int peak = 0;
	for (int i = 0; i < SIZE; i++) // using loop compare all the period to find out the most vehicles counts period
	{
		if (road[i].vehiclesCounts > road[peak].vehiclesCounts)
			peak = i; //update the peak if now value is larger than previous
	}
	return peak + 1;
}

// Function congestion
void congestionPeriod(Traffic road[])
{
	bool congestionFound = false; // initial boolean flag as false
	for (int i = 0; i < SIZE; i++) // looping the period inside array
	{
		if (road[i].vehiclesCounts >= CONGESTION_LIMIT) //compare each period vehicles counts
		{
			cout << "Congestion detected at period " << i + 1 << endl;
			congestionFound = true; //update the congestionFound become true
		}
	}
	if (!congestionFound) //condition of screen out congestion not detected
		cout << "Congestion not detected " << endl; 

	return;
}