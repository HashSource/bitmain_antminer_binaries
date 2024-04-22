
undefined strbuffer_pop(int *param_1)

{
  undefined uVar1;
  int iVar2;
  
  if (param_1[1] != 0) {
    iVar2 = param_1[1] + -1;
    param_1[1] = iVar2;
    uVar1 = *(undefined *)(*param_1 + iVar2);
    *(undefined *)(*param_1 + iVar2) = 0;
    return uVar1;
  }
  return 0;
}

