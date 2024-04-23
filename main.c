#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>
typedef int INT;
typedef double DOUBLE;
typedef char CHAR;

typedef enum
{
    TEMPERATURE,
    PRESSURE
}Sensor;

typedef struct 
{
    INT ELEMENT;
    INT ID;
    DOUBLE TEMP;
    DOUBLE VALUE_PRESSURE;

}DATA_T;


void process(Sensor sensor,...)
{
    DATA_T data;
    va_list args;
    va_start(args,sensor);
    switch (sensor)
    {
        case TEMPERATURE:
        {
            data.ELEMENT=va_arg(args,INT);
            data.ID=va_arg(args,INT);
            data.TEMP=va_arg(args,DOUBLE);
            printf("id:= %d and value := %f\n",data.ID,data.TEMP);
            
            if(data.ELEMENT > 2)
            {
                CHAR *message = va_arg(args,char *);
                printf("message := %s\n",message);
            } 
            break;
        }
        case PRESSURE:
        {
            data.ELEMENT=va_arg(args,INT);
            data.ID=va_arg(args,INT);
            data.VALUE_PRESSURE=va_arg(args,DOUBLE);
            printf("id:= %d and value := %f\n",data.ID,data.VALUE_PRESSURE);
            
            if(data.ELEMENT > 2)
            {
                CHAR *message = va_arg(args,char *);
                printf("message := %s\n",message);
            } 
            break;
        }       
    }


    va_end(args);
}


int main(void)
{
    process(TEMPERATURE,3,1,2.45,"warning");
    process(PRESSURE,2,2,1024.2444);
    
    return 0;
}