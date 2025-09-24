
int BIO_asn1_get_suffix(BIO *b,undefined1 **psuffix,undefined1 **psuffix_free)

{
  long lVar1;
  undefined1 *local_18;
  undefined1 *puStack_14;
  
  lVar1 = BIO_ctrl(b,0x98,0,&local_18);
  if (0 < lVar1) {
    *psuffix = local_18;
    *psuffix_free = puStack_14;
  }
  return lVar1;
}

