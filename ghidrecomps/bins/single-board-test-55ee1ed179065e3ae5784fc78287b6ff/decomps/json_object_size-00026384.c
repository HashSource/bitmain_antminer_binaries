
int json_object_size(int *param_1)

{
  int iVar1;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = param_1[2];
  }
  return iVar1;
}

