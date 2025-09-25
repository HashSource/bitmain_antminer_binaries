
int ssl_session_cmp(int *param_1,int *param_2)

{
  int iVar1;
  
  if ((*param_1 == *param_2) && (param_1[0x52] == param_2[0x52])) {
    iVar1 = memcmp(param_1 + 0x53,param_2 + 0x53,param_1[0x52]);
    return iVar1;
  }
  return 1;
}

