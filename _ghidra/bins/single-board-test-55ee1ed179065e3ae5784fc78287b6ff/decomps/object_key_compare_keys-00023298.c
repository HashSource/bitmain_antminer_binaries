
int object_key_compare_keys(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strcmp(*(char **)(param_1 + 4),*(char **)(param_2 + 4));
  return iVar1;
}

