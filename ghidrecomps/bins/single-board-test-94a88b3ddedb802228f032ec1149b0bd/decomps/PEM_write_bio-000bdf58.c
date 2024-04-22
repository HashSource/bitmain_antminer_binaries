
int PEM_write_bio(BIO *bp,char *name,char *hdr,uchar *data,long len)

{
  size_t sVar1;
  int iVar2;
  size_t len_00;
  size_t sVar3;
  uchar *out;
  int iVar4;
  uchar *in;
  long inl;
  int iVar5;
  int local_8c;
  EVP_ENCODE_CTX EStack_88;
  
  EVP_EncodeInit(&EStack_88);
  sVar1 = strlen(name);
  iVar2 = BIO_write(bp,DAT_000be0d0,0xb);
  if ((((iVar2 == 0xb) && (len_00 = BIO_write(bp,name,sVar1), len_00 == sVar1)) &&
      (iVar2 = BIO_write(bp,DAT_000be0d8,6), iVar2 == 6)) &&
     ((sVar1 = strlen(hdr), (int)sVar1 < 1 ||
      ((sVar3 = BIO_write(bp,hdr,sVar1), sVar3 == sVar1 &&
       (iVar2 = BIO_write(bp,DAT_000be0dc,1), iVar2 == 1)))))) {
    out = (uchar *)CRYPTO_malloc(0x2000,DAT_000be0d4,0x26d);
    if (out == (uchar *)0x0) {
      iVar2 = 0x41;
      goto LAB_000bdf84;
    }
    if (len < 1) {
      iVar2 = 0;
    }
    else {
      iVar5 = 0;
      iVar2 = 0;
      do {
        in = data + iVar5;
        inl = len;
        if (0x13ff < len) {
          inl = 0x1400;
        }
        iVar5 = iVar5 + inl;
        EVP_EncodeUpdate(&EStack_88,out,&local_8c,in,inl);
        len = len - inl;
        if ((local_8c != 0) && (iVar4 = BIO_write(bp,out,local_8c), iVar4 != local_8c))
        goto LAB_000be046;
        iVar2 = iVar2 + local_8c;
      } while (0 < len);
    }
    EVP_EncodeFinal(&EStack_88,out,&local_8c);
    if ((0 < local_8c) && (iVar5 = BIO_write(bp,out,local_8c), iVar5 != local_8c)) {
LAB_000be046:
      OPENSSL_cleanse(out,0x2000);
      CRYPTO_free(out);
      iVar2 = 7;
      goto LAB_000bdf84;
    }
    OPENSSL_cleanse(out,0x2000);
    CRYPTO_free(out);
    iVar5 = BIO_write(bp,DAT_000be0e0,9);
    if ((iVar5 == 9) &&
       ((sVar1 = BIO_write(bp,name,len_00), len_00 == sVar1 &&
        (iVar5 = BIO_write(bp,DAT_000be0d8,6), iVar5 == 6)))) {
      return local_8c + iVar2;
    }
  }
  iVar2 = 7;
LAB_000bdf84:
  ERR_put_error(9,0x72,iVar2,DAT_000be0d4,0x28d);
  return 0;
}

