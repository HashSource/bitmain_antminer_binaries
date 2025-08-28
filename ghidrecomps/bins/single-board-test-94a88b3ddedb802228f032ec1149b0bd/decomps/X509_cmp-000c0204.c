
int X509_cmp(X509 *a,X509 *b)

{
  int iVar1;
  X509_CINF *pXVar2;
  size_t __n;
  X509_CINF *pXVar3;
  
  X509_check_purpose(a,-1,0);
  X509_check_purpose(b,-1,0);
  iVar1 = memcmp(&a->rfc3779_addr,&b->rfc3779_addr,0x14);
  if (((iVar1 == 0) && (pXVar3 = a->cert_info, (pXVar3->enc).modified == 0)) &&
     (pXVar2 = b->cert_info, (pXVar2->enc).modified == 0)) {
    __n = (pXVar3->enc).len;
    iVar1 = __n - (pXVar2->enc).len;
    if (iVar1 == 0) {
      iVar1 = memcmp((pXVar3->enc).enc,(pXVar2->enc).enc,__n);
      return iVar1;
    }
  }
  return iVar1;
}

