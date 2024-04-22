
undefined4 loop(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  ushort **ppuVar5;
  undefined4 uVar6;
  undefined auStack_138 [276];
  
  memset(auStack_138,0,0x10f);
  while( true ) {
    while (bVar2 = *param_1, bVar2 != 0x2a) {
      if (bVar2 == 0x3f) {
        ppuVar5 = __ctype_b_loc();
        if (-1 < (int)((uint)(*ppuVar5)[*param_2] << 0x11)) {
          if (*param_2 == 0) {
            return 1;
          }
          return 2;
        }
        param_2 = param_2 + 1;
        param_1 = param_1 + 1;
      }
      else {
        if (bVar2 == 0) {
          if (*param_2 != 0) {
            return 1;
          }
          return 0;
        }
        if (bVar2 == 0x5c) {
          ppuVar5 = __ctype_b_loc();
          pbVar1 = param_1 + 1;
          if (-1 < (int)((uint)(*ppuVar5)[*pbVar1] << 0x11)) {
            return 2;
          }
          bVar2 = *param_2;
          param_1 = param_1 + 2;
          param_2 = param_2 + 1;
          if ((uint)*pbVar1 != (uint)bVar2) {
            return 1;
          }
        }
        else {
          if (bVar2 == 0x5b) {
                    /* WARNING: Could not recover jumptable at 0x0005fcd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            uVar6 = (*(code *)(&switchD_0005fcd4::switchdataD_0005fcd8 +
                              (uint)switchD_0005fcd4::switchdataD_0005fcd8 * 2))();
            return uVar6;
          }
          bVar3 = *param_2;
          param_1 = param_1 + 1;
          param_2 = param_2 + 1;
          if (bVar2 != bVar3) {
            return 1;
          }
        }
      }
    }
    for (; param_1[1] == 0x2a; param_1 = param_1 + 1) {
    }
    if ((*param_2 == 0) && (param_1[1] == 0)) {
      return 0;
    }
    iVar4 = loop(param_1 + 1,param_2);
    if (iVar4 == 0) {
      return 0;
    }
    if (*param_2 == 0) break;
    param_2 = param_2 + 1;
  }
  return 1;
}

