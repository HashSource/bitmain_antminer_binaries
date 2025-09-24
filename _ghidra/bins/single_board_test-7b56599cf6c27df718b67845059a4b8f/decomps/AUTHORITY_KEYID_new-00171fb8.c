
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

AUTHORITY_KEYID * AUTHORITY_KEYID_new(void)

{
  AUTHORITY_KEYID *pAVar1;
  
  pAVar1 = (AUTHORITY_KEYID *)ASN1_item_new((ASN1_ITEM *)&AUTHORITY_KEYID_it);
  return pAVar1;
}

