
int X509_load_cert_crl_file(X509_LOOKUP *ctx,char *file,int type)

{
  int iVar1;
  BIO *bp;
  stack_st_X509_INFO *psVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  if (type != 1) {
    iVar1 = X509_load_cert_file(ctx,file,type);
    return iVar1;
  }
  bp = BIO_new_file(file,"r");
  if (bp == (BIO *)0x0) {
    ERR_put_error(0xb,0x84,2,"crypto/x509/by_file.c",199);
    iVar1 = 0;
  }
  else {
    psVar2 = PEM_X509_INFO_read_bio(bp,(stack_st_X509_INFO *)0x0,(undefined1 *)0x0,"");
    BIO_free(bp);
    if (psVar2 == (stack_st_X509_INFO *)0x0) {
      ERR_put_error(0xb,0x84,9,"crypto/x509/by_file.c",0xcd);
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
      iVar5 = 0;
      while( true ) {
        iVar3 = OPENSSL_sk_num(psVar2);
        iVar6 = iVar5 + 1;
        if (iVar3 <= iVar5) break;
        puVar4 = (undefined4 *)OPENSSL_sk_value(psVar2,iVar5);
        if ((X509 *)*puVar4 != (X509 *)0x0) {
          iVar5 = X509_STORE_add_cert(ctx->store_ctx,(X509 *)*puVar4);
          if (iVar5 == 0) goto LAB_00165474;
          iVar1 = iVar1 + 1;
        }
        iVar5 = iVar6;
        if ((X509_CRL *)puVar4[1] != (X509_CRL *)0x0) {
          iVar3 = X509_STORE_add_crl(ctx->store_ctx,(X509_CRL *)puVar4[1]);
          if (iVar3 == 0) goto LAB_00165474;
          iVar1 = iVar1 + 1;
        }
      }
      if (iVar1 == 0) {
        ERR_put_error(0xb,0x84,0x88,"crypto/x509/by_file.c",0xdf);
      }
LAB_00165474:
      OPENSSL_sk_pop_free(psVar2,0x186c3d);
    }
  }
  return iVar1;
}

