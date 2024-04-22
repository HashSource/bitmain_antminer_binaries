
/* WARNING: Unknown calling convention */

int get_block_header_version(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002e048 + 0x8d4) + 0x130);
  if ((*DAT_0002e04c != '\0') &&
     (((*DAT_0002e050 != '\0' || (*DAT_0002e054 != '\0')) || (6 < *DAT_0002e058)))) {
    snprintf(tmp42,0x800,DAT_0002e05c,DAT_0002e060,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

