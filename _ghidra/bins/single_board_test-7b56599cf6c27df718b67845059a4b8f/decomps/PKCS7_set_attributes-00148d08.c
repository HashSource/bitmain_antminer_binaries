
int PKCS7_set_attributes(PKCS7_SIGNER_INFO *p7si,stack_st_X509_ATTRIBUTE *sk)

{
  stack_st_X509_ATTRIBUTE *psVar1;
  X509_ATTRIBUTE *pXVar2;
  int iVar3;
  int iVar4;
  
  OPENSSL_sk_pop_free(p7si->unauth_attr,0x16cc01);
  psVar1 = (stack_st_X509_ATTRIBUTE *)OPENSSL_sk_dup(sk);
  p7si->unauth_attr = psVar1;
  if (psVar1 != (stack_st_X509_ATTRIBUTE *)0x0) {
    iVar4 = 0;
    do {
      iVar3 = OPENSSL_sk_num(sk);
      if (iVar3 <= iVar4) {
        return 1;
      }
      psVar1 = p7si->unauth_attr;
      pXVar2 = (X509_ATTRIBUTE *)OPENSSL_sk_value(sk,iVar4);
      pXVar2 = X509_ATTRIBUTE_dup(pXVar2);
      iVar3 = OPENSSL_sk_set(psVar1,iVar4,pXVar2);
      iVar4 = iVar4 + 1;
    } while (iVar3 != 0);
  }
  return 0;
}

