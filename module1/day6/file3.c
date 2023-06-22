#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
} LogEntry;

void readLogData(LogEntry logEntries[], int* numEntries) {
    FILE* file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        exit(1);
    }

    char line[100];
    fgets(line, sizeof(line), file); // Skip the header line

    *numEntries = 0;
    while (fgets(line, sizeof(line), file) != NULL && *numEntries < MAX_ENTRIES) {
        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]", &entry.entryNo, entry.sensorNo,
               &entry.temperature, &entry.humidity, &entry.light, entry.timestamp);
        logEntries[*numEntries] = entry;
        (*numEntries)++;
    }

    fclose(file);
}

void displayLogData(LogEntry logEntries[], int numEntries) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (int i = 0; i < numEntries; i++) {
        LogEntry entry = logEntries[i];
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n", entry.entryNo, entry.sensorNo,
               entry.temperature, entry.humidity, entry.light, entry.timestamp);
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    readLogData(logEntries, &numEntries);
    displayLogData(logEntries, numEntries);

    return 0;
}
