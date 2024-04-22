
/* WARNING: Unknown calling convention */

int get_hash_counting_number(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002e980 + 0x8d4) + 0x90);
  if ((*DAT_0002e984 != '\0') &&
     (((*DAT_0002e988 != '\0' || (*DAT_0002e98c != '\0')) || (6 < *DAT_0002e990)))) {
    snprintf(tmp42,0x800,DAT_0002e994,DAT_0002e998,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

