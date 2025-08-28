
byte * first_opt(uint *param_1,int *param_2)

{
  int *piVar1;
  byte bVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  
  *param_1 = 0;
  if (opt_count == 0) {
    return (byte *)0x0;
  }
  puVar6 = opt_table;
  if (opt_table[1] == 8) {
    uVar9 = 1;
    puVar3 = opt_table;
    do {
      puVar6 = puVar3 + 7;
      *param_1 = uVar9;
      if (opt_count <= uVar9) {
        return (byte *)0x0;
      }
      piVar1 = puVar3 + 8;
      uVar9 = uVar9 + 1;
      puVar3 = puVar6;
    } while (*piVar1 == 8);
  }
  pbVar5 = (byte *)*puVar6;
  iVar4 = 0;
  pbVar8 = pbVar5;
  do {
    iVar7 = iVar4;
    pbVar8 = pbVar8 + 1;
    bVar2 = *pbVar8;
    if ((bVar2 & 0xdf) == 0) break;
    iVar4 = iVar7 + 1;
  } while (bVar2 != 0x3d && bVar2 != 0x7c);
  *param_2 = iVar7;
  return pbVar5 + 1;
}

