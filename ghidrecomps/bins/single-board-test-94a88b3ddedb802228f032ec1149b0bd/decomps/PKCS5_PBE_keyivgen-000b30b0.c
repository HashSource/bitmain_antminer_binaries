
int PKCS5_PBE_keyivgen(EVP_CIPHER_CTX *ctx,char *pass,int passlen,ASN1_TYPE *param,
                      EVP_CIPHER *cipher,EVP_MD *md,int en_de)

{
  PBEPARAM *a;
  int iVar1;
  int iVar2;
  ASN1_STRING *pAVar3;
  size_t sVar4;
  uchar *d;
  long lVar5;
  uchar *local_cc;
  uchar auStack_c8 [16];
  EVP_MD_CTX EStack_b8;
  uchar auStack_a0 [16];
  undefined auStack_90 [48];
  uchar auStack_60 [64];
  
  EVP_MD_CTX_init(&EStack_b8);
  if (((param == (ASN1_TYPE *)0x0) || (param->type != 0x10)) ||
     (pAVar3 = (param->value).asn1_string, pAVar3 == (ASN1_STRING *)0x0)) {
    ERR_put_error(6,0x75,0x72,DAT_000b3264,0x5d);
    return 0;
  }
  local_cc = pAVar3->data;
  a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_cc,pAVar3->length);
  if (a == (PBEPARAM *)0x0) {
    ERR_put_error(6,0x75,0x72,DAT_000b3264,99);
    return 0;
  }
  lVar5 = 1;
  if (a->iter != (ASN1_INTEGER *)0x0) {
    lVar5 = ASN1_INTEGER_get(a->iter);
  }
  d = a->salt->data;
  sVar4 = a->salt->length;
  if (pass == (char *)0x0) {
    passlen = 0;
  }
  else if (passlen == -1) {
    passlen = strlen(pass);
  }
  iVar1 = EVP_DigestInit_ex(&EStack_b8,md,(ENGINE *)0x0);
  if (((iVar1 != 0) && (iVar1 = EVP_DigestUpdate(&EStack_b8,pass,passlen), iVar1 != 0)) &&
     (iVar1 = EVP_DigestUpdate(&EStack_b8,d,sVar4), iVar1 != 0)) {
    PBEPARAM_free(a);
    iVar1 = EVP_DigestFinal_ex(&EStack_b8,auStack_a0,(uint *)0x0);
    if (iVar1 != 0) {
      sVar4 = EVP_MD_size(md);
      if ((int)sVar4 < 0) {
        return 0;
      }
      if (1 < lVar5) {
        iVar1 = 1;
        do {
          iVar1 = iVar1 + 1;
          iVar2 = EVP_DigestInit_ex(&EStack_b8,md,(ENGINE *)0x0);
          if (iVar2 == 0) goto LAB_000b312e;
          iVar2 = EVP_DigestUpdate(&EStack_b8,auStack_a0,sVar4);
          if ((iVar2 == 0) ||
             (iVar2 = EVP_DigestFinal_ex(&EStack_b8,auStack_a0,(uint *)0x0), iVar2 == 0))
          goto LAB_000b312e;
        } while (iVar1 != lVar5);
      }
      iVar1 = EVP_CIPHER_key_length(cipher);
      if (0x40 < iVar1) {
        OpenSSLDie(DAT_000b3264,0x87,DAT_000b3268);
      }
      sVar4 = EVP_CIPHER_key_length(cipher);
      memcpy(auStack_60,auStack_a0,sVar4);
      iVar1 = EVP_CIPHER_iv_length(cipher);
      if (0x10 < iVar1) {
        OpenSSLDie(DAT_000b3264,0x89,DAT_000b326c);
      }
      iVar1 = EVP_CIPHER_iv_length(cipher);
      sVar4 = EVP_CIPHER_iv_length(cipher);
      memcpy(auStack_c8,auStack_90 + -iVar1,sVar4);
      iVar1 = EVP_CipherInit_ex(ctx,cipher,(ENGINE *)0x0,auStack_60,auStack_c8,en_de);
      if (iVar1 != 0) {
        OPENSSL_cleanse(auStack_a0,0x40);
        OPENSSL_cleanse(auStack_60,0x40);
        iVar1 = 1;
        OPENSSL_cleanse(auStack_c8,0x10);
        goto LAB_000b3130;
      }
    }
  }
LAB_000b312e:
  iVar1 = 0;
LAB_000b3130:
  EVP_MD_CTX_cleanup(&EStack_b8);
  return iVar1;
}

