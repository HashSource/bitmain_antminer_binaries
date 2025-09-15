
ulong X509_NAME_hash_old(X509_NAME *x)

{
  EVP_MD *type;
  int iVar1;
  ulong uVar2;
  byte local_30;
  byte local_2f;
  byte local_2e;
  byte local_2d;
  EVP_MD_CTX EStack_20;
  
  i2d_X509_NAME(x,(uchar **)0x0);
  EVP_MD_CTX_init(&EStack_20);
  EVP_MD_CTX_set_flags(&EStack_20,8);
  type = EVP_md5();
  iVar1 = EVP_DigestInit_ex(&EStack_20,type,(ENGINE *)0x0);
  if (((iVar1 == 0) ||
      (iVar1 = EVP_DigestUpdate(&EStack_20,x->bytes->data,x->bytes->length), iVar1 == 0)) ||
     (iVar1 = EVP_DigestFinal_ex(&EStack_20,&local_30,(uint *)0x0), iVar1 == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = (uint)local_2e << 0x10 | (uint)local_2f << 8 | (uint)local_30 | (uint)local_2d << 0x18;
  }
  EVP_MD_CTX_cleanup(&EStack_20);
  return uVar2;
}

