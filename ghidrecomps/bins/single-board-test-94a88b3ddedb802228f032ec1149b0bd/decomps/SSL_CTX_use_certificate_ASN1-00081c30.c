
int SSL_CTX_use_certificate_ASN1(SSL_CTX *ctx,int len,uchar *d)

{
  X509 *a;
  int iVar1;
  uchar *local_14;
  
  local_14 = d;
  a = d2i_X509((X509 **)0x0,&local_14,len);
  if (a == (X509 *)0x0) {
    ERR_put_error(0x14,0xac,0xd,DAT_00081c98,0x1ea);
    iVar1 = 0;
  }
  else {
    iVar1 = ssl_cert_inst(&ctx->cert);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xab,0x41,DAT_00081c98,0x176);
      iVar1 = 0;
    }
    else {
      iVar1 = ssl_set_cert(ctx->cert,a);
    }
    X509_free(a);
  }
  return iVar1;
}

