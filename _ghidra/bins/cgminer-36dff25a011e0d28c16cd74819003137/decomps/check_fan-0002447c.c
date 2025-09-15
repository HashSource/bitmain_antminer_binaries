
/* WARNING: Unknown calling convention */

_Bool check_fan(void)

{
  int iVar1;
  uint fan_speed;
  uchar fan_id;
  FILE *pFile;
  int i;
  
  fan_id = '\0';
  dev->fan_speed_top1 = 0;
  dev->fan_speed_low1 = 0;
  i = 0;
  do {
    if (7 < i) {
      return true;
    }
    iVar1 = get_fan_speed(&fan_id,&fan_speed);
    if (iVar1 != -1) {
      dev->fan_speed_value[fan_id] = fan_speed * 0x78;
      if ((fan_speed == 0) || (dev->fan_exist[fan_id] != '\0')) {
        if ((fan_speed == 0) && (dev->fan_exist[fan_id] == '\x01')) {
          dev->fan_exist[fan_id] = '\0';
          dev->fan_num = dev->fan_num + 0xff;
          dev->fan_exist_map = dev->fan_exist_map & ~(1 << fan_id);
        }
      }
      else {
        dev->fan_exist[fan_id] = '\x01';
        dev->fan_num = dev->fan_num + '\x01';
        dev->fan_exist_map = dev->fan_exist_map | 1 << fan_id;
      }
      if (dev->fan_speed_top1 < dev->fan_speed_value[fan_id]) {
        dev->fan_speed_top1 = dev->fan_speed_value[fan_id];
      }
      if (((dev->fan_speed_value[fan_id] < dev->fan_speed_low1) &&
          (dev->fan_speed_value[fan_id] != 0)) || (dev->fan_speed_low1 == 0)) {
        dev->fan_speed_low1 = dev->fan_speed_value[fan_id];
      }
      if ((dev->fan_speed_value[fan_id] < 0x1f5) && (dev->fan_exist[fan_id] == '\x01')) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile = (FILE *)fopen(log_file,"a+");
          if (pFile != (FILE *)0x0) {
            fprintf((FILE *)pFile,"%s:%d:%s: check FAN Speed Error: fan[%d] speed=%d\n",
                    "driver-btm-soc.c",0x582,"check_fan",(uint)fan_id,dev->fan_speed_value[fan_id]);
          }
          fclose((FILE *)pFile);
        }
        return false;
      }
    }
    i = i + 1;
  } while( true );
}

