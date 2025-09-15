
undefined4
cswift_mod_exp(BIGNUM *param_1,BIGNUM *param_2,BIGNUM *param_3,BIGNUM *param_4,BN_CTX *param_5)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  int iVar2;
  BIGNUM *pBVar3;
  undefined4 uVar4;
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
  
  iVar1 = (*p_CSwift_AcquireAccContext)(&local_78);
  if (iVar1 != 0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    uVar4 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,0x6c,"e_cswift.c",0x1ff);
    goto LAB_000dad26;
  }
  BN_CTX_start(param_5);
  a = BN_CTX_get(param_5);
  a_00 = BN_CTX_get(param_5);
  a_01 = BN_CTX_get(param_5);
  a_02 = BN_CTX_get(param_5);
  if (a_02 == (BIGNUM *)0x0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    uVar4 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,0x66,"e_cswift.c",0x20a);
    goto LAB_000daeac;
  }
  if (a->dmax < param_4->top) {
    pBVar3 = bn_expand2(a,param_4->top);
    if (pBVar3 != (BIGNUM *)0x0) {
      iVar1 = param_3->top;
      if (a_00->dmax < iVar1) goto LAB_000daed2;
      goto LAB_000dad78;
    }
LAB_000dae62:
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    uVar4 = 0;
    ERR_put_error(CSWIFT_lib_error_code,0x69,0x67,"e_cswift.c",0x20f);
  }
  else {
    iVar1 = param_3->top;
    if (a_00->dmax < iVar1) {
LAB_000daed2:
      pBVar3 = bn_expand2(a_00,iVar1);
      if (pBVar3 == (BIGNUM *)0x0) goto LAB_000dae62;
    }
LAB_000dad78:
    if (((a_01->dmax < param_2->top) &&
        (pBVar3 = bn_expand2(a_01,param_2->top), pBVar3 == (BIGNUM *)0x0)) ||
       ((a_02->dmax < param_4->top &&
        (pBVar3 = bn_expand2(a_02,param_4->top), pBVar3 == (BIGNUM *)0x0)))) goto LAB_000dae62;
    local_54 = 2;
    local_50 = BN_bn2bin(param_4,(uchar *)a->d);
    local_4c = a->d;
    local_48 = BN_bn2bin(param_3,(uchar *)a_00->d);
    local_44 = a_00->d;
    iVar1 = (*p_CSwift_AttachKeyParam)(local_78,&local_54);
    if (iVar1 == -0x2716) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      uVar4 = 0;
      ERR_put_error(CSWIFT_lib_error_code,0x69,0x65,"e_cswift.c",0x21f);
    }
    else {
      if (iVar1 == 0) {
        uVar4 = 1;
        local_74 = BN_bn2bin(param_2,(uchar *)a_01->d);
        local_70 = a_01->d;
        iVar2 = BN_num_bits(param_4);
        iVar1 = iVar2 + 7;
        if (iVar2 + 7 < 0) {
          iVar1 = iVar2 + 0xe;
        }
        local_6c = iVar1 >> 3;
        memset(a_02->d,0,local_6c);
        local_68 = a_02->d;
        iVar1 = (*p_CSwift_SimpleRequest)(local_78,2,&local_74,1,&local_6c,1);
        if (iVar1 == 0) {
          BN_bin2bn((uchar *)a_02->d,local_6c,param_1);
          goto LAB_000daeac;
        }
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x234);
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(CSWIFT_lib_error_code,0x69,0x6b,"e_cswift.c",0x224);
      }
      uVar4 = 0;
      sprintf(acStack_64,"%ld",iVar1);
      ERR_add_error_data(2,"CryptoSwift error number is ",acStack_64);
    }
  }
LAB_000daeac:
  (*p_CSwift_ReleaseAccContext)(local_78);
LAB_000dad26:
  BN_CTX_end(param_5);
  return uVar4;
}

