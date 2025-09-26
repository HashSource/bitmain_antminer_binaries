
/* WARNING: Unknown calling convention */

int serch_ntc_table(int ntc)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0xb;
  iVar2 = 1;
  while ((ntc < iVar1 || (NTC_TABLE[iVar2][0] <= ntc))) {
    if (iVar2 == 0x97) {
      return 0x7d;
    }
    iVar1 = (int)NTC_TABLE[iVar2][0];
    iVar2 = iVar2 + 1;
  }
  return (int)NTC_TABLE[iVar2 + -1][1];
}

