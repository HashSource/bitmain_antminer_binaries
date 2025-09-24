
int X509_verify_cert(X509_STORE_CTX *ctx)

{
  int iVar1;
  int iVar2;
  int iVar3;
  stack_st_void *psVar4;
  stack_st_void *psVar5;
  
  if (ctx->current_method == 0) {
    iVar3 = 0x104;
    iVar1 = 0x69;
LAB_0016a634:
    ERR_put_error(0xb,0x7f,iVar1,"crypto/x509/x509_vfy.c",iVar3);
    ctx->error_depth = 0x45;
    return -1;
  }
  if (ctx->last_untrusted != 0) {
    iVar3 = 0x10e;
    iVar1 = 0x42;
    goto LAB_0016a634;
  }
  psVar4 = (ctx->ex_data).sk;
  iVar1 = X509_up_ref();
  if (iVar1 == 0) {
    ERR_put_error(0xb,0x7f,0x44,"crypto/x509/x509_vfy.c",0x114);
    ctx->error_depth = 1;
    return -1;
  }
  iVar1 = OPENSSL_sk_new_null();
  ctx->last_untrusted = iVar1;
  if ((iVar1 == 0) || (iVar1 = OPENSSL_sk_push(iVar1,ctx->current_method), iVar1 == 0)) {
    X509_free((X509 *)ctx->current_method);
    ERR_put_error(0xb,0x7f,0x41,"crypto/x509/x509_vfy.c",0x120);
    ctx->error_depth = 0x11;
    return -1;
  }
  ctx->valid = 1;
  iVar1 = X509_get0_pubkey(ctx->current_method);
  iVar3 = ctx->crls[1].stack.sorted;
  if (0 < iVar3) {
    if (iVar1 != 0) {
      iVar1 = EVP_PKEY_security_bits();
      if (4 < iVar3) {
        iVar3 = 5;
      }
      if (*(int *)(&minbits_table + (iVar3 + -1) * 4) <= iVar1) goto LAB_0016a528;
    }
    iVar1 = ctx->current_method;
    ctx->explicit_policy = 0;
    if (iVar1 == 0) {
      iVar1 = OPENSSL_sk_value(ctx->last_untrusted);
    }
    ctx->error = iVar1;
    ctx->error_depth = 0x42;
    iVar1 = (*ctx->verify)((X509_STORE_CTX *)0x0);
    if (iVar1 == 0) {
      return 0;
    }
  }
LAB_0016a528:
  if ((psVar4 == (stack_st_void *)0x0) || (iVar1 = OPENSSL_sk_num((psVar4->stack).data), iVar1 < 1))
  {
LAB_0016a5b4:
    iVar1 = verify_chain(ctx);
  }
  else {
    psVar5 = (ctx->ex_data).sk;
    iVar3 = ctx->current_method;
    X509_free((X509 *)(psVar5->stack).comp);
    (psVar5->stack).comp = (_func_290 *)0x0;
    (psVar5->stack).num_alloc = 0;
    psVar5[1].stack.data = (char **)0xffffffff;
    psVar4 = (ctx->ex_data).sk;
    iVar1 = ctx->current_method;
    psVar5[1].stack.sorted = -1;
    iVar1 = dane_match_isra_1(ctx->valid,psVar4,iVar1,0);
    if (iVar1 == 0) {
      if (((psVar5[1].stack.num & 5U) != 0) || (-1 < (int)psVar5[1].stack.data)) goto LAB_0016a5b4;
      X509_get_pubkey_parameters((EVP_PKEY *)0x0,(stack_st_X509 *)ctx->last_untrusted);
      iVar1 = X509_chain_check_suiteb(0,iVar3,0,(ctx->crls->stack).num_alloc);
      if (iVar1 != 0) {
        ctx->explicit_policy = 0;
        if (iVar3 == 0) {
          iVar3 = OPENSSL_sk_value(ctx->last_untrusted,0);
          ctx->error_depth = iVar1;
          ctx->error = iVar3;
          iVar1 = (*ctx->verify)((X509_STORE_CTX *)0x0);
          if (iVar1 != 0) {
            ctx->explicit_policy = 0;
            goto LAB_0016a718;
          }
        }
        else {
          ctx->error = iVar3;
          ctx->error_depth = iVar1;
          iVar1 = (*ctx->verify)((X509_STORE_CTX *)0x0);
          if (iVar1 != 0) {
            ctx->explicit_policy = 0;
            goto LAB_0016a618;
          }
        }
LAB_0016a596:
        iVar1 = 0;
        goto LAB_0016a598;
      }
      ctx->explicit_policy = 0;
      if (iVar3 == 0) {
LAB_0016a718:
        iVar3 = OPENSSL_sk_value(ctx->last_untrusted,0);
      }
LAB_0016a618:
      ctx->error = iVar3;
      ctx->error_depth = 0x41;
      iVar1 = (*ctx->verify)((X509_STORE_CTX *)0x0);
    }
    else {
      X509_get_pubkey_parameters((EVP_PKEY *)0x0,(stack_st_X509 *)ctx->last_untrusted);
      if (iVar1 < 1) {
        ctx->explicit_policy = 0;
        ctx->error = iVar3;
        ctx->error_depth = 0x11;
        return -1;
      }
      iVar1 = X509_chain_check_suiteb(0,iVar3,0,(ctx->crls->stack).num_alloc);
      if (iVar1 != 0) {
        ctx->explicit_policy = 0;
        iVar2 = iVar3;
        if (iVar3 == 0) {
          iVar2 = OPENSSL_sk_value(ctx->last_untrusted,0);
        }
        ctx->error = iVar2;
        ctx->error_depth = iVar1;
        iVar1 = (*ctx->verify)((X509_STORE_CTX *)0x0);
        if (iVar1 == 0) goto LAB_0016a596;
      }
      if ((-1 < psVar5[1].stack.num_alloc << 0x1f) && (iVar1 = check_id(ctx), iVar1 == 0))
      goto LAB_0016a596;
      ctx->error = iVar3;
      ctx->explicit_policy = 0;
      iVar1 = (*ctx->verify)((X509_STORE_CTX *)0x1);
    }
  }
  if (0 < iVar1) {
    return iVar1;
  }
LAB_0016a598:
  if (ctx->error_depth != 0) {
    return iVar1;
  }
  ctx->error_depth = 1;
  return iVar1;
}

