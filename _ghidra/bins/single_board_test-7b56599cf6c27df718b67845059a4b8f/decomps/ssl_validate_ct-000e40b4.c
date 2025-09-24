
int ssl_validate_ct(SSL *param_1)

{
  int iVar1;
  undefined4 uVar2;
  SSL_SESSION *s;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1[2].tlsext_ticket_expected == 0) {
    return 1;
  }
  iVar3 = *(int *)(param_1[2].tlsext_ticket_expected + 0x19c);
  if ((((iVar3 != 0 && param_1[3].mode != 0) && (param_1[3].wbio == (BIO *)0x0)) &&
      (param_1[3].rbio != (BIO *)0x0)) &&
     ((iVar1 = OPENSSL_sk_num(param_1[3].rbio), 1 < iVar1 &&
      (((iVar1 = OPENSSL_sk_num(param_1->cert), iVar1 < 1 ||
        (*(byte **)param_1->sid_ctx == (byte *)0x0)) || (1 < **(byte **)param_1->sid_ctx - 2)))))) {
    iVar1 = CT_POLICY_EVAL_CTX_new();
    if (iVar1 == 0) {
      ossl_statem_fatal(param_1,0x50,400,0x41,"ssl/ssl_lib.c",0x1397);
    }
    else {
      uVar2 = OPENSSL_sk_value(param_1[3].rbio,1);
      CT_POLICY_EVAL_CTX_set1_cert(iVar1,iVar3);
      CT_POLICY_EVAL_CTX_set1_issuer(iVar1,uVar2);
      CT_POLICY_EVAL_CTX_set_shared_CTLOG_STORE(iVar1,param_1[3].method[2].ssl_write);
      s = SSL_get_session(param_1);
      SSL_SESSION_get_time(s);
      CT_POLICY_EVAL_CTX_set_time(iVar1);
      uVar2 = SSL_get0_peer_scts(param_1);
      iVar3 = SCT_LIST_validate(uVar2,iVar1);
      if (iVar3 < 0) {
        uVar4 = 0x13b4;
        uVar2 = 0xd0;
      }
      else {
        iVar3 = (*(code *)param_1[3].mode)(iVar1,uVar2,param_1[3].max_cert_list);
        if (0 < iVar3) {
          CT_POLICY_EVAL_CTX_free(iVar1);
          return iVar3;
        }
        uVar4 = 0x13bd;
        uVar2 = 0xea;
      }
      ossl_statem_fatal(param_1,0x28,400,uVar2,"ssl/ssl_lib.c",uVar4);
    }
    CT_POLICY_EVAL_CTX_free(iVar1);
    param_1[3].wbio = (BIO *)0x47;
    return 0;
  }
  return 1;
}

