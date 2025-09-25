
bool shake_ctrl(int param_1,int param_2,undefined4 param_3,int param_4)

{
  bool bVar1;
  
  bVar1 = param_2 == 3;
  if (bVar1) {
    param_4 = *(int *)(param_1 + 0xc);
  }
  if (bVar1) {
    *(undefined4 *)(param_4 + 0xcc) = param_3;
  }
  return bVar1;
}

