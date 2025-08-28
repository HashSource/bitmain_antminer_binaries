
int ssl_verify_cert_chain(void *param_1,_STACK *param_2)

{
  int iVar1;
  X509 *x509;
  X509_VERIFY_PARAM *to;
  char *name;
  code *pcVar2;
  X509_STORE *store;
  X509_STORE_CTX XStack_98;
  
  store = *(X509_STORE **)(*(int *)((int)param_1 + 0x98) + 0x150);
  if (store == (X509_STORE *)0x0) {
    store = *(X509_STORE **)(*(int *)((int)param_1 + 0xe4) + 0xc);
  }
  if ((param_2 == (_STACK *)0x0) || (iVar1 = sk_num(param_2), iVar1 == 0)) {
    iVar1 = 0;
  }
  else {
    x509 = (X509 *)sk_value(param_2,0);
    iVar1 = X509_STORE_CTX_init(&XStack_98,store,x509,(stack_st_X509 *)param_2);
    if (iVar1 == 0) {
      ERR_put_error(0x14,0xcf,0xb,"ssl_cert.c",0x2d5);
      iVar1 = 0;
    }
    else {
      X509_STORE_CTX_set_flags(&XStack_98,*(uint *)(*(int *)((int)param_1 + 0x98) + 0x38) & 0x30000)
      ;
      iVar1 = ssl_x509_store_ctx_idx_19563;
      if (ssl_x509_store_ctx_idx_19563 < 0) {
        CRYPTO_lock(9,0xc,"ssl_cert.c",0x94);
        if (ssl_x509_store_ctx_idx_19563 < 0) {
          ssl_x509_store_ctx_idx_19563 =
               X509_STORE_CTX_get_ex_new_index
                         (0,"SSL for verify callback",(undefined1 *)0x0,(undefined1 *)0x0,
                          (undefined1 *)0x0);
        }
        iVar1 = ssl_x509_store_ctx_idx_19563;
        CRYPTO_lock(10,0xc,"ssl_cert.c",0x9b);
      }
      X509_STORE_CTX_set_ex_data(&XStack_98,iVar1,param_1);
      name = "ssl_server";
      if (*(int *)((int)param_1 + 0x24) != 0) {
        name = "ssl_client";
      }
      X509_STORE_CTX_set_default(&XStack_98,name);
      to = X509_STORE_CTX_get0_param(&XStack_98);
      X509_VERIFY_PARAM_set1(to,*(X509_VERIFY_PARAM **)((int)param_1 + 0x70));
      if (*(verify_cb **)((int)param_1 + 0xcc) != (verify_cb *)0x0) {
        X509_STORE_CTX_set_verify_cb(&XStack_98,*(verify_cb **)((int)param_1 + 0xcc));
      }
      pcVar2 = *(code **)(*(int *)((int)param_1 + 0xe4) + 100);
      if (pcVar2 == (code *)0x0) {
        iVar1 = X509_verify_cert(&XStack_98);
      }
      else {
        iVar1 = (*pcVar2)(&XStack_98,*(undefined4 *)(*(int *)((int)param_1 + 0xe4) + 0x68));
      }
      *(int *)((int)param_1 + 0xec) = XStack_98.error;
      X509_STORE_CTX_cleanup(&XStack_98);
    }
  }
  return iVar1;
}

