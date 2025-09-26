
int X509_VERIFY_PARAM_set_purpose(X509_VERIFY_PARAM *param,int purpose)

{
  int iVar1;
  
  iVar1 = X509_PURPOSE_set(&param->purpose,purpose);
  return iVar1;
}

