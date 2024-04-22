
int s2hex(int param_1,int param_2,int param_3)

{
  undefined uVar1;
  int iVar2;
  int local_14;
  
  if (((param_2 == 0) || (param_3 < 1)) || (param_1 == 0)) {
    printf("s2hex para error dst(%p), src(%p), inlen(%d)\n",param_1,param_2,param_3);
    iVar2 = -1;
  }
  else {
    for (local_14 = 0; local_14 < param_3 / 2; local_14 = local_14 + 1) {
      uVar1 = twoc2hex(*(undefined *)(param_2 + local_14 * 2),
                       *(undefined *)(param_2 + local_14 * 2 + 1));
      *(undefined *)(param_1 + local_14) = uVar1;
    }
    if (param_3 % 2 != 0) {
      uVar1 = twoc2hex(*(undefined *)(param_2 + local_14 * 2),0);
      *(undefined *)(param_1 + local_14) = uVar1;
    }
    iVar2 = param_3 / 2 + param_3 % 2;
  }
  return iVar2;
}

