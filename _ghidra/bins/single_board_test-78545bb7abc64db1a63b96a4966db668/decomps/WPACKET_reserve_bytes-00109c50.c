
undefined4 WPACKET_reserve_bytes(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  size_t len;
  uint uVar3;
  
  if (param_1[5] == 0 || param_2 == 0) {
    return 0;
  }
  if (param_2 <= (uint)(param_1[4] - param_1[3])) {
    if (param_1[1] == 0) {
      uVar3 = ((BUF_MEM *)*param_1)->length;
      if (uVar3 - param_1[3] < param_2) {
        if (param_2 < uVar3) {
          param_2 = uVar3;
        }
        if ((int)param_2 < 0) {
          len = 0xffffffff;
        }
        else {
          len = param_2 * 2;
          if (len < 0x100) {
            len = 0x100;
          }
        }
        iVar2 = BUF_MEM_grow((BUF_MEM *)*param_1,len);
        if (iVar2 == 0) {
          return 0;
        }
      }
    }
    if (param_3 != (undefined4 *)0x0) {
      uVar1 = WPACKET_get_curr(param_1);
      *param_3 = uVar1;
    }
    return 1;
  }
  return 0;
}

