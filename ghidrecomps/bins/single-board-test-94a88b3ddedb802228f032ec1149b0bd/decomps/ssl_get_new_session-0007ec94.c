
undefined4 ssl_get_new_session(SSL *param_1,int param_2)

{
  SSL_SESSION *__s;
  time_t tVar1;
  char *pcVar2;
  long lVar3;
  CRYPTO_EX_DATA *ad;
  void *pvVar4;
  int iVar5;
  int line;
  uint uVar6;
  SSL_SESSION *pSVar7;
  GEN_SESSION_CB pGVar8;
  uint local_1c [2];
  
  __s = (SSL_SESSION *)CRYPTO_malloc(0xf4,DAT_0007ef00,0xc4);
  if (__s == (SSL_SESSION *)0x0) {
    ERR_put_error(0x14,0xbd,0x41,DAT_0007ef00,0xc6);
    return 0;
  }
  memset(__s,0,0xf4);
  *(undefined4 *)(__s->krb5_client_princ + 0x10) = 1;
  *(undefined4 *)(__s->krb5_client_princ + 0x14) = 1;
  *(undefined4 *)(__s->krb5_client_princ + 0x18) = 0x130;
  tVar1 = time((time_t *)0x0);
  *(undefined4 *)(__s->krb5_client_princ + 0x38) = 0;
  *(time_t *)(__s->krb5_client_princ + 0x1c) = tVar1;
  ad = (CRYPTO_EX_DATA *)(__s->krb5_client_princ + 0x30);
  *(undefined4 *)(__s->krb5_client_princ + 0x3c) = 0;
  *(undefined4 *)(__s->krb5_client_princ + 0x20) = 0;
  *(undefined4 *)(__s->krb5_client_princ + 0x40) = 0;
  *(undefined4 *)(__s->krb5_client_princ + 0x44) = 0;
  *(undefined4 *)(__s->krb5_client_princ + 0x48) = 0;
  *(undefined4 *)(__s->krb5_client_princ + 0x4c) = 0;
  *(undefined4 *)(__s->krb5_client_princ + 0x50) = 0;
  CRYPTO_new_ex_data(3,__s,ad);
  pvVar4 = param_1->tls_session_secret_cb_arg;
  __s->krb5_client_princ_len = 0;
  *(undefined4 *)__s->krb5_client_princ = 0;
  iVar5 = *(int *)((int)pvVar4 + 0x24);
  *(undefined4 *)(__s->krb5_client_princ + 0x60) = 0;
  if (iVar5 == 0) {
    lVar3 = SSL_get_default_timeout(param_1);
    *(long *)(__s->krb5_client_princ + 0x18) = lVar3;
  }
  else {
    *(int *)(__s->krb5_client_princ + 0x18) = iVar5;
  }
  pSVar7 = param_1->session;
  if (pSVar7 != (SSL_SESSION *)0x0) {
    ad = (CRYPTO_EX_DATA *)0xe;
    iVar5 = CRYPTO_add_lock((int *)(pSVar7->krb5_client_princ + 0x14),-1,0xe,DAT_0007ef00,0x352);
    if (iVar5 < 1) {
      SSL_SESSION_free_part_0(pSVar7);
    }
    param_1->session = (SSL_SESSION *)0x0;
  }
  if (param_2 == 0) {
    __s->session_id_length = 0;
    goto LAB_0007ed46;
  }
  iVar5 = param_1->version;
  if (iVar5 == 2) {
    ad = (CRYPTO_EX_DATA *)0x10;
    __s->ssl_version = 2;
  }
  if (iVar5 == 2) {
    __s->session_id_length = (uint)ad;
  }
  else {
    if (((((iVar5 != 0x300) && (iVar5 != 0x301)) && (iVar5 != 0x302)) &&
        ((iVar5 != 0x303 && (iVar5 != 0x100)))) && ((iVar5 != 0xfeff && (iVar5 != 0xfefd)))) {
      line = 0x1c3;
      iVar5 = 0x103;
      goto LAB_0007edf8;
    }
    __s->ssl_version = iVar5;
    __s->session_id_length = 0x20;
  }
  if (param_1->tlsext_ocsp_resplen == 0) {
    CRYPTO_lock(5,0xc,DAT_0007ef00,0x1dd);
    pGVar8 = param_1->generate_session_id;
    if ((param_1->generate_session_id == (GEN_SESSION_CB)0x0) &&
       (pGVar8 = *(GEN_SESSION_CB *)((int)param_1->tls_session_secret_cb_arg + 0xec),
       pGVar8 == (GEN_SESSION_CB)0x0)) {
      pGVar8 = DAT_0007ef04;
    }
    CRYPTO_lock(6,0xc,DAT_0007ef00,0x1e2);
    local_1c[0] = __s->session_id_length;
    iVar5 = (*pGVar8)(param_1,__s->session_id,local_1c);
    if (iVar5 == 0) {
      line = 0x1e8;
      iVar5 = 0x12d;
      goto LAB_0007edf8;
    }
    if (local_1c[0] != 0) {
      uVar6 = __s->session_id_length;
      if (local_1c[0] <= uVar6) {
        if ((local_1c[0] < uVar6) && (param_1->version == 2)) {
          memset(__s->session_id + local_1c[0],0,uVar6 - local_1c[0]);
          uVar6 = __s->session_id_length;
        }
        else {
          __s->session_id_length = local_1c[0];
          uVar6 = local_1c[0];
        }
        iVar5 = SSL_has_matching_session_id(param_1,__s->session_id,uVar6);
        if (iVar5 != 0) {
          line = 0x1ff;
          iVar5 = 0x12e;
          goto LAB_0007edf8;
        }
        goto LAB_0007edd6;
      }
    }
    line = 499;
    iVar5 = 0x12f;
    goto LAB_0007edf8;
  }
  __s->session_id_length = 0;
LAB_0007edd6:
  if ((char *)param_1->tlsext_debug_arg == (char *)0x0) {
LAB_0007ed46:
    if (param_1->sid_ctx_length < 0x21) {
      memcpy(__s->sid_ctx,param_1->sid_ctx,param_1->sid_ctx_length);
      iVar5 = param_1->version;
      __s->sid_ctx_length = param_1->sid_ctx_length;
      param_1->session = __s;
      __s->ssl_version = iVar5;
      *(undefined4 *)(__s->krb5_client_princ + 0x10) = 0;
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
  iVar5 = 0x44;
LAB_0007edf8:
  ERR_put_error(0x14,0xb5,iVar5,DAT_0007ef00,line);
  iVar5 = CRYPTO_add_lock((int *)(__s->krb5_client_princ + 0x14),-1,0xe,DAT_0007ef00,0x352);
  if (iVar5 < 1) {
    SSL_SESSION_free_part_0(__s);
  }
  return 0;
}

