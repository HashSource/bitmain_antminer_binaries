
X509_EXTENSION * X509V3_EXT_i2d(int ext_nid,int crit,void *ext_struc)

{
  ASN1_STRING *pAVar1;
  X509V3_EXT_METHOD *pXVar2;
  int num;
  ASN1_OCTET_STRING *data;
  X509_EXTENSION *pXVar3;
  ASN1_STRING *local_28;
  ASN1_STRING *local_24 [2];
  
  pXVar2 = X509V3_EXT_get_nid(ext_nid);
  if (pXVar2 == (X509V3_EXT_METHOD *)0x0) {
    ERR_put_error(0x22,0x88,0x81,"crypto/x509v3/v3_conf.c",0xb6);
    return (X509_EXTENSION *)0x0;
  }
  local_28 = (ASN1_STRING *)0x0;
  if (pXVar2->it == (ASN1_ITEM *)0x0) {
    num = (*pXVar2->i2d)(ext_struc,(uchar **)0x0);
    data = (ASN1_OCTET_STRING *)CRYPTO_malloc(num,"crypto/x509v3/v3_conf.c",0x95);
    local_28 = data;
    if (data == (ASN1_STRING *)0x0) goto LAB_0016f546;
    local_24[0] = data;
    (*pXVar2->i2d)(ext_struc,(uchar **)local_24);
LAB_0016f4ec:
    data = ASN1_OCTET_STRING_new();
    pAVar1 = local_28;
    if (data != (ASN1_OCTET_STRING *)0x0) {
      local_28 = (ASN1_STRING *)0x0;
      data->length = num;
      data->data = (uchar *)pAVar1;
      pXVar3 = X509_EXTENSION_create_by_NID((X509_EXTENSION **)0x0,ext_nid,crit,data);
      if (pXVar3 != (X509_EXTENSION *)0x0) {
        ASN1_OCTET_STRING_free(data);
        return pXVar3;
      }
      goto LAB_0016f546;
    }
  }
  else {
    num = ASN1_item_i2d((ASN1_VALUE *)ext_struc,(uchar **)&local_28,pXVar2->it);
    if (-1 < num) goto LAB_0016f4ec;
  }
  data = (ASN1_STRING *)0x0;
LAB_0016f546:
  ERR_put_error(0x22,0x87,0x41,"crypto/x509v3/v3_conf.c",0xa8);
  CRYPTO_free(local_28);
  ASN1_OCTET_STRING_free(data);
  return (X509_EXTENSION *)0x0;
}

