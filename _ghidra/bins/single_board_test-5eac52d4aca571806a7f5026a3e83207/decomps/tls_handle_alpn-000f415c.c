
undefined4 tls_handle_alpn(int param_1)

{
  undefined4 uVar1;
  void *__s2;
  uint __n;
  int iVar2;
  int iVar3;
  code *pcVar4;
  byte local_1d;
  void *local_1c;
  
  pcVar4 = *(code **)(*(int *)(param_1 + 0x4d0) + 0x170);
  local_1c = (void *)0x0;
  local_1d = 0;
  if (pcVar4 != (code *)0x0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x348);
    if (iVar2 != 0) {
      iVar2 = (*pcVar4)(param_1,&local_1c,&local_1d,iVar2,
                        *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x34c),
                        *(undefined4 *)(*(int *)(param_1 + 0x4d0) + 0x174));
      if (iVar2 == 0) {
        CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 0x340));
        iVar3 = *(int *)(param_1 + 0x7c);
        uVar1 = CRYPTO_memdup(local_1c,local_1d,"ssl/statem/statem_srvr.c",0x883);
        iVar2 = *(int *)(param_1 + 0x7c);
        *(undefined4 *)(iVar3 + 0x340) = uVar1;
        if (*(int *)(iVar2 + 0x340) == 0) {
          *(undefined4 *)(iVar2 + 0x344) = 0;
          ossl_statem_fatal(param_1,0x50,0x232,0x44,"ssl/statem/statem_srvr.c",0x887);
          return 0;
        }
        iVar3 = *(int *)(param_1 + 0x474);
        __n = (uint)local_1d;
        *(undefined4 *)(iVar2 + 0x33c) = 0;
        __s2 = *(void **)(iVar3 + 0x1e4);
        *(uint *)(iVar2 + 0x344) = __n;
        if (__s2 != (void *)0x0) {
          if ((__n == *(uint *)(iVar3 + 0x1e8)) && (iVar2 = memcmp(local_1c,__s2,__n), iVar2 == 0))
          {
            return 1;
          }
          *(undefined4 *)(param_1 + 0x5b0) = 0;
          if (*(int *)(param_1 + 0x8c) != 0) {
            return 1;
          }
          ossl_statem_fatal(param_1,0x50,0x232,0x44,"ssl/statem/statem_srvr.c",0x8a1);
          return 0;
        }
        *(undefined4 *)(param_1 + 0x5b0) = 0;
        if (*(int *)(param_1 + 0x8c) != 0) {
          return 1;
        }
        uVar1 = CRYPTO_memdup(local_1c,__n,"ssl/statem/statem_srvr.c",0x8a5);
        iVar2 = *(int *)(param_1 + 0x474);
        *(undefined4 *)(iVar3 + 0x1e4) = uVar1;
        if (*(int *)(iVar2 + 0x1e4) != 0) {
          *(uint *)(iVar2 + 0x1e8) = (uint)local_1d;
          return 1;
        }
        ossl_statem_fatal(param_1,0x50,0x232,0x44,"ssl/statem/statem_srvr.c",0x8a9);
        return 0;
      }
      if (iVar2 != 3) {
        ossl_statem_fatal(param_1,0x78,0x232,0xeb,"ssl/statem/statem_srvr.c",0x8b3);
        return 0;
      }
    }
  }
  if (*(int *)(*(int *)(param_1 + 0x474) + 0x1e4) != 0) {
    *(undefined4 *)(param_1 + 0x5b0) = 0;
    return 1;
  }
  return 1;
}

