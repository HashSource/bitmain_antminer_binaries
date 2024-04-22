
/* WARNING: Unknown calling convention */

void set_time_stamp(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002e190;
  *(uint *)(*(int *)(DAT_0002e18c + 0x8d4) + 0x134) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e194 != '\0' || (*DAT_0002e198 != '\0')) || (6 < *DAT_0002e19c)))) {
    snprintf(tmp42,0x800,DAT_0002e1a0,DAT_0002e1a4,value);
    _applog(7,tmp42,false);
  }
  get_time_stamp();
  return;
}

