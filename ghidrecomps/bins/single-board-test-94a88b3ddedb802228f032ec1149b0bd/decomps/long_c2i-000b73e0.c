
undefined4
long_c2i(uint *param_1,byte *param_2,uint param_3,undefined4 param_4,undefined4 param_5,int param_6)

{
  bool bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int line;
  uint uVar4;
  uint uVar5;
  
  if (4 < (int)param_3) {
    line = 0xa3;
    goto LAB_000b7432;
  }
  uVar4 = param_3;
  if (param_3 != 0) {
    if ((char)*param_2 < '\0') {
      uVar5 = 0;
      uVar4 = 0;
      if (0 < (int)param_3) {
        pbVar3 = param_2;
        do {
          pbVar2 = pbVar3 + 1;
          uVar4 = (uint)(byte)~*pbVar3 | uVar4 << 8;
          pbVar3 = pbVar2;
        } while (pbVar2 != param_2 + param_3);
        bVar1 = true;
        goto LAB_000b7414;
      }
LAB_000b7416:
      uVar4 = ~uVar5;
    }
    else {
      uVar4 = 0;
      if (0 < (int)param_3) {
        pbVar3 = param_2;
        do {
          pbVar2 = pbVar3 + 1;
          uVar4 = (uint)*pbVar3 | uVar4 << 8;
          pbVar3 = pbVar2;
        } while (pbVar2 != param_2 + param_3);
        bVar1 = false;
LAB_000b7414:
        uVar5 = uVar4;
        if (bVar1) goto LAB_000b7416;
      }
    }
  }
  if (*(uint *)(param_6 + 0x14) != uVar4) {
    *param_1 = uVar4;
    return 1;
  }
  line = 0xb9;
LAB_000b7432:
  ERR_put_error(0xd,0xa6,0x80,DAT_000b7464,line);
  return 0;
}

