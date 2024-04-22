
undefined4 Curl_pipeline_server_blacklisted(int param_1,int param_2)

{
  int *piVar1;
  size_t sVar2;
  int iVar3;
  char **ppcVar4;
  char *__s;
  
  if (((*(int *)(param_1 + 0x40) != 0) && (param_2 != 0)) &&
     (piVar1 = (int *)Curl_multi_pipelining_server_bl(), piVar1 != (int *)0x0)) {
    for (ppcVar4 = (char **)*piVar1; ppcVar4 != (char **)0x0; ppcVar4 = (char **)ppcVar4[2]) {
      __s = *ppcVar4;
      sVar2 = strlen(__s);
      iVar3 = Curl_raw_nequal(__s,param_2,sVar2);
      if (iVar3 != 0) {
        Curl_infof(param_1,DAT_0003c5f0,param_2);
        return 1;
      }
    }
  }
  return 0;
}

