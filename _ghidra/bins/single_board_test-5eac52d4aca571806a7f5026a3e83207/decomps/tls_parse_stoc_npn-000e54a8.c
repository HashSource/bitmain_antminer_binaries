
undefined4 tls_parse_stoc_npn(int param_1,undefined4 *param_2)

{
  void *__dest;
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  code *pcVar6;
  byte local_1d;
  void *local_1c [2];
  
  if ((*(int *)(*(int *)(param_1 + 0x7c) + 0x180) == 0) ||
     (uVar4 = 1, *(int *)(*(int *)(param_1 + 0x7c) + 0x204) == 0)) {
    pcVar6 = *(code **)(*(int *)(param_1 + 0x4d0) + 0x188);
    if (pcVar6 == (code *)0x0) {
      ossl_statem_fatal(param_1,0x6e,0x246,0x6e,"ssl/statem/extensions_clnt.c",0x634);
      uVar4 = 0;
    }
    else {
      pbVar1 = (byte *)*param_2;
      iVar3 = param_2[1];
      do {
        if (iVar3 == 0) {
          iVar3 = (*pcVar6)(param_1,local_1c,&local_1d,(byte *)*param_2,param_2[1],
                            *(undefined4 *)(*(int *)(param_1 + 0x4d0) + 0x18c));
          if (iVar3 != 0) {
            ossl_statem_fatal(param_1,0x28,0x246,0x6e,"ssl/statem/extensions_clnt.c",0x644);
            return 0;
          }
          CRYPTO_free(*(void **)(param_1 + 0x59c));
          __dest = CRYPTO_malloc((uint)local_1d,"ssl/statem/extensions_clnt.c",0x64d);
          *(void **)(param_1 + 0x59c) = __dest;
          if (__dest == (void *)0x0) {
            *(undefined4 *)(param_1 + 0x5a0) = 0;
            ossl_statem_fatal(param_1,0x50,0x246,0x44,"ssl/statem/extensions_clnt.c",0x651);
            return 0;
          }
          memcpy(__dest,local_1c[0],(uint)local_1d);
          *(uint *)(param_1 + 0x5a0) = (uint)local_1d;
          *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x33c) = 1;
          return 1;
        }
        uVar5 = iVar3 - 1;
        uVar2 = (uint)*pbVar1;
        pbVar1 = pbVar1 + uVar2 + 1;
        iVar3 = uVar5 - uVar2;
      } while ((uVar2 <= uVar5) && (uVar2 != 0));
      uVar4 = 0;
      ossl_statem_fatal(param_1,0x32,0x235,0x6e,"ssl/statem/extensions_clnt.c",0x61e);
    }
  }
  return uVar4;
}

