
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

NETSCAPE_CERT_SEQUENCE * NETSCAPE_CERT_SEQUENCE_new(void)

{
  NETSCAPE_CERT_SEQUENCE *pNVar1;
  
  pNVar1 = (NETSCAPE_CERT_SEQUENCE *)ASN1_item_new((ASN1_ITEM *)&NETSCAPE_CERT_SEQUENCE_it);
  return pNVar1;
}

