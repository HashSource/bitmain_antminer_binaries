
undefined4 hashtable_iter_next(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 4) == param_1 + 0xc) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(param_2 + 4);
  }
  return uVar1;
}

