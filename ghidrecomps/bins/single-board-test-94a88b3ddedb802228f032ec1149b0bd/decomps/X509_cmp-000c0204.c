
int X509_cmp(X509 *a,X509 *b)

{
  int iVar1;
  X509_CINF *pXVar2;
  int iVar3;
  undefined4 in_r3;
  X509_CINF *pXVar4;
  
  X509_check_purpose(a,-1,0);
  X509_check_purpose(b,-1,0);
  iVar1 = memcmp(&a->rfc3779_addr,&b->rfc3779_addr,0x14);
  if (((iVar1 == 0) && (pXVar4 = a->cert_info, (pXVar4->enc).modified == 0)) &&
     (pXVar2 = b->cert_info, (pXVar2->enc).modified == 0)) {
    iVar3 = (pXVar4->enc).len;
    iVar1 = iVar3 - (pXVar2->enc).len;
    if (iVar1 == 0) {
      iVar1 = (*(code *)PTR_memcmp_00194160)((pXVar4->enc).enc,(pXVar2->enc).enc,iVar3,in_r3);
      return iVar1;
    }
  }
  return iVar1;
}

