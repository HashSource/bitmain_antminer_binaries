
int WPACKET_allocate_bytes(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = WPACKET_reserve_bytes();
  if (iVar1 != 0) {
    iVar1 = 1;
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + param_2;
    *(int *)(param_1 + 8) = param_2 + *(int *)(param_1 + 8);
  }
  return iVar1;
}

