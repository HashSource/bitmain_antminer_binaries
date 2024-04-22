
uchar * PKCS12_pbe_crypt(X509_ALGOR *algor,char *pass,int passlen,uchar *in,int inlen,uchar **data,
                        int *datalen,int en_de)

{
  int iVar1;
  uchar *out;
  int iVar2;
  int local_b0;
  EVP_CIPHER_CTX EStack_ac;
  
  EVP_CIPHER_CTX_init(&EStack_ac);
  iVar1 = EVP_PBE_CipherInit(algor->algorithm,pass,passlen,algor->parameter,&EStack_ac,en_de);
  if (iVar1 == 0) {
    ERR_put_error(0x23,0x77,0x73,DAT_0010efd0,0x57);
    out = (uchar *)0x0;
  }
  else {
    iVar1 = EVP_CIPHER_CTX_block_size(&EStack_ac);
    out = (uchar *)CRYPTO_malloc(iVar1 + inlen,DAT_0010efd0,0x5b);
    if (out == (uchar *)0x0) {
      ERR_put_error(0x23,0x77,0x41,DAT_0010efd0,0x5c);
    }
    else {
      iVar2 = EVP_CipherUpdate(&EStack_ac,out,&local_b0,in,inlen);
      iVar1 = local_b0;
      if (iVar2 == 0) {
        CRYPTO_free(out);
        ERR_put_error(0x23,0x77,6,DAT_0010efd0,99);
        out = (uchar *)0x0;
      }
      else {
        iVar2 = EVP_CipherFinal_ex(&EStack_ac,out + local_b0,&local_b0);
        if (iVar2 == 0) {
          CRYPTO_free(out);
          ERR_put_error(0x23,0x77,0x74,DAT_0010efd0,0x6c);
          out = (uchar *)0x0;
        }
        else {
          if (datalen != (int *)0x0) {
            *datalen = iVar1 + local_b0;
          }
          if (data != (uchar **)0x0) {
            *data = out;
          }
        }
      }
    }
    EVP_CIPHER_CTX_cleanup(&EStack_ac);
  }
  return out;
}

