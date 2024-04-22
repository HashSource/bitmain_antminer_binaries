
undefined strbuffer_pop(int *param_1)

{
  undefined uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = 0;
  }
  else {
    param_1[1] = param_1[1] + -1;
    uVar1 = *(undefined *)(*param_1 + param_1[1]);
    *(undefined *)(*param_1 + param_1[1]) = 0;
  }
  return uVar1;
}

