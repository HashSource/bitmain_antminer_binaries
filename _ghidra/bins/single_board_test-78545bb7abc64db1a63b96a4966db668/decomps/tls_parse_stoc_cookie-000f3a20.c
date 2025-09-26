
undefined4 tls_parse_stoc_cookie(int param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if (1 < (uint)param_2[1]) {
    puVar1 = (undefined1 *)*param_2;
    uVar3 = param_2[1] - 2;
    uVar4 = (uint)CONCAT11(*puVar1,puVar1[1]);
    if (uVar4 <= uVar3) {
      if (uVar4 == uVar3) {
        *param_2 = puVar1 + 2 + uVar4;
        param_2[1] = 0;
        CRYPTO_free(*(void **)(param_1 + 0x5b4));
        *(undefined4 *)(param_1 + 0x5b4) = 0;
        *(undefined4 *)(param_1 + 0x5b8) = 0;
        if (uVar4 != 0) {
          iVar2 = CRYPTO_memdup(puVar1 + 2,uVar4,"ssl/statem/../packet_local.h",0x1ce);
          *(int *)(param_1 + 0x5b4) = iVar2;
          if (iVar2 == 0) goto LAB_000f3a74;
          *(uint *)(param_1 + 0x5b8) = uVar4;
        }
        return 1;
      }
    }
  }
LAB_000f3a74:
  ossl_statem_fatal(param_1,0x32,0x216,0x9f,"ssl/statem/extensions_clnt.c",0x781);
  return 0;
}

