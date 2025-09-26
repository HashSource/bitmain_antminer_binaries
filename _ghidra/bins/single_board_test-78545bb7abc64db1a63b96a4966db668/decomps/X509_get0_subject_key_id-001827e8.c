
long X509_get0_subject_key_id(X509 *param_1)

{
  int iVar1;
  long lVar2;
  
  iVar1 = X509_check_purpose(param_1,-1,-1);
  if (iVar1 == 1) {
    lVar2 = param_1[1].ex_pathlen;
  }
  else {
    lVar2 = 0;
  }
  return lVar2;
}

