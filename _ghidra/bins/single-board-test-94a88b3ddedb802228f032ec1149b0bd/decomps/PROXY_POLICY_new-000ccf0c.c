
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

PROXY_POLICY * PROXY_POLICY_new(void)

{
  PROXY_POLICY *pPVar1;
  
  pPVar1 = (PROXY_POLICY *)ASN1_item_new((ASN1_ITEM *)&PROXY_POLICY_it);
  return pPVar1;
}

