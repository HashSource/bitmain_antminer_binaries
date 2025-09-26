
BIO * cms_EncryptedContent_init_bio(int param_1)

{
  bool bVar1;
  bool bVar2;
  BIO_METHOD *type;
  BIO *bp;
  int iVar3;
  ASN1_OBJECT *pAVar4;
  size_t len;
  ASN1_TYPE *type_00;
  void *ptr;
  char *name;
  EVP_CIPHER *pEVar5;
  uchar *key;
  uchar *iv;
  uchar *puVar6;
  uchar *enc;
  undefined4 *puVar7;
  EVP_CIPHER_CTX *local_3c;
  uchar auStack_38 [20];
  
  enc = *(uchar **)(param_1 + 0xc);
  puVar7 = *(undefined4 **)(param_1 + 4);
  if (enc != (uchar *)0x0) {
    enc = (uchar *)0x1;
  }
  type = BIO_f_cipher();
  bp = BIO_new(type);
  if (bp == (BIO *)0x0) {
    ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x58);
    return (BIO *)0x0;
  }
  BIO_ctrl(bp,0x81,0,&local_3c);
  if (enc == (uchar *)0x0) {
    iVar3 = OBJ_obj2nid((ASN1_OBJECT *)*puVar7);
    name = OBJ_nid2sn(iVar3);
    pEVar5 = EVP_get_cipherbyname(name);
    if (pEVar5 == (EVP_CIPHER *)0x0) {
      ERR_put_error(0x2e,0x78,0x94,"cms_enc.c",0x69);
      puVar6 = (uchar *)0x0;
      len = 0;
    }
    else {
      iVar3 = EVP_CipherInit_ex(local_3c,pEVar5,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,0);
      if (iVar3 < 1) goto LAB_00171526;
      iVar3 = EVP_CIPHER_asn1_to_param(local_3c,(ASN1_TYPE *)puVar7[1]);
      if (0 < iVar3) {
        len = EVP_CIPHER_CTX_key_length(local_3c);
        iv = (uchar *)0x0;
        goto LAB_00171424;
      }
      ERR_put_error(0x2e,0x78,0x66,"cms_enc.c",0x80);
      len = 0;
      puVar6 = enc;
    }
LAB_0017145c:
    ptr = *(void **)(param_1 + 0x10);
joined_r0x001713ca:
    if (ptr == (void *)0x0) {
      bVar2 = false;
      goto LAB_0017138e;
    }
    bVar2 = false;
  }
  else {
    pEVar5 = *(EVP_CIPHER **)(param_1 + 0xc);
    if (*(int *)(param_1 + 0x10) != 0) {
      *(undefined4 *)(param_1 + 0xc) = 0;
    }
    iv = (uchar *)0x0;
    iVar3 = EVP_CipherInit_ex(local_3c,pEVar5,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,1);
    if (iVar3 < 1) {
LAB_00171526:
      len = 0;
      ERR_put_error(0x2e,0x78,0x65,"cms_enc.c",0x70);
      puVar6 = (uchar *)0x0;
      goto LAB_0017145c;
    }
    pEVar5 = EVP_CIPHER_CTX_cipher(local_3c);
    iVar3 = EVP_CIPHER_type(pEVar5);
    pAVar4 = OBJ_nid2obj(iVar3);
    *puVar7 = pAVar4;
    iVar3 = EVP_CIPHER_CTX_iv_length(local_3c);
    if (0 < iVar3) {
      iVar3 = RAND_pseudo_bytes(auStack_38,iVar3);
      if (iVar3 < 1) {
        len = 0;
        puVar6 = iv;
        goto LAB_0017145c;
      }
      iv = auStack_38;
    }
    len = EVP_CIPHER_CTX_key_length(local_3c);
    puVar6 = (uchar *)0x0;
    if (*(int *)(param_1 + 0x10) != 0) goto LAB_00171332;
LAB_00171424:
    key = (uchar *)CRYPTO_malloc(len,"cms_enc.c",0x86);
    puVar6 = key;
    if (key == (uchar *)0x0) {
      ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0x88);
      goto LAB_0017145c;
    }
    iVar3 = EVP_CIPHER_CTX_rand_key(local_3c,key);
    if (iVar3 < 1) goto LAB_0017145c;
    if (*(int *)(param_1 + 0x10) != 0) {
LAB_00171332:
      if ((*(size_t *)(param_1 + 0x14) == len) ||
         (iVar3 = EVP_CIPHER_CTX_set_key_length(local_3c,*(size_t *)(param_1 + 0x14)), 0 < iVar3)) {
        key = *(uchar **)(param_1 + 0x10);
        bVar1 = false;
        goto LAB_00171348;
      }
      if ((enc == (uchar *)0x0) && (*(int *)(param_1 + 0x18) == 0)) {
        OPENSSL_cleanse(*(void **)(param_1 + 0x10),*(size_t *)(param_1 + 0x14));
        CRYPTO_free(*(void **)(param_1 + 0x10));
        *(uchar **)(param_1 + 0x10) = puVar6;
        *(size_t *)(param_1 + 0x14) = len;
        ERR_clear_error();
        key = *(uchar **)(param_1 + 0x10);
        bVar1 = false;
        puVar6 = enc;
        goto LAB_00171348;
      }
      ERR_put_error(0x2e,0x78,0x76,"cms_enc.c",0xa3);
      ptr = *(void **)(param_1 + 0x10);
      goto joined_r0x001713ca;
    }
    *(uchar **)(param_1 + 0x10) = key;
    *(size_t *)(param_1 + 0x14) = len;
    if (enc == (uchar *)0x0) {
      ERR_clear_error();
      puVar6 = enc;
      goto LAB_00171332;
    }
    bVar1 = true;
    puVar6 = (uchar *)0x0;
LAB_00171348:
    iVar3 = EVP_CipherInit_ex(local_3c,(EVP_CIPHER *)0x0,(ENGINE *)0x0,key,iv,(int)enc);
    if (iVar3 < 1) {
      ERR_put_error(0x2e,0x78,0x65,"cms_enc.c",0xb3);
      bVar2 = false;
    }
    else if (iv == (uchar *)0x0) {
LAB_00171382:
      bVar2 = true;
    }
    else {
      type_00 = ASN1_TYPE_new();
      puVar7[1] = type_00;
      if (type_00 == (ASN1_TYPE *)0x0) {
        ERR_put_error(0x2e,0x78,0x41,"cms_enc.c",0xba);
        bVar2 = false;
      }
      else {
        iVar3 = EVP_CIPHER_param_to_asn1(local_3c,type_00);
        if (0 < iVar3) goto LAB_00171382;
        ERR_put_error(0x2e,0x78,0x66,"cms_enc.c",0xbf);
        bVar2 = false;
      }
    }
    ptr = *(void **)(param_1 + 0x10);
    if ((ptr == (void *)0x0) || (bVar1)) goto LAB_0017138e;
  }
  OPENSSL_cleanse(ptr,*(size_t *)(param_1 + 0x14));
  CRYPTO_free(*(void **)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x10) = 0;
LAB_0017138e:
  if (puVar6 != (uchar *)0x0) {
    OPENSSL_cleanse(puVar6,len);
    CRYPTO_free(puVar6);
  }
  if (!bVar2) {
    BIO_free(bp);
    bp = (BIO *)0x0;
  }
  return bp;
}

