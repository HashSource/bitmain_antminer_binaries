
int EVP_PKEY_meth_remove
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = OPENSSL_sk_delete_ptr(app_pkey_methods,param_1,param_3,&app_pkey_methods,param_4);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

