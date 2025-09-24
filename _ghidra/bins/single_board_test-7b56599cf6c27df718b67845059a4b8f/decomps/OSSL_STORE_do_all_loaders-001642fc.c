
undefined4
OSSL_STORE_do_all_loaders
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  OPENSSL_LH_doall_arg(loader_register,param_1,param_2,&registry_lock,param_4);
  return 1;
}

