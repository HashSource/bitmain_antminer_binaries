
undefined4 SSL_set_ciphersuites(SSL *param_1,char *param_2)

{
  GEN_SESSION_CB arg;
  undefined4 uVar1;
  stack_st_SSL_CIPHER *psVar2;
  int iVar3;
  
  arg = (GEN_SESSION_CB)OPENSSL_sk_new_null();
  if (arg != (GEN_SESSION_CB)0x0) {
    if ((*param_2 == '\0') ||
       (iVar3 = CONF_parse_list(param_2,0x3a,1,(list_cb *)0xe7071,arg), iVar3 != 0)) {
      OPENSSL_sk_free(param_1->generate_session_id);
      iVar3 = *(int *)(param_1->sid_ctx + 0x1c);
      param_1->generate_session_id = arg;
      if (iVar3 == 0) {
        psVar2 = SSL_get_ciphers(param_1);
        if (psVar2 != (stack_st_SSL_CIPHER *)0x0) {
          uVar1 = OPENSSL_sk_dup();
          *(undefined4 *)(param_1->sid_ctx + 0x1c) = uVar1;
        }
        if (*(int *)(param_1->sid_ctx + 0x1c) == 0) {
          return 1;
        }
        arg = param_1->generate_session_id;
      }
      uVar1 = update_cipher_list(param_1->sid_ctx + 0x1c,&param_1->session,arg);
      return uVar1;
    }
    OPENSSL_sk_free(arg);
  }
  if ((*(int *)(param_1->sid_ctx + 0x1c) == 0) &&
     (psVar2 = SSL_get_ciphers(param_1), psVar2 != (stack_st_SSL_CIPHER *)0x0)) {
    uVar1 = OPENSSL_sk_dup();
    *(undefined4 *)(param_1->sid_ctx + 0x1c) = uVar1;
  }
  return 0;
}

