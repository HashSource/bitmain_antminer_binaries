
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ASN1_STRING_TABLE_cleanup(void)

{
  int iVar1;
  
  iVar1 = stable;
  if (stable != 0) {
    stable = 0;
    OPENSSL_sk_pop_free(iVar1,0x1825b1);
    return;
  }
  return;
}

