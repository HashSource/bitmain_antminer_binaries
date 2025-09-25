
undefined4 ssl_log_secret(int param_1,char *param_2,byte *param_3,int param_4)

{
  size_t sVar1;
  char *__dest;
  undefined4 uVar2;
  int iVar3;
  int num;
  byte *pbVar4;
  char *pcVar5;
  byte *pbVar6;
  int iVar7;
  char *pcVar8;
  
  if (*(int *)(*(int *)(param_1 + 0x4d0) + 0x21c) != 0) {
    sVar1 = strlen(param_2);
    iVar3 = (param_4 + 0x20) * 2;
    iVar7 = *(int *)(param_1 + 0x7c);
    num = iVar3 + 3 + sVar1;
    __dest = (char *)CRYPTO_malloc(num,"ssl/ssl_lib.c",0x14af);
    if (__dest == (char *)0x0) {
      ossl_statem_fatal(param_1,0x50,500,0x41,"ssl/ssl_lib.c",0x14b1);
      uVar2 = 0;
    }
    else {
      strcpy(__dest,param_2);
      pcVar8 = __dest + sVar1 + 1;
      __dest[sVar1] = ' ';
      pbVar4 = (byte *)(iVar7 + 0xab);
      pcVar5 = pcVar8;
      do {
        pbVar4 = pbVar4 + 1;
        sprintf(pcVar5,"%02x",(uint)*pbVar4);
        pcVar5 = pcVar5 + 2;
      } while (pbVar4 != (byte *)(iVar7 + 0xcb));
      pcVar5 = pcVar8 + 0x41;
      pcVar8[0x40] = ' ';
      if (param_4 != 0) {
        pbVar4 = param_3;
        pcVar8 = pcVar5;
        do {
          pbVar6 = pbVar4 + 1;
          sprintf(pcVar8,"%02x",(uint)*pbVar4);
          pbVar4 = pbVar6;
          pcVar8 = pcVar8 + 2;
        } while (param_3 + param_4 != pbVar6);
        pcVar5 = pcVar5 + iVar3 + -0x40;
      }
      *pcVar5 = '\0';
      (**(code **)(*(int *)(param_1 + 0x4d0) + 0x21c))(param_1,__dest);
      CRYPTO_clear_free(__dest,num,"ssl/ssl_lib.c",0x14c6);
      uVar2 = 1;
    }
    return uVar2;
  }
  return 1;
}

