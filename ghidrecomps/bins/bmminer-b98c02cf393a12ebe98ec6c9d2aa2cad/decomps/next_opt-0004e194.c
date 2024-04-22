
byte * next_opt(int param_1,uint *param_2,int *param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte **ppbVar5;
  uint uVar6;
  byte *pbVar7;
  
  uVar6 = *param_2;
  if (uVar6 < opt_count) {
    do {
      ppbVar5 = (byte **)(opt_table + uVar6 * 0x1c);
      if (ppbVar5[1] != (byte *)0x8) {
        if (param_1 == 0) {
          pbVar7 = *ppbVar5;
          iVar2 = 0;
          pbVar3 = pbVar7;
          goto LAB_0004e1fa;
        }
        pbVar3 = (byte *)next_name(param_1,param_3,ppbVar5,uVar6,param_4);
        if (pbVar3 != (byte *)0x0) {
          return pbVar3;
        }
        uVar6 = *param_2;
        param_1 = 0;
      }
      uVar6 = uVar6 + 1;
      *param_2 = uVar6;
    } while (uVar6 < opt_count);
  }
  return (byte *)0x0;
  while (iVar2 = iVar4 + 1, bVar1 != 0x3d && bVar1 != 0x7c) {
LAB_0004e1fa:
    iVar4 = iVar2;
    pbVar3 = pbVar3 + 1;
    bVar1 = *pbVar3;
    if ((bVar1 & 0xdf) == 0) break;
  }
  *param_3 = iVar4;
  return pbVar7 + 1;
}

