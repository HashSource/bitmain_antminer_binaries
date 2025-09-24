
int tls_finish_handshake(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  SSL_CTX *pSVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  bool bVar6;
  
  iVar5 = *(int *)(param_1 + 0x54);
  if (param_3 != 0) {
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) & 8) == 0) {
      BUF_MEM_free(*(BUF_MEM **)(param_1 + 0x6c));
      *(undefined4 *)(param_1 + 0x6c) = 0;
      iVar1 = ssl_free_wbio_buffer(param_1);
      if (iVar1 == 0) {
        iVar1 = 0;
        goto LAB_000f4228;
      }
    }
    else {
      iVar1 = ssl_free_wbio_buffer(param_1);
      if (iVar1 == 0) {
LAB_000f4228:
        ossl_statem_fatal(param_1,0x50,0x255,0x44,"ssl/statem/statem_lib.c",0x423);
        return iVar1;
      }
    }
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  if (((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
      (iVar1 = **(int **)(param_1 + 4), iVar1 == 0x10000 || iVar1 < 0x304)) ||
     (*(int *)(param_1 + 0x1c) != 0)) {
    if (iVar5 != 0) goto LAB_000f410e;
LAB_000f40ac:
    pcVar4 = *(code **)(param_1 + 0x4b4);
    if ((pcVar4 == (code *)0x0) &&
       (pcVar4 = *(code **)(*(int *)(param_1 + 0x4d0) + 0xa0), pcVar4 == (code *)0x0))
    goto LAB_000f4256;
    ossl_statem_set_in_init(param_1,iVar5);
    if (((-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) &&
        ((iVar5 = **(int **)(param_1 + 4), iVar5 != 0x10000 && 0x303 < iVar5 &&
         (*(int *)(*(int *)(param_1 + 0x7c) + 0x180) != 0)))) &&
       (*(int *)(*(int *)(param_1 + 0x7c) + 0x204) != 0)) goto LAB_000f40d0;
  }
  else {
    iVar1 = *(int *)(param_1 + 0x5f4);
    bVar6 = iVar1 == 4;
    if (bVar6) {
      iVar1 = 1;
    }
    if (bVar6) {
      *(int *)(param_1 + 0x5f4) = iVar1;
    }
    if (iVar5 == 0) goto LAB_000f40ac;
LAB_000f410e:
    *(undefined4 *)(param_1 + 0x5ec) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x54) = 0;
    *(undefined4 *)(param_1 + 0x55c) = 0;
    ssl3_cleanup_key_block(param_1);
    if (*(int *)(param_1 + 0x1c) == 0) {
      if ((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
         (iVar5 = **(int **)(param_1 + 4), iVar5 == 0x10000 || iVar5 < 0x304)) {
        ssl_update_cache(param_1,1);
        pSVar2 = *(SSL_CTX **)(param_1 + 0x5e0);
      }
      else {
        pSVar2 = *(SSL_CTX **)(param_1 + 0x5e0);
        if (pSVar2->session_timeout << 0x1f < 0) {
          SSL_CTX_remove_session(pSVar2,*(SSL_SESSION **)(param_1 + 0x474));
          pSVar2 = *(SSL_CTX **)(param_1 + 0x5e0);
        }
      }
      if (*(int *)(param_1 + 0x8c) != 0) {
        piVar3 = &(pSVar2->stats).sess_cb_hit;
        do {
          ExclusiveAccess(piVar3);
          bVar6 = (bool)hasExclusiveAccess(piVar3);
        } while (!bVar6);
        *piVar3 = *piVar3 + 1;
        pSVar2 = *(SSL_CTX **)(param_1 + 0x5e0);
      }
      piVar3 = &(pSVar2->stats).sess_accept;
      *(undefined4 *)(param_1 + 0x18) = 0xedc69;
      do {
        ExclusiveAccess(piVar3);
        bVar6 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar6);
      *piVar3 = *piVar3 + 1;
    }
    else {
      if ((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) ||
         (iVar5 = **(int **)(param_1 + 4), iVar5 == 0x10000 || iVar5 < 0x304)) {
        ssl_update_cache(param_1,2);
      }
      piVar3 = (int *)(*(int *)(param_1 + 0x4d0) + 0x4c);
      do {
        ExclusiveAccess(piVar3);
        bVar6 = (bool)hasExclusiveAccess(piVar3);
      } while (!bVar6);
      *piVar3 = *piVar3 + 1;
      *(undefined4 *)(param_1 + 0x18) = 0xedc71;
    }
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
      iVar5 = *(int *)(param_1 + 0x80);
      *(undefined2 *)(iVar5 + 0x10c) = 0;
      *(undefined2 *)(iVar5 + 0x108) = 0;
      *(undefined2 *)(iVar5 + 0x10a) = 0;
      dtls1_clear_received_buffer(param_1);
    }
    pcVar4 = *(code **)(param_1 + 0x4b4);
    if ((pcVar4 == (code *)0x0) &&
       (pcVar4 = *(code **)(*(int *)(param_1 + 0x4d0) + 0xa0), pcVar4 == (code *)0x0)) {
LAB_000f4256:
      ossl_statem_set_in_init(param_1,0);
      goto LAB_000f40d0;
    }
    ossl_statem_set_in_init(param_1,0);
  }
  (*pcVar4)(param_1,0x20,1);
LAB_000f40d0:
  if (param_4 == 0) {
    ossl_statem_set_in_init(param_1,1);
    return 2;
  }
  return 1;
}

