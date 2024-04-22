
int BIO_asn1_set_suffix(BIO *b,undefined1 *suffix,undefined1 *suffix_free)

{
  long lVar1;
  undefined1 *local_10;
  undefined1 *local_c;
  
  local_10 = suffix;
  local_c = suffix_free;
  lVar1 = BIO_ctrl(b,0x97,0,&local_10);
  return lVar1;
}

