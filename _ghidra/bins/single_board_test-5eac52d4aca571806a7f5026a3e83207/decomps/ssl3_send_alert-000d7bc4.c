
undefined4 ssl3_send_alert(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = ((int *)param_1[1])[0x19];
  if ((((*(int *)(iVar2 + 0x30) << 0x1c < 0) ||
       (iVar3 = *(int *)param_1[1], iVar3 == 0x10000 || iVar3 < 0x304)) && (3 < param_1[0x1a] - 1U))
     && (param_1[0x113] != 1)) {
    iVar2 = (**(code **)(iVar2 + 0x28))(param_3);
  }
  else {
    iVar2 = tls13_alert_code(param_3);
  }
  if (*param_1 == 0x300 && iVar2 == 0x46) {
    uVar4 = 1;
    iVar2 = 0x28;
  }
  else {
    if (iVar2 < 0) {
      return 0xffffffff;
    }
    if (iVar2 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = 1;
    }
  }
  if ((param_1[10] & uVar4) == 0) {
    if ((param_2 == 2) && ((SSL_SESSION *)param_1[0x11d] != (SSL_SESSION *)0x0)) {
      SSL_CTX_remove_session((SSL_CTX *)param_1[0x178],(SSL_SESSION *)param_1[0x11d]);
    }
    iVar5 = param_1[0x1f];
    *(char *)(iVar5 + 0xec) = (char)param_2;
    iVar3 = param_1[0x1f];
    *(undefined4 *)(iVar5 + 0xe8) = 1;
    *(char *)(iVar3 + 0xed) = (char)iVar2;
    iVar2 = RECORD_LAYER_write_pending(param_1 + 0x194);
    if (iVar2 == 0) {
                    /* WARNING: Could not recover jumptable at 0x000d7c3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (**(code **)(param_1[1] + 0x40))(param_1);
      return uVar1;
    }
  }
  return 0xffffffff;
}

