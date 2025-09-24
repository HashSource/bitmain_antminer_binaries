
undefined4 final_server_name(SSL *param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  SSL_CIPHER *pSVar3;
  char *pcVar4;
  int iVar5;
  SSL_SESSION *pSVar6;
  uint uVar7;
  _func_3211 **pp_Var8;
  int *piVar9;
  EVP_CIPHER_CTX *pEVar10;
  _func_3212 *p_Var11;
  int iVar12;
  undefined4 local_1c;
  
  local_1c = 0x70;
  uVar2 = SSL_get_options();
  if ((param_1[3].method == (SSL_METHOD *)0x0) || (uVar7 = param_1[3].max_send_fragment, uVar7 == 0)
     ) {
    ossl_statem_fatal(param_1,0x50,0x22e,0x44,"ssl/statem/extensions.c",0x3a8);
    return 0;
  }
  p_Var11 = param_1[3].method[2].get_cipher_by_char;
  if (p_Var11 == (_func_3212 *)0x0) {
    pSVar3 = (SSL_CIPHER *)0x3;
    if (*(code **)(uVar7 + 0x130) == (code *)0x0) goto LAB_000e673a;
    pSVar3 = (SSL_CIPHER *)
             (**(code **)(uVar7 + 0x130))(param_1,&local_1c,*(undefined4 *)(uVar7 + 0x134));
  }
  else {
    pSVar3 = (*p_Var11)((uchar *)param_1);
  }
  if (param_1->in_handshake != 0) {
    if (param_3 != 0) {
      param_3 = 1;
    }
    if (pSVar3 != (SSL_CIPHER *)0x0) {
      param_3 = 0;
    }
    if (param_3 != 0) {
      if (param_1->enc_write_ctx == (EVP_CIPHER_CTX *)0x0) {
        CRYPTO_free(*(void **)(param_1[2].tlsext_ticket_expected + 0x1cc));
        iVar12 = param_1[2].tlsext_ticket_expected;
        pcVar4 = CRYPTO_strdup((char *)param_1[3].param,"ssl/statem/extensions.c",0x3bf);
        iVar5 = param_1[2].tlsext_ticket_expected;
        *(char **)(iVar12 + 0x1cc) = pcVar4;
        pSVar3 = (SSL_CIPHER *)0x0;
        if ((*(int *)(iVar5 + 0x1cc) == 0) &&
           (pSVar3 = (SSL_CIPHER *)param_1[3].param, pSVar3 != (SSL_CIPHER *)0x0)) {
          ossl_statem_fatal(param_1,0x50,0x22e,0x44,"ssl/statem/extensions.c",0x3c2);
          pSVar3 = (SSL_CIPHER *)0x0;
        }
      }
      else {
        pSVar3 = (SSL_CIPHER *)0x0;
      }
    }
  }
LAB_000e673a:
  if ((((*(int *)(param_1->mac_flags + 0x180) == 0) || (*(int *)(param_1->mac_flags + 0x204) == 0))
      && (param_1[3].method != (SSL_METHOD *)param_1[3].max_send_fragment)) &&
     (param_1[2].tlsext_debug_cb == (_func_3297 *)0x0)) {
    pp_Var8 = &(param_1[3].method)->ssl_ctx_ctrl;
    do {
      ExclusiveAccess(pp_Var8);
      bVar1 = (bool)hasExclusiveAccess(pp_Var8);
    } while (!bVar1);
    *pp_Var8 = *pp_Var8 + 1;
    piVar9 = (int *)(param_1[3].max_send_fragment + 0x44);
    do {
      ExclusiveAccess(piVar9);
      bVar1 = (bool)hasExclusiveAccess(piVar9);
    } while (!bVar1);
    *piVar9 = *piVar9 + -1;
  }
  if (pSVar3 != (SSL_CIPHER *)0x0) {
    if (pSVar3 == (SSL_CIPHER *)0x2) {
      ossl_statem_fatal(param_1,local_1c,0x22e,0xea,"ssl/statem/extensions.c",0x3f3);
      return 0;
    }
    if (pSVar3 != (SSL_CIPHER *)0x3) {
      if (pSVar3 != (SSL_CIPHER *)0x1) {
        return 1;
      }
      if ((*(int *)(((int *)param_1->type)[0x19] + 0x30) << 0x1c < 0) ||
         (iVar5 = *(int *)param_1->type, iVar5 < 0x304 || iVar5 == 0x10000)) {
        ssl3_send_alert(param_1,1,local_1c);
      }
    }
    param_1[3].options = 0;
    return 1;
  }
  uVar2 = ((uVar2 ^ 0x4000) << 0x11) >> 0x1f;
  if (param_1[3].compress == (COMP_CTX *)0x0) {
    uVar2 = 0;
  }
  if (((uVar2 != 0) && (iVar5 = SSL_get_options(param_1), iVar5 << 0x11 < 0)) &&
     (pEVar10 = param_1->enc_write_ctx, param_1[3].compress = (COMP_CTX *)0x0,
     pEVar10 == (EVP_CIPHER_CTX *)0x0)) {
    pSVar6 = SSL_get_session(param_1);
    if (pSVar6 == (SSL_SESSION *)0x0) {
      ossl_statem_fatal(param_1,0x50,0x22e,0x44,"ssl/statem/extensions.c",0x3eb);
      return 0;
    }
    CRYPTO_free(pSVar6->next);
    pSVar6->next = (ssl_session_st **)0x0;
    pSVar6->tlsext_hostname = (char *)0x0;
    pSVar6->tlsext_ecpointformatlist_length = 0;
    pSVar6->tlsext_ecpointformatlist = (uchar *)0x0;
    iVar5 = ssl_generate_session_id(param_1,pSVar6);
    if (iVar5 == 0) {
      ossl_statem_fatal(param_1,0x50,0x22e,0x44,"ssl/statem/extensions.c",0x3e6);
      return 0;
    }
  }
  return 1;
}

