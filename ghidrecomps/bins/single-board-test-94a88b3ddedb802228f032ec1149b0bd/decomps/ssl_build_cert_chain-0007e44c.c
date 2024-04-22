
int ssl_build_cert_chain(undefined4 *param_1,X509_STORE *param_2,uint param_3)

{
  int iVar1;
  X509_STORE *ctx;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  X509 *pXVar5;
  X509 *pXVar6;
  int iVar7;
  X509 **ppXVar8;
  X509_STORE_CTX XStack_a8;
  
  ppXVar8 = (X509 **)*param_1;
  pXVar6 = *ppXVar8;
  if (pXVar6 == (X509 *)0x0) {
    ERR_put_error(0x14,0x14c,0xb3,DAT_0007e624,0x484);
    iVar1 = 0;
  }
  else {
    if ((param_3 & 4) == 0) {
      ctx = (X509_STORE *)param_1[0x53];
      if ((X509_STORE *)param_1[0x53] == (X509_STORE *)0x0) {
        ctx = param_2;
      }
      if ((int)(param_3 << 0x1f) < 0) {
        pXVar5 = ppXVar8[3];
      }
      else {
        pXVar5 = (X509 *)0x0;
      }
    }
    else {
      ctx = X509_STORE_new();
      iVar1 = 0;
      if (ctx == (X509_STORE *)0x0) {
LAB_0007e582:
        X509_STORE_free(ctx);
        return 0;
      }
      while( true ) {
        iVar3 = sk_num((_STACK *)ppXVar8[3]);
        iVar7 = iVar1 + 1;
        if (iVar3 <= iVar1) break;
        pXVar6 = (X509 *)sk_value((_STACK *)ppXVar8[3],iVar1);
        iVar3 = X509_STORE_add_cert(ctx,pXVar6);
        iVar1 = iVar7;
        if (iVar3 == 0) {
          uVar2 = ERR_peek_last_error();
          if ((uVar2 >> 0x18 != 0xb) || ((uVar2 & 0xfff) != 0x65)) goto LAB_0007e582;
          ERR_clear_error();
        }
      }
      iVar1 = X509_STORE_add_cert(ctx,*ppXVar8);
      if (iVar1 == 0) {
        uVar2 = ERR_peek_last_error();
        if ((uVar2 >> 0x18 != 0xb) || ((uVar2 & 0xfff) != 0x65)) goto LAB_0007e582;
        ERR_clear_error();
        pXVar6 = *ppXVar8;
        pXVar5 = (X509 *)0x0;
      }
      else {
        pXVar6 = *ppXVar8;
        pXVar5 = (X509 *)0x0;
      }
    }
    iVar1 = X509_STORE_CTX_init(&XStack_a8,ctx,pXVar6,(stack_st_X509 *)pXVar5);
    param_2 = ctx;
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x14c,0xb,DAT_0007e624,0x4a8);
      iVar1 = 0;
    }
    else {
      X509_STORE_CTX_set_flags(&XStack_a8,param_1[0xe] & 0x30000);
      iVar1 = X509_verify_cert(&XStack_a8);
      if (iVar1 < 1) {
        if ((param_3 & 8) == 0) {
          ERR_put_error(0x14,0x14c,0x86,DAT_0007e624,0x4b9);
          iVar1 = X509_STORE_CTX_get_error(&XStack_a8);
          pcVar4 = X509_verify_cert_error_string(iVar1);
          ERR_add_error_data(2,DAT_0007e628,pcVar4);
          X509_STORE_CTX_cleanup(&XStack_a8);
          iVar1 = 0;
          goto joined_r0x0007e4da;
        }
        if ((int)(param_3 << 0x1b) < 0) {
          ERR_clear_error();
          iVar1 = 2;
        }
        else {
          iVar1 = 2;
        }
      }
      else {
        iVar1 = 0;
      }
      pXVar6 = (X509 *)X509_STORE_CTX_get1_chain(&XStack_a8);
      X509_STORE_CTX_cleanup(&XStack_a8);
      if (ppXVar8[3] != (X509 *)0x0) {
        sk_pop_free((_STACK *)ppXVar8[3],DAT_0007e620);
      }
      pXVar5 = (X509 *)sk_shift((_STACK *)pXVar6);
      X509_free(pXVar5);
      if (((int)(param_3 << 0x1e) < 0) && (iVar3 = sk_num((_STACK *)pXVar6), 0 < iVar3)) {
        iVar3 = sk_num((_STACK *)pXVar6);
        pXVar5 = (X509 *)sk_value((_STACK *)pXVar6,iVar3 + -1);
        X509_check_purpose(pXVar5,-1,0);
        if ((int)(pXVar5->ex_flags << 0x12) < 0) {
          pXVar5 = (X509 *)sk_pop((_STACK *)pXVar6);
          X509_free(pXVar5);
        }
      }
      if (iVar1 == 0) {
        iVar1 = 1;
      }
      ppXVar8[3] = pXVar6;
    }
  }
joined_r0x0007e4da:
  if ((param_3 & 4) != 0) {
    X509_STORE_free(param_2);
  }
  return iVar1;
}

