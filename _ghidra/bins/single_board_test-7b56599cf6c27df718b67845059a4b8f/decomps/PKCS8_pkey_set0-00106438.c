
int PKCS8_pkey_set0(PKCS8_PRIV_KEY_INFO *priv,ASN1_OBJECT *aobj,int version,int ptype,void *pval,
                   uchar *penc,int penclen)

{
  int iVar1;
  
  if (((version < 0) || (iVar1 = ASN1_INTEGER_set((ASN1_INTEGER *)priv->broken,version), iVar1 != 0)
      ) && (iVar1 = X509_ALGOR_set0((X509_ALGOR *)priv->version,aobj,ptype,pval), iVar1 != 0)) {
    if (penc != (uchar *)0x0) {
      ASN1_STRING_set0((ASN1_STRING *)priv->pkeyalg,penc,penclen);
      return 1;
    }
    return 1;
  }
  return 0;
}

