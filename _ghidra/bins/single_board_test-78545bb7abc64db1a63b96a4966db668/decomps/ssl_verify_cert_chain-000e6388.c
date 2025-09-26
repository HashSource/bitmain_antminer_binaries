
int ssl_verify_cert_chain(void *param_1,stack_st_X509 *param_2)

{
  int iVar1;
  X509_STORE_CTX *ctx;
  X509 *x509;
  X509_VERIFY_PARAM *to;
  undefined4 uVar2;
  int iVar3;
  stack_st_X509 *psVar4;
  char *name;
  code *pcVar5;
  X509_STORE *store;
  
  if ((param_2 != (stack_st_X509 *)0x0) && (iVar1 = OPENSSL_sk_num(param_2), iVar1 != 0)) {
    store = *(X509_STORE **)(*(int *)((int)param_1 + 0x404) + 0xec);
    if (store == (X509_STORE *)0x0) {
      store = *(X509_STORE **)(*(int *)((int)param_1 + 0x4d0) + 0x10);
    }
    ctx = X509_STORE_CTX_new();
    if (ctx != (X509_STORE_CTX *)0x0) {
      x509 = (X509 *)OPENSSL_sk_value(param_2,0);
      iVar1 = X509_STORE_CTX_init(ctx,store,x509,param_2);
      if (iVar1 == 0) {
        ERR_put_error(0x14,0xcf,0xb,"ssl/ssl_cert.c",0x183);
        iVar1 = 0;
      }
      else {
        to = X509_STORE_CTX_get0_param(ctx);
        uVar2 = SSL_get_security_level(param_1);
        X509_VERIFY_PARAM_set_auth_level(to,uVar2);
        X509_STORE_CTX_set_flags(ctx,*(uint *)(*(int *)((int)param_1 + 0x404) + 0x10) & 0x30000);
        iVar1 = SSL_get_ex_data_X509_STORE_CTX_idx();
        iVar1 = X509_STORE_CTX_set_ex_data(ctx,iVar1,param_1);
        if (iVar1 != 0) {
          iVar1 = OPENSSL_sk_num(*(undefined4 *)((int)param_1 + 0x98));
          if (0 < iVar1) {
            X509_STORE_CTX_set0_dane(ctx,(int)param_1 + 0x94);
          }
          if (*(int *)((int)param_1 + 0x1c) == 0) {
            name = "ssl_server";
          }
          else {
            name = "ssl_client";
          }
          X509_STORE_CTX_set_default(ctx,name);
          X509_VERIFY_PARAM_set1(to,*(X509_VERIFY_PARAM **)((int)param_1 + 0x90));
          if (*(verify_cb **)((int)param_1 + 0x4b0) != (verify_cb *)0x0) {
            X509_STORE_CTX_set_verify_cb(ctx,*(verify_cb **)((int)param_1 + 0x4b0));
          }
          pcVar5 = *(code **)(*(int *)((int)param_1 + 0x4d0) + 0x68);
          if (pcVar5 == (code *)0x0) {
            iVar1 = X509_verify_cert(ctx);
          }
          else {
            iVar1 = (*pcVar5)(ctx,*(undefined4 *)(*(int *)((int)param_1 + 0x4d0) + 0x6c));
          }
          iVar3 = X509_STORE_CTX_get_error(ctx);
          *(int *)((int)param_1 + 0x4d8) = iVar3;
          OPENSSL_sk_pop_free(*(undefined4 *)((int)param_1 + 0x4d4),0x178169);
          *(undefined4 *)((int)param_1 + 0x4d4) = 0;
          iVar3 = X509_STORE_CTX_get0_chain(ctx);
          if (iVar3 != 0) {
            psVar4 = X509_STORE_CTX_get1_chain(ctx);
            *(stack_st_X509 **)((int)param_1 + 0x4d4) = psVar4;
            if (psVar4 == (stack_st_X509 *)0x0) {
              ERR_put_error(0x14,0xcf,0x41,"ssl/ssl_cert.c",0x1b3);
              iVar1 = 0;
            }
          }
          X509_VERIFY_PARAM_move_peername(*(undefined4 *)((int)param_1 + 0x90),to);
        }
      }
      X509_STORE_CTX_free(ctx);
      return iVar1;
    }
    ERR_put_error(0x14,0xcf,0x41,"ssl/ssl_cert.c",0x17d);
  }
  return 0;
}

