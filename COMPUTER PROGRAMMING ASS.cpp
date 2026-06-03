#include <iostream>
#include <iomanip>
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

		//Input ROAD A
		cout << "====== ROAD A ======" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << " The vehicle count at period " << i + 1 << " is : ";
			cin >> roadA[i].vehiclesCounts;
		}

		//Input ROAD B
		cout << endl << "====== ROAD B ======" << endl;
		for (int i = 0; i < SIZE; i++)
		{
			cout << " The vehicle count at period " << i + 1 << " is : ";
			cin >> roadB[i].vehiclesCounts;
		}

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
	cout << endl << "===== ROAD B REPORT =====" << endl;
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
		cout << "Road A having heavily traffic flow than road B " << endl;
	}
	else if (totalRoadA < totalRoadB)
	{
		cout << "Road B having heavily traffic flow than road A " << endl;
	}
	else 
	{
		cout << "Both road having same traffic flow " << endl;
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
	return peak;
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