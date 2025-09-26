
/* WARNING: Unknown calling convention */

int32_t fan_get_realtime_speed(bitmain_fan_id_e id)

{
  int iVar1;
  uint32_t speed;
  uint32_t ver;
  
  speed = 0;
  iVar1 = 6;
  fpga_read(0,&ver);
  ver = ver & 0xffff;
  do {
    fpga_read(1,&speed);
    if ((speed << 0x15) >> 0x1d == id) {
      if (ver == 0xb025) {
        iVar1 = (speed & 0xff) * 0xf0;
      }
      else {
        iVar1 = (speed & 0xff) * 0x78;
      }
      return iVar1;
    }
    usleep(10000);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return -1;
}

