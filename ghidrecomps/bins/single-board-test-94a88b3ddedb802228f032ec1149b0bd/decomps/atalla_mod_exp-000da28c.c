
undefined4
atalla_mod_exp(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  size_t __n;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  ulong *puVar5;
  undefined4 uVar6;
  undefined auStack_74 [12];
  ulong *local_68;
  size_t local_64;
  ulong *local_58;
  size_t local_54;
  
  iVar3 = DAT_000da4b0;
  if (*(int *)(DAT_000da4b0 + 8) == 0) {
    iVar4 = *(int *)(DAT_000da4b0 + 4);
    if (iVar4 == 0) {
      iVar4 = ERR_get_next_error_library();
      *(int *)(iVar3 + 4) = iVar4;
    }
    uVar6 = 0;
    ERR_put_error(iVar4,0x67,0x69,DAT_000da4b4,0x1de);
    goto LAB_000da400;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  a_01 = BN_CTX_get(param_5);
  a_02 = BN_CTX_get(param_5);
  if (a_02 == (BIGNUM *)0x0) {
    iVar4 = *(int *)(iVar3 + 4);
    if (iVar4 == 0) {
      iVar4 = ERR_get_next_error_library();
      *(int *)(iVar3 + 4) = iVar4;
    }
    uVar6 = 0;
    ERR_put_error(iVar4,0x67,0x65,DAT_000da4b4,0x1e8);
    goto LAB_000da400;
  }
  iVar4 = param_4->top;
  if (a->dmax < iVar4) {
    pBVar1 = bn_expand2(a,iVar4);
    if (pBVar1 != (BIGNUM *)0x0) {
      iVar4 = param_4->top;
      goto LAB_000da2dc;
    }
  }
  else {
LAB_000da2dc:
    if (a_00->dmax < iVar4) {
      pBVar1 = bn_expand2(a_00,iVar4);
      if (pBVar1 == (BIGNUM *)0x0) goto LAB_000da426;
      iVar4 = param_4->top;
    }
    if (a_01->dmax < iVar4) {
      pBVar1 = bn_expand2(a_01,iVar4);
      if (pBVar1 == (BIGNUM *)0x0) goto LAB_000da426;
      iVar4 = param_4->top;
    }
    if ((iVar4 <= a_02->dmax) || (pBVar1 = bn_expand2(a_02,iVar4), pBVar1 != (BIGNUM *)0x0)) {
      memset(auStack_74,0,0x4c);
      iVar2 = BN_num_bits(param_4);
      iVar4 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar4 = iVar2 + 7;
      }
      __n = iVar4 >> 3;
      memset(a_00->d,0,__n);
      memset(a->d,0,__n);
      puVar5 = a_00->d;
      iVar2 = BN_num_bits(param_3);
      iVar4 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar4 = iVar2 + 7;
      }
      BN_bn2bin(param_3,(uchar *)((int)puVar5 + (__n - (iVar4 >> 3))));
      puVar5 = a->d;
      iVar2 = BN_num_bits(param_4);
      iVar4 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar4 = iVar2 + 7;
      }
      BN_bn2bin(param_4,(uchar *)((int)puVar5 + (__n - (iVar4 >> 3))));
      local_58 = a_00->d;
      local_68 = a->d;
      local_64 = __n;
      local_54 = __n;
      memset(a_01->d,0,__n);
      memset(a_02->d,0,__n);
      puVar5 = a_01->d;
      iVar2 = BN_num_bits(param_2);
      iVar4 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar4 = iVar2 + 7;
      }
      BN_bn2bin(param_2,(uchar *)((int)puVar5 + (__n - (iVar4 >> 3))));
      iVar3 = (**(code **)(iVar3 + 0x10))(auStack_74,a_02->d,a_01->d,local_64);
      if (iVar3 == 0) {
        uVar6 = 1;
        BN_bin2bn((uchar *)a_02->d,__n,param_1);
      }
      else {
        if (ATALLA_lib_error_code == 0) {
          ATALLA_lib_error_code = ERR_get_next_error_library();
        }
        uVar6 = 0;
        ERR_put_error(ATALLA_lib_error_code,0x67,0x6a,DAT_000da4b4,0x203);
      }
      goto LAB_000da400;
    }
  }
LAB_000da426:
  iVar4 = DAT_000da4b0;
  iVar3 = *(int *)(iVar3 + 4);
  if (iVar3 == 0) {
    iVar3 = ERR_get_next_error_library();
    *(int *)(iVar4 + 4) = iVar3;
  }
  uVar6 = 0;
  ERR_put_error(iVar3,0x67,0x66,DAT_000da4b4,0x1ed);
LAB_000da400:
  BN_CTX_end(param_5);
  return uVar6;
}

