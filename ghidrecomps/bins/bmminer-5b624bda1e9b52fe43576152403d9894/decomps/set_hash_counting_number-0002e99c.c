
/* WARNING: Unknown calling convention */

void set_hash_counting_number(uint value)

{
  char cVar1;
  char tmp42 [2048];
  
  cVar1 = *DAT_0002e9f0;
  *(uint *)(*(int *)(DAT_0002e9ec + 0x8d4) + 0x90) = value;
  if ((cVar1 != '\0') &&
     (((*DAT_0002e9f4 != '\0' || (*DAT_0002e9f8 != '\0')) || (6 < *DAT_0002e9fc)))) {
    snprintf(tmp42,0x800,DAT_0002ea00,DAT_0002ea04,value);
    _applog(7,tmp42,false);
  }
  get_hash_counting_number();
  return;
}

