
undefined4
ssl_log_rsa_client_key_exchange(int param_1,int param_2,uint param_3,byte *param_4,int param_5)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  byte *pbVar6;
  byte *pbVar7;
  int num;
  
  if (7 < param_3) {
    uVar1 = 1;
    if (*(int *)(*(int *)(param_1 + 0x4d0) + 0x21c) != 0) {
      iVar3 = (param_5 + 8) * 2;
      num = iVar3 + 6;
      pcVar2 = (char *)CRYPTO_malloc(num,"ssl/ssl_lib.c",0x14af);
      if (pcVar2 == (char *)0x0) {
        ossl_statem_fatal(param_1,0x50,500,0x41,"ssl/ssl_lib.c",0x14b1);
        uVar1 = 0;
      }
      else {
        pbVar7 = (byte *)(param_2 + -1);
        builtin_strncpy(pcVar2,"RSA ",4);
        pcVar5 = pcVar2 + 4;
        do {
          pbVar7 = pbVar7 + 1;
          pcVar4 = pcVar5 + 2;
          sprintf(pcVar5,"%02x",(uint)*pbVar7);
          pcVar5 = pcVar4;
        } while (pcVar4 != pcVar2 + 0x14);
        pcVar5 = pcVar2 + 0x15;
        pcVar2[0x14] = ' ';
        if (param_5 != 0) {
          pbVar7 = param_4;
          pcVar4 = pcVar5;
          do {
            pbVar6 = pbVar7 + 1;
            sprintf(pcVar4,"%02x",(uint)*pbVar7);
            pbVar7 = pbVar6;
            pcVar4 = pcVar4 + 2;
          } while (param_4 + param_5 != pbVar6);
          pcVar5 = pcVar5 + iVar3 + -0x10;
        }
        *pcVar5 = '\0';
        (**(code **)(*(int *)(param_1 + 0x4d0) + 0x21c))(param_1,pcVar2);
        CRYPTO_clear_free(pcVar2,num,"ssl/ssl_lib.c",0x14c6);
        uVar1 = 1;
      }
    }
    return uVar1;
  }
  ossl_statem_fatal(param_1,0x50,499,0x44,"ssl/ssl_lib.c",0x14d3);
  return 0;
}

