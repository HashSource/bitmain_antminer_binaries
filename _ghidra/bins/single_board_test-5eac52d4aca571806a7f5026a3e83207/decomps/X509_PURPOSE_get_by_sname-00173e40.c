
int X509_PURPOSE_get_by_sname(char *sname)

{
  X509_PURPOSE *pXVar1;
  int iVar2;
  int idx;
  
  idx = 0;
  while( true ) {
    iVar2 = X509_PURPOSE_get_count();
    if (iVar2 <= idx) {
      return -1;
    }
    pXVar1 = X509_PURPOSE_get0(idx);
    iVar2 = strcmp(pXVar1->sname,sname);
    if (iVar2 == 0) break;
    idx = idx + 1;
  }
  return idx;
}

