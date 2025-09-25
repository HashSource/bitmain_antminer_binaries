
undefined4 tls_parse_ctos_supported_groups(int param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined1 *local_18;
  uint local_14;
  
  if (1 < (uint)param_2[1]) {
    puVar1 = (undefined1 *)*param_2;
    uVar2 = param_2[1] - 2;
    uVar3 = (uint)CONCAT11(*puVar1,puVar1[1]);
    if (uVar3 <= uVar2) {
      puVar1 = puVar1 + 2;
      if (uVar3 == uVar2) {
        *param_2 = puVar1 + uVar3;
        param_2[1] = 0;
        local_18 = puVar1;
        local_14 = uVar3;
        if ((uVar3 != 0) && (-1 < (int)(uVar3 << 0x1f))) {
          if ((*(int *)(param_1 + 0x8c) != 0) &&
             ((*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0 ||
              (iVar4 = **(int **)(param_1 + 4), iVar4 == 0x10000 || iVar4 < 0x304)))) {
            return 1;
          }
          CRYPTO_free(*(void **)(param_1 + 0x57c));
          *(undefined4 *)(param_1 + 0x57c) = 0;
          *(undefined4 *)(param_1 + 0x578) = 0;
          iVar4 = tls1_save_u16(&local_18,param_1 + 0x57c,param_1 + 0x578);
          if (iVar4 == 0) {
            ossl_statem_fatal(param_1,0x50,0x242,0x44,"ssl/statem/extensions_srvr.c",0x3d2);
            return 0;
          }
          return 1;
        }
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x242,0x6e,"ssl/statem/extensions_srvr.c",0x3c5);
  return 0;
}

