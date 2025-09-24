
void ssl3_write(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = __errno_location();
  iVar2 = *(int *)(param_1 + 0x7c);
  *piVar1 = 0;
  if (*(int *)(iVar2 + 0xf0) != 0) {
    ssl3_renegotiate_check(param_1);
  }
  (**(code **)(*(int *)(param_1 + 4) + 0x3c))(param_1,0x17,param_2,param_3,param_4);
  return;
}

