
undefined4
atalla_mod_exp_mont(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  size_t __n;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *pBVar1;
  int iVar2;
  int iVar3;
  ulong *puVar4;
  undefined4 uVar5;
  undefined1 auStack_74 [12];
  ulong *puStack_68;
  size_t sStack_64;
  ulong *puStack_58;
  size_t sStack_54;
  
  if (atalla_dso == 0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    uVar5 = 0;
    ERR_put_error(ATALLA_lib_error_code,0x67,0x69,"e_atalla.c",0x1de);
    goto LAB_000da400;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  a_01 = BN_CTX_get(param_5);
  a_02 = BN_CTX_get(param_5);
  if (a_02 == (BIGNUM *)0x0) {
    if (ATALLA_lib_error_code == 0) {
      ATALLA_lib_error_code = ERR_get_next_error_library();
    }
    uVar5 = 0;
    ERR_put_error(ATALLA_lib_error_code,0x67,0x65,"e_atalla.c",0x1e8);
    goto LAB_000da400;
  }
  iVar3 = param_4->top;
  if (a->dmax < iVar3) {
    pBVar1 = bn_expand2(a,iVar3);
    if (pBVar1 != (BIGNUM *)0x0) {
      iVar3 = param_4->top;
      goto LAB_000da2dc;
    }
  }
  else {
LAB_000da2dc:
    if (a_00->dmax < iVar3) {
      pBVar1 = bn_expand2(a_00,iVar3);
      if (pBVar1 == (BIGNUM *)0x0) goto LAB_000da426;
      iVar3 = param_4->top;
    }
    if (a_01->dmax < iVar3) {
      pBVar1 = bn_expand2(a_01,iVar3);
      if (pBVar1 == (BIGNUM *)0x0) goto LAB_000da426;
      iVar3 = param_4->top;
    }
    if ((iVar3 <= a_02->dmax) || (pBVar1 = bn_expand2(a_02,iVar3), pBVar1 != (BIGNUM *)0x0)) {
      memset(auStack_74,0,0x4c);
      iVar2 = BN_num_bits(param_4);
      iVar3 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar3 = iVar2 + 7;
      }
      __n = iVar3 >> 3;
      memset(a_00->d,0,__n);
      memset(a->d,0,__n);
      puVar4 = a_00->d;
      iVar2 = BN_num_bits(param_3);
      iVar3 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar3 = iVar2 + 7;
      }
      BN_bn2bin(param_3,(uchar *)((int)puVar4 + (__n - (iVar3 >> 3))));
      puVar4 = a->d;
      iVar2 = BN_num_bits(param_4);
      iVar3 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar3 = iVar2 + 7;
      }
      BN_bn2bin(param_4,(uchar *)((int)puVar4 + (__n - (iVar3 >> 3))));
      puStack_58 = a_00->d;
      puStack_68 = a->d;
      sStack_64 = __n;
      sStack_54 = __n;
      memset(a_01->d,0,__n);
      memset(a_02->d,0,__n);
      puVar4 = a_01->d;
      iVar2 = BN_num_bits(param_2);
      iVar3 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar3 = iVar2 + 7;
      }
      BN_bn2bin(param_2,(uchar *)((int)puVar4 + (__n - (iVar3 >> 3))));
      iVar3 = (*p_Atalla_RSAPrivateKeyOpFn)(auStack_74,a_02->d,a_01->d,sStack_64);
      if (iVar3 == 0) {
        uVar5 = 1;
        BN_bin2bn((uchar *)a_02->d,__n,param_1);
      }
      else {
        if (ATALLA_lib_error_code == 0) {
          ATALLA_lib_error_code = ERR_get_next_error_library();
        }
        uVar5 = 0;
        ERR_put_error(ATALLA_lib_error_code,0x67,0x6a,"e_atalla.c",0x203);
      }
      goto LAB_000da400;
    }
  }
LAB_000da426:
  if (ATALLA_lib_error_code == 0) {
    ATALLA_lib_error_code = ERR_get_next_error_library();
  }
  uVar5 = 0;
  ERR_put_error(ATALLA_lib_error_code,0x67,0x66,"e_atalla.c",0x1ed);
LAB_000da400:
  BN_CTX_end(param_5);
  return uVar5;
}

