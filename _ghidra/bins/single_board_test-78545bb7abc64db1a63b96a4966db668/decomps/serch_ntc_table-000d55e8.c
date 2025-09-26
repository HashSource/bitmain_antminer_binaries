
/* WARNING: Unknown calling convention */

int serch_ntc_table(int ntc)

{
  int iVar1;
  
  if (ntc < 0xb) {
    return -0x1e;
  }
  if (0x5f7 < ntc) {
    return 0x7d;
  }
  iVar1 = serch_ntc_table(ntc);
  return iVar1;
}

