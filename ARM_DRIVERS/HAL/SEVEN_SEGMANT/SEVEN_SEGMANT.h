/*
 * 7SEGMANT.h
 *
 *  Created on: Feb 6, 2021
 *      Author: ahmedalyeldin
 */

#ifndef SEVEN_SEGMANT_H_
#define SEVEN_SEGMANT_H_

#define Comm_Anode   0
#define Comm_Cathode 1
#define Single       0
#define Multiplexed  1

#define SEGMENT_PORT     DIO_U8_PORTA
#define ENABLE_PORT1     DIO_U8_PORTA
#define ENABLE_PIN1      DIO_U8_PIN7
#define ENABLE_PORT2	 DIO_U8_PORTA
#define ENABLE_PIN2      DIO_U8_PIN8
#define SEGMANT_COMMON   Comm_Cathode
#define SEGMANT_TYPE     Single

void SEVENSEGMENT_print(int number);


#endif /* SEVEN_SEGMANT_H_ */
