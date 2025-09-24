
/* WARNING: Unknown calling convention */

_Bool fan_speed_check(void)

{
  int32_t iVar1;
  char time_stamp [48];
  char tmp1 [256];
  int speed [4];
  int i;
  int fan_speed;
  int fan_state;
  int time;
  
  time = 0;
  do {
    fan_state = 0;
    fan_speed = 0;
    memset(speed,0,0x10);
    for (i = 0; i < 4; i = i + 1) {
      iVar1 = fan_get_realtime_speed(i);
      speed[i] = iVar1;
      if (speed[i] == -1) break;
      fan_speed = speed[i] + fan_speed;
      if (5000 < speed[i]) {
        fan_state = fan_state + 1;
      }
    }
    if ((fan_state == 4) && ((Local_Config_Information->Test_Info).Fan.Fan_Limit <= (uint)fan_speed)
       ) {
      return true;
    }
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : fan speed:[%d][%d][%d][%d],%d<%d\n","fan_speed_check",speed[0],speed[1],speed[2],
           speed[3],fan_speed,(Local_Config_Information->Test_Info).Fan.Fan_Limit);
    snprintf(tmp1,0x100,"fan speed:[%d][%d][%d][%d],%d<%d",speed[0],speed[1],speed[2],speed[3],
             fan_speed,(Local_Config_Information->Test_Info).Fan.Fan_Limit);
    log_to_file(tmp1,time_stamp);
    sleep(1);
    time = time + 1;
    if (0x2d < time) {
      return false;
    }
  } while( true );
}

