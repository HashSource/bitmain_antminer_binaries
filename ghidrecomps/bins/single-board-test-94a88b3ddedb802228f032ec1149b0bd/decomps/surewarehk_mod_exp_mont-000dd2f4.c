
int surewarehk_mod_exp_mont
              (BIGNUM *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int lib;
  ulong *puVar2;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined2 uStack_54;
  undefined auStack_52 [50];
  
  iVar1 = DAT_000dd2e4;
  uStack_60 = *DAT_000dd2dc;
  uStack_5c = DAT_000dd2dc[1];
  uStack_58 = DAT_000dd2dc[2];
  uStack_54 = (undefined2)DAT_000dd2dc[3];
  memset(auStack_52,0,0x32);
  if (*(int *)(iVar1 + 0x10) == 0) {
    lib = *(int *)(iVar1 + 4);
    if (lib == 0) {
      lib = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = lib;
    }
    ERR_put_error(lib,0x6b,0x75,DAT_000dd2e0,0x435);
  }
  else if (param_1 != (BIGNUM *)0x0) {
    bn_expand2(param_1,param_4[1]);
    if (param_1->dmax == param_4[1]) {
      iVar1 = (**(code **)(iVar1 + 0x10))
                        (&uStack_60,param_1->dmax << 2,*param_4,param_3[1] << 2,*param_3,
                         param_2[1] << 2,*param_2,param_1->d);
      surewarehk_error_handling(&uStack_60,0x6b,iVar1);
      if (iVar1 != 1) {
        return iVar1;
      }
      iVar1 = param_4[1];
      param_1->top = iVar1;
      if (iVar1 < 1) {
        return 1;
      }
      puVar2 = param_1->d + iVar1 + -1;
      do {
        if (*puVar2 != 0) break;
        iVar1 = iVar1 + -1;
        puVar2 = puVar2 + -1;
      } while (iVar1 != 0);
      param_1->top = iVar1;
      return 1;
    }
  }
  return 0;
}

