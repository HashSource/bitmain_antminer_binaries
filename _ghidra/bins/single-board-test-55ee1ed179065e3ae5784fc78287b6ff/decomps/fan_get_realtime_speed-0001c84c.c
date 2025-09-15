
int fan_get_realtime_speed(uint param_1)

{
  uint local_10;
  int local_c;
  
  local_10 = 0;
  local_c = 0;
  while( true ) {
    if (5 < local_c) {
      return -1;
    }
    if (platform_is_t9 == 0) {
      fpga_read(v9_fpga_map._4_4_,&local_10);
    }
    else {
      fpga_read(DAT_00035554,&local_10);
    }
    printf("%s:%d","fan_get_realtime_speed",0x20);
    printf("FAN_SPEED fpga value = 0x%x\n",local_10);
    if ((local_10 >> 8 & 7) == param_1) break;
    usleep(10000);
    local_c = local_c + 1;
  }
  return (local_10 & 0xff) * 0x78;
}

