
uint stream_get_part_3(code **param_1,undefined4 param_2)

{
  undefined uVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  code *pcVar5;
  uint uVar6;
  code **ppcVar7;
  
  pcVar4 = param_1[4] + 1;
  uVar6 = (uint)(byte)((code *)((int)param_1 + (int)param_1[4]))[8];
  if (uVar6 == 0) {
    uVar3 = (**param_1)(param_1[1]);
    if (uVar3 == 0xffffffff) {
      param_1[5] = (code *)0xffffffff;
      return 0xffffffff;
    }
    pcVar5 = (code *)(uVar3 - 0x80);
    uVar6 = uVar3 & 0xff;
    *(char *)(param_1 + 2) = (char)uVar3;
    param_1[4] = (code *)0x0;
    pcVar4 = pcVar5;
    if ((code *)0x7f < pcVar5) {
      pcVar4 = (code *)0x1;
    }
    if (pcVar5 < (code *)0x80) {
      uVar6 = utf8_check_first(uVar6);
      if (uVar6 != 0) {
        if (uVar6 < 2) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("count >= 2","compat/jansson-2.9/src/load.c",0xbc,DAT_0004ff7c);
        }
        ppcVar7 = param_1 + 2;
        do {
          uVar1 = (**param_1)(param_1[1]);
          ppcVar7 = (code **)((int)ppcVar7 + 1);
          *(undefined *)ppcVar7 = uVar1;
        } while ((code **)(uVar6 + 7 + (int)param_1) != ppcVar7);
        iVar2 = utf8_check_full(param_1 + 2,uVar6,0);
        if (iVar2 != 0) {
          *(undefined *)((int)param_1 + uVar6 + 8) = 0;
          pcVar4 = param_1[4] + 1;
          uVar6 = (uint)(byte)((code *)((int)param_1 + (int)param_1[4]))[8];
          goto LAB_0004fe94;
        }
      }
      param_1[5] = (code *)0xfffffffe;
      error_set(param_2,param_1,"unable to decode byte 0x%x",uVar3);
      return 0xfffffffe;
    }
    *(undefined *)((int)param_1 + 9) = 0;
  }
LAB_0004fe94:
  param_1[4] = pcVar4;
  param_1[9] = param_1[9] + 1;
  if (uVar6 == 10) {
    pcVar4 = param_1[7];
    param_1[7] = (code *)0x0;
    param_1[6] = param_1[6] + 1;
    param_1[8] = pcVar4;
    return 10;
  }
  iVar2 = utf8_check_first(uVar6);
  if (iVar2 == 0) {
    return uVar6;
  }
  param_1[7] = param_1[7] + 1;
  return uVar6;
}

