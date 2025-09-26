
bool WPACKET_get_length(int param_1,int *param_2)

{
  bool bVar1;
  
  bVar1 = param_2 != (int *)0x0 && *(int *)(param_1 + 0x14) != 0;
  if (bVar1) {
    *param_2 = *(int *)(param_1 + 0xc) - *(int *)(*(int *)(param_1 + 0x14) + 0xc);
  }
  return bVar1;
}

