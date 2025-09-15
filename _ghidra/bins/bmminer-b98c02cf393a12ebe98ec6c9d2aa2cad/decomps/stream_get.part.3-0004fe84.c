
uint stream_get_part_3(undefined4 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  uVar5 = param_1[4] + 1;
  uVar7 = (uint)*(byte *)((int)param_1 + param_1[4] + 8);
  if (uVar7 == 0) {
    uVar3 = (*(code *)*param_1)(param_1[1]);
    if (uVar3 == 0xffffffff) {
      param_1[5] = 0xffffffff;
      return 0xffffffff;
    }
    uVar6 = uVar3 - 0x80;
    uVar7 = uVar3 & 0xff;
    *(char *)(param_1 + 2) = (char)uVar3;
    param_1[4] = 0;
    uVar5 = uVar6;
    if (0x7f < uVar6) {
      uVar5 = 1;
    }
    if (uVar6 < 0x80) {
      uVar5 = utf8_check_first(uVar7);
      if (uVar5 != 0) {
        if (uVar5 < 2) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("count >= 2","compat/jansson-2.9/src/load.c",0xbc,"stream_get");
        }
        puVar8 = param_1 + 2;
        do {
          uVar1 = (*(code *)*param_1)(param_1[1]);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
          *(undefined1 *)puVar8 = uVar1;
        } while ((undefined4 *)(uVar5 + 7 + (int)param_1) != puVar8);
        iVar2 = utf8_check_full(param_1 + 2,uVar5,0);
        if (iVar2 != 0) {
          *(undefined1 *)((int)param_1 + uVar5 + 8) = 0;
          uVar5 = param_1[4] + 1;
          uVar7 = (uint)*(byte *)((int)param_1 + param_1[4] + 8);
          goto LAB_0004fe94;
        }
      }
      param_1[5] = 0xfffffffe;
      error_set(param_2,param_1,"unable to decode byte 0x%x",uVar3);
      return 0xfffffffe;
    }
    *(undefined1 *)((int)param_1 + 9) = 0;
  }
LAB_0004fe94:
  param_1[4] = uVar5;
  param_1[9] = param_1[9] + 1;
  if (uVar7 == 10) {
    uVar4 = param_1[7];
    param_1[7] = 0;
    param_1[6] = param_1[6] + 1;
    param_1[8] = uVar4;
    return 10;
  }
  iVar2 = utf8_check_first(uVar7);
  if (iVar2 == 0) {
    return uVar7;
  }
  param_1[7] = param_1[7] + 1;
  return uVar7;
}

