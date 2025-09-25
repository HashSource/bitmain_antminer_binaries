
undefined4 tls_construct_cke_psk_preamble(int param_1,undefined4 param_2)

{
  size_t len;
  size_t sVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  code *pcVar7;
  undefined4 uVar8;
  char acStack_1ac [132];
  undefined1 auStack_128 [260];
  
  pcVar7 = *(code **)(param_1 + 0x4c0);
  if (pcVar7 == (code *)0x0) {
    ossl_statem_fatal(param_1,0x50,0x197,0xe0,"ssl/statem/statem_clnt.c",0xb57);
    len = 0;
    uVar8 = 0;
    pcVar2 = (char *)0x0;
    pcVar3 = (char *)0x0;
    sVar1 = 0;
  }
  else {
    memset(acStack_1ac,0,0x81);
    len = (*pcVar7)(param_1,*(undefined4 *)(*(int *)(param_1 + 0x474) + 400),acStack_1ac,0x80,
                    auStack_128,0x100);
    if (len < 0x101) {
      if (len == 0) {
        ossl_statem_fatal(param_1,0x28,0x197,0xdf,"ssl/statem/statem_clnt.c",0xb69);
        uVar8 = 0;
        pcVar2 = (char *)0x0;
        pcVar3 = (char *)0x0;
        sVar1 = 0;
      }
      else {
        sVar1 = strlen(acStack_1ac);
        if (sVar1 < 0x81) {
          pcVar2 = (char *)CRYPTO_memdup(auStack_128,len,"ssl/statem/statem_clnt.c",0xb74);
          pcVar3 = CRYPTO_strdup(acStack_1ac,"ssl/statem/statem_clnt.c",0xb75);
          pcVar5 = (char *)(uint)(pcVar3 == (char *)0x0 || pcVar2 == (char *)0x0);
          if (pcVar3 == (char *)0x0 || pcVar2 == (char *)0x0) {
            uVar8 = 0;
            ossl_statem_fatal(param_1,0x50,0x197,0x41,"ssl/statem/statem_clnt.c",0xb78);
          }
          else {
            CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 600));
            iVar6 = *(int *)(param_1 + 0x7c);
            iVar4 = *(int *)(param_1 + 0x474);
            *(char **)(iVar6 + 600) = pcVar2;
            *(size_t *)(iVar6 + 0x25c) = len;
            CRYPTO_free(*(void **)(iVar4 + 0x194));
            *(char **)(*(int *)(param_1 + 0x474) + 0x194) = pcVar3;
            iVar4 = WPACKET_sub_memcpy__(param_2,acStack_1ac,sVar1,2);
            if (iVar4 == 0) {
              ossl_statem_fatal(param_1,0x50,0x197,0x44,"ssl/statem/statem_clnt.c",0xb86);
              uVar8 = 0;
              pcVar2 = (char *)0x0;
              pcVar3 = (char *)0x0;
            }
            else {
              uVar8 = 1;
              pcVar2 = pcVar5;
              pcVar3 = pcVar5;
            }
          }
        }
        else {
          pcVar3 = (char *)0x0;
          pcVar2 = (char *)0x0;
          uVar8 = 0;
          ossl_statem_fatal(param_1,0x50,0x197,0x44,"ssl/statem/statem_clnt.c",0xb70);
        }
      }
    }
    else {
      pcVar3 = (char *)0x0;
      len = 0x100;
      sVar1 = 0;
      ossl_statem_fatal(param_1,0x28,0x197,0x44,"ssl/statem/statem_clnt.c",0xb63);
      pcVar2 = (char *)0x0;
      uVar8 = 0;
    }
  }
  OPENSSL_cleanse(auStack_128,len);
  OPENSSL_cleanse(acStack_1ac,0x81);
  CRYPTO_clear_free(pcVar2,len,"ssl/statem/statem_clnt.c",0xb8f);
  CRYPTO_clear_free(pcVar3,sVar1,"ssl/statem/statem_clnt.c",0xb90);
  return uVar8;
}

