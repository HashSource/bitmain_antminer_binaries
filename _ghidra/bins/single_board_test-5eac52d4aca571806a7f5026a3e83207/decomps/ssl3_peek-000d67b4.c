
int ssl3_peek(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = __errno_location();
  iVar2 = *(int *)(param_1 + 0x7c);
  *piVar1 = 0;
  if (*(int *)(iVar2 + 0xf0) != 0) {
    ssl3_renegotiate_check(param_1);
    iVar2 = *(int *)(param_1 + 0x7c);
  }
  iVar3 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar2 + 0xfc) = 1;
  iVar2 = (**(code **)(iVar3 + 0x38))(param_1,0x17,0,param_2,param_3,1,param_4);
  if ((iVar2 == -1) && (*(int *)(*(int *)(param_1 + 0x7c) + 0xfc) == 2)) {
    ossl_statem_set_in_handshake(param_1,1);
    iVar2 = (**(code **)(*(int *)(param_1 + 4) + 0x38))(param_1,0x17,0,param_2,param_3,1,param_4);
    ossl_statem_set_in_handshake(param_1,0);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0xfc) = 0;
  }
  return iVar2;
}

