
undefined4 ssl_get_new_session(SSL *param_1,int param_2)

{
  SSL_SESSION *__s;
  time_t tVar1;
  char *pcVar2;
  long lVar3;
  uint extraout_r2;
  uint extraout_r2_00;
  uint uVar4;
  uint extraout_r2_01;
  uint extraout_r2_02;
  void *pvVar5;
  int iVar6;
  int line;
  SSL_SESSION *pSVar7;
  code *pcVar8;
  uint local_1c [2];
  
  __s = (SSL_SESSION *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xc4);
  if (__s == (SSL_SESSION *)0x0) {
    ERR_put_error(0x14,0xbd,0x41,"ssl_sess.c",0xc6);
    return 0;
  }
  memset(__s,0,0xf4);
  __s->krb5_client_princ[0x10] = '\x01';
  __s->krb5_client_princ[0x11] = '\0';
  __s->krb5_client_princ[0x12] = '\0';
  __s->krb5_client_princ[0x13] = '\0';
  __s->krb5_client_princ[0x14] = '\x01';
  __s->krb5_client_princ[0x15] = '\0';
  __s->krb5_client_princ[0x16] = '\0';
  __s->krb5_client_princ[0x17] = '\0';
  __s->krb5_client_princ[0x18] = '0';
  __s->krb5_client_princ[0x19] = '\x01';
  __s->krb5_client_princ[0x1a] = '\0';
  __s->krb5_client_princ[0x1b] = '\0';
  tVar1 = time((time_t *)0x0);
  __s->krb5_client_princ[0x38] = '\0';
  __s->krb5_client_princ[0x39] = '\0';
  __s->krb5_client_princ[0x3a] = '\0';
  __s->krb5_client_princ[0x3b] = '\0';
  *(time_t *)(__s->krb5_client_princ + 0x1c) = tVar1;
  __s->krb5_client_princ[0x3c] = '\0';
  __s->krb5_client_princ[0x3d] = '\0';
  __s->krb5_client_princ[0x3e] = '\0';
  __s->krb5_client_princ[0x3f] = '\0';
  __s->krb5_client_princ[0x20] = '\0';
  __s->krb5_client_princ[0x21] = '\0';
  __s->krb5_client_princ[0x22] = '\0';
  __s->krb5_client_princ[0x23] = '\0';
  __s->krb5_client_princ[0x40] = '\0';
  __s->krb5_client_princ[0x41] = '\0';
  __s->krb5_client_princ[0x42] = '\0';
  __s->krb5_client_princ[0x43] = '\0';
  __s->krb5_client_princ[0x44] = '\0';
  __s->krb5_client_princ[0x45] = '\0';
  __s->krb5_client_princ[0x46] = '\0';
  __s->krb5_client_princ[0x47] = '\0';
  __s->krb5_client_princ[0x48] = '\0';
  __s->krb5_client_princ[0x49] = '\0';
  __s->krb5_client_princ[0x4a] = '\0';
  __s->krb5_client_princ[0x4b] = '\0';
  __s->krb5_client_princ[0x4c] = '\0';
  __s->krb5_client_princ[0x4d] = '\0';
  __s->krb5_client_princ[0x4e] = '\0';
  __s->krb5_client_princ[0x4f] = '\0';
  __s->krb5_client_princ[0x50] = '\0';
  __s->krb5_client_princ[0x51] = '\0';
  __s->krb5_client_princ[0x52] = '\0';
  __s->krb5_client_princ[0x53] = '\0';
  CRYPTO_new_ex_data(3,__s,(CRYPTO_EX_DATA *)(__s->krb5_client_princ + 0x30));
  pvVar5 = param_1->tls_session_secret_cb_arg;
  __s->krb5_client_princ_len = 0;
  __s->krb5_client_princ[0] = '\0';
  __s->krb5_client_princ[1] = '\0';
  __s->krb5_client_princ[2] = '\0';
  __s->krb5_client_princ[3] = '\0';
  iVar6 = *(int *)((int)pvVar5 + 0x24);
  __s->krb5_client_princ[0x60] = '\0';
  __s->krb5_client_princ[0x61] = '\0';
  __s->krb5_client_princ[0x62] = '\0';
  __s->krb5_client_princ[99] = '\0';
  if (iVar6 == 0) {
    lVar3 = SSL_get_default_timeout(param_1);
    *(long *)(__s->krb5_client_princ + 0x18) = lVar3;
    uVar4 = extraout_r2_01;
  }
  else {
    *(int *)(__s->krb5_client_princ + 0x18) = iVar6;
    uVar4 = extraout_r2;
  }
  pSVar7 = param_1->session;
  if (pSVar7 != (SSL_SESSION *)0x0) {
    iVar6 = CRYPTO_add_lock((int *)(pSVar7->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x352);
    uVar4 = extraout_r2_00;
    if (iVar6 < 1) {
      SSL_SESSION_free_part_0(pSVar7);
      uVar4 = extraout_r2_02;
    }
    param_1->session = (SSL_SESSION *)0x0;
  }
  if (param_2 == 0) {
    __s->session_id_length = 0;
    goto LAB_0007ed46;
  }
  iVar6 = param_1->version;
  if (iVar6 == 2) {
    uVar4 = 0x10;
    __s->ssl_version = 2;
  }
  if (iVar6 == 2) {
    __s->session_id_length = uVar4;
  }
  else {
    if (((((iVar6 != 0x300) && (iVar6 != 0x301)) && (iVar6 != 0x302)) &&
        ((iVar6 != 0x303 && (iVar6 != 0x100)))) && ((iVar6 != 0xfeff && (iVar6 != 0xfefd)))) {
      line = 0x1c3;
      iVar6 = 0x103;
      goto LAB_0007edf8;
    }
    __s->ssl_version = iVar6;
    __s->session_id_length = 0x20;
  }
  if (param_1->tlsext_ocsp_resplen == 0) {
    CRYPTO_lock(5,0xc,"ssl_sess.c",0x1dd);
    pcVar8 = param_1->generate_session_id;
    if ((pcVar8 == (GEN_SESSION_CB)0x0) &&
       (pcVar8 = *(code **)((int)param_1->tls_session_secret_cb_arg + 0xec),
       pcVar8 == (GEN_SESSION_CB)0x0)) {
      pcVar8 = (code *)0x7e671;
    }
    CRYPTO_lock(6,0xc,"ssl_sess.c",0x1e2);
    local_1c[0] = __s->session_id_length;
    iVar6 = (*pcVar8)(param_1,__s->session_id,local_1c);
    if (iVar6 == 0) {
      line = 0x1e8;
      iVar6 = 0x12d;
      goto LAB_0007edf8;
    }
    if (local_1c[0] != 0) {
      uVar4 = __s->session_id_length;
      if (local_1c[0] <= uVar4) {
        if ((local_1c[0] < uVar4) && (param_1->version == 2)) {
          memset(__s->session_id + local_1c[0],0,uVar4 - local_1c[0]);
          uVar4 = __s->session_id_length;
        }
        else {
          __s->session_id_length = local_1c[0];
          uVar4 = local_1c[0];
        }
        iVar6 = SSL_has_matching_session_id(param_1,__s->session_id,uVar4);
        if (iVar6 != 0) {
          line = 0x1ff;
          iVar6 = 0x12e;
          goto LAB_0007edf8;
        }
        goto LAB_0007edd6;
      }
    }
    line = 499;
    iVar6 = 0x12f;
    goto LAB_0007edf8;
  }
  __s->session_id_length = 0;
LAB_0007edd6:
  if ((char *)param_1->tlsext_debug_arg == (char *)0x0) {
LAB_0007ed46:
    if (param_1->sid_ctx_length < 0x21) {
      memcpy(__s->sid_ctx,param_1->sid_ctx,param_1->sid_ctx_length);
      iVar6 = param_1->version;
      __s->sid_ctx_length = param_1->sid_ctx_length;
      param_1->session = __s;
      __s->ssl_version = iVar6;
      __s->krb5_client_princ[0x10] = '\0';
      __s->krb5_client_princ[0x11] = '\0';
      __s->krb5_client_princ[0x12] = '\0';
      __s->krb5_client_princ[0x13] = '\0';
      return 1;
    }
    line = 0x213;
  }
  else {
    pcVar2 = BUF_strdup((char *)param_1->tlsext_debug_arg);
    line = 0x208;
    *(char **)(__s->krb5_client_princ + 0x40) = pcVar2;
    if (pcVar2 != (char *)0x0) goto LAB_0007ed46;
  }
  iVar6 = 0x44;
LAB_0007edf8:
  ERR_put_error(0x14,0xb5,iVar6,"ssl_sess.c",line);
  iVar6 = CRYPTO_add_lock((int *)(__s->krb5_client_princ + 0x14),-1,0xe,"ssl_sess.c",0x352);
  if (iVar6 < 1) {
    SSL_SESSION_free_part_0(__s);
  }
  return 0;
}

