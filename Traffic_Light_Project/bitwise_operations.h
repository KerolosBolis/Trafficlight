#ifndef  BITWISE_OPERATIONS_H_
#define BITWISEOPERATIONS_H_


#define SET_BIT(REG,BIT)    (REG|=(1<<BIT))
#define TOOGLE_BIT(REG,BIT) (REG^=(1<<BIT))
#define CLEAR_BIT(REG,BIT)  (REG&=~(1<<BIT))
#define GET_BIT(REG,BIT)    ((REG>>BIT)&1)
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )
#define BIT_IS_CLEAR(REG,BIT) ( !(REG & (1<<BIT)) )
#endif