
int PEM_X509_INFO_write_bio
              (BIO *bp,X509_INFO *xi,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cd,void *u)

{
  int iVar1;
  char *pcVar2;
  int n;
  size_t sVar3;
  X509 *x;
  uchar *data;
  undefined auStack_4b4 [140];
  char local_428 [1028];
  
  if (enc != (EVP_CIPHER *)0x0) {
    iVar1 = EVP_CIPHER_nid(enc);
    pcVar2 = OBJ_nid2sn(iVar1);
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(9,0x75,0x71,DAT_0010ae40,0x13b);
      iVar1 = 0;
      goto LAB_0010ad94;
    }
  }
  if (xi->x_pkey == (X509_PKEY *)0x0) {
LAB_0010add6:
    x = xi->x509;
  }
  else {
    data = (uchar *)xi->enc_data;
    if ((data == (uchar *)0x0) || (iVar1 = xi->enc_len, iVar1 < 1)) {
      iVar1 = PEM_write_bio_RSAPrivateKey(bp,(xi->x_pkey->dec_pkey->pkey).rsa,enc,kstr,klen,cd,u);
      if (iVar1 < 1) {
LAB_0010ade4:
        iVar1 = 0;
        goto LAB_0010ad94;
      }
      goto LAB_0010add6;
    }
    if (enc == (EVP_CIPHER *)0x0) {
      ERR_put_error(9,0x75,0x7f,DAT_0010ae40,0x148);
      iVar1 = 0;
      goto LAB_0010ad94;
    }
    n = EVP_CIPHER_nid((xi->enc_cipher).cipher);
    pcVar2 = OBJ_nid2sn(n);
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(9,0x75,0x71,DAT_0010ae40,0x159);
      iVar1 = 0;
      goto LAB_0010ad94;
    }
    sVar3 = strlen(pcVar2);
    if (0x400 < sVar3 + enc->iv_len * 2 + 0x24) {
      OpenSSLDie(DAT_0010ae40,0x15f,DAT_0010ae44);
    }
    local_428[0] = '\0';
    PEM_proc_type(local_428,10);
    PEM_dek_info(local_428,pcVar2,enc->iv_len,(char *)(xi->enc_cipher).iv);
    iVar1 = PEM_write_bio(bp,DAT_0010ae3c,local_428,data,iVar1);
    if (iVar1 < 1) goto LAB_0010ade4;
    x = xi->x509;
  }
  if (x == (X509 *)0x0) {
    iVar1 = 1;
  }
  else {
    iVar1 = PEM_write_bio_X509(bp,x);
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
LAB_0010ad94:
  OPENSSL_cleanse(auStack_4b4,0x8c);
  OPENSSL_cleanse(local_428,0x400);
  return iVar1;
}

