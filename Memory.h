/*
 * memory.h
 *
 *  Created on: 10 maj 2016
 *      Author: pojo
 */

#ifndef MEMORY_H_
#define MEMORY_H_

#include "SPI_own.h"

unsigned short page_counter;
unsigned short array_counter;
unsigned short arr_data[256];
int max_number_of_pages;// Antal "pages" i minnet som man kan skriva till (1 page = 256 bytes)

void memoryInit(SPI_Handle handle, int max_pages);
void memorySendStorage(SPI_Handle handle);
void memoryStoreData(SPI_Handle handle, unsigned char* data);

#endif /* MEMORY_H_ */
