
ulong X509_issuer_and_serial_hash(X509 *a)

{
  char *__s;
  EVP_MD *type;
  int iVar1;
  size_t cnt;
  ASN1_INTEGER *pAVar2;
  ulong uVar3;
  byte local_38;
  byte local_37;
  byte local_36;
  byte local_35;
  EVP_MD_CTX EStack_28;
  
  EVP_MD_CTX_init(&EStack_28);
  __s = X509_NAME_oneline(a->cert_info->issuer,(char *)0x0,0);
  type = EVP_md5();
  iVar1 = EVP_DigestInit_ex(&EStack_28,type,(ENGINE *)0x0);
  if (iVar1 != 0) {
    cnt = strlen(__s);
    iVar1 = EVP_DigestUpdate(&EStack_28,__s,cnt);
    if (iVar1 != 0) {
      CRYPTO_free(__s);
      pAVar2 = a->cert_info->serialNumber;
      iVar1 = EVP_DigestUpdate(&EStack_28,pAVar2->data,pAVar2->length);
      if ((iVar1 != 0) && (iVar1 = EVP_DigestFinal_ex(&EStack_28,&local_38,(uint *)0x0), iVar1 != 0)
         ) {
        uVar3 = (uint)local_36 << 0x10 | (uint)local_37 << 8 | (uint)local_38 |
                (uint)local_35 << 0x18;
        goto LAB_000bffdc;
      }
    }
  }
  uVar3 = 0;
LAB_000bffdc:
  EVP_MD_CTX_cleanup(&EStack_28);
  return uVar3;
}

