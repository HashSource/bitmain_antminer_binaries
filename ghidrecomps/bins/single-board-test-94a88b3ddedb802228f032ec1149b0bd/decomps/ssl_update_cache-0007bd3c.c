
void ssl_update_cache(int param_1,uint param_2)

{
  char cVar1;
  SSL_CTX *pSVar2;
  int iVar3;
  time_t tm;
  uint uVar4;
  
  if ((*(SSL_SESSION **)(param_1 + 0xc0))->session_id_length == 0) {
    return;
  }
  pSVar2 = *(SSL_CTX **)(param_1 + 0x170);
  uVar4 = pSVar2->session_cache_mode;
  if (((param_2 & uVar4) != 0) && (*(int *)(param_1 + 0x6c) == 0)) {
    if (-1 < (int)(uVar4 << 0x16)) {
      iVar3 = SSL_CTX_add_session(pSVar2,*(SSL_SESSION **)(param_1 + 0xc0));
      if (iVar3 == 0) goto LAB_0007bd8c;
      pSVar2 = *(SSL_CTX **)(param_1 + 0x170);
    }
    if (pSVar2->new_session_cb != (_func_3229 *)0x0) {
      CRYPTO_add_lock((int *)(*(int *)(param_1 + 0xc0) + 0xa4),1,0xe,DAT_0007bdec,0xa40);
      iVar3 = (**(code **)(*(int *)(param_1 + 0x170) + 0x28))
                        (param_1,*(undefined4 *)(param_1 + 0xc0));
      if (iVar3 == 0) {
        SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0xc0));
      }
    }
  }
LAB_0007bd8c:
  if ((-1 < (int)(uVar4 << 0x18)) && (param_2 == (param_2 & uVar4))) {
    pSVar2 = *(SSL_CTX **)(param_1 + 0x170);
    if ((int)(param_2 << 0x1f) < 0) {
      cVar1 = *(char *)&(pSVar2->stats).sess_connect_good;
    }
    else {
      cVar1 = *(char *)&(pSVar2->stats).sess_accept_good;
    }
    if (cVar1 == -1) {
      tm = time((time_t *)0x0);
      SSL_CTX_flush_sessions(pSVar2,tm);
      return;
    }
  }
  return;
}

