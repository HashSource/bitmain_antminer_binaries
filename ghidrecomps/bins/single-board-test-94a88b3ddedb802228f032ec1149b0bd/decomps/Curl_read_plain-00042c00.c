
undefined4 Curl_read_plain(int param_1,void *param_2,size_t param_3,ssize_t *param_4)

{
  ssize_t sVar1;
  int *piVar2;
  undefined4 uVar3;
  
  sVar1 = recv(param_1,param_2,param_3,0);
  if (sVar1 == -1) {
    piVar2 = __errno_location();
    if (*piVar2 == 0xb || *piVar2 == 4) {
      uVar3 = 0x51;
    }
    else {
      uVar3 = 0x38;
    }
    return uVar3;
  }
  *param_4 = sVar1;
  return 0;
}

