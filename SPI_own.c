/*
 * SPI_own.c
 *
 *  Created on: 10 maj 2016
 *      Author: pojo
 */

#include "SPI_own.h"
#include "stdlib.h"

void SPIInitTest(handle){
    //Assert_isTrue(params != NULL, NULL);

    unsigned int spiBitRate = 1000000;
    SPI_FrameFormat spiFrameFormat = SPI_POL0_PHA0;
    /* Logical peripheral number indexed
       into the SPI_config table */
    unsigned int spiIndex = 0; // =?
	/* Initialize SPI parameters. Master mode, blocking mode
     * and dataSize=8 is default and should not be changed.
     * The other parameters can be set from LCD parameters.
     */
	SPI_Params spiParams;
	SPI_Params_init(&spiParams);
	spiParams.bitRate = spiBitRate;
	spiParams.frameFormat = spiFrameFormat;

	/* Try open the SPI */
	handle = SPI_open(spiIndex, &spiParams);
	if (!handle)
	{
		return (NULL);
	}
}

bool SPISendCommand(SPI_Handle handle, unsigned short command, unsigned short* pAdrr){
	unsigned short usLen = 1;
	unsigned short* pcData;
	if(pAdrr != NULL){
		pcData = (unsigned short *)malloc (4 * sizeof(unsigned short));//{command, pAdrr[0], pAdrr[1], pAdrr[2]};
		pcData[0] = command;
		pcData[1] = pAdrr[0];
		pcData[2] = pAdrr[1];
		pcData[3] = pAdrr[2];
		usLen = 4;
	}
	else{
		pcData = (unsigned short *)malloc (sizeof(unsigned short));//{command, pAdrr[0], pAdrr[1], pAdrr[2]};
		pcData[0] = command;
	}
	SPI_Transaction spiTransaction;
	spiTransaction.arg = NULL;
	spiTransaction.count = usLen;
	spiTransaction.txBuf = (Ptr)pcData;
	spiTransaction.rxBuf = NULL;

	bool ret = SPI_transfer(handle, &spiTransaction);
	free(pcData);
	if(ret == false){
		return false;
	}
	return true;
}

bool SPI_sendArray(SPI_Handle handle, unsigned short *pcData, unsigned short usLen, int page){
    /* Do SPI transfer */
	SPI_Transaction spiTransaction;
    spiTransaction.arg = NULL;
    spiTransaction.count = usLen;
    spiTransaction.txBuf = (Ptr)pcData;
    spiTransaction.rxBuf = NULL;

    bool ret = SPI_transfer(handle, &spiTransaction);
    if(ret == false){
        return false;
    }

    /* return... */
    return true;
}

char* SPI_receiveArray(SPI_Handle handle, unsigned short usLen){
    char* pcData;
	/* Do SPI transfer */
    SPISendCommand(handle, 0x06, NULL);

    SPI_Transaction spiTransaction;
    spiTransaction.arg = NULL;
    spiTransaction.count = usLen;
    spiTransaction.txBuf = NULL;
    spiTransaction.rxBuf = (Ptr)pcData;

    bool ret = SPI_transfer(handle, &spiTransaction);
    if(ret == false){
        //return false;// Fel, lös det
    }

    /* return... */
    return pcData;
}
