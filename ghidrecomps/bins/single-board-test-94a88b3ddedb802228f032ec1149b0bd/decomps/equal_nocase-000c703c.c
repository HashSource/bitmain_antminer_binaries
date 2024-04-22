
uint equal_nocase(byte *param_1,uint param_2,byte *param_3,uint param_4,uint param_5)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  byte bVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  
  pbVar3 = param_1;
  if ((param_5 & 0x8000) != 0) {
    uVar1 = param_2;
    if ((param_4 < param_2) && (bVar4 = *param_1, bVar4 != 0)) {
      pbVar6 = param_1;
      if ((int)(param_5 << 0x1b) < 0) {
        do {
          pbVar5 = pbVar6 + 1;
          pbVar3 = pbVar6;
          if ((bVar4 == 0x2e) || (uVar1 = uVar1 - 1, pbVar3 = pbVar5, uVar1 <= param_4)) break;
          bVar4 = pbVar6[1];
          pbVar6 = pbVar5;
        } while (bVar4 != 0);
      }
      else {
        pbVar6 = param_1 + 1;
        do {
          uVar1 = uVar1 - 1;
          pbVar3 = pbVar6;
          if (uVar1 <= param_4) break;
          bVar4 = *pbVar6;
          pbVar6 = pbVar6 + 1;
        } while (bVar4 != 0);
      }
    }
    if (param_4 == uVar1) goto LAB_000c7076;
  }
  bVar7 = param_4 != param_2;
  param_4 = param_2;
  pbVar3 = param_1;
  if (bVar7) {
    return 0;
  }
LAB_000c7076:
  if (param_4 == 0) {
LAB_000c70b8:
    uVar1 = 1;
  }
  else {
    uVar1 = (uint)*pbVar3;
    bVar4 = *param_3;
    if (uVar1 != 0) {
      pbVar6 = pbVar3 + (param_4 - 1);
      do {
        uVar2 = (uint)bVar4;
        if (uVar1 != uVar2) {
          if (uVar1 - 0x41 < 0x1a) {
            uVar1 = uVar1 + 0x20 & 0xff;
          }
          if (uVar2 - 0x41 < 0x1a) {
            uVar2 = uVar2 + 0x20 & 0xff;
          }
          if (uVar1 != uVar2) {
            return 0;
          }
        }
        if (pbVar3 == pbVar6) goto LAB_000c70b8;
        pbVar3 = pbVar3 + 1;
        uVar1 = (uint)*pbVar3;
        param_3 = param_3 + 1;
        bVar4 = *param_3;
      } while (uVar1 != 0);
    }
  }
  return uVar1;
}

