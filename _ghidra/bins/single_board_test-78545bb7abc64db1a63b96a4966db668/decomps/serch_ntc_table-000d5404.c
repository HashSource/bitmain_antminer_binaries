
/* WARNING: Unknown calling convention */

int serch_ntc_table(int ntc)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  iVar1 = 0;
  while( true ) {
    iVar2 = iVar1 + 1;
    if ((NTC_TABLE[iVar1][0] <= ntc) && (ntc < NTC_TABLE[iVar3][0])) break;
    iVar3 = iVar3 + 1;
    iVar1 = iVar2;
    if (iVar2 == 0x97) {
      return 0x7d;
    }
  }
  return (int)NTC_TABLE[iVar1][1];
}

