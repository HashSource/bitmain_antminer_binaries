
void get_intrange(char *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = sscanf(param_1,"%d-%d",param_2,param_3,param_4);
  if (iVar1 == 1) {
    *param_3 = *param_2;
  }
  return;
}

