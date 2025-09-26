
/* WARNING: Unknown calling convention */

_Bool enable_power_calibration(void)

{
  int32_t iVar1;
  char time_stamp [48];
  char tmp1 [256];
  _Bool is_calibrated;
  int32_t ret;
  char *sn;
  
  is_calibrated = false;
  sn = bitmain_power_get_sn();
  if (sn == (char *)0x0) {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : can not get power sn:\n","enable_power_calibration");
    builtin_strncpy(tmp1,"can not get power sn:",0x16);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : power sn:%s\n","enable_power_calibration",sn);
    snprintf(tmp1,0x100,"power sn:%s",sn);
    log_to_file(tmp1,time_stamp);
  }
  ret = bitmain_power_is_calibrated(&is_calibrated);
  if ((ret == 0) && (is_calibrated != false)) {
    bitmain_power_set_is_use_calibration_data(true);
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    iVar1 = bitmain_power_get_calibration_date();
    printf("%s : enable_power_calibration,calibration date:%d.\n","enable_power_calibration",iVar1);
    iVar1 = bitmain_power_get_calibration_date();
    snprintf(tmp1,0x100,"enable_power_calibration,calibration date:%d.",iVar1);
    log_to_file(tmp1,time_stamp);
  }
  else {
    print_time_stamp(time_stamp,0x30);
    printf("%s ",time_stamp);
    printf("%s : warning:power is not calibration.\n","enable_power_calibration");
    builtin_strncpy(tmp1,"warning:power is not calibration",0x20);
    tmp1[0x20] = '.';
    tmp1[0x21] = '\0';
    log_to_file(tmp1,time_stamp);
  }
  return is_calibrated;
}

