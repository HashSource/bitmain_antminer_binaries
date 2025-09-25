
int WPACKET_memset(undefined4 param_1,int param_2,size_t param_3)

{
  int iVar1;
  void *local_14 [2];
  
  if (param_3 == 0) {
    return 1;
  }
  iVar1 = WPACKET_allocate_bytes(param_1,param_3,local_14);
  if (iVar1 != 0) {
    memset(local_14[0],param_2,param_3);
    iVar1 = 1;
  }
  return iVar1;
}

