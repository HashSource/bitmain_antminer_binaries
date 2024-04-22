
undefined4 ssl3_send_alert(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined uVar4;
  
  iVar1 = (**(code **)(*(int *)(param_1[2] + 100) + 0x30))(param_3);
  if ((*param_1 == 0x300) && (iVar1 == 0x46)) {
    uVar4 = 0x28;
  }
  else {
    if (iVar1 < 0) {
      return 0xffffffff;
    }
    uVar4 = (undefined)iVar1;
  }
  if ((param_2 == 2) && ((SSL_SESSION *)param_1[0x30] != (SSL_SESSION *)0x0)) {
    SSL_CTX_remove_session((SSL_CTX *)param_1[0x39],(SSL_SESSION *)param_1[0x30]);
  }
  iVar3 = param_1[0x16];
  *(char *)(iVar3 + 400) = (char)param_2;
  iVar1 = param_1[0x16];
  *(undefined4 *)(iVar3 + 0x18c) = 1;
  *(undefined *)(iVar1 + 0x191) = uVar4;
  if (*(int *)(param_1[0x16] + 0x108) != 0) {
    return 0xffffffff;
  }
  uVar2 = (**(code **)(param_1[2] + 0x3c))(param_1);
  return uVar2;
}

