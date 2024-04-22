
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ECDSA_SIG * ECDSA_SIG_new(void)

{
  ECDSA_SIG *pEVar1;
  
  pEVar1 = (ECDSA_SIG *)ASN1_item_new((ASN1_ITEM *)&ECDSA_SIG_it);
  return pEVar1;
}

