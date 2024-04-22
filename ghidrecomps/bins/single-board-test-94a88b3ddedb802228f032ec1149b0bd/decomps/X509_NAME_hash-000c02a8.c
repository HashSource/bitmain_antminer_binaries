
ulong X509_NAME_hash(X509_NAME *x)

{
  EVP_MD *type;
  ulong uVar1;
  size_t count;
  uchar *data;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  
  i2d_X509_NAME(x,(uchar **)0x0);
  data = x->canon_enc;
  count = x->canon_enclen;
  type = EVP_sha1();
  uVar1 = EVP_Digest(data,count,&local_28,(uint *)0x0,type,(ENGINE *)0x0);
  if (uVar1 != 0) {
    uVar1 = (uint)local_26 << 0x10 | (uint)local_27 << 8 | (uint)local_28 | (uint)local_25 << 0x18;
  }
  return uVar1;
}

