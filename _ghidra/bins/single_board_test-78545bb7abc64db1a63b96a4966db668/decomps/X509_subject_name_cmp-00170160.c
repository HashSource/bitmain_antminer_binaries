
int X509_subject_name_cmp(X509 *a,X509 *b)

{
  int iVar1;
  
  iVar1 = X509_NAME_cmp((X509_NAME *)a->ex_flags,(X509_NAME *)b->ex_flags);
  return iVar1;
}

