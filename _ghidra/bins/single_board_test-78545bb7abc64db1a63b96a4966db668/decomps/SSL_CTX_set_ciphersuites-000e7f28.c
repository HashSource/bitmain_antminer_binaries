
undefined4 SSL_CTX_set_ciphersuites(int param_1,char *param_2)

{
  void *arg;
  undefined4 uVar1;
  int iVar2;
  
  arg = (void *)OPENSSL_sk_new_null();
  if (arg == (void *)0x0) {
    return 0;
  }
  if ((*param_2 != '\0') &&
     (iVar2 = CONF_parse_list(param_2,0x3a,1,(list_cb *)0xe7071,arg), iVar2 == 0)) {
    OPENSSL_sk_free(arg);
    return 0;
  }
  OPENSSL_sk_free(*(undefined4 *)(param_1 + 0xc));
  *(void **)(param_1 + 0xc) = arg;
  if (*(int *)(param_1 + 4) == 0) {
    return 1;
  }
  uVar1 = update_cipher_list(param_1 + 4,param_1 + 8,arg);
  return uVar1;
}

