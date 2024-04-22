
undefined4
cswift_mod_exp(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  int iVar1;
  int iVar2;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar3;
  int iVar4;
  BIGNUM *pBVar5;
  undefined4 uVar6;
  undefined4 local_78;
  int local_74;
  ulong *local_70;
  size_t local_6c;
  ulong *local_68;
  char acStack_64 [16];
  undefined4 local_54;
  int local_50;
  ulong *local_4c;
  int local_48;
  ulong *local_44;
  
  iVar1 = DAT_000daf48;
  iVar2 = (**(code **)(DAT_000daf48 + 0xc))(&local_78);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar2;
    }
    uVar6 = 0;
    ERR_put_error(iVar2,0x69,0x6c,DAT_000daf4c,0x1ff);
    goto LAB_000dad26;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  a_01 = BN_CTX_get(param_5);
  a_02 = BN_CTX_get(param_5);
  if (a_02 == (BIGNUM *)0x0) {
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 == 0) {
      iVar2 = ERR_get_next_error_library();
      *(int *)(iVar1 + 4) = iVar2;
    }
    uVar6 = 0;
    ERR_put_error(iVar2,0x69,0x66,DAT_000daf4c,0x20a);
    goto LAB_000daeac;
  }
  if (a->dmax < param_4->top) {
    pBVar5 = bn_expand2(a,param_4->top);
    if (pBVar5 != (BIGNUM *)0x0) {
      iVar2 = param_3->top;
      if (a_00->dmax < iVar2) goto LAB_000daed2;
      goto LAB_000dad78;
    }
LAB_000dae62:
    iVar2 = DAT_000daf48;
    iVar3 = *(int *)(iVar1 + 4);
    if (iVar3 == 0) {
      iVar3 = ERR_get_next_error_library();
      *(int *)(iVar2 + 4) = iVar3;
    }
    uVar6 = 0;
    ERR_put_error(iVar3,0x69,0x67,DAT_000daf4c,0x20f);
  }
  else {
    iVar2 = param_3->top;
    if (a_00->dmax < iVar2) {
LAB_000daed2:
      pBVar5 = bn_expand2(a_00,iVar2);
      if (pBVar5 == (BIGNUM *)0x0) goto LAB_000dae62;
    }
LAB_000dad78:
    if (((a_01->dmax < param_2->top) &&
        (pBVar5 = bn_expand2(a_01,param_2->top), pBVar5 == (BIGNUM *)0x0)) ||
       ((a_02->dmax < param_4->top &&
        (pBVar5 = bn_expand2(a_02,param_4->top), pBVar5 == (BIGNUM *)0x0)))) goto LAB_000dae62;
    local_54 = 2;
    local_50 = BN_bn2bin(param_4,(uchar *)a->d);
    iVar2 = DAT_000daf48;
    local_4c = a->d;
    local_48 = BN_bn2bin(param_3,(uchar *)a_00->d);
    local_44 = a_00->d;
    iVar3 = (**(code **)(iVar1 + 0x10))(local_78,&local_54);
    if (iVar3 == -0x2716) {
      iVar3 = *(int *)(iVar2 + 4);
      if (iVar3 == 0) {
        iVar3 = ERR_get_next_error_library();
        *(int *)(iVar2 + 4) = iVar3;
      }
      uVar6 = 0;
      ERR_put_error(iVar3,0x69,0x65,DAT_000daf4c,0x21f);
    }
    else {
      if (iVar3 == 0) {
        uVar6 = 1;
        local_74 = BN_bn2bin(param_2,(uchar *)a_01->d);
        local_70 = a_01->d;
        iVar4 = BN_num_bits(param_4);
        iVar3 = iVar4 + 7;
        if (iVar4 + 7 < 0) {
          iVar3 = iVar4 + 0xe;
        }
        local_6c = iVar3 >> 3;
        memset(a_02->d,0,local_6c);
        local_68 = a_02->d;
        iVar3 = (**(code **)(iVar2 + 0x14))(local_78,2,&local_74,1,&local_6c,1);
        if (iVar3 == 0) {
          BN_bin2bn((uchar *)a_02->d,local_6c,param_1);
          goto LAB_000daeac;
        }
        iVar4 = *(int *)(iVar2 + 4);
        if (iVar4 == 0) {
          iVar4 = ERR_get_next_error_library();
          *(int *)(iVar2 + 4) = iVar4;
        }
        ERR_put_error(iVar4,0x69,0x6b,DAT_000daf4c,0x234);
      }
      else {
        iVar4 = *(int *)(iVar2 + 4);
        if (iVar4 == 0) {
          iVar4 = ERR_get_next_error_library();
          *(int *)(iVar2 + 4) = iVar4;
        }
        ERR_put_error(iVar4,0x69,0x6b,DAT_000daf4c,0x224);
      }
      uVar6 = 0;
      sprintf(acStack_64,DAT_000daf50,iVar3);
      ERR_add_error_data(2,DAT_000daf54,acStack_64);
    }
  }
LAB_000daeac:
  (**(code **)(iVar1 + 0x18))(local_78);
LAB_000dad26:
  BN_CTX_end(param_5);
  return uVar6;
}

