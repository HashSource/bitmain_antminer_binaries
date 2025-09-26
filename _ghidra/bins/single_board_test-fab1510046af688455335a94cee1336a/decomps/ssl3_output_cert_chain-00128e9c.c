
int ssl3_output_cert_chain(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_1c [2];
  
  local_1c[0] = *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c) + 3;
  iVar1 = ssl_add_cert_chain(param_1,param_2,local_1c);
  if (iVar1 != 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x3c) + 4);
    iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c);
    local_1c[0] = (local_1c[0] + -3) - iVar2;
    iVar1 = iVar3 + iVar2;
    *(char *)(iVar3 + iVar2) = (char)((uint)local_1c[0] >> 0x10);
    *(char *)(iVar1 + 1) = (char)((uint)local_1c[0] >> 8);
    *(char *)(iVar1 + 2) = (char)local_1c[0];
    local_1c[0] = local_1c[0] + 3;
    (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x40))(param_1,0xb);
    iVar1 = local_1c[0] + *(int *)(*(int *)(*(int *)(param_1 + 8) + 100) + 0x3c);
  }
  return iVar1;
}

