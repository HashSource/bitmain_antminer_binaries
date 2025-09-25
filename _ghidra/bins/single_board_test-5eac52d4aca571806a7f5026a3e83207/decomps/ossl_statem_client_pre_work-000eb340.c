
undefined4 ossl_statem_client_pre_work(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 1:
    uVar1 = tls_finish_handshake(param_1,param_2,1);
    return uVar1;
  case 0xc:
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
      iVar2 = ssl3_init_finished_mac();
      uVar1 = 2;
      if (iVar2 == 0) {
        uVar1 = 0;
      }
      return uVar1;
    }
    break;
  case 0x10:
    if ((*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) &&
       (*(int *)(param_1 + 0x8c) != 0)) {
      *(undefined4 *)(param_1 + 0x5c) = 0;
      return 2;
    }
    break;
  case 0x2e:
switchD_000eb348_caseD_2e:
    uVar1 = tls_finish_handshake(param_1,param_2,0,1);
    return uVar1;
  case 0x2f:
    if (*(int *)(param_1 + 0x68) != 0 && *(int *)(param_1 + 0x68) != 7)
    goto switchD_000eb348_caseD_2e;
  }
  return 2;
}

