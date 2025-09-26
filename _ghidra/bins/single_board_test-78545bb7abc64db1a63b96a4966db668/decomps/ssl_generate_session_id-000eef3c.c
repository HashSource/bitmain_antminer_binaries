
undefined4 ssl_generate_session_id(SSL *param_1,int param_2)

{
  int iVar1;
  COMP_CTX *pCVar2;
  undefined4 uVar3;
  code *pcVar4;
  uchar *id;
  size_t __n;
  uint local_24 [2];
  
  iVar1 = param_1->version;
  if (iVar1 < 0x305) {
    if ((iVar1 < 0x300) && (iVar1 != 0x100)) {
LAB_000ef00a:
      ossl_statem_fatal(param_1,0x50,0x223,0x103,"ssl/ssl_sess.c",0x12a);
      return 0;
    }
  }
  else if ((iVar1 != 0xfefd) && (iVar1 != 0xfeff)) goto LAB_000ef00a;
  pCVar2 = param_1[3].compress;
  *(undefined4 *)(param_2 + 0x148) = 0x20;
  if (pCVar2 == (COMP_CTX *)0x0) {
    CRYPTO_THREAD_read_lock(param_1[9].first_packet);
    CRYPTO_THREAD_read_lock(*(undefined4 *)(param_1[3].max_send_fragment + 0x218));
    pcVar4 = (code *)param_1[2].tlsext_ellipticcurvelist;
    if ((pcVar4 == (code *)0x0) &&
       (pcVar4 = *(code **)(param_1[3].max_send_fragment + 0xfc), pcVar4 == (code *)0x0)) {
      pcVar4 = (code *)0xeee15;
    }
    id = (uchar *)(param_2 + 0x14c);
    CRYPTO_THREAD_unlock(*(undefined4 *)(param_1[3].max_send_fragment + 0x218));
    CRYPTO_THREAD_unlock(param_1[9].first_packet);
    __n = *(size_t *)(param_2 + 0x148);
    memset(id,0,__n);
    local_24[0] = __n;
    iVar1 = (*pcVar4)(param_1,id,local_24);
    if (iVar1 == 0) {
      ossl_statem_fatal(param_1,0x50,0x223,0x12d,"ssl/ssl_sess.c",0x151);
      uVar3 = 0;
    }
    else {
      if ((local_24[0] == 0) || (*(uint *)(param_2 + 0x148) < local_24[0])) {
        ossl_statem_fatal(param_1,0x50,0x223,0x12f,"ssl/ssl_sess.c",0x15b);
        return 0;
      }
      *(uint *)(param_2 + 0x148) = local_24[0];
      iVar1 = SSL_has_matching_session_id(param_1,id,local_24[0]);
      if (iVar1 == 0) {
        uVar3 = 1;
      }
      else {
        ossl_statem_fatal(param_1,0x50,0x223,0x12e,"ssl/ssl_sess.c",0x163);
        uVar3 = 0;
      }
    }
  }
  else {
    uVar3 = 1;
    *(undefined4 *)(param_2 + 0x148) = 0;
  }
  return uVar3;
}

