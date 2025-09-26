
ASN1_OCTET_STRING * SXNET_get_id_ulong(SXNET *sx,ulong lzone)

{
  ASN1_INTEGER *a;
  int iVar1;
  ASN1_OCTET_STRING *pAVar2;
  
  a = ASN1_INTEGER_new();
  if ((a != (ASN1_INTEGER *)0x0) && (iVar1 = ASN1_INTEGER_set(a,lzone), iVar1 != 0)) {
    pAVar2 = SXNET_get_id_INTEGER(sx,a);
    ASN1_INTEGER_free(a);
    return pAVar2;
  }
  ERR_put_error(0x22,0x81,0x41,"crypto/x509v3/v3_sxnet.c",0xdd);
  ASN1_INTEGER_free(a);
  return (ASN1_OCTET_STRING *)0x0;
}

