
void json_integer_copy(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 == (int *)0x0) || (*param_1 != 3)) {
    iVar2 = 0;
    iVar3 = 0;
  }
  else {
    iVar2 = param_1[2];
    iVar3 = param_1[3];
  }
  puVar1 = (undefined4 *)jsonp_malloc(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = iVar2;
    puVar1[3] = iVar3;
    *puVar1 = 3;
    puVar1[1] = 1;
  }
  return;
}

