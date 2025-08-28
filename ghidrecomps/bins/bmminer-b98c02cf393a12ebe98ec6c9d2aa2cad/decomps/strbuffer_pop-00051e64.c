
undefined1 strbuffer_pop(int *param_1)

{
  undefined1 uVar1;
  int iVar2;
  
  if (param_1[1] != 0) {
    iVar2 = param_1[1] + -1;
    param_1[1] = iVar2;
    uVar1 = *(undefined1 *)(*param_1 + iVar2);
    *(undefined1 *)(*param_1 + iVar2) = 0;
    return uVar1;
  }
  return 0;
}

