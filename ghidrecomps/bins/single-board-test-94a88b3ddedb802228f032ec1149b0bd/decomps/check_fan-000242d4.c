
undefined4 check_fan(void)

{
  int iVar1;
  int local_28;
  byte local_21;
  FILE *local_20;
  FILE *local_1c;
  FILE *local_18;
  FILE *local_14;
  int local_10;
  int local_c;
  
  local_c = 0;
  local_21 = 0;
  local_10 = 0;
  do {
    if (1 < local_10) {
      if (3 < log_level) {
        local_20 = fopen(log_file,"a+");
        if (local_20 != (FILE *)0x0) {
          fprintf(local_20,"%s:%d: check FAN ERROR: fan num=%d , ought to be %d\n",
                  "driver-bitmain.c",0x1c0e,fan_num,2);
        }
        fclose(local_20);
      }
      return 0;
    }
    for (local_c = 0; local_c < 8; local_c = local_c + 1) {
      iVar1 = get_fan_speed(&local_21,&local_28);
      if (iVar1 != -1) {
        *(int *)(fan_speed_value + (uint)local_21 * 4) = local_28 * 0x78;
        if ((local_28 == 0) || (*(char *)((int)&fan_exist + (uint)local_21) != '\0')) {
          if ((local_28 == 0) && (*(char *)((int)&fan_exist + (uint)local_21) == '\x01')) {
            *(undefined *)((int)&fan_exist + (uint)local_21) = 0;
            fan_num = fan_num + -1;
          }
        }
        else {
          *(undefined *)((int)&fan_exist + (uint)local_21) = 1;
          fan_num = fan_num + 1;
        }
        if ((*(uint *)(fan_speed_value + (uint)local_21 * 4) < 3000) &&
           (*(char *)((int)&fan_exist + (uint)local_21) == '\x01')) {
          if (3 < log_level) {
            local_1c = fopen(log_file,"a+");
            if (local_1c != (FILE *)0x0) {
              fprintf(local_1c,"%s:%d: check FAN Speed Error: fan[%d] speed=%d\n","driver-bitmain.c"
                      ,0x1bfb,(uint)local_21,*(undefined4 *)(fan_speed_value + (uint)local_21 * 4));
            }
            fclose(local_1c);
          }
          return 0;
        }
        if ((*(char *)((int)&fan_exist + (uint)local_21) == '\x01') && (3 < log_level)) {
          local_18 = fopen(log_file,"a+");
          if (local_18 != (FILE *)0x0) {
            fprintf(local_18,"%s:%d: check FAN Speed: fan[%d] speed=%d\n","driver-bitmain.c",0x1c01,
                    (uint)local_21,*(undefined4 *)(fan_speed_value + (uint)local_21 * 4));
          }
          fclose(local_18);
        }
      }
    }
    if (1 < fan_num) {
      if (3 < log_level) {
        local_14 = fopen(log_file,"a+");
        if (local_14 != (FILE *)0x0) {
          fprintf(local_14,"%s:%d: check FAN OK: fan num=%d\n","driver-bitmain.c",0x1c08,fan_num);
        }
        fclose(local_14);
      }
      return 1;
    }
    local_10 = local_10 + 1;
  } while( true );
}

