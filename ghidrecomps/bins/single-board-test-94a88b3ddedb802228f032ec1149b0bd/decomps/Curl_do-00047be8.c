
int Curl_do(int **param_1,char *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = *param_1;
  iVar3 = *piVar2;
  if (*(code **)(piVar2[0x86] + 8) != (code *)0x0) {
    iVar1 = (**(code **)(piVar2[0x86] + 8))(piVar2);
    if (iVar1 == 0x37) {
      if (*(char *)((int)piVar2 + 0x1ee) == '\0') {
        return 0x37;
      }
      if (*(int *)(iVar3 + 0x40) != 0) {
        return 0x37;
      }
      iVar3 = Curl_reconnect_request(param_1);
      if (iVar3 != 0) {
        return iVar3;
      }
      piVar2 = *param_1;
      iVar1 = (**(code **)(piVar2[0x86] + 8))(piVar2,param_2);
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*param_2 != '\0') {
      do_complete(piVar2);
      return 0;
    }
  }
  return 0;
}

