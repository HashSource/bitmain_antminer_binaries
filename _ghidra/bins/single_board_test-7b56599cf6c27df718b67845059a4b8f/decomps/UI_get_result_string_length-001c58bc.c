
int UI_get_result_string_length(int *param_1)

{
  int iVar1;
  
  if (*param_1 - 1U < 2) {
    iVar1 = param_1[4];
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

