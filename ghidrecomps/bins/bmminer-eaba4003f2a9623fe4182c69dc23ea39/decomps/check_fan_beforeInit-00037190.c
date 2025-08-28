
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void check_fan_beforeInit(void)

{
  int iVar1;
  byte bVar2;
  bool bVar3;
  char tmp42 [2048];
  char logstr [256];
  uint fan_speed;
  uchar fan_id;
  int j;
  int i;
  
  fan_id = '\0';
  for (j = 0; j < 2; j = j + 1) {
    for (i = 0; i < 8; i = i + 1) {
      iVar1 = get_fan_speed(&fan_id,&fan_speed);
      if (iVar1 != -1) {
        dev->fan_speed_value[fan_id] = fan_speed * 0x78;
        if ((fan_speed == 0) || (dev->fan_exist[fan_id] != '\0')) {
          if ((fan_speed == 0) && (dev->fan_exist[fan_id] == '\x01')) {
            dev->fan_exist[fan_id] = '\0';
            dev->fan_num = dev->fan_num + 0xff;
            iVar1 = 1 << fan_id;
            bVar3 = iVar1 != 0;
            if (bVar3) {
              iVar1 = 0;
            }
            bVar2 = (byte)iVar1;
            if (!bVar3) {
              bVar2 = 1;
            }
            dev->fan_exist_map = (uint)bVar2 & dev->fan_exist_map;
          }
        }
        else {
          dev->fan_exist[fan_id] = '\x01';
          dev->fan_num = dev->fan_num + '\x01';
          dev->fan_exist_map = 1 << fan_id | dev->fan_exist_map;
        }
        if ((dev->fan_exist[fan_id] == '\x01') && (check_fan_beforeInit::print_num < 100)) {
          check_fan_beforeInit::print_num = check_fan_beforeInit::print_num + 1;
          if ((use_syslog != false) || ((opt_log_output != false || (4 < opt_log_level)))) {
            snprintf(tmp42,0x800,"get fan[%d] speed=%d\n",(uint)fan_id,dev->fan_speed_value[fan_id])
            ;
            _applog(5,tmp42,false);
          }
          if ((99 < check_fan_beforeInit::print_num) &&
             (((use_syslog != false || (opt_log_output != false)) || (4 < opt_log_level)))) {
            builtin_strncpy(tmp42,"Fatal Error: some Fan lost or Fan speed low!",0x2c);
            tmp42[0x2c] = '\n';
            tmp42[0x2d] = '\0';
            _applog(5,tmp42,false);
          }
        }
        if (dev->fan_speed_top1 < dev->fan_speed_value[fan_id]) {
          dev->fan_speed_top1 = dev->fan_speed_value[fan_id];
        }
        if (((dev->fan_speed_value[fan_id] < dev->fan_speed_low1) &&
            (dev->fan_speed_value[fan_id] != 0)) || (dev->fan_speed_low1 == 0)) {
          dev->fan_speed_low1 = dev->fan_speed_value[fan_id];
        }
      }
    }
  }
  return;
}

