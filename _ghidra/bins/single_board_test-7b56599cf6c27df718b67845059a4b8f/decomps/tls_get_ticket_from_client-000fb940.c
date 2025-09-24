
undefined4 tls_get_ticket_from_client(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *param_3 = 0;
  param_1[0x157] = 0;
  if (((iVar2 < 0x301) || (iVar2 = tls_use_ticket(), iVar2 == 0)) ||
     (iVar2 = *(int *)(param_2 + 0x268), *(int *)(iVar2 + 0x98) == 0)) {
    uVar1 = 2;
  }
  else {
    uVar1 = tls_decrypt_ticket(param_1,*(undefined4 *)(iVar2 + 0x90),*(undefined4 *)(iVar2 + 0x94),
                               param_2 + 0x2c,*(undefined4 *)(param_2 + 0x28),param_3);
  }
  return uVar1;
}

