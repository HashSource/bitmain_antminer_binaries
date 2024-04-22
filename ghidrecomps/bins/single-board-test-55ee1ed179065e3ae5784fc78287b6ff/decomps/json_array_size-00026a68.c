
int json_array_size(int *param_1)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 1)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1[3];
  }
  return iVar1;
}

