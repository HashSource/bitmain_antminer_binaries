
int ssl_build_cert_chain(undefined4 *param_1,X509_STORE *param_2,uint param_3)

{
  int iVar1;
  _STACK *st;
  X509_STORE *ctx;
  ulong uVar2;
  int iVar3;
  char *pcVar4;
  stack_st_X509 *chain;
  X509 *pXVar5;
  int iVar6;
  int *piVar7;
  X509_STORE_CTX XStack_a8;
  
  piVar7 = (int *)*param_1;
  pXVar5 = (X509 *)*piVar7;
  if (pXVar5 == (X509 *)0x0) {
    ERR_put_error(0x14,0x14c,0xb3,"ssl_cert.c",0x484);
    iVar1 = 0;
  }
  else {
    if ((param_3 & 4) == 0) {
      ctx = (X509_STORE *)param_1[0x53];
      if ((X509_STORE *)param_1[0x53] == (X509_STORE *)0x0) {
        ctx = param_2;
      }
      if ((int)(param_3 << 0x1f) < 0) {
        chain = (stack_st_X509 *)piVar7[3];
      }
      else {
        chain = (stack_st_X509 *)0x0;
      }
    }
    else {
      ctx = X509_STORE_new();
      iVar1 = 0;
      if (ctx == (X509_STORE *)0x0) {
LAB_0011aa56:
        X509_STORE_free(ctx);
        return 0;
      }
      while( true ) {
        iVar3 = sk_num((_STACK *)piVar7[3]);
        iVar6 = iVar1 + 1;
        if (iVar3 <= iVar1) break;
        pXVar5 = (X509 *)sk_value((_STACK *)piVar7[3],iVar1);
        iVar3 = X509_STORE_add_cert(ctx,pXVar5);
        iVar1 = iVar6;
        if (iVar3 == 0) {
          uVar2 = ERR_peek_last_error();
          if ((uVar2 >> 0x18 != 0xb) || ((uVar2 & 0xfff) != 0x65)) goto LAB_0011aa56;
          ERR_clear_error();
        }
      }
      iVar1 = X509_STORE_add_cert(ctx,(X509 *)*piVar7);
      if (iVar1 == 0) {
        uVar2 = ERR_peek_last_error();
        if ((uVar2 >> 0x18 != 0xb) || ((uVar2 & 0xfff) != 0x65)) goto LAB_0011aa56;
        ERR_clear_error();
        pXVar5 = (X509 *)*piVar7;
        chain = (stack_st_X509 *)0x0;
      }
      else {
        pXVar5 = (X509 *)*piVar7;
        chain = (stack_st_X509 *)0x0;
      }
    }
    iVar1 = X509_STORE_CTX_init(&XStack_a8,ctx,pXVar5,chain);
    param_2 = ctx;
    if (iVar1 == 0) {
      ERR_put_error(0x14,0x14c,0xb,"ssl_cert.c",0x4a8);
      iVar1 = 0;
    }
    else {
      X509_STORE_CTX_set_flags(&XStack_a8,param_1[0xe] & 0x30000);
      iVar1 = X509_verify_cert(&XStack_a8);
      if (iVar1 < 1) {
        if ((param_3 & 8) == 0) {
          ERR_put_error(0x14,0x14c,0x86,"ssl_cert.c",0x4b9);
          iVar1 = X509_STORE_CTX_get_error(&XStack_a8);
          pcVar4 = X509_verify_cert_error_string(iVar1);
          ERR_add_error_data(2,"Verify error:",pcVar4);
          X509_STORE_CTX_cleanup(&XStack_a8);
          iVar1 = 0;
          goto joined_r0x0011a9ae;
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
      st = &X509_STORE_CTX_get1_chain(&XStack_a8)->stack;
      X509_STORE_CTX_cleanup(&XStack_a8);
      if ((_STACK *)piVar7[3] != (_STACK *)0x0) {
        sk_pop_free((_STACK *)piVar7[3],X509_free);
      }
      pXVar5 = (X509 *)sk_shift(st);
      X509_free(pXVar5);
      if (((int)(param_3 << 0x1e) < 0) && (iVar3 = sk_num(st), 0 < iVar3)) {
        iVar3 = sk_num(st);
        pXVar5 = (X509 *)sk_value(st,iVar3 + -1);
        X509_check_purpose(pXVar5,-1,0);
        if ((int)(pXVar5->ex_flags << 0x12) < 0) {
          pXVar5 = (X509 *)sk_pop(st);
          X509_free(pXVar5);
        }
      }
      if (iVar1 == 0) {
        iVar1 = 1;
      }
      piVar7[3] = (int)st;
    }
  }
joined_r0x0011a9ae:
  if ((param_3 & 4) != 0) {
    X509_STORE_free(param_2);
  }
  return iVar1;
}

