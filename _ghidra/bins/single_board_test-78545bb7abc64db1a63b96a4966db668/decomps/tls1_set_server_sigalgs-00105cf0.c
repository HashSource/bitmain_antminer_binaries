
undefined4 tls1_set_server_sigalgs(int param_1)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  short *local_1c [2];
  
  CRYPTO_free(*(void **)(param_1 + 0xf88));
  iVar5 = *(int *)(param_1 + 0x7c);
  *(undefined4 *)(param_1 + 0xf88) = 0;
  *(undefined4 *)(param_1 + 0xf8c) = 0;
  memset((void *)(iVar5 + 0x27c),0,0x24);
  if ((*(int *)(iVar5 + 0x26c) == 0) && (*(int *)(iVar5 + 0x268) == 0)) {
    iVar1 = tls12_get_psigalgs(param_1,1,local_1c);
    iVar5 = 0;
    do {
      iVar2 = tls1_get_legacy_sigalg(param_1,iVar5);
      if ((iVar2 != 0) && (iVar1 != 0)) {
        if (*local_1c[0] != *(short *)(iVar2 + 4)) {
          iVar4 = 0;
          psVar3 = local_1c[0];
          do {
            iVar4 = iVar4 + 1;
            if (iVar1 == iVar4) goto LAB_00105d7e;
            psVar3 = psVar3 + 1;
          } while (*psVar3 != *(short *)(iVar2 + 4));
        }
        *(undefined4 *)(*(int *)(param_1 + 0x7c) + iVar5 * 4 + 0x27c) = 2;
      }
LAB_00105d7e:
      iVar5 = iVar5 + 1;
    } while (iVar5 != 9);
  }
  else {
    iVar5 = tls1_process_sigalgs(param_1);
    if (iVar5 == 0) {
      ossl_statem_fatal(param_1,0x50,0x14f,0x44,"ssl/t1_lib.c",0x507);
      return 0;
    }
    if (*(int *)(param_1 + 0xf88) == 0) {
      ossl_statem_fatal(param_1,0x28,0x14f,0x178,"ssl/t1_lib.c",0x50f);
      return 0;
    }
  }
  return 1;
}

