
undefined4 hwcrhk_rsa_mod_exp(BIGNUM *param_1,undefined4 *param_2,RSA *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  ulong *puVar3;
  uint uVar4;
  undefined1 *local_468;
  undefined4 local_464;
  undefined4 local_460;
  int local_45c;
  ulong *local_458;
  int local_454;
  ulong *local_450;
  int local_44c;
  ulong *local_448;
  int local_444;
  ulong *local_440;
  int local_43c;
  ulong *local_438;
  int local_434;
  ulong *local_430;
  uint local_42c;
  undefined1 auStack_428 [1028];
  
  local_468 = auStack_428;
  local_464 = 0x400;
  if (hwcrhk_context == 0) {
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(HWCRHK_lib_error_code,0x6d,0x6a,"e_chil.c",0x3c7);
    return 0;
  }
  puVar1 = (undefined4 *)RSA_get_ex_data(param_3,hndidx_rsa);
  if (puVar1 == (undefined4 *)0x0) {
    if ((((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
        (param_3->dmp1 == (BIGNUM *)0x0)) ||
       ((param_3->dmq1 == (BIGNUM *)0x0 || (param_3->iqmp == (BIGNUM *)0x0)))) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x3fc;
      goto LAB_000dc4e8;
    }
    bn_expand2(param_1,param_3->n->top);
    local_454 = param_3->p->top << 2;
    local_450 = param_3->q->d;
    local_43c = param_3->dmq1->top << 2;
    local_44c = param_3->q->top << 2;
    local_444 = param_3->dmp1->top << 2;
    local_458 = param_3->p->d;
    local_448 = param_3->dmp1->d;
    local_440 = param_3->dmq1->d;
    local_438 = param_3->iqmp->d;
    local_460 = *param_2;
    local_434 = param_3->iqmp->top << 2;
    local_45c = param_2[1] << 2;
    local_42c = param_1->dmax << 2;
    local_430 = param_1->d;
    iVar2 = (*p_hwcrhk_ModExpCRT)
                      (hwcrhk_context,local_460,local_45c,local_458,local_454,local_450,local_44c,
                       local_448,local_444,local_440,local_43c,local_438,local_434,&local_430,
                       &local_468);
    uVar4 = local_42c >> 2;
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
    if (-1 < iVar2) {
      return 1;
    }
    if (iVar2 == -2) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x41a;
      goto LAB_000dc37a;
    }
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x41d;
  }
  else {
    if (param_3->n == (BIGNUM *)0x0) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x3d7;
LAB_000dc4e8:
      ERR_put_error(HWCRHK_lib_error_code,0x6d,0x69,"e_chil.c",iVar2);
      return 0;
    }
    bn_expand2(param_1,param_3->n->top);
    local_438 = (ulong *)*param_2;
    local_430 = param_1->d;
    local_434 = param_2[1] << 2;
    local_42c = param_1->dmax << 2;
    iVar2 = (*p_hwcrhk_RSA)(local_438,local_434,*puVar1,&local_430,&local_468);
    uVar4 = local_42c >> 2;
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
    if (-1 < iVar2) {
      return 1;
    }
    if (iVar2 == -2) {
      if (HWCRHK_lib_error_code == 0) {
        HWCRHK_lib_error_code = ERR_get_next_error_library();
      }
      iVar2 = 0x3ef;
LAB_000dc37a:
      ERR_put_error(HWCRHK_lib_error_code,0x6d,0x70,"e_chil.c",iVar2);
      goto LAB_000dc364;
    }
    if (HWCRHK_lib_error_code == 0) {
      HWCRHK_lib_error_code = ERR_get_next_error_library();
    }
    iVar2 = 0x3f2;
  }
  ERR_put_error(HWCRHK_lib_error_code,0x6d,0x6f,"e_chil.c",iVar2);
LAB_000dc364:
  ERR_add_error_data(1,local_468);
  return 0;
}

