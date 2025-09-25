
uchar * PKCS12_pbe_crypt(X509_ALGOR *algor,char *pass,int passlen,uchar *in,int inlen,uchar **data,
                        int *datalen,int en_de)

{
  EVP_CIPHER_CTX *ctx;
  int iVar1;
  uchar *out;
  int iVar2;
  int local_2c [2];
  
  ctx = EVP_CIPHER_CTX_new();
  if (ctx == (EVP_CIPHER_CTX *)0x0) {
    ERR_put_error(0x23,0x77,0x41,"crypto/pkcs12/p12_decr.c",0x21);
    out = (uchar *)0x0;
  }
  else {
    iVar1 = EVP_PBE_CipherInit(algor->algorithm,pass,passlen,algor->parameter,ctx,en_de);
    if (iVar1 == 0) {
      ERR_put_error(0x23,0x77,0x73,"crypto/pkcs12/p12_decr.c",0x29);
      out = (uchar *)0x0;
    }
    else {
      iVar1 = EVP_CIPHER_CTX_block_size(ctx);
      out = (uchar *)CRYPTO_malloc(iVar1 + inlen,"crypto/pkcs12/p12_decr.c",0x2d);
      if (out == (uchar *)0x0) {
        ERR_put_error(0x23,0x77,0x41,"crypto/pkcs12/p12_decr.c",0x2f);
      }
      else {
        iVar2 = EVP_CipherUpdate(ctx,out,local_2c,in,inlen);
        iVar1 = local_2c[0];
        if (iVar2 == 0) {
          CRYPTO_free(out);
          ERR_put_error(0x23,0x77,6,"crypto/pkcs12/p12_decr.c",0x36);
          out = (uchar *)0x0;
        }
        else {
          iVar2 = EVP_CipherFinal_ex(ctx,out + local_2c[0],local_2c);
          if (iVar2 == 0) {
            CRYPTO_free(out);
            ERR_put_error(0x23,0x77,0x74,"crypto/pkcs12/p12_decr.c",0x3f);
            out = (uchar *)0x0;
          }
          else {
            if (datalen != (int *)0x0) {
              *datalen = local_2c[0] + iVar1;
            }
            if (data != (uchar **)0x0) {
              *data = out;
            }
          }
        }
      }
    }
  }
  EVP_CIPHER_CTX_free(ctx);
  return out;
}

