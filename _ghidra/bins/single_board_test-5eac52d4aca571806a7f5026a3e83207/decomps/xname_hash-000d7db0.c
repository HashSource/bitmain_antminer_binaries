
ulong xname_hash(X509_NAME *x)

{
  EVP_MD *type;
  ulong uVar1;
  size_t count;
  uchar *data;
  ulong auStack_24 [6];
  
  i2d_X509_NAME(x,(uchar **)0x0);
  data = x->canon_enc;
  count = x->canon_enclen;
  type = EVP_sha1();
  uVar1 = EVP_Digest(data,count,(uchar *)auStack_24,(uint *)0x0,type,(ENGINE *)0x0);
  if (uVar1 != 0) {
    uVar1 = auStack_24[0];
  }
  return uVar1;
}

