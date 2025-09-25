
SSL_SESSION * lookup_sess_in_cache(int *param_1,void *param_2,size_t param_3)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  SSL_SESSION *pSVar4;
  int local_21c [82];
  size_t local_d4;
  undefined1 auStack_d0 [184];
  
  iVar3 = param_1[0x178];
  if ((*(uint *)(iVar3 + 0x24) & 0x100) == 0) {
    local_21c[0] = *param_1;
    if (0x20 < param_3) {
      return (SSL_SESSION *)0x0;
    }
    memcpy(auStack_d0,param_2,param_3);
    local_d4 = param_3;
    CRYPTO_THREAD_read_lock(*(undefined4 *)(iVar3 + 0x218));
    pSVar4 = (SSL_SESSION *)OPENSSL_LH_retrieve(*(undefined4 *)(param_1[0x178] + 0x14),local_21c);
    if (pSVar4 != (SSL_SESSION *)0x0) {
      SSL_SESSION_up_ref();
      CRYPTO_THREAD_unlock(*(undefined4 *)(param_1[0x178] + 0x218));
      return pSVar4;
    }
    CRYPTO_THREAD_unlock(*(undefined4 *)(param_1[0x178] + 0x218));
    piVar2 = (int *)(param_1[0x178] + 0x50);
    do {
      ExclusiveAccess(piVar2);
      bVar1 = (bool)hasExclusiveAccess(piVar2);
    } while (!bVar1);
    *piVar2 = *piVar2 + 1;
    iVar3 = param_1[0x178];
  }
  pSVar4 = *(SSL_SESSION **)(iVar3 + 0x34);
  if (pSVar4 != (SSL_SESSION *)0x0) {
    local_21c[0] = 1;
    pSVar4 = (SSL_SESSION *)(*(code *)pSVar4)(param_1,param_2,param_3,local_21c);
    if (pSVar4 != (SSL_SESSION *)0x0) {
      piVar2 = (int *)(param_1[0x178] + 0x60);
      do {
        ExclusiveAccess(piVar2);
        bVar1 = (bool)hasExclusiveAccess(piVar2);
      } while (!bVar1);
      *piVar2 = *piVar2 + 1;
      if (local_21c[0] != 0) {
        SSL_SESSION_up_ref();
      }
      if (-1 < ((SSL_CTX *)param_1[0x178])->session_timeout << 0x16) {
        SSL_CTX_add_session((SSL_CTX *)param_1[0x178],pSVar4);
      }
    }
  }
  return pSVar4;
}

