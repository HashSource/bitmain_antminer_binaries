
undefined8 json_integer_value(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 3)) {
    iVar1 = 0;
    iVar2 = 0;
  }
  else {
    iVar1 = param_1[2];
    iVar2 = param_1[3];
  }
  return CONCAT44(iVar2,iVar1);
}

