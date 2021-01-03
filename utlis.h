/*
 * utlis.h
 *
 * Created: 12/1/2020 11:20:27 AM
 *  Author: Ahmed Ashraf
 */ 


#ifndef UTLIS_H_
#define UTLIS_H_


#define SET_BIT(VAR,BIT)          VAR |=  (1 << (BIT))
#define CLR_BIT(VAR,BIT)          VAR &= ~(1 << (BIT))
#define GET_BIT(VAR,BIT)          ((VAR >> BIT) & 1  )
#define TOG_BIT(VAR,BIT)          VAR ^=  (1 << (BIT))


#endif /* UTLIS_H_ */