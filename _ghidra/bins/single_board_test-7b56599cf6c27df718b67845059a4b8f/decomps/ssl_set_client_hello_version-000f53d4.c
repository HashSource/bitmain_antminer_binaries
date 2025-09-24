
int ssl_set_client_hello_version(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 auStack_18 [4];
  int local_14 [2];
  
  if ((*(int *)(param_1[0x1f] + 0x180) != 0) && (*(int *)(param_1[0x1f] + 0x204) != 0)) {
    return 0;
  }
  iVar1 = ssl_get_min_max_version(param_1,auStack_18,local_14,0);
  if (iVar1 == 0) {
    iVar2 = *(int *)(param_1[1] + 100);
    *param_1 = local_14[0];
    if (((uint)(0x303 < local_14[0]) & (*(uint *)(iVar2 + 0x30) ^ 8) >> 3) != 0) {
      local_14[0] = 0x303;
    }
    param_1[0x141] = local_14[0];
  }
  return iVar1;
}

