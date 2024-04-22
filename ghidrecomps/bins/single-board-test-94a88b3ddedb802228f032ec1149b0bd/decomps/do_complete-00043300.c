
void do_complete(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = param_1[0x8a];
  if (param_1[0x8a] <= param_1[0x89]) {
    iVar2 = param_1[0x89];
  }
  *(undefined *)(iVar1 + 0x148) = 0;
  *(int *)(iVar1 + 300) = iVar2 + 1;
  Curl_pgrsTime(iVar1,6);
  return;
}

