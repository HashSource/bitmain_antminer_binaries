
int Curl_gethostname(char *param_1,size_t param_2)

{
  int iVar1;
  char *pcVar2;
  
  *param_1 = '\0';
  iVar1 = gethostname(param_1,param_2);
  param_1[param_2 - 1] = '\0';
  if ((iVar1 == 0) && (pcVar2 = strchr(param_1,0x2e), pcVar2 != (char *)0x0)) {
    *pcVar2 = '\0';
  }
  return iVar1;
}

