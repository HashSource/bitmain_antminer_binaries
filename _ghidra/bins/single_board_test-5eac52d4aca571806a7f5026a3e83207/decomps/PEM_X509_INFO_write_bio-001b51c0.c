
int PEM_X509_INFO_write_bio
              (BIO *bp,X509_INFO *xi,EVP_CIPHER *enc,uchar *kstr,int klen,undefined1 *cd,void *u)

{
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  RSA *x;
  X509 *x_00;
  uchar *data;
  char local_428 [1028];
  
  if (enc != (EVP_CIPHER *)0x0) {
    iVar1 = EVP_CIPHER_nid(enc);
    pcVar2 = OBJ_nid2sn(iVar1);
    if (pcVar2 != (char *)0x0) {
      sVar3 = strlen(pcVar2);
      iVar1 = EVP_CIPHER_iv_length(enc);
      if (sVar3 + 0x24 + iVar1 * 2 < 0x401) goto LAB_001b51f8;
    }
    iVar1 = 0;
    ERR_put_error(9,0x75,0x71,"crypto/pem/pem_info.c",0x10a);
    goto LAB_001b5274;
  }
LAB_001b51f8:
  if (xi->x_pkey == (X509_PKEY *)0x0) {
LAB_001b52ce:
    x_00 = xi->x509;
  }
  else {
    data = (uchar *)xi->enc_data;
    if ((data == (uchar *)0x0) || (iVar1 = xi->enc_len, iVar1 < 1)) {
      x = (RSA *)EVP_PKEY_get0_RSA(xi->x_pkey->dec_pkey);
      iVar1 = PEM_write_bio_RSAPrivateKey(bp,x,enc,kstr,klen,cd,u);
      if (iVar1 < 1) {
LAB_001b52da:
        iVar1 = 0;
        goto LAB_001b5274;
      }
      goto LAB_001b52ce;
    }
    if (enc == (EVP_CIPHER *)0x0) {
      ERR_put_error(9,0x75,0x7f,"crypto/pem/pem_info.c",0x117);
      iVar1 = 0;
      goto LAB_001b5274;
    }
    iVar4 = EVP_CIPHER_nid((xi->enc_cipher).cipher);
    pcVar2 = OBJ_nid2sn(iVar4);
    if (pcVar2 == (char *)0x0) {
      ERR_put_error(9,0x75,0x71,"crypto/pem/pem_info.c",0x128);
      iVar1 = 0;
      goto LAB_001b5274;
    }
    local_428[0] = '\0';
    PEM_proc_type(local_428,10);
    iVar4 = EVP_CIPHER_iv_length(enc);
    PEM_dek_info(local_428,pcVar2,iVar4,(char *)(xi->enc_cipher).iv);
    iVar1 = PEM_write_bio(bp,"RSA PRIVATE KEY",local_428,data,iVar1);
    if (iVar1 < 1) goto LAB_001b52da;
    x_00 = xi->x509;
  }
  if (x_00 == (X509 *)0x0) {
    iVar1 = 1;
  }
  else {
    iVar1 = PEM_write_bio_X509(bp,x_00);
    if (iVar1 < 1) {
      iVar1 = 0;
    }
    else {
      iVar1 = 1;
    }
  }
LAB_001b5274:
  OPENSSL_cleanse(local_428,0x400);
  return iVar1;
}

