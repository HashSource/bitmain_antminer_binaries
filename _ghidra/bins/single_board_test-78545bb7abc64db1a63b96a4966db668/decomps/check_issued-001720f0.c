
bool check_issued(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = x509_likely_issued(param_3);
  return iVar1 == 0;
}

