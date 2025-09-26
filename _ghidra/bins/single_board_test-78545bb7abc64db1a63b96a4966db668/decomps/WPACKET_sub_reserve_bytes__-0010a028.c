
int WPACKET_sub_reserve_bytes__(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  
  iVar1 = WPACKET_reserve_bytes(param_1,param_2 + param_4,param_3,param_4,param_4);
  if (iVar1 != 0) {
    iVar1 = 1;
    *param_3 = param_4 + *param_3;
  }
  return iVar1;
}

