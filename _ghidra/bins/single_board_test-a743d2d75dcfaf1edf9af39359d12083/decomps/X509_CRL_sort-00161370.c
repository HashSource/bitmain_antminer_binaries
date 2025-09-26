
int X509_CRL_sort(X509_CRL *crl)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  
  sk_sort(&crl->crl->revoked->stack);
  for (iVar3 = 0; iVar2 = sk_num(&crl->crl->revoked->stack), iVar3 < iVar2; iVar3 = iVar3 + 1) {
    pvVar1 = sk_value(&crl->crl->revoked->stack,iVar3);
    *(int *)((int)pvVar1 + 0x14) = iVar3;
  }
  (crl->crl->enc).modified = 1;
  return 1;
}

