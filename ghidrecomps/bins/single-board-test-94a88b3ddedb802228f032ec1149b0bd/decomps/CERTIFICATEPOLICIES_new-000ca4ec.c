
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

CERTIFICATEPOLICIES * CERTIFICATEPOLICIES_new(void)

{
  ASN1_VALUE *pAVar1;
  
  pAVar1 = ASN1_item_new((ASN1_ITEM *)CERTIFICATEPOLICIES_it);
  return (CERTIFICATEPOLICIES *)pAVar1;
}

