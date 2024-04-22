
undefined4
x509_name_ex_print(BIO *param_1,X509_NAME **param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = X509_NAME_print_ex(param_1,*param_2,param_3,*(ulong *)(param_5 + 4));
  if (iVar1 < 1) {
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

