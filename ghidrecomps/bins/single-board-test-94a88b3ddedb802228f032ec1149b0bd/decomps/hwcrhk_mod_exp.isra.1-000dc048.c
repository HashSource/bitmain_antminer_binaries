
undefined4
hwcrhk_mod_exp_isra_1(BIGNUM *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  ulong *puVar3;
  uint uVar4;
  undefined1 *local_448;
  undefined4 local_444;
  undefined4 local_440;
  int local_43c;
  undefined4 local_438;
  int local_434;
  undefined4 local_430;
  int local_42c;
  ulong *local_428;
  uint local_424;
  undefined1 auStack_420 [1024];
  
  local_448 = auStack_420;
  local_444 = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6b,0x6a,"e_chil.c",0x396);
    uVar2 = 0;
  }
  else {
    bn_expand2(param_1,param_4[1]);
    local_430 = *param_4;
    local_438 = *param_3;
    local_42c = param_4[1] << 2;
    local_43c = param_2[1] << 2;
    local_434 = param_3[1] << 2;
    local_440 = *param_2;
    local_424 = param_1->dmax << 2;
    local_428 = param_1->d;
    iVar1 = (*p_hwcrhk_ModExp)(hwcrhk_context,local_440,local_43c,local_438,local_434,local_430,
                               local_42c,&local_428,&local_448);
    uVar4 = local_424 >> 2;
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
      ERR_add_error_data(1,local_448);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}

