
int X509_VERIFY_PARAM_set_trust(X509_VERIFY_PARAM *param,int trust)

{
  int iVar1;
  
  iVar1 = X509_TRUST_set(&param->trust,trust);
  return iVar1;
}

