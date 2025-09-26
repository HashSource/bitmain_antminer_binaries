
int ssl3_read(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = __errno_location();
  iVar3 = *(int *)(param_1 + 0x7c);
  *piVar1 = 0;
  if (*(int *)(iVar3 + 0xf0) != 0) {
    ssl3_renegotiate_check(param_1);
    iVar3 = *(int *)(param_1 + 0x7c);
  }
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar3 + 0xfc) = 1;
  iVar3 = (**(code **)(iVar2 + 0x38))(param_1,0x17,0,param_2,param_3,0,param_4);
  if ((iVar3 == -1) && (*(int *)(*(int *)(param_1 + 0x7c) + 0xfc) == 2)) {
    ossl_statem_set_in_handshake(param_1,1);
    iVar3 = (**(code **)(*(int *)(param_1 + 4) + 0x38))(param_1,0x17,0,param_2,param_3,0,param_4);
    ossl_statem_set_in_handshake(param_1,0);
  }
  else {
    *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0xfc) = 0;
  }
  return iVar3;
}

