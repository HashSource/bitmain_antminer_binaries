
uint tls_process_initial_server_flight(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = ssl3_check_cert_and_algorithm();
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x53c) != -1) {
    pcVar2 = *(code **)(*(int *)(param_1 + 0x4d0) + 0x150);
    if (pcVar2 != (code *)0x0) {
      iVar1 = (*pcVar2)(param_1,*(undefined4 *)(*(int *)(param_1 + 0x4d0) + 0x154));
      if (iVar1 == 0) {
        ossl_statem_fatal(param_1,0x71,0x1ba,0x148,"ssl/statem/statem_clnt.c",0xb14);
        return 0;
      }
      if (iVar1 < 0) {
        ossl_statem_fatal(param_1,0x50,0x1ba,0x126,"ssl/statem/statem_clnt.c",0xb1a);
        return 0;
      }
    }
  }
  if ((*(int *)(param_1 + 0x5d0) != 0) && (iVar1 = ssl_validate_ct(param_1), iVar1 == 0)) {
    return *(uint *)(param_1 + 0x4ac) & 1 ^ 1;
  }
  return 1;
}

