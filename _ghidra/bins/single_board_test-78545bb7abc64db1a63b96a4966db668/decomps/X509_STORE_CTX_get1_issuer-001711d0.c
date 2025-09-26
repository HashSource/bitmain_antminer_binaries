
int X509_STORE_CTX_get1_issuer(X509 **issuer,X509_STORE_CTX *ctx,X509 *x)

{
  int iVar1;
  X509_NAME *name;
  int iVar2;
  int *piVar3;
  X509_NAME *b;
  X509 *pXVar4;
  int iVar5;
  X509_STORE *pXVar6;
  int local_2c;
  
  iVar1 = X509_OBJECT_new();
  pXVar6 = ctx->ctx;
  if (iVar1 == 0) {
    pXVar6 = (X509_STORE *)0xffffffff;
  }
  else {
    *issuer = (X509 *)0x0;
    name = X509_get_issuer_name(x);
    iVar2 = X509_STORE_CTX_get_by_subject(ctx,1,name,iVar1);
    if (iVar2 == 1) {
      iVar2 = (*ctx->get_issuer)((X509 **)ctx,(X509_STORE_CTX *)x,*(X509 **)(iVar1 + 4));
      if ((iVar2 == 0) ||
         (iVar2 = x509_check_cert_time(ctx,*(undefined4 *)(iVar1 + 4),0xffffffff), iVar2 == 0)) {
        X509_OBJECT_free(iVar1);
        if (pXVar6 != (X509_STORE *)0x0) {
          X509_STORE_lock();
          iVar1 = X509_OBJECT_idx_by_subject(pXVar6->objs,1,name);
          local_2c = 0;
          if (iVar1 != -1) {
            do {
              do {
                iVar2 = OPENSSL_sk_num(pXVar6->objs);
                iVar5 = iVar1 + 1;
                if ((iVar2 <= iVar1) ||
                   (piVar3 = (int *)OPENSSL_sk_value(pXVar6->objs,iVar1), *piVar3 != 1))
                goto LAB_001712cc;
                b = X509_get_subject_name((X509 *)piVar3[1]);
                iVar1 = X509_NAME_cmp(name,b);
                if (iVar1 != 0) goto LAB_001712cc;
                iVar2 = (*ctx->get_issuer)((X509 **)ctx,(X509_STORE_CTX *)x,(X509 *)piVar3[1]);
                iVar1 = iVar5;
              } while (iVar2 == 0);
              pXVar4 = (X509 *)piVar3[1];
              *issuer = pXVar4;
              iVar2 = x509_check_cert_time(ctx,pXVar4,0xffffffff);
              local_2c = 1;
            } while (iVar2 == 0);
          }
LAB_001712cc:
          if ((*issuer != (X509 *)0x0) && (iVar1 = X509_up_ref(), iVar1 == 0)) {
            *issuer = (X509 *)0x0;
            local_2c = -1;
          }
          X509_STORE_unlock(pXVar6);
          return local_2c;
        }
      }
      else {
        *issuer = *(X509 **)(iVar1 + 4);
        iVar2 = X509_up_ref();
        pXVar6 = (X509_STORE *)0x1;
        if (iVar2 == 0) {
          pXVar6 = (X509_STORE *)0xffffffff;
          *issuer = (X509 *)0x0;
        }
        X509_OBJECT_free(iVar1);
      }
    }
    else {
      X509_OBJECT_free(iVar1);
      pXVar6 = (X509_STORE *)0x0;
    }
  }
  return (int)pXVar6;
}

