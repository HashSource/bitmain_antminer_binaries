
/* WARNING: Unknown calling convention */

void set_target_bits(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002e268;
  *(uint *)(*(int *)(DAT_0002e264 + 0x8d4) + 0x138) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e26c != '\0' || (*DAT_0002e270 != '\0')) || (6 < *DAT_0002e274)))) {
    snprintf(tmp42,0x800,DAT_0002e278,DAT_0002e27c,value);
    _applog(7,tmp42,false);
  }
  get_target_bits();
  return;
}

