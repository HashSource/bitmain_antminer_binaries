
uint equal_email(void *param_1,size_t param_2,void *param_3,size_t param_4)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  size_t sVar4;
  uint uVar5;
  byte *pbVar6;
  byte *pbVar7;
  byte *pbVar8;
  
  if (param_2 != param_4) {
    return 0;
  }
  if (param_2 != 0) {
    sVar4 = param_2 - 1;
    pbVar6 = (byte *)((int)param_1 + sVar4);
    if (*(char *)((int)param_1 + sVar4) == '@') {
LAB_000c74e8:
      pbVar8 = (byte *)((int)param_3 + sVar4);
    }
    else {
      pbVar8 = (byte *)((int)param_3 + sVar4);
      if (*(char *)((int)param_3 + sVar4) != '@') {
        pbVar7 = (byte *)((int)param_1 + (param_2 - 2));
        pbVar2 = (byte *)((int)param_3 + (param_2 - 2));
        do {
          pbVar8 = pbVar2;
          pbVar6 = pbVar7;
          if (sVar4 == 0) goto LAB_000c74d4;
          sVar4 = sVar4 - 1;
          if (*pbVar6 == 0x40) goto LAB_000c74e8;
          pbVar7 = pbVar6 + -1;
          pbVar2 = pbVar8 + -1;
        } while (*pbVar8 != 0x40);
      }
    }
    if (param_2 - sVar4 != 0) {
      uVar3 = (uint)*pbVar6;
      bVar1 = *pbVar8;
      if (uVar3 != 0) {
        pbVar7 = pbVar6 + (param_2 - sVar4) + -1;
        do {
          uVar5 = (uint)bVar1;
          if (uVar3 != uVar5) {
            if (uVar3 - 0x41 < 0x1a) {
              uVar3 = uVar3 + 0x20 & 0xff;
            }
            if (uVar5 - 0x41 < 0x1a) {
              uVar5 = uVar5 + 0x20 & 0xff;
            }
            if (uVar3 != uVar5) {
              return 0;
            }
          }
          if (pbVar6 == pbVar7) goto LAB_000c74ce;
          pbVar6 = pbVar6 + 1;
          uVar3 = (uint)*pbVar6;
          pbVar8 = pbVar8 + 1;
          bVar1 = *pbVar8;
        } while (uVar3 != 0);
      }
      return uVar3;
    }
LAB_000c74ce:
    if (sVar4 != 0) {
      param_2 = sVar4;
    }
  }
LAB_000c74d4:
  uVar3 = memcmp(param_1,param_3,param_2);
  uVar5 = 1 - uVar3;
  if (1 < uVar3) {
    uVar5 = 0;
  }
  return uVar5;
}

