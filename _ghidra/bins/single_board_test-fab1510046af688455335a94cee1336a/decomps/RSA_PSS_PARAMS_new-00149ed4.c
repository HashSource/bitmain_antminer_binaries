
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

RSA_PSS_PARAMS * RSA_PSS_PARAMS_new(void)

{
  RSA_PSS_PARAMS *pRVar1;
  
  pRVar1 = (RSA_PSS_PARAMS *)ASN1_item_new((ASN1_ITEM *)&RSA_PSS_PARAMS_it);
  return pRVar1;
}

