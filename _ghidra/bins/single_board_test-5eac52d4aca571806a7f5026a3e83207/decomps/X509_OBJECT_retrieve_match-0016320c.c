
X509_OBJECT * X509_OBJECT_retrieve_match(stack_st_X509_OBJECT *h,X509_OBJECT *x)

{
  int iVar1;
  X509_OBJECT *pXVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = OPENSSL_sk_find();
  if (-1 < iVar1) {
    if (1 < x->type - 1U) {
      pXVar2 = (X509_OBJECT *)OPENSSL_sk_value(h,iVar1);
      return pXVar2;
    }
    iVar3 = OPENSSL_sk_num(h);
    if (iVar1 < iVar3) {
      do {
        pXVar2 = (X509_OBJECT *)OPENSSL_sk_value(h,iVar1);
        iVar4 = pXVar2->type;
        if (iVar4 != x->type) {
          return (X509_OBJECT *)0x0;
        }
        if (iVar4 == 1) {
          iVar4 = X509_subject_name_cmp((pXVar2->data).x509,(x->data).x509);
LAB_0016325e:
          if (iVar4 != 0) {
            return (X509_OBJECT *)0x0;
          }
          iVar4 = x->type;
        }
        else if (iVar4 == 2) {
          iVar4 = X509_CRL_cmp((pXVar2->data).crl,(x->data).crl);
          goto LAB_0016325e;
        }
        if (iVar4 == 1) {
          iVar4 = X509_cmp((pXVar2->data).x509,(x->data).x509);
        }
        else {
          if (iVar4 != 2) {
            return pXVar2;
          }
          iVar4 = X509_CRL_match((pXVar2->data).crl,(x->data).crl);
        }
        if (iVar4 == 0) {
          return pXVar2;
        }
        iVar1 = iVar1 + 1;
      } while (iVar3 != iVar1);
    }
  }
  return (X509_OBJECT *)0x0;
}

