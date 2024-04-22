
int X509_STORE_CTX_get1_issuer(X509 **issuer,X509_STORE_CTX *ctx,X509 *x)

{
  X509_NAME *name;
  int iVar1;
  int iVar2;
  int *piVar3;
  X509_NAME *b;
  X509_OBJECT local_28;
  
  name = X509_get_issuer_name(x);
  iVar1 = X509_STORE_get_by_subject(ctx,1,name,&local_28);
  if (iVar1 == 1) {
    iVar2 = (*ctx->check_issued)(ctx,x,(X509 *)local_28.data.ptr);
    if (iVar2 == 0) {
      if (local_28.type == 1) {
        X509_free(local_28.data.x509);
      }
      else if (local_28.type == 2) {
        X509_CRL_free(local_28.data.crl);
      }
      CRYPTO_lock(9,0xb,DAT_000c4364,0x281);
      iVar1 = x509_object_idx_cnt(ctx->ctx->objs,1,name,0);
      if (iVar1 == -1) {
LAB_000c42ac:
        iVar1 = 0;
      }
      else {
        do {
          iVar2 = sk_num(&ctx->ctx->objs->stack);
          if ((iVar2 <= iVar1) ||
             (piVar3 = (int *)sk_value(&ctx->ctx->objs->stack,iVar1), *piVar3 != 1))
          goto LAB_000c42ac;
          b = X509_get_subject_name((X509 *)piVar3[1]);
          iVar2 = X509_NAME_cmp(name,b);
          if (iVar2 != 0) goto LAB_000c42ac;
          iVar2 = (*ctx->check_issued)(ctx,x,(X509 *)piVar3[1]);
          iVar1 = iVar1 + 1;
        } while (iVar2 == 0);
        iVar2 = *piVar3;
        *issuer = (X509 *)piVar3[1];
        if (iVar2 == 1) {
          CRYPTO_add_lock((int *)(piVar3[1] + 0x10),1,3,DAT_000c4364,0x197);
          iVar1 = 1;
        }
        else {
          iVar1 = 1;
          if (iVar2 == 2) {
            CRYPTO_add_lock((int *)(piVar3[1] + 0xc),1,6,DAT_000c4364,0x19a);
          }
        }
      }
      CRYPTO_lock(10,0xb,DAT_000c4364,0x295);
    }
    else {
      *issuer = (X509 *)local_28.data;
    }
  }
  else if (iVar1 == -1) {
    if (local_28.type == 1) {
      X509_free(local_28.data.x509);
    }
    else if (local_28.type == 2) {
      X509_CRL_free(local_28.data.crl);
    }
    ERR_put_error(0xb,0x92,0x6a,DAT_000c4364,0x26f);
    iVar1 = -1;
  }
  else if (iVar1 != 0) {
    if (local_28.type == 1) {
      iVar1 = -1;
      X509_free(local_28.data.x509);
    }
    else if (local_28.type == 2) {
      iVar1 = -1;
      X509_CRL_free(local_28.data.crl);
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}

