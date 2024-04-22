
undefined4 hwcrhk_rsa_mod_exp(BIGNUM *param_1,ulong **param_2,RSA *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  uint uVar6;
  undefined *local_468;
  undefined4 local_464;
  ulong *local_460;
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
  undefined auStack_428 [1028];
  
  iVar3 = DAT_000dc53c;
  local_468 = auStack_428;
  local_464 = 0x400;
  if (*(int *)(DAT_000dc53c + 0x14) == 0) {
    iVar2 = *(int *)(DAT_000dc53c + 0x1c);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar3 + 0x1c) = iVar2;
    }
    ERR_put_error(iVar2,0x6d,0x6a,DAT_000dc544,0x3c7);
    return 0;
  }
  puVar1 = (undefined4 *)RSA_get_ex_data(param_3,*DAT_000dc540);
  iVar2 = DAT_000dc53c;
  if (puVar1 == (undefined4 *)0x0) {
    if ((((param_3->p == (BIGNUM *)0x0) || (param_3->q == (BIGNUM *)0x0)) ||
        (param_3->dmp1 == (BIGNUM *)0x0)) ||
       ((param_3->dmq1 == (BIGNUM *)0x0 || (param_3->iqmp == (BIGNUM *)0x0)))) {
      iVar4 = *(int *)(iVar3 + 0x1c);
      if (iVar4 == 0) {
        iVar4 = ERR_get_next_error_library();
        *(int *)(iVar2 + 0x1c) = iVar4;
      }
      iVar3 = 0x3fc;
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
    local_45c = (int)param_2[1] << 2;
    local_42c = param_1->dmax << 2;
    local_430 = param_1->d;
    iVar2 = (**(code **)(iVar3 + 0x3c))
                      (*(undefined4 *)(iVar3 + 0x14),local_460,local_45c,local_458,local_454,
                       local_450,local_44c,local_448,local_444,local_440,local_43c,local_438,
                       local_434,&local_430,&local_468);
    uVar6 = local_42c >> 2;
    param_1->top = uVar6;
    if (uVar6 != 0) {
      puVar5 = param_1->d + (uVar6 - 1);
      do {
        if (*puVar5 != 0) break;
        uVar6 = uVar6 - 1;
        puVar5 = puVar5 + -1;
      } while (uVar6 != 0);
      param_1->top = uVar6;
    }
    iVar4 = DAT_000dc53c;
    if (-1 < iVar2) {
      return 1;
    }
    iVar3 = *(int *)(iVar3 + 0x1c);
    if (iVar2 == -2) {
      if (iVar3 == 0) {
        iVar3 = ERR_get_next_error_library();
        *(int *)(iVar4 + 0x1c) = iVar3;
      }
      iVar2 = 0x41a;
      goto LAB_000dc37a;
    }
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar4 + 0x1c) = iVar3;
    }
    iVar2 = 0x41d;
  }
  else {
    if (param_3->n == (BIGNUM *)0x0) {
      iVar4 = *(int *)(iVar3 + 0x1c);
      if (iVar4 == 0) {
        iVar4 = ERR_get_next_error_library();
        *(int *)(iVar3 + 0x1c) = iVar4;
      }
      iVar3 = 0x3d7;
LAB_000dc4e8:
      ERR_put_error(iVar4,0x6d,0x69,DAT_000dc544,iVar3);
      return 0;
    }
    bn_expand2(param_1,param_3->n->top);
    local_438 = *param_2;
    local_430 = param_1->d;
    local_434 = (int)param_2[1] << 2;
    local_42c = param_1->dmax << 2;
    iVar2 = (**(code **)(iVar3 + 0x2c))(local_438,local_434,*puVar1,&local_430,&local_468);
    uVar6 = local_42c >> 2;
    param_1->top = uVar6;
    if (uVar6 != 0) {
      puVar5 = param_1->d + (uVar6 - 1);
      do {
        if (*puVar5 != 0) break;
        uVar6 = uVar6 - 1;
        puVar5 = puVar5 + -1;
      } while (uVar6 != 0);
      param_1->top = uVar6;
    }
    iVar4 = DAT_000dc53c;
    if (-1 < iVar2) {
      return 1;
    }
    iVar3 = *(int *)(iVar3 + 0x1c);
    if (iVar2 == -2) {
      if (iVar3 == 0) {
        iVar3 = ERR_get_next_error_library();
        *(int *)(iVar4 + 0x1c) = iVar3;
      }
      iVar2 = 0x3ef;
LAB_000dc37a:
      ERR_put_error(iVar3,0x6d,0x70,DAT_000dc544,iVar2);
      goto LAB_000dc364;
    }
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar4 + 0x1c) = iVar3;
    }
    iVar2 = 0x3f2;
  }
  ERR_put_error(iVar3,0x6d,0x6f,DAT_000dc544,iVar2);
LAB_000dc364:
  ERR_add_error_data(1,local_468);
  return 0;
}

