
undefined4 ossl_statem_server_pre_work(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 0x13:
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
      dtls1_clear_sent_buffer();
      return 2;
    }
    break;
  case 0x15:
    *(undefined4 *)(param_1 + 0x28) = 0;
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
      dtls1_clear_sent_buffer();
      *(undefined4 *)(param_1 + 0x5c) = 0;
      return 2;
    }
    break;
  case 0x16:
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) {
      *(undefined4 *)(param_1 + 0x5c) = 1;
      return 2;
    }
    break;
  case 0x21:
    if (*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) {
LAB_001015c4:
      *(undefined4 *)(param_1 + 0x5c) = 0;
      return 2;
    }
    iVar2 = **(int **)(param_1 + 4);
    iVar1 = iVar2 + -0x10000;
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    if (iVar2 < 0x304) {
      iVar1 = 0;
    }
    if (iVar1 == 0) {
      return 2;
    }
    if (*(int *)(param_1 + 0xf70) != 0) {
      return 2;
    }
    uVar3 = 0;
    goto LAB_001014fc;
  case 0x23:
    iVar1 = (*(int **)(param_1 + 4))[0x19];
    if ((*(int *)(iVar1 + 0x30) << 0x1c < 0) ||
       (iVar2 = **(int **)(param_1 + 4), iVar2 == 0x10000 || iVar2 < 0x304)) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x474) + 0x1b8);
      if (iVar2 == 0) {
        *(undefined4 *)(*(int *)(param_1 + 0x474) + 0x1b8) =
             *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x210);
      }
      else if (iVar2 != *(int *)(*(int *)(param_1 + 0x7c) + 0x210)) {
        ossl_statem_fatal(param_1,0x50,0x280,0x44,"ssl/statem/statem_srvr.c",0x2f0);
        return 0;
      }
      iVar1 = (**(code **)(iVar1 + 8))(param_1);
      if (iVar1 == 0) {
        return 0;
      }
      if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c < 0) goto LAB_001015c4;
    }
    break;
  case 0x2e:
    if ((*(int *)(param_1 + 0x68) != 9) && (-1 < **(int **)(param_1 + 0x7c) << 0x14)) {
      return 2;
    }
  case 1:
    uVar3 = 1;
LAB_001014fc:
    uVar3 = tls_finish_handshake(param_1,param_2,uVar3);
    return uVar3;
  }
  return 2;
}

