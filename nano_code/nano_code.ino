#include "flight_controller.h"
#include "imu.h"

const byte numChars = 64;
char receivedChars[numChars];
char tempChars[numChars];        // temporary array for use when parsing

      // variables to hold the parsed data
int m1 = 0;
int m2 = 0;
int m3 = 0;
int m4 = 0;



boolean newData = false;

//============

void setup() {
    Serial.begin(115200);

//    Serial.println("Enter data in this style <12, 12>  ");
    setupFlightController();
     
    if (!imu_init()) {
    Serial.println("IMU init failed!");
    } else {
      Serial.println("IMU ready");
    }
}

//============

void loop() {
//    recvWithStartEndMarkers();
//    if (newData == true) {
//        strcpy(tempChars, receivedChars);
//            // this temporary copy is necessary to protect the original data
//            //   because strtok() used in parseData() replaces the commas with \0
//        parseData();
//        showParsedData();
//        newData = false;
//    }
    imu_update();
    updateFlightController();
}

//============

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;

    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

//============

void parseData() {      // split the data into its parts

    char * strtokIndx; // this is used by strtok() as an index

    strtokIndx = strtok(tempChars,",");      // get the first part - the string
    m1 = atoi(strtokIndx); // copy it to messageFromPC
 
    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
    m2 = atoi(strtokIndx);     // convert this part to an integer

//    strtokIndx = strtok(NULL, ",");
//    m3 = atoi(strtokIndx);     // convert this part to a float
//
//    strtokIndx = strtok(NULL, ",");
//    m4 = atoi(strtokIndx);     // convert this part to a float
    
//    strtokIndx = strtok(NULL, ","); // this continues where the previous call left off
//    ax = atof(strtokIndx);     // convert this part to an integer
//
//    strtokIndx = strtok(NULL, ",");
//    ay = atof(strtokIndx);     // convert this part to a float
//
//    strtokIndx = strtok(NULL, ",");
//    az = atof(strtokIndx);     // convert this part to a float

}

//============

void showParsedData() {
    Serial.print("M1 ");
    Serial.print(m1);
    Serial.print("M2 ");
    Serial.print(m2);
    Serial.print("M3 ");
    Serial.print(m3);
    Serial.print("M4 ");
    Serial.print(m4);
    Serial.print("Ax ");
    Serial.print(ax);
    Serial.print("Ay ");
    Serial.print(ay);
    Serial.print("Az ");
    Serial.println(az);
}
