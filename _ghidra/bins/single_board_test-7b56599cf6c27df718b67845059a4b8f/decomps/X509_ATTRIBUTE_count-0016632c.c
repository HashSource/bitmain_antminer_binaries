
int X509_ATTRIBUTE_count(X509_ATTRIBUTE *attr)

{
  int iVar1;
  
  if (attr != (X509_ATTRIBUTE *)0x0) {
    iVar1 = OPENSSL_sk_num(attr->single);
    return iVar1;
  }
  return 0;
}

