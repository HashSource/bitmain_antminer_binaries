
/* WARNING: Unknown calling convention */

void set_block_header_version(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002e0b8;
  *(uint *)(*(int *)(DAT_0002e0b4 + 0x8d4) + 0x130) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e0bc != '\0' || (*DAT_0002e0c0 != '\0')) || (6 < *DAT_0002e0c4)))) {
    snprintf(tmp42,0x800,DAT_0002e0c8,DAT_0002e0cc,value);
    _applog(7,tmp42,false);
  }
  get_block_header_version();
  return;
}

