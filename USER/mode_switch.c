#include "mode_switch.h"

mode MODE;

void mode_init(void)
{
    Mode0();
}

void Mode0(void)//
{
    MODE.VC_Set = 75;
    
    MODE.DC_PID_P_COEF = 21;
    MODE.DC_P_MIN = 500;
    MODE.DC_P_MAX = 3000;
    MODE.DC_PID_D = 45;
    MODE.DC_Out_MAX = 2500;

}
