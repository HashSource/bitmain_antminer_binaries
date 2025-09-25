
uchar * X509_alias_get0(X509 *x,int *len)

{
  ASIdentifiers_st *pAVar1;
  
  pAVar1 = x[1].rfc3779_asid;
  if ((pAVar1 != (ASIdentifiers_st *)0x0) &&
     (pAVar1 = (ASIdentifiers_st *)pAVar1[1].asnum, pAVar1 != (ASIdentifiers_st *)0x0)) {
    if (len != (int *)0x0) {
      *len = (int)pAVar1->asnum;
    }
    pAVar1 = (ASIdentifiers_st *)pAVar1[1].asnum;
  }
  return (uchar *)pAVar1;
}

