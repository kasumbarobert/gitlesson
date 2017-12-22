#include <stdio.h>
#include <string.h>
#define DATE_10M 0
#define TIME_10M 1
#define TIMESTAMP_10M 2
#define GW_LAT_10M 3
#define GW_LONG_10M 4
#define V_MCU_10M 5
#define V_IN_10M 6
#define V_A1_10M 7
#define V_A2_10M 8
#define V_A3_10M 9

#define DATE_2M 0
#define TIME_2M 1
#define TIMESTAMP_2M 2
#define GW_LAT_2M 3
#define GW_LONG_2M 4
#define V_MCU_2M 5
#define V_IN_2M 6
#define T_SHT2X_2M 7
#define RH_SHT2X_2M 8
#define TTL_2M 9
#define RSSI_2M 10
#define LQI_2M  11

#define GW_LAT_2M_KEY "GW_LAT"
#define GW_LONG_2M_KEY "GW_LON"
#define V_MCU_2M_KEY "V_MCU"
#define V_IN_2M_KEY "V_IN"
#define T_SHT2X_2M_KEY "T_SHT2X"
#define RH_SHT2X_2M_KEY "RH_SHT2X"
#define TTL_2M_KEY "TTL"
#define RSSI_2M_KEY "RSSI"
#define LQI_2M_KEY "LQI"

#define TEN_M_KEY "TXT=mak2-10m"
#define TWO_M_KEY "TXT=mak2-2m"
#define GROUND_KEY "TXT=mak2-gnd"
#define SINK_KEY "TXT=mak2-sink"
char *findKeyValue(char *substr,char *key){
    //the substring should be of the form key=value
    if(strstr(substr,key)!=NULL){
        const char equal_symbol[2]="=";
        char *token;
        token = strtok(substr,equal_symbol);
       
        if(*token==*key){
          token=strtok(NULL,equal_symbol);
          return token;
        }else{
            return NULL;
        }
        
    }else{
        return NULL;//the key is not contained in the substr
    }
}
int main(){
    printf("Hello world \n");
    char txt[]="V_IN&2.94";
    char *value =findKeyValue(txt,V_IN_2M_KEY);
    
    if(value !=NULL){
        printf("%s\n",value);
    }
    return 0;
}
