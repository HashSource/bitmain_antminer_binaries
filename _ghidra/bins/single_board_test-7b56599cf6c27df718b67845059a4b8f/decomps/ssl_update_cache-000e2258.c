
void ssl_update_cache(int param_1,uint param_2)

{
  SSL_CTX *pSVar1;
  time_t tm;
  int iVar2;
  SSL_SESSION *c;
  int *piVar3;
  uint uVar4;
  int iVar5;
  
  c = *(SSL_SESSION **)(param_1 + 0x474);
  if (*(int *)(c->krb5_client_princ + 0xb8) == 0) {
    return;
  }
  if (((*(int *)(param_1 + 0x1c) != 0) && (*(int *)(c->krb5_client_princ + 0xdc) == 0)) &&
     (*(int *)(param_1 + 0x4ac) << 0x1f < 0)) {
    return;
  }
  pSVar1 = *(SSL_CTX **)(param_1 + 0x5e0);
  uVar4 = pSVar1->session_timeout;
  if ((uVar4 & param_2) == 0) goto LAB_000e2344;
  if (*(int *)(param_1 + 0x8c) == 0) {
    if (-1 < (int)(uVar4 << 0x16)) {
      if (-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) {
        iVar2 = **(int **)(param_1 + 4);
LAB_000e22d8:
        if ((((*(int *)(param_1 + 0x1c) != 0 && (0x303 < iVar2 && iVar2 != 0x10000)) &&
             ((*(int *)(param_1 + 0xf50) == 0 || (*(int *)(param_1 + 0x4ec) << 7 < 0)))) &&
            (pSVar1->get_session_cb == (_func_3231 *)0x0)) &&
           (-1 < *(int *)(param_1 + 0x4ec) << 0x11)) goto LAB_000e2320;
      }
      SSL_CTX_add_session(pSVar1,c);
      pSVar1 = *(SSL_CTX **)(param_1 + 0x5e0);
    }
  }
  else {
    if (*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) goto LAB_000e2344;
    iVar2 = **(int **)(param_1 + 4);
    iVar5 = iVar2 + -0x10000;
    if (iVar5 != 0) {
      iVar5 = 1;
    }
    if (iVar2 < 0x304) {
      iVar5 = 0;
    }
    if (iVar5 == 0) goto LAB_000e2344;
    if ((uVar4 & 0x200) == 0) goto LAB_000e22d8;
  }
LAB_000e2320:
  if (pSVar1->remove_session_cb != (_func_3230 *)0x0) {
    SSL_SESSION_up_ref(*(undefined4 *)(param_1 + 0x474));
    iVar2 = (**(code **)(*(int *)(param_1 + 0x5e0) + 0x2c))
                      (param_1,*(undefined4 *)(param_1 + 0x474));
    if (iVar2 == 0) {
      SSL_SESSION_free(*(SSL_SESSION **)(param_1 + 0x474));
    }
  }
LAB_000e2344:
  if (((uint)(param_2 == (uVar4 & param_2)) & (uVar4 ^ 0x80) >> 7) != 0) {
    pSVar1 = *(SSL_CTX **)(param_1 + 0x5e0);
    if ((int)(param_2 << 0x1f) < 0) {
      piVar3 = &(pSVar1->stats).sess_accept;
    }
    else {
      piVar3 = &(pSVar1->stats).sess_miss;
    }
    if ((*piVar3 & 0xffU) == 0xff) {
      tm = time((time_t *)0x0);
      SSL_CTX_flush_sessions(pSVar1,tm);
      return;
    }
  }
  return;
}

