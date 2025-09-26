
int dtls1_handle_timeout(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = dtls1_is_timer_expired();
  if (iVar1 != 0) {
    iVar1 = *(int *)(param_1 + 0x80);
    if (*(code **)(iVar1 + 0x194) == (code *)0x0) {
      uVar3 = *(int *)(iVar1 + 0x18c) << 1;
      uVar4 = 60000000;
      if (uVar3 < 0x3938701) {
        uVar4 = uVar3;
      }
      *(uint *)(iVar1 + 0x18c) = uVar4;
    }
    else {
      uVar2 = (**(code **)(iVar1 + 0x194))(param_1,*(undefined4 *)(iVar1 + 0x18c));
      *(undefined4 *)(iVar1 + 0x18c) = uVar2;
    }
    iVar1 = dtls1_check_timeout_num(param_1);
    if (-1 < iVar1) {
      uVar4 = *(int *)(*(int *)(param_1 + 0x80) + 0x178) + 1;
      if (2 < uVar4) {
        uVar4 = 1;
      }
      *(uint *)(*(int *)(param_1 + 0x80) + 0x178) = uVar4;
      dtls1_start_timer(param_1);
      iVar1 = dtls1_retransmit_buffered_messages(param_1);
      return iVar1;
    }
    iVar1 = -1;
  }
  return iVar1;
}

