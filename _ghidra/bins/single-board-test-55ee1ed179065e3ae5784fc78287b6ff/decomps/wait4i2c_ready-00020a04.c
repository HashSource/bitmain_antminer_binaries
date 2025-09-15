
undefined4 wait4i2c_ready(void)

{
  char cVar1;
  uint uVar2;
  int local_10;
  uint local_c;
  
  local_10 = 0;
  local_c = 0;
  do {
    if (platform_is_t9 == 0) {
      fpga_read(v9_fpga_map._44_4_,&local_10);
    }
    else {
      fpga_read(DAT_0003557c,&local_10);
    }
    if (local_10 < 0) {
      return 1;
    }
    usleep(5000);
    uVar2 = local_c;
    if (0x13 < local_c) {
      uVar2 = 0;
    }
    cVar1 = (char)uVar2;
    if (local_c < 0x14) {
      cVar1 = '\x01';
    }
    local_c = local_c + 1;
  } while (cVar1 != '\0');
  return 0;
}

