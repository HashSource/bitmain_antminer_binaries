
int CMS_SignerInfo_sign(CMS_SignerInfo *si)

{
  EVP_PKEY_CTX *pEVar1;
  int iVar2;
  char *name;
  EVP_MD *type;
  size_t cnt;
  ASN1_TIME *a;
  EVP_MD_CTX *ctx;
  EVP_PKEY_CTX *local_24;
  uchar *local_20;
  size_t local_1c;
  
  ctx = *(EVP_MD_CTX **)(si + 0x24);
  local_24 = (EVP_PKEY_CTX *)0x0;
  local_20 = (uchar *)0x0;
  iVar2 = OBJ_obj2nid((ASN1_OBJECT *)**(undefined4 **)(si + 8));
  name = OBJ_nid2sn(iVar2);
  type = EVP_get_digestbyname(name);
  if (type == (EVP_MD *)0x0) {
    return 0;
  }
  iVar2 = CMS_signed_get_attr_by_NID(si,0x34,-1);
  if (iVar2 < 0) {
    a = X509_gmtime_adj((ASN1_TIME *)0x0,0);
    if ((a == (ASN1_TIME *)0x0) ||
       (iVar2 = CMS_signed_add1_attr_by_NID(si,0x34,a->type,a,-1), iVar2 < 1)) {
      ASN1_TIME_free(a);
      ERR_put_error(0x2e,0x67,0x41,"crypto/cms/cms_sd.c",0x1a3);
      goto LAB_0019bd70;
    }
    ASN1_TIME_free(a);
  }
  iVar2 = CMS_si_check_attributes(si);
  if (iVar2 == 0) goto LAB_0019bd70;
  pEVar1 = *(EVP_PKEY_CTX **)(si + 0x28);
  if (*(EVP_PKEY_CTX **)(si + 0x28) == (EVP_PKEY_CTX *)0x0) {
    EVP_MD_CTX_reset(ctx);
    iVar2 = EVP_DigestSignInit(ctx,&local_24,type,(ENGINE *)0x0,*(EVP_PKEY **)(si + 0x20));
    if (iVar2 < 1) goto LAB_0019bd70;
    *(EVP_PKEY_CTX **)(si + 0x28) = local_24;
    pEVar1 = local_24;
  }
  local_24 = pEVar1;
  iVar2 = EVP_PKEY_CTX_ctrl(local_24,-1,8,0xb,0,si);
  if (iVar2 < 1) {
    iVar2 = 0x2b0;
  }
  else {
    cnt = ASN1_item_i2d(*(ASN1_VALUE **)(si + 0xc),&local_20,(ASN1_ITEM *)CMS_Attributes_Sign_it);
    if ((local_20 == (uchar *)0x0) || (iVar2 = EVP_DigestUpdate(ctx,local_20,cnt), iVar2 < 1))
    goto LAB_0019bd70;
    iVar2 = EVP_DigestSignFinal(ctx,(uchar *)0x0,&local_1c);
    if (iVar2 < 1) goto LAB_0019bd70;
    CRYPTO_free(local_20);
    local_20 = (uchar *)CRYPTO_malloc(local_1c,"crypto/cms/cms_sd.c",0x2bd);
    if ((local_20 == (uchar *)0x0) ||
       (iVar2 = EVP_DigestSignFinal(ctx,local_20,&local_1c), iVar2 < 1)) goto LAB_0019bd70;
    iVar2 = EVP_PKEY_CTX_ctrl(local_24,-1,8,0xb,1,si);
    if (0 < iVar2) {
      EVP_MD_CTX_reset(ctx);
      ASN1_STRING_set0(*(ASN1_STRING **)(si + 0x14),local_20,local_1c);
      return 1;
    }
    iVar2 = 0x2c5;
  }
  ERR_put_error(0x2e,0x97,0x6e,"crypto/cms/cms_sd.c",iVar2);
LAB_0019bd70:
  CRYPTO_free(local_20);
  EVP_MD_CTX_reset(ctx);
  return 0;
}

