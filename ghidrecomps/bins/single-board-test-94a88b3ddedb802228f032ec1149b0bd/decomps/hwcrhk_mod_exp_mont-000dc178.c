
undefined4
hwcrhk_mod_exp_mont(BIGNUM *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  ulong *puVar3;
  uint uVar4;
  undefined1 *puStack_448;
  undefined4 uStack_444;
  undefined4 uStack_440;
  int iStack_43c;
  undefined4 uStack_438;
  int iStack_434;
  undefined4 uStack_430;
  int iStack_42c;
  ulong *puStack_428;
  uint uStack_424;
  undefined1 auStack_420 [1024];
  
  puStack_448 = auStack_420;
  uStack_444 = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6b,0x6a,"e_chil.c",0x396);
    uVar2 = 0;
  }
  else {
    bn_expand2(param_1,param_4[1]);
    uStack_430 = *param_4;
    uStack_438 = *param_3;
    iStack_42c = param_4[1] << 2;
    iStack_43c = param_2[1] << 2;
    iStack_434 = param_3[1] << 2;
    uStack_440 = *param_2;
    uStack_424 = param_1->dmax << 2;
    puStack_428 = param_1->d;
    iVar1 = (*p_hwcrhk_ModExp)(hwcrhk_context,uStack_440,iStack_43c,uStack_438,iStack_434,uStack_430
                               ,iStack_42c,&puStack_428,&puStack_448);
    uVar4 = uStack_424 >> 2;
    param_1->top = uVar4;
    if (uVar4 != 0) {
      puVar3 = param_1->d + (uVar4 - 1);
      do {
        if (*puVar3 != 0) break;
        uVar4 = uVar4 - 1;
        puVar3 = puVar3 + -1;
      } while (uVar4 != 0);
      param_1->top = uVar4;
    }
    if (iVar1 < 0) {
      if (iVar1 == -2) {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6b,0x70,"e_chil.c",0x3ad);
      }
      else {
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,0x6b,0x6f,"e_chil.c",0x3af);
      }
      ERR_add_error_data(1,puStack_448);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

