/*
 * ADC.c
 *
 *  Created on: 11 maj 2016
 *      Author: pojo
 */
#include "ADC.h"

void readADC(SPI_Handle handle){
	int i;
	for(i = 0; i < 4; i++){
		unsigned short data[2];
		//Hämta data från adc
		AUXADCGenManualTrigger();

		memoryStoreData(handle, data);//insert data istället för 5
	}
}


