
void getPICChainIndexOffset(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_1 - 1U < 0xd) {
    iVar1 = (param_1 - 1U) * 4;
    uVar2 = *(undefined4 *)(CSWTCH_722 + iVar1);
    uVar3 = *(undefined4 *)(CSWTCH_723 + iVar1);
  }
  else {
    uVar3 = 0;
    uVar2 = uVar3;
  }
  *param_2 = uVar2;
  *param_3 = uVar3;
  return;
}

