
void Curl_verboseconnect(int *param_1)

{
  int iVar1;
  
  if (*(char *)(*param_1 + 0x310) != '\0') {
    if (*(char *)((int)param_1 + 0x1ef) == '\0') {
      iVar1 = param_1[0x27];
    }
    else {
      iVar1 = param_1[0x2b];
    }
    Curl_infof(*param_1,DAT_000457f0,iVar1,param_1 + 0x16,param_1[0x2c],param_1[0x11]);
  }
  return;
}

