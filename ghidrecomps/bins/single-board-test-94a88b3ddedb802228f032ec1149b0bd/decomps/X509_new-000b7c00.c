
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509 * X509_new(void)

{
  X509 *pXVar1;
  
  pXVar1 = (X509 *)ASN1_item_new(DAT_000b7c08);
  return pXVar1;
}

