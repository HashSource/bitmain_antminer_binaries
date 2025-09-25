
undefined4 tls_process_cke_psk_preamble(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  undefined1 auStack_118 [256];
  
  if (1 < (uint)param_2[1]) {
    puVar3 = (undefined1 *)*param_2;
    uVar4 = param_2[1] - 2;
    uVar5 = (uint)CONCAT11(*puVar3,puVar3[1]);
    if (uVar5 <= uVar4) {
      *param_2 = puVar3 + 2 + uVar5;
      param_2[1] = uVar4 - uVar5;
      if (0x80 < uVar5) {
        ossl_statem_fatal(param_1,0x32,0x19e,0x92,"ssl/statem/statem_srvr.c",0xb7f);
        return 0;
      }
      if (*(int *)(param_1 + 0x4c4) == 0) {
        ossl_statem_fatal(param_1,0x50,0x19e,0xe1,"ssl/statem/statem_srvr.c",0xb84);
        return 0;
      }
      iVar6 = *(int *)(param_1 + 0x474);
      CRYPTO_free(*(void **)(iVar6 + 0x194));
      iVar1 = CRYPTO_strndup(puVar3 + 2,uVar5,"ssl/statem/../packet_local.h",0x1e5);
      *(int *)(iVar6 + 0x194) = iVar1;
      if (iVar1 == 0) {
        ossl_statem_fatal(param_1,0x50,0x19e,0x44,"ssl/statem/statem_srvr.c",0xb8a);
        return 0;
      }
      uVar4 = (**(code **)(param_1 + 0x4c4))
                        (param_1,*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x194),auStack_118,
                         0x100);
      if (uVar4 < 0x101) {
        if (uVar4 == 0) {
          ossl_statem_fatal(param_1,0x73,0x19e,0xdf,"ssl/statem/statem_srvr.c",0xb9b);
          return 0;
        }
        CRYPTO_free(*(void **)(*(int *)(param_1 + 0x7c) + 600));
        iVar1 = *(int *)(param_1 + 0x7c);
        uVar2 = CRYPTO_memdup(auStack_118,uVar4,"ssl/statem/statem_srvr.c",0xba0);
        *(undefined4 *)(iVar1 + 600) = uVar2;
        OPENSSL_cleanse(auStack_118,uVar4);
        iVar1 = *(int *)(param_1 + 0x7c);
        if (*(int *)(iVar1 + 600) == 0) {
          *(undefined4 *)(iVar1 + 0x25c) = 0;
          ossl_statem_fatal(param_1,0x50,0x19e,0x41,"ssl/statem/statem_srvr.c",0xba6);
          return 0;
        }
        *(uint *)(iVar1 + 0x25c) = uVar4;
        return 1;
      }
      ossl_statem_fatal(param_1,0x50,0x19e,0x44,"ssl/statem/statem_srvr.c",0xb93);
      return 0;
    }
  }
  ossl_statem_fatal(param_1,0x32,0x19e,0x9f,"ssl/statem/statem_srvr.c",0xb7a);
  return 0;
}

