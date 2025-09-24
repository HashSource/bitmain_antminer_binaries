
undefined4 ssl3_setup_write_buffer(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  
  *(int *)(param_1 + 0x660) = param_2;
  if (param_3 == 0) {
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) & 8) == 0) {
      iVar5 = 5;
      iVar4 = 0x5c;
    }
    else {
      iVar5 = 0xe;
      iVar4 = 0x65;
    }
    iVar1 = ssl_get_max_send_fragment();
    iVar2 = ssl_allow_compression(param_1);
    if (iVar2 == 0) {
      param_3 = iVar5 + iVar1 + 0x57;
    }
    else {
      param_3 = iVar5 + iVar1 + 0x457;
    }
    if (-1 < *(int *)(param_1 + 0x4ec) << 0x14) {
      param_3 = param_3 + iVar4;
    }
  }
  if (param_2 != 0) {
    iVar4 = 0;
    iVar5 = param_1 + 0x6c8;
    do {
      HintPreloadData(iVar5);
      if (*(void **)(iVar5 + -0x50) == (void *)0x0) {
LAB_000d6f08:
        pvVar3 = CRYPTO_malloc(param_3,"ssl/record/ssl3_buffer.c",0x77);
        if (pvVar3 == (void *)0x0) {
          *(int *)(param_1 + 0x660) = iVar4;
          ossl_statem_fatal(param_1,0xffffffff,0x123,0x41,"ssl/record/ssl3_buffer.c",0x80);
          return 0;
        }
        *(undefined4 *)(iVar5 + -0x50) = 0;
        *(undefined4 *)(iVar5 + -0x4c) = 0;
        *(undefined4 *)(iVar5 + -0x48) = 0;
        *(undefined4 *)(iVar5 + -0x44) = 0;
        *(undefined4 *)(iVar5 + -0x40) = 0;
        *(void **)(iVar5 + -0x50) = pvVar3;
        *(int *)(iVar5 + -0x48) = param_3;
      }
      else if (param_3 != *(int *)(iVar5 + -0x48)) {
        CRYPTO_free(*(void **)(iVar5 + -0x50));
        *(undefined4 *)(iVar5 + -0x50) = 0;
        goto LAB_000d6f08;
      }
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + 0x14;
    } while (param_2 != iVar4);
  }
  return 1;
}

