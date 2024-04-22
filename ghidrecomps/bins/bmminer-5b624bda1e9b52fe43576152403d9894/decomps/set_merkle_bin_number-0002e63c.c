
/* WARNING: Unknown calling convention */

void set_merkle_bin_number(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002e694;
  *(uint *)(*(int *)(DAT_0002e690 + 0x8d4) + 0x114) = value & 0xffff;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e698 != '\0' || (*DAT_0002e69c != '\0')) || (6 < *DAT_0002e6a0)))) {
    snprintf(tmp42,0x800,DAT_0002e6a4,DAT_0002e6a8,value & 0xffff);
    _applog(7,tmp42,false);
  }
  get_merkle_bin_number();
  return;
}

