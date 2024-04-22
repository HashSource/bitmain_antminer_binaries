
int * hashtable_find_pair(undefined4 param_1,int *param_2,char *param_3,int param_4)

{
  int iVar1;
  int local_c;
  
  iVar1 = bucket_is_empty(param_1,param_2);
  if (iVar1 == 0) {
    local_c = *param_2;
    while( true ) {
      if ((*(int *)(local_c + -4) == param_4) &&
         (iVar1 = strcmp((char *)(local_c + 0x10),param_3), iVar1 == 0)) {
        return (int *)(local_c + -4);
      }
      if (param_2[1] == local_c) break;
      local_c = *(int *)(local_c + 4);
    }
  }
  return (int *)0x0;
}

