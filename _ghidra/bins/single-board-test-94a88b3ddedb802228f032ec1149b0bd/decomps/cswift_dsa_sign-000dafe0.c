
DSA_SIG * cswift_dsa_sign(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  BN_CTX *ctx;
  int iVar2;
  BIGNUM *pBVar3;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  BIGNUM *a_02;
  BIGNUM *pBVar4;
  int iVar5;
  DSA_SIG *pDVar6;
  ulong *puVar7;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  size_t local_6c;
  ulong *local_68;
  char acStack_64 [16];
  undefined4 local_54;
  int local_50;
  ulong *local_4c;
  int local_48;
  ulong *local_44;
  int local_40;
  ulong *local_3c;
  int local_38;
  ulong *local_34;
  
  ctx = BN_CTX_new();
  if (ctx == (BN_CTX *)0x0) {
    return (DSA_SIG *)0x0;
  }
  iVar2 = (*p_CSwift_AcquireAccContext)(&local_78);
  if (iVar2 != 0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    pDVar6 = (DSA_SIG *)0x0;
    ERR_put_error(CSWIFT_lib_error_code,0x65,0x6c,"e_cswift.c",0x32d);
    goto LAB_000db15c;
  }
  BN_CTX_start(ctx);
  pBVar3 = BN_CTX_get(ctx);
  a = BN_CTX_get(ctx);
  a_00 = BN_CTX_get(ctx);
  a_01 = BN_CTX_get(ctx);
  a_02 = BN_CTX_get(ctx);
  if (a_02 == (BIGNUM *)0x0) {
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    pDVar6 = (DSA_SIG *)0x0;
    ERR_put_error(CSWIFT_lib_error_code,0x65,0x66,"e_cswift.c",0x339);
    goto LAB_000db1f2;
  }
  iVar2 = *(int *)(*(int *)(param_3 + 0xc) + 4);
  if (pBVar3->dmax < iVar2) {
    pBVar4 = bn_expand2(pBVar3,iVar2);
    if (pBVar4 != (BIGNUM *)0x0) {
      iVar2 = *(int *)(*(int *)(param_3 + 0x10) + 4);
      if (a->dmax < iVar2) goto LAB_000db212;
      goto LAB_000db056;
    }
LAB_000db196:
    if (CSWIFT_lib_error_code == 0) {
      CSWIFT_lib_error_code = ERR_get_next_error_library();
    }
    pDVar6 = (DSA_SIG *)0x0;
    ERR_put_error(CSWIFT_lib_error_code,0x65,0x67,"e_cswift.c",0x341);
  }
  else {
    iVar2 = *(int *)(*(int *)(param_3 + 0x10) + 4);
    if (a->dmax < iVar2) {
LAB_000db212:
      pBVar4 = bn_expand2(a,iVar2);
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_000db196;
    }
LAB_000db056:
    iVar2 = *(int *)(*(int *)(param_3 + 0x14) + 4);
    if ((a_00->dmax < iVar2) && (pBVar4 = bn_expand2(a_00,iVar2), pBVar4 == (BIGNUM *)0x0))
    goto LAB_000db196;
    iVar2 = *(int *)(*(int *)(param_3 + 0x1c) + 4);
    if (a_01->dmax < iVar2) {
      pBVar4 = bn_expand2(a_01,iVar2);
      if (pBVar4 == (BIGNUM *)0x0) goto LAB_000db196;
      pBVar4 = *(BIGNUM **)(param_3 + 0xc);
      iVar2 = pBVar4->top;
      if (a_02->dmax < iVar2) goto LAB_000db1cc;
    }
    else {
      pBVar4 = *(BIGNUM **)(param_3 + 0xc);
      iVar2 = pBVar4->top;
      if (a_02->dmax < iVar2) {
LAB_000db1cc:
        pBVar4 = bn_expand2(a_02,iVar2);
        if (pBVar4 == (BIGNUM *)0x0) goto LAB_000db196;
        pBVar4 = *(BIGNUM **)(param_3 + 0xc);
      }
    }
    local_54 = 3;
    local_50 = BN_bn2bin(pBVar4,(uchar *)pBVar3->d);
    local_4c = pBVar3->d;
    local_48 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x10),(uchar *)a->d);
    local_44 = a->d;
    local_40 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x14),(uchar *)a_00->d);
    local_3c = a_00->d;
    local_38 = BN_bn2bin(*(BIGNUM **)(param_3 + 0x1c),(uchar *)a_01->d);
    local_34 = a_01->d;
    iVar2 = (*p_CSwift_AttachKeyParam)(local_78,&local_54);
    if (iVar2 == -0x2716) {
      if (CSWIFT_lib_error_code == 0) {
        CSWIFT_lib_error_code = ERR_get_next_error_library();
      }
      pDVar6 = (DSA_SIG *)0x0;
      ERR_put_error(CSWIFT_lib_error_code,0x65,0x65,"e_cswift.c",0x354);
    }
    else {
      if (iVar2 == 0) {
        local_74 = param_2;
        local_70 = param_1;
        iVar5 = BN_num_bits(*(BIGNUM **)(param_3 + 0xc));
        iVar2 = iVar5 + 7;
        if (iVar5 + 7 < 0) {
          iVar2 = iVar5 + 0xe;
        }
        local_6c = iVar2 >> 3;
        memset(a_02->d,0,local_6c);
        local_68 = a_02->d;
        iVar2 = (*p_CSwift_SimpleRequest)(local_78,3,&local_74,1,&local_6c,1);
        if (iVar2 == 0) {
          pDVar6 = DSA_SIG_new();
          if (pDVar6 != (DSA_SIG *)0x0) {
            pBVar3 = BN_bin2bn((uchar *)a_02->d,0x14,(BIGNUM *)0x0);
            puVar7 = a_02->d;
            pDVar6->r = pBVar3;
            pBVar3 = BN_bin2bn((uchar *)(puVar7 + 5),0x14,(BIGNUM *)0x0);
            pcVar1 = p_CSwift_ReleaseAccContext;
            pDVar6->s = pBVar3;
            (*pcVar1)(local_78);
            goto LAB_000db15c;
          }
          goto LAB_000db1f2;
        }
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar5 = 0x36a;
      }
      else {
        if (CSWIFT_lib_error_code == 0) {
          CSWIFT_lib_error_code = ERR_get_next_error_library();
        }
        iVar5 = 0x359;
      }
      ERR_put_error(CSWIFT_lib_error_code,0x65,0x6b,"e_cswift.c",iVar5);
      pDVar6 = (DSA_SIG *)0x0;
      sprintf(acStack_64,"%ld",iVar2);
      ERR_add_error_data(2,"CryptoSwift error number is ",acStack_64);
    }
  }
LAB_000db1f2:
  (*p_CSwift_ReleaseAccContext)(local_78);
LAB_000db15c:
  BN_CTX_end(ctx);
  BN_CTX_free(ctx);
  return pDVar6;
}

