/*
I, Liana Severo (li724622) affirm that this program is entirely my own work and that I have
neither developed my code together with any another person, nor copied any code from any other person,
nor permitted my code to be copied or otherwise used by any other person, nor have I copied, modified, or
otherwise used program code that I have found in any external source, including but not limited to, online
sources. I acknowledge that any violation of the above terms will be treated as academic dishonesty.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "airPdata.h"

#define MAX 1024

// Function prototypes
void printData(airPdata *airport);

int main(int argc, char *argv[])
{
    // Variable declarations
    FILE *ifp;
    char *buffer, *front;
    airPdata *airportData;
    //int lineNumber = 1;
    char *region, *ADO, *use, *ownership, *regulation, *serviceLevel, *hubType;

    // Allocate memory for buffer array to hold data read from file
    if((buffer = (char*)malloc(sizeof(char)*MAX)) == NULL)
        return (-1);

    // Allocate memory for struct
    if((airportData = (airPdata*)malloc(sizeof(airPdata))) == NULL)
        return (-1);

    // Check if file opens correctly, if not, exit safely
    if ((ifp = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "etl ERROR: File \"%s\" not found.\n", argv[1]);
        return (-1);
    }

    // Print header
    printf("%-12s %-11s %-42s %-34s %-3s %-15s %-16s Tower\n", "FAA Site", "Short Name", "Airport Name", "City", "ST", "Latitude", "Longitude");
    printf("%-12s %-11s %-42s %-34s %-3s %-15s %-16s =====\n", "========", "==========", "============", "====", "==", "========", "=========");


    //fgets parameters: char* buffer, int size, FILE* ptr, it returns NULL at the end of file
    // Reads file using fgets
    while((fgets(buffer, MAX, ifp)) != NULL)
    {
        //printf("Got line %d\n", lineNumber);

        // Store pointer to beginning of buffer array in front, as to not lose it
        front = buffer;

        // Use strsep function to parse data
        // strsep returns a pointer to the NEXT token from buffer.
        // When there are no more tokens, strsep returns NULL.
        airportData->siteNumber = strsep(&buffer, ",");
        airportData->LocID = strsep(&buffer, ",");
        airportData->fieldName = strsep(&buffer, ",");
        airportData->city = strsep(&buffer, ",");
        airportData->state = strsep(&buffer, ",");
        region = strsep(&buffer, ","); // region; ignore this field
        ADO = strsep(&buffer, ","); // Airline Dispatch Officel; ignore this field
        use = strsep(&buffer, ","); // public or private; ignore this field
        airportData->latitude = strsep(&buffer, ",");
        airportData->longitude = strsep(&buffer, ",");
        ownership = strsep(&buffer, ","); // public or private; ignore this field
        regulation = strsep(&buffer, ","); // FAA regulation; ignore this field
        serviceLevel = strsep(&buffer, ","); // service level; ignore this field
        hubType = strsep(&buffer, ","); // hub type; ignore this field
        airportData->controlTower = strsep(&buffer, ",")[0];

        // In order: siteNum, LocID, fieldName, city, state,
        // region, ADO, use, latitude, longitude, ownership, regulation, serviceLevel, hubType,
        // controlTower, fuel, other, basedTotal, totalOps

        buffer = front;

        //printf("strsep: %d\n", lineNumber);
        //lineNumber++;

        printData(airportData);
    }

    free(buffer);
    free(airportData);
    fclose(ifp);

    return 0;
}

void printData(airPdata *airport)
{
    // Function prints data for a given airport, using same format as the provided header line
    // Input: A pointer to an airPdata structure
    // If a NULL pointer is passed to this function, print an error msg to STDERR and return w/o printing to STDOUT

    if(airport == NULL)
    {
        fprintf(stderr, "You have passed in a NULL pointer. This file does not exist\n");
        return;
    }

    printf("%-12s %-11s %-42s %-34s %-3s %-15s %-16s %c\n", airport->siteNumber, airport->LocID, airport->fieldName, airport->city, airport->state, airport->latitude, airport->longitude, airport->controlTower);

}
