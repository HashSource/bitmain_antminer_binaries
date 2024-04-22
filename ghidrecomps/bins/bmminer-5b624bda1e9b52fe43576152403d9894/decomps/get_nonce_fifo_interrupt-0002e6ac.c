
/* WARNING: Unknown calling convention */

int get_nonce_fifo_interrupt(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002e6f8 + 0x8d4) + 0x1c);
  if ((*DAT_0002e6fc != '\0') &&
     (((*DAT_0002e700 != '\0' || (*DAT_0002e704 != '\0')) || (6 < *DAT_0002e708)))) {
    snprintf(tmp42,0x800,DAT_0002e70c,DAT_0002e710,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

