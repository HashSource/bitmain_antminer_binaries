
undefined4
tls_parse_stoc_status_request(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_3 == 0x4000) {
    return 1;
  }
  if (*(int *)(param_1 + 0x53c) == 1) {
    if ((*(uint *)((*(int **)(param_1 + 4))[0x19] + 0x30) & 8) == 0) {
      iVar1 = **(int **)(param_1 + 4);
      if ((0x303 < iVar1 && iVar1 != 0x10000) || (*(int *)(param_2 + 4) == 0)) {
        if (iVar1 != 0x10000 && 0x303 < iVar1) {
          if (param_5 != 0) {
            return 1;
          }
          uVar2 = tls_process_cert_status_body(param_1);
          return uVar2;
        }
LAB_000e5348:
        *(undefined4 *)(param_1 + 0x548) = 1;
        return 1;
      }
    }
    else if (*(int *)(param_2 + 4) == 0) goto LAB_000e5348;
    ossl_statem_fatal(param_1,0x32,0x249,0x6e,"ssl/statem/extensions_clnt.c",0x5b6);
  }
  else {
    ossl_statem_fatal(param_1,0x6e,0x249,0x6e,"ssl/statem/extensions_clnt.c",0x5b1);
  }
  return 0;
}

