
undefined4 OPENSSL_INIT_set_config_appname(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = __strdup(param_2);
    if (iVar1 == 0) {
      return 0;
    }
  }
  free(*(void **)(param_1 + 4));
  *(int *)(param_1 + 4) = iVar1;
  return 1;
}

