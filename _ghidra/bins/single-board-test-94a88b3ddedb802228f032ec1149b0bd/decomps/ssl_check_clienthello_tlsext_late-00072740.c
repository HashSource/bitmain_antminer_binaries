
undefined4 ssl_check_clienthello_tlsext_late(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((*(int *)(param_1 + 0x128) != -1) && (*(int *)(param_1 + 0xe4) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0xe4) + 0x13c) != 0)) {
    iVar1 = ssl_get_server_send_pkey();
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 300) = 0;
      return 1;
    }
    iVar2 = *(int *)(param_1 + 0xe4);
    **(int **)(param_1 + 0x98) = iVar1;
    iVar1 = (**(code **)(iVar2 + 0x13c))(param_1,*(undefined4 *)(iVar2 + 0x140));
    if (iVar1 == 2) {
      ssl3_send_alert(param_1,2,0x50);
      return 0xffffffff;
    }
    if (iVar1 != 3) {
      if (iVar1 != 0) {
        return 1;
      }
      iVar1 = *(int *)(param_1 + 0x138);
      if (iVar1 != 0) {
        *(undefined4 *)(param_1 + 300) = 1;
        return 1;
      }
      goto LAB_00072792;
    }
  }
  iVar1 = 0;
LAB_00072792:
  *(int *)(param_1 + 300) = iVar1;
  return 1;
}

