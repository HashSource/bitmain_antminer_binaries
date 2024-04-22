
/* WARNING: Unknown calling convention */

int get_fan_speed(uchar *fan_id,uint *fan_speed)

{
  uint uVar1;
  char tmp42 [2048];
  
  uVar1 = *(uint *)(*(int *)(DAT_0002da98 + 0x8d4) + 4);
  *fan_speed = uVar1 & 0xff;
  *fan_id = (byte)((uVar1 << 0x15) >> 0x1d);
  if (((*fan_speed != 0) && (*DAT_0002da9c != '\0')) &&
     ((*DAT_0002daa0 != '\0' || ((*DAT_0002daa4 != '\0' || (6 < *DAT_0002dab0)))))) {
    snprintf(tmp42,0x800,DAT_0002daa8,DAT_0002daac,(uVar1 << 0x15) >> 0x1d,*fan_speed);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

