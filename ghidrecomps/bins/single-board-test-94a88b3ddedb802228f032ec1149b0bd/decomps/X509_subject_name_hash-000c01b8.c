
ulong X509_subject_name_hash(X509 *x)

{
  EVP_MD *type;
  ulong uVar1;
  X509_NAME *a;
  size_t count;
  uchar *data;
  byte local_28;
  byte local_27;
  byte local_26;
  byte local_25;
  
  a = x->cert_info->subject;
  i2d_X509_NAME(a,(uchar **)0x0);
  data = a->canon_enc;
  count = a->canon_enclen;
  type = EVP_sha1();
  uVar1 = EVP_Digest(data,count,&local_28,(uint *)0x0,type,(ENGINE *)0x0);
  if (uVar1 != 0) {
    uVar1 = (uint)local_26 << 0x10 | (uint)local_27 << 8 | (uint)local_28 | (uint)local_25 << 0x18;
  }
  return uVar1;
}

