
undefined4 ser_number(undefined *param_1,int param_2)

{
  undefined4 uVar1;
  undefined uVar2;
  
  if (param_2 < 0x80) {
    uVar2 = 1;
    uVar1 = 2;
  }
  else if (param_2 < 0x4080) {
    uVar2 = 2;
    uVar1 = 3;
  }
  else if (param_2 < 0x204080) {
    uVar2 = 3;
    uVar1 = 4;
  }
  else {
    uVar2 = 4;
    uVar1 = 5;
  }
  *(int *)(param_1 + 1) = param_2;
  *param_1 = uVar2;
  return uVar1;
}

