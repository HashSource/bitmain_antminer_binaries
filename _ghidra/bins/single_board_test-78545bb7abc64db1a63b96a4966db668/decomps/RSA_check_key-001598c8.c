
int RSA_check_key(RSA *param_1)

{
  int iVar1;
  
  iVar1 = RSA_check_key_ex(param_1,0);
  return iVar1;
}

