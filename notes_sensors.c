/* ----------------------------------------------------------------------------
 * PSD Sensors
 * ----------------------------------------------------------------------------

	PSD = Position Sensitive Device
*/

/* ----------------------------------------------------------------------------
 * Implementation of Interfaces
 * ----------------------------------------------------------------------------*/

//-------------------------------------
//EXAMPLE PSD Sensor (digital)
/*
	* out1 = VIN into PSD
	* in1 = output from PSD
*/
int psd() {
	int results = 0;

	//If PSD output (in1) == 0; !in1 == 1
	//I.e. Check for sensor readout every 100us 
	while (!in1) {
		//Wait for line to rise in us
		usleep(100);//microSecs
	}

	//Pump out the results
	//compose output data from incoming sequential bits
	//8 bits
	for (int i = 0; i < 8; i++) {
		out1 = 1;//rising edge
		usleep(200);//microSecs

		out1 = 0;//falling edge
		result = 2*result + in1; //results = (results<<1) | in1;
		usleep(200;)//microSecs
	}

	return result;
}
        
/* ----------------------------------------------------------------------------
 * API Functions
 * ----------------------------------------------------------------------------*/
 #include <eyebot.h>

//Delivers actual timestamp or distance (mm) measured by the selected PSD (int psd)
int PSDGet(int psd)

//Returns the RAW sensor reading measure by selected PSD (int psd)
int PSDGetRaw(int psd)

/* ----------------------------------------------------------------------------
 * C API examples
 * ----------------------------------------------------------------------------*/
 int sensorRead = PSDGetRaw(2);