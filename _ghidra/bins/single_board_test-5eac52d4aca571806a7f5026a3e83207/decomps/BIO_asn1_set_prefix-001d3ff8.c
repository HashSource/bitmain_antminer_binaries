
int BIO_asn1_set_prefix(BIO *b,undefined1 *prefix,undefined1 *prefix_free)

{
  long lVar1;
  undefined1 *local_10;
  undefined1 *local_c;
  
  local_10 = prefix;
  local_c = prefix_free;
  lVar1 = BIO_ctrl(b,0x95,0,&local_10);
  return lVar1;
}

