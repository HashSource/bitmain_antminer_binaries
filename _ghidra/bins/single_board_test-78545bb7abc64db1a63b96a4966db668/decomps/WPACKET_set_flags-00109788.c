
int WPACKET_set_flags(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x10) = param_2;
    iVar1 = 1;
  }
  return iVar1;
}

