
int CMS_EncryptedData_set1_key(CMS_ContentInfo *cms,EVP_CIPHER *ciph,uchar *key,size_t keylen)

{
  ASN1_VALUE *pAVar1;
  ASN1_OBJECT *pAVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (keylen == 0 || key == (uchar *)0x0) {
    ERR_put_error(0x2e,0x7b,0x82,"crypto/cms/cms_enc.c",0xbc);
  }
  else if (ciph == (EVP_CIPHER *)0x0) {
    iVar3 = OBJ_obj2nid(*(ASN1_OBJECT **)cms);
    if (iVar3 == 0x1a) {
      puVar4 = *(undefined4 **)(cms + 4);
      goto LAB_001d137a;
    }
    ERR_put_error(0x2e,0x7b,0x7a,"crypto/cms/cms_enc.c",200);
  }
  else {
    pAVar1 = ASN1_item_new((ASN1_ITEM *)CMS_EncryptedData_it);
    *(ASN1_VALUE **)(cms + 4) = pAVar1;
    if (pAVar1 != (ASN1_VALUE *)0x0) {
      pAVar2 = OBJ_nid2obj(0x1a);
      puVar4 = *(undefined4 **)(cms + 4);
      *(ASN1_OBJECT **)cms = pAVar2;
      *puVar4 = 0;
LAB_001d137a:
      iVar3 = cms_EncryptedContent_init(puVar4[1],ciph,key,keylen);
      return iVar3;
    }
    ERR_put_error(0x2e,0x7b,0x41,"crypto/cms/cms_enc.c",0xc2);
  }
  return 0;
}

