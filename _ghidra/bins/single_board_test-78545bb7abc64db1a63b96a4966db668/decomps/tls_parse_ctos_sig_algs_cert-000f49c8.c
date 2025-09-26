
undefined4 tls_parse_ctos_sig_algs_cert(int param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  undefined1 *local_18;
  uint local_14;
  
  if (1 < (uint)param_2[1]) {
    puVar4 = (undefined1 *)*param_2;
    uVar2 = param_2[1] - 2;
    uVar3 = (uint)CONCAT11(*puVar4,puVar4[1]);
    if (uVar3 <= uVar2) {
      puVar4 = puVar4 + 2;
      if (uVar3 == uVar2) {
        *param_2 = puVar4 + uVar3;
        param_2[1] = 0;
        local_18 = puVar4;
        local_14 = uVar3;
        if (uVar3 != 0) {
          if ((*(int *)(param_1 + 0x8c) == 0) &&
             (iVar1 = tls1_save_sigalgs(param_1,&local_18,1), iVar1 == 0)) {
            ossl_statem_fatal(param_1,0x32,0x267,0x6e,"ssl/statem/extensions_srvr.c",0x12f);
            return 0;
          }
          return 1;
        }
      }
    }
  }
  ossl_statem_fatal(param_1,0x32,0x267,0x6e,"ssl/statem/extensions_srvr.c",0x129);
  return 0;
}

