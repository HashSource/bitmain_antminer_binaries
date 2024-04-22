
/* WARNING: Unknown calling convention */

int get_merkle_bin_number(void)

{
  uint uVar1;
  char tmp42 [2048];
  
  uVar1 = (uint)*(ushort *)(*(int *)(DAT_0002e620 + 0x8d4) + 0x114);
  if ((*DAT_0002e624 != '\0') &&
     (((*DAT_0002e628 != '\0' || (*DAT_0002e62c != '\0')) || (6 < *DAT_0002e630)))) {
    snprintf(tmp42,0x800,DAT_0002e634,DAT_0002e638,uVar1);
    _applog(7,tmp42,false);
  }
  return uVar1;
}

