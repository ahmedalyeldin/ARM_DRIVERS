/*
 * STK_inteface.h
 *
 *  Created on: 10-Feb-2021
 *      Author: ahmed
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

void 	STK_voidInit(void);
void 	STK__delay_us(u32 Copy_u32Ticks);
void 	STK_voidIntervalSingle(u32 Copy_u32Ticks,void (*copy_pf)(void));
void 	STK_voidIntervalPeriodic(u32 Copy_u32Ticks,void (*copy_pf)(void));
void 	STK_voidStopInternal(void);
u32		STK_u32GetCounts(void);
u32 	STK_u32GetRemainingTime(void);
/*
void	STK_voidEnableSTK(void);
void	STK_voidEnbaleInterrupt(void);
*/

#endif /* STK_INTERFACE_H_ */
