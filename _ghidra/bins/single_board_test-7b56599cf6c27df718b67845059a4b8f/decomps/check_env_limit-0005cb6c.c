
/* WARNING: Unknown calling convention */

int check_env_limit(void)

{
  int iVar1;
  char time_stamp [48];
  char tmp1 [256];
  int32_t temp;
  
  iVar1 = pf_get_max_value(g_rt.tempval,((g_rt.config)->board).sensor.sensor_num);
  if (iVar1 < 0x3e) {
    iVar1 = 0;
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : temp:%d over than:%d,exit sweep.\n","check_env_limit",iVar1,0x3d);
    snprintf(tmp1,0x100,"temp:%d over than:%d,exit sweep.",iVar1,0x3d);
    log_to_file(tmp1,time_stamp);
    iVar1 = -1;
  }
  return iVar1;
}

