
int tls1_check_ec_tmp_key(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000) == 0) {
    iVar1 = tls1_shared_group(param_1,0);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    return iVar1;
  }
  if (param_2 != 0x300c02b) {
    if (param_2 != 0x300c02c) {
      return 0;
    }
    iVar1 = tls1_check_group_id(param_1,0x18,1,param_4);
    return iVar1;
  }
  iVar1 = tls1_check_group_id(param_1,0x17,1,param_4);
  return iVar1;
}

