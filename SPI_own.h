/*
 * SPI_own.h
 *
 *  Created on: 10 maj 2016
 *      Author: pojo
 */

#ifndef SPI_OWN_H_
#define SPI_OWN_H_

#include <ti/drivers/SPI.h>
#include <ti/sysbios/BIOS.h>

void SPIInitTest();
bool SPISendCommand(SPI_Handle handle, unsigned short command, unsigned short* pAdrr);
bool SPI_sendArray(SPI_Handle handle, unsigned short *pcData, unsigned short usLen, int page);
char* SPI_receiveArray(SPI_Handle handle, unsigned short usLen);

#endif /* SPI_OWN_H_ */
