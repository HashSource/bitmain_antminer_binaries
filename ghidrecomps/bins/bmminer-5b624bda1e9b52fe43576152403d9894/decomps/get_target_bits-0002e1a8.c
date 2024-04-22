
/* WARNING: Unknown calling convention */

int get_target_bits(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002e1f8 + 0x8d4) + 0x138);
  if ((*DAT_0002e1fc != '\0') &&
     (((*DAT_0002e200 != '\0' || (*DAT_0002e204 != '\0')) || (6 < *DAT_0002e208)))) {
    snprintf(tmp42,0x800,DAT_0002e20c,DAT_0002e210,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

