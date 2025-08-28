
int CMS_EncryptedData_set1_key(CMS_ContentInfo *cms,EVP_CIPHER *ciph,uchar *key,size_t keylen)

{
  ASN1_VALUE *pAVar1;
  ASN1_OBJECT *pAVar2;
  void *__dest;
  int iVar3;
  undefined4 *puVar4;
  
  if (key == (uchar *)0x0 || keylen == 0) {
    ERR_put_error(0x2e,0x7b,0x82,"cms_enc.c",0xeb);
    __dest = (void *)0x0;
  }
  else {
    if (ciph == (EVP_CIPHER *)0x0) {
      iVar3 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
      if (iVar3 != 0x1a) {
        ERR_put_error(0x2e,0x7b,0x7a,"cms_enc.c",0xf7);
        return 0;
      }
      puVar4 = *(undefined4 **)(cms + 4);
    }
    else {
      pAVar1 = ASN1_item_new((ASN1_ITEM *)CMS_EncryptedData_it);
      *(ASN1_VALUE **)(cms + 4) = pAVar1;
      if (pAVar1 == (ASN1_VALUE *)0x0) {
        ERR_put_error(0x2e,0x7b,0x41,"cms_enc.c",0xf1);
        return 0;
      }
      pAVar2 = OBJ_nid2obj(0x1a);
      puVar4 = *(undefined4 **)(cms + 4);
      *(ASN1_OBJECT **)cms = pAVar2;
      *puVar4 = 0;
    }
    puVar4 = (undefined4 *)puVar4[1];
    puVar4[3] = ciph;
    __dest = CRYPTO_malloc(keylen,"cms_enc.c",0xdb);
    puVar4[4] = __dest;
    if (__dest != (void *)0x0) {
      memcpy(__dest,key,keylen);
      puVar4[5] = keylen;
      __dest = (void *)0x1;
      if (ciph != (EVP_CIPHER *)0x0) {
        pAVar2 = OBJ_nid2obj(0x15);
        __dest = (void *)0x1;
        *puVar4 = pAVar2;
      }
    }
  }
  return (int)__dest;
}

