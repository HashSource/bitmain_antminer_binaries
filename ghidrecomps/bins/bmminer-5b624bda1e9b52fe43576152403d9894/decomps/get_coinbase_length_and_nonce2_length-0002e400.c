
/* WARNING: Unknown calling convention */

int get_coinbase_length_and_nonce2_length(void)

{
  int iVar1;
  char tmp42 [2048];
  
  iVar1 = *(int *)(*(int *)(DAT_0002e450 + 0x8d4) + 0x104);
  if ((*DAT_0002e454 != '\0') &&
     (((*DAT_0002e458 != '\0' || (*DAT_0002e45c != '\0')) || (6 < *DAT_0002e460)))) {
    snprintf(tmp42,0x800,DAT_0002e464,DAT_0002e468,iVar1);
    _applog(7,tmp42,false);
  }
  return iVar1;
}

