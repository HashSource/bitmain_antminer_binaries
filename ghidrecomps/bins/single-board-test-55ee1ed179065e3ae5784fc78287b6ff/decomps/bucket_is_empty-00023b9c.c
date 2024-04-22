
undefined4 bucket_is_empty(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((*param_2 == param_1 + 0xc) && (*param_2 == param_2[1])) {
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

