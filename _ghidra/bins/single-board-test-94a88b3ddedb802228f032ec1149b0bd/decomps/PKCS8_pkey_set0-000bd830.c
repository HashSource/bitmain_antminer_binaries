
int PKCS8_pkey_set0(PKCS8_PRIV_KEY_INFO *priv,ASN1_OBJECT *aobj,int version,int ptype,void *pval,
                   uchar *penc,int penclen)

{
  int iVar1;
  ASN1_OCTET_STRING *value;
  
  if ((version < 0) || (iVar1 = ASN1_INTEGER_set(priv->version,version), iVar1 != 0)) {
    if (penc == (uchar *)0x0) {
      iVar1 = X509_ALGOR_set0(priv->pkeyalg,aobj,ptype,pval);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      return iVar1;
    }
    value = ASN1_OCTET_STRING_new();
    if (value != (ASN1_OCTET_STRING *)0x0) {
      iVar1 = priv->broken;
      value->data = penc;
      if (iVar1 == 1) {
        iVar1 = 0x10;
      }
      else {
        iVar1 = 4;
      }
      value->length = penclen;
      ASN1_TYPE_set(priv->pkey,iVar1,value);
      iVar1 = X509_ALGOR_set0(priv->pkeyalg,aobj,ptype,pval);
      if (iVar1 != 0) {
        return 1;
      }
      value->data = (uchar *)0x0;
      return 0;
    }
  }
  return 0;
}

