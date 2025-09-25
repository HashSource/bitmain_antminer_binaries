
int PEM_write_bio(BIO *bp,char *name,char *hdr,uchar *data,long len)

{
  EVP_ENCODE_CTX *ctx;
  size_t len_00;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  int extraout_r0;
  int iVar4;
  long inl;
  uchar *in;
  uchar *out;
  int iVar5;
  int *local_38;
  int local_2c [2];
  
  ctx = (EVP_ENCODE_CTX *)EVP_ENCODE_CTX_new();
  if (ctx == (EVP_ENCODE_CTX *)0x0) {
LAB_001417d8:
    iVar1 = 0x41;
    out = (uchar *)0x0;
  }
  else {
    EVP_EncodeInit(ctx);
    len_00 = strlen(name);
    iVar1 = BIO_write(bp,"-----BEGIN ",0xb);
    if ((((iVar1 == 0xb) && (sVar2 = BIO_write(bp,name,len_00), len_00 == sVar2)) &&
        (iVar1 = BIO_write(bp,"-----\n",6), iVar1 == 6)) &&
       (((hdr == (char *)0x0 || (sVar2 = strlen(hdr), (int)sVar2 < 1)) ||
        ((sVar3 = BIO_write(bp,hdr,sVar2), sVar2 == sVar3 &&
         (iVar1 = BIO_write(bp,"\n",1), iVar1 == 1)))))) {
      out = (uchar *)CRYPTO_malloc(0x2000,"crypto/pem/pem_lib.c",0x276);
      if (out == (uchar *)0x0) goto LAB_001417d8;
      if (len < 1) {
        iVar5 = 0;
      }
      else {
        iVar1 = 0;
        iVar5 = 0;
        do {
          inl = len;
          if (0x13ff < len) {
            inl = 0x1400;
          }
          in = data + iVar1;
          len = len - inl;
          iVar1 = iVar1 + inl;
          EVP_EncodeUpdate(ctx,out,local_2c,in,inl);
          if ((extraout_r0 == 0) ||
             ((local_2c[0] != 0 && (iVar4 = BIO_write(bp,out,local_2c[0]), iVar4 != local_2c[0]))))
          goto LAB_00141898;
          iVar5 = iVar5 + local_2c[0];
        } while (0 < len);
      }
      local_38 = local_2c;
      EVP_EncodeFinal(ctx,out,local_38);
      if (((((local_2c[0] < 1) || (iVar1 = BIO_write(bp,out,local_2c[0]), iVar1 == local_2c[0])) &&
           (iVar1 = BIO_write(bp,"-----END ",9), iVar1 == 9)) &&
          ((sVar2 = BIO_write(bp,name,len_00), len_00 == sVar2 &&
           (iVar1 = BIO_write(bp,"-----\n",6), iVar1 == 6)))) &&
         (iVar5 = iVar5 + local_2c[0], iVar5 != 0)) goto LAB_001417b8;
LAB_00141898:
      iVar1 = 7;
    }
    else {
      iVar1 = 7;
      out = (uchar *)0x0;
    }
  }
  iVar5 = 0;
  ERR_put_error(9,0x72,iVar1,"crypto/pem/pem_lib.c",0x292);
LAB_001417b8:
  EVP_ENCODE_CTX_free(ctx);
  CRYPTO_clear_free(out,0x2000,"crypto/pem/pem_lib.c",0x294);
  return iVar5;
}

