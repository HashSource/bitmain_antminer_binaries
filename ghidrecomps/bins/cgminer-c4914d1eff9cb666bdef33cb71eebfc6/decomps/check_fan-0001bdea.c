
/* WARNING: Unknown calling convention */

int check_fan(void)

{
  all_parameters *paVar1;
  int iVar2;
  uint fan_speed;
  uchar fan_id;
  FILE *pFile;
  FILE *pFile_1;
  int i;
  
  paVar1 = dev;
  fan_id = '\0';
  *(undefined *)&dev->fan_speed_top1 = 0;
  *(undefined *)((int)&paVar1->fan_speed_top1 + 1) = 0;
  *(undefined *)((int)&paVar1->fan_speed_top1 + 2) = 0;
  *(undefined *)((int)&paVar1->fan_speed_top1 + 3) = 0;
  paVar1 = dev;
  *(undefined *)&dev->fan_speed_low1 = 0;
  *(undefined *)((int)&paVar1->fan_speed_low1 + 1) = 0;
  *(undefined *)((int)&paVar1->fan_speed_low1 + 2) = 0;
  *(undefined *)((int)&paVar1->fan_speed_low1 + 3) = 0;
  i = 0;
  do {
    if (7 < i) {
      if (4 < log_level) {
        print_crt_time_to_file(log_file,4);
        pFile_1 = (FILE *)fopen(log_file,"a+");
        if (pFile_1 != (FILE *)0x0) {
          fprintf((FILE *)pFile_1,"%s:%d:%s: fan num = %d\n","driver-btm-soc.c",0x402,"check_fan",
                  (uint)dev->fan_num);
        }
        fclose((FILE *)pFile_1);
      }
      return (uint)dev->fan_num;
    }
    iVar2 = get_fan_speed(&fan_id,&fan_speed);
    if (iVar2 != -1) {
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
      if ((dev->fan_speed_value[fan_id] < 500) && (dev->fan_exist[fan_id] == '\x01')) {
        if (3 < log_level) {
          print_crt_time_to_file(log_file,3);
          pFile = (FILE *)fopen(log_file,"a+");
          if (pFile != (FILE *)0x0) {
            fprintf((FILE *)pFile,"%s:%d:%s: check FAN Speed Error: fan[%d] speed=%d\n",
                    "driver-btm-soc.c",0x3fd,"check_fan",(uint)fan_id,dev->fan_speed_value[fan_id]);
          }
          fclose((FILE *)pFile);
        }
        return -1;
      }
    }
    i = i + 1;
  } while( true );
}

