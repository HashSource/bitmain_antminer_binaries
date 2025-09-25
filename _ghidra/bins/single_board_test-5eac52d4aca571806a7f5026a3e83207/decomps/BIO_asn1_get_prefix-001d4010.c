
int BIO_asn1_get_prefix(BIO *b,undefined1 **pprefix,undefined1 **pprefix_free)

{
  long lVar1;
  undefined1 *local_18;
  undefined1 *puStack_14;
  
  lVar1 = BIO_ctrl(b,0x96,0,&local_18);
  if (0 < lVar1) {
    *pprefix = local_18;
    *pprefix_free = puStack_14;
  }
  return lVar1;
}

