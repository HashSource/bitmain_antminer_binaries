
int PKCS7_signatureVerify(BIO *bio,PKCS7 *p7,PKCS7_SIGNER_INFO *si,X509 *x509)

{
  int iVar1;
  EVP_MD *pEVar2;
  BIO *bp;
  EVP_PKEY *pkey;
  ASN1_OBJECT *b;
  ASN1_OBJECT **ppAVar3;
  int iVar4;
  void *pvVar5;
  char *name;
  size_t cnt;
  int iVar6;
  size_t *psVar7;
  _STACK *val;
  ASN1_OCTET_STRING *pAVar8;
  EVP_MD_CTX *local_84;
  uchar *local_80;
  size_t local_7c;
  EVP_MD_CTX EStack_78;
  uchar auStack_60 [64];
  
  EVP_MD_CTX_init(&EStack_78);
  iVar1 = OBJ_obj2nid(p7->type);
  if ((iVar1 != 0x16) && (iVar1 = OBJ_obj2nid(p7->type), iVar1 != 0x18)) {
    ERR_put_error(0x21,0x71,0x72,DAT_000d0da0,0x40f);
    goto LAB_000d0c2a;
  }
  iVar1 = OBJ_obj2nid(si->digest_alg->algorithm);
  if (bio != (BIO *)0x0) {
    do {
      bp = BIO_find_type(bio,0x208);
      if (bp == (BIO *)0x0) break;
      BIO_ctrl(bp,0x78,0,&local_84);
      if (local_84 == (EVP_MD_CTX *)0x0) {
        ERR_put_error(0x21,0x71,0x44,DAT_000d0da0,0x41f);
        iVar1 = 0;
        goto LAB_000d0c2c;
      }
      pEVar2 = EVP_MD_CTX_md(local_84);
      iVar6 = EVP_MD_type(pEVar2);
      if (iVar6 == iVar1) {
LAB_000d0c3a:
        iVar6 = EVP_MD_CTX_copy_ex(&EStack_78,local_84);
        if (iVar6 == 0) goto LAB_000d0c2a;
        val = &si->auth_attr->stack;
        if ((val == (_STACK *)0x0) || (iVar6 = sk_num(val), iVar6 == 0)) goto LAB_000d0c52;
        local_80 = (uchar *)0x0;
        iVar6 = EVP_DigestFinal_ex(&EStack_78,auStack_60,&local_7c);
        if (iVar6 == 0) goto LAB_000d0c2a;
        b = OBJ_nid2obj(0x33);
        iVar6 = 0;
        if (b == (ASN1_OBJECT *)0x0) goto LAB_000d0ce8;
        goto LAB_000d0cd6;
      }
      pEVar2 = EVP_MD_CTX_md(local_84);
      iVar6 = EVP_MD_pkey_type(pEVar2);
      if (iVar6 == iVar1) goto LAB_000d0c3a;
      bio = BIO_next(bp);
    } while (bio != (BIO *)0x0);
  }
  iVar6 = 0x41a;
  goto LAB_000d0c06;
  while( true ) {
    ppAVar3 = (ASN1_OBJECT **)sk_value(val,iVar6);
    iVar4 = OBJ_cmp(*ppAVar3,b);
    iVar6 = iVar6 + 1;
    if (iVar4 == 0) break;
LAB_000d0cd6:
    iVar4 = sk_num(val);
    if (iVar4 <= iVar6) goto LAB_000d0ce8;
  }
  if ((((ppAVar3[1] == (ASN1_OBJECT *)0x0) && (iVar6 = sk_num((_STACK *)ppAVar3[2]), iVar6 != 0)) &&
      (pvVar5 = sk_value((_STACK *)ppAVar3[2],0), pvVar5 != (void *)0x0)) &&
     (psVar7 = *(size_t **)((int)pvVar5 + 4), psVar7 != (size_t *)0x0)) {
    if ((*psVar7 != local_7c) || (iVar6 = memcmp((void *)psVar7[2],auStack_60,*psVar7), iVar6 != 0))
    {
      ERR_put_error(0x21,0x71,0x65,DAT_000d0da0,0x450);
      iVar1 = -1;
      goto LAB_000d0c2c;
    }
    name = OBJ_nid2sn(iVar1);
    pEVar2 = EVP_get_digestbyname(name);
    iVar1 = EVP_DigestInit_ex(&EStack_78,pEVar2,(ENGINE *)0x0);
    if (iVar1 != 0) {
      cnt = ASN1_item_i2d((ASN1_VALUE *)val,&local_80,DAT_000d0da4);
      if ((int)cnt < 1) {
        ERR_put_error(0x21,0x71,0xd,DAT_000d0da0,0x45b);
        iVar1 = -1;
        goto LAB_000d0c2c;
      }
      iVar1 = EVP_DigestUpdate(&EStack_78,local_80,cnt);
      if (iVar1 != 0) {
        CRYPTO_free(local_80);
LAB_000d0c52:
        pAVar8 = si->enc_digest;
        pkey = X509_get_pubkey(x509);
        if (pkey == (EVP_PKEY *)0x0) {
          iVar1 = -1;
        }
        else {
          iVar1 = EVP_VerifyFinal(&EStack_78,pAVar8->data,pAVar8->length,pkey);
          EVP_PKEY_free(pkey);
          if (iVar1 < 1) {
            ERR_put_error(0x21,0x71,0x69,DAT_000d0da0,0x46f);
            iVar1 = -1;
          }
          else {
            iVar1 = 1;
          }
        }
        goto LAB_000d0c2c;
      }
    }
LAB_000d0c2a:
    iVar1 = 0;
    goto LAB_000d0c2c;
  }
LAB_000d0ce8:
  iVar6 = 0x440;
LAB_000d0c06:
  iVar1 = 0;
  ERR_put_error(0x21,0x71,0x6c,DAT_000d0da0,iVar6);
LAB_000d0c2c:
  EVP_MD_CTX_cleanup(&EStack_78);
  return iVar1;
}

