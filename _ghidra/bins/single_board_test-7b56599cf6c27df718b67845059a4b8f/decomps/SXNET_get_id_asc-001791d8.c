
ASN1_OCTET_STRING * SXNET_get_id_asc(SXNET *sx,char *zone)

{
  ASN1_INTEGER *zone_00;
  ASN1_OCTET_STRING *pAVar1;
  
  zone_00 = s2i_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,zone);
  if (zone_00 == (ASN1_INTEGER *)0x0) {
    ERR_put_error(0x22,0x80,0x83,"crypto/x509v3/v3_sxnet.c",0xce);
    pAVar1 = (ASN1_OCTET_STRING *)0x0;
  }
  else {
    pAVar1 = SXNET_get_id_INTEGER(sx,zone_00);
    ASN1_INTEGER_free(zone_00);
  }
  return pAVar1;
}

