
int Curl_getconnectinfo(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined uStack_19;
  int local_18;
  char local_14;
  
  iVar2 = *(int *)(param_1 + 0x590);
  if ((iVar2 != 0) &&
     ((iVar1 = *(int *)(param_1 + 0x44), iVar1 != 0 ||
      (iVar1 = *(int *)(param_1 + 0x40), iVar1 != 0)))) {
    local_14 = '\0';
    local_18 = iVar2;
    Curl_conncache_foreach(iVar1 + 0x68,&local_18,DAT_00039050);
    if (local_14 == '\0') {
      *(undefined4 *)(param_1 + 0x590) = 0;
    }
    else {
      if (param_2 != (int *)0x0) {
        *param_2 = iVar2;
      }
      iVar1 = *(int *)(iVar2 + 0x154);
      if (*(char *)(iVar2 + 0x178) == '\0') {
        if (iVar1 == -1) {
          return -1;
        }
        iVar2 = recv(iVar1,&uStack_19,1,2);
      }
      else {
        iVar2 = Curl_ssl_check_cxn(iVar2);
      }
      if (iVar2 != 0) {
        return iVar1;
      }
    }
  }
  return -1;
}

