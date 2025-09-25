
int X509_TRUST_set_default(int param_1,X509 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = default_trust;
  default_trust = param_1;
  return iVar1;
}

