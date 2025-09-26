
int ASN1_sign(undefined1 *i2d,X509_ALGOR *algor1,X509_ALGOR *algor2,ASN1_BIT_STRING *signature,
             char *data,EVP_PKEY *pkey,EVP_MD *type)

{
  ASN1_TYPE *pAVar1;
  ASN1_OBJECT *pAVar2;
  size_t cnt;
  void *d;
  size_t len;
  uchar *md;
  int iVar3;
  void *local_48;
  uint local_44;
  EVP_MD_CTX EStack_40;
  
  local_44 = 0;
  EVP_MD_CTX_init(&EStack_40);
  if (algor1 != (X509_ALGOR *)0x0) {
    if (type->pkey_type == 0x71) {
      ASN1_TYPE_free(algor1->parameter);
      algor1->parameter = (ASN1_TYPE *)0x0;
    }
    else {
      pAVar1 = algor1->parameter;
      if ((pAVar1 == (ASN1_TYPE *)0x0) || (pAVar1->type != 5)) {
        ASN1_TYPE_free(pAVar1);
        pAVar1 = ASN1_TYPE_new();
        algor1->parameter = pAVar1;
        if (pAVar1 == (ASN1_TYPE *)0x0) goto LAB_001a01b4;
        pAVar1->type = 5;
      }
    }
    ASN1_OBJECT_free(algor1->algorithm);
    pAVar2 = OBJ_nid2obj(type->pkey_type);
    algor1->algorithm = pAVar2;
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      if (pAVar2->length != 0) goto LAB_001a005a;
LAB_001a01bc:
      ERR_put_error(0xd,0x80,0x9a,"a_sign.c",0xa9);
      goto LAB_001a01b4;
    }
LAB_001a01a4:
    ERR_put_error(0xd,0x80,0xa2,"a_sign.c",0xa4);
LAB_001a01b4:
    EVP_MD_CTX_cleanup(&EStack_40);
    return local_44;
  }
LAB_001a005a:
  if (algor2 != (X509_ALGOR *)0x0) {
    pAVar1 = algor2->parameter;
    if (type->pkey_type == 0x71) {
      ASN1_TYPE_free(pAVar1);
      algor2->parameter = (ASN1_TYPE *)0x0;
    }
    else if ((pAVar1 == (ASN1_TYPE *)0x0) || (pAVar1->type != 5)) {
      ASN1_TYPE_free(pAVar1);
      pAVar1 = ASN1_TYPE_new();
      algor2->parameter = pAVar1;
      if (pAVar1 == (ASN1_TYPE *)0x0) goto LAB_001a01b4;
      pAVar1->type = 5;
    }
    ASN1_OBJECT_free(algor2->algorithm);
    pAVar2 = OBJ_nid2obj(type->pkey_type);
    algor2->algorithm = pAVar2;
    if (pAVar2 == (ASN1_OBJECT *)0x0) goto LAB_001a01a4;
    if (pAVar2->length == 0) goto LAB_001a01bc;
  }
  cnt = (*(code *)i2d)(data,0);
  d = CRYPTO_malloc(cnt,"a_sign.c",0xae);
  len = EVP_PKEY_size(pkey);
  local_44 = len;
  md = (uchar *)CRYPTO_malloc(len,"a_sign.c",0xb0);
  if (d == (void *)0x0 || md == (uchar *)0x0) {
    local_44 = 0;
    ERR_put_error(0xd,0x80,0x41,"a_sign.c",0xb3);
    EVP_MD_CTX_cleanup(&EStack_40);
    if (d == (void *)0x0) goto LAB_001a0100;
  }
  else {
    local_48 = d;
    (*(code *)i2d)(data,&local_48);
    iVar3 = EVP_DigestInit_ex(&EStack_40,type,(ENGINE *)0x0);
    if (((iVar3 == 0) || (iVar3 = EVP_DigestUpdate(&EStack_40,d,cnt), iVar3 == 0)) ||
       (iVar3 = EVP_SignFinal(&EStack_40,md,&local_44,pkey), iVar3 == 0)) {
      local_44 = 0;
      ERR_put_error(0xd,0x80,6,"a_sign.c",0xbe);
    }
    else {
      if (signature->data != (uchar *)0x0) {
        CRYPTO_free(signature->data);
      }
      signature->data = md;
      md = (uchar *)0x0;
      signature->length = local_44;
      signature->flags = signature->flags & 0xfffffff0U | 8;
    }
    EVP_MD_CTX_cleanup(&EStack_40);
  }
  OPENSSL_cleanse(d,cnt);
  CRYPTO_free(d);
LAB_001a0100:
  if (md != (uchar *)0x0) {
    OPENSSL_cleanse(md,len);
    CRYPTO_free(md);
  }
  return local_44;
}

