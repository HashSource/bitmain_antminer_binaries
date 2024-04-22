
int PKCS7_dataVerify(X509_STORE *cert_store,X509_STORE_CTX *ctx,BIO *bio,PKCS7 *p7,
                    PKCS7_SIGNER_INFO *si)

{
  int iVar1;
  X509 *x509;
  stack_st_X509 *sk;
  
  if (p7 == (PKCS7 *)0x0) {
    ERR_put_error(0x21,0x6b,0x8f,DAT_000d0eac,0x3d1);
  }
  else if ((p7->d).ptr == (char *)0x0) {
    ERR_put_error(0x21,0x6b,0x7a,DAT_000d0eac,0x3d6);
  }
  else {
    iVar1 = OBJ_obj2nid(p7->type);
    if ((iVar1 == 0x16) || (iVar1 = OBJ_obj2nid(p7->type), iVar1 == 0x18)) {
      sk = ((p7->d).sign)->cert;
      x509 = X509_find_by_issuer_and_serial
                       (sk,si->issuer_and_serial->issuer,si->issuer_and_serial->serial);
      if (x509 == (X509 *)0x0) {
        ERR_put_error(0x21,0x6b,0x6a,DAT_000d0eac,0x3ea);
      }
      else {
        iVar1 = X509_STORE_CTX_init(ctx,cert_store,x509,sk);
        if (iVar1 == 0) {
          ERR_put_error(0x21,0x6b,0xb,DAT_000d0eac,0x3f0);
        }
        else {
          X509_STORE_CTX_set_purpose(ctx,4);
          iVar1 = X509_verify_cert(ctx);
          if (0 < iVar1) {
            X509_STORE_CTX_cleanup(ctx);
            iVar1 = PKCS7_signatureVerify(bio,p7,si,x509);
            return iVar1;
          }
          ERR_put_error(0x21,0x6b,0xb,DAT_000d0eac,0x3f6);
          X509_STORE_CTX_cleanup(ctx);
        }
      }
    }
    else {
      ERR_put_error(0x21,0x6b,0x72,DAT_000d0eac,0x3df);
    }
  }
  return 0;
}

