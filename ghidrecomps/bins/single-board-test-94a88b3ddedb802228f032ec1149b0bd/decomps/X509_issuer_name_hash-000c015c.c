
ulong X509_issuer_name_hash(X509 *a)

{
  EVP_MD *type;
  ulong uVar1;
  X509_NAME *a_00;
  size_t count;
  uchar *data;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  
  a_00 = a->cert_info->issuer;
  i2d_X509_NAME(a_00,(uchar **)0x0);
  data = a_00->canon_enc;
  count = a_00->canon_enclen;
  type = EVP_sha1();
  uVar1 = EVP_Digest(data,count,&local_28,(uint *)0x0,type,(ENGINE *)0x0);
  if (uVar1 != 0) {
    uVar1 = (uint)local_26 << 0x10 | (uint)local_27 << 8 | (uint)local_28 | (uint)local_25 << 0x18;
  }
  return uVar1;
}

