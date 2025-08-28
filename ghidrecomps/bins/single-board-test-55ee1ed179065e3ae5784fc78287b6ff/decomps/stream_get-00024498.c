
uint stream_get(undefined4 *param_1,undefined4 param_2)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_c;
  
  if (param_1[5] != 0) {
    return param_1[5];
  }
  if (*(char *)((int)param_1 + param_1[4] + 8) == '\0') {
    uVar2 = (*(code *)*param_1)(param_1[1]);
    if (uVar2 == 0xffffffff) {
      param_1[5] = 0xffffffff;
      return 0xffffffff;
    }
    *(char *)(param_1 + 2) = (char)uVar2;
    param_1[4] = 0;
    if ((0x7f < (int)uVar2) && ((int)uVar2 < 0x100)) {
      iVar3 = utf8_check_first(uVar2 & 0xff);
      if (iVar3 != 0) {
        if (iVar3 < 2) {
                    /* WARNING: Subroutine does not return */
          __assert_fail("count >= 2","3rdparty/jansson-2.6/src/load.c",0xaf,"stream_get");
        }
        for (local_c = 1; local_c < iVar3; local_c = local_c + 1) {
          uVar1 = (*(code *)*param_1)(param_1[1]);
          *(undefined1 *)((int)param_1 + local_c + 8) = uVar1;
        }
        iVar4 = utf8_check_full(param_1 + 2,iVar3,0);
        if (iVar4 != 0) {
          *(undefined1 *)((int)param_1 + iVar3 + 8) = 0;
          goto LAB_00024588;
        }
      }
      param_1[5] = 0xfffffffe;
      error_set(param_2,param_1,"unable to decode byte 0x%x",uVar2);
      return 0xfffffffe;
    }
    *(undefined1 *)((int)param_1 + 9) = 0;
  }
LAB_00024588:
  uVar2 = (uint)*(byte *)((int)param_1 + param_1[4] + 8);
  param_1[4] = param_1[4] + 1;
  param_1[9] = param_1[9] + 1;
  if (uVar2 == 10) {
    param_1[6] = param_1[6] + 1;
    param_1[8] = param_1[7];
    param_1[7] = 0;
  }
  else {
    iVar3 = utf8_check_first(uVar2);
    if (iVar3 != 0) {
      param_1[7] = param_1[7] + 1;
    }
  }
  return uVar2;
}

