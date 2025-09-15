
int Curl_pp_vsendf(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char *__s;
  size_t sVar2;
  int *piVar3;
  undefined4 local_30;
  undefined4 uStack_2c;
  size_t local_24 [2];
  
  piVar3 = *(int **)(param_1 + 0x2c);
  iVar1 = curl_maprintf("%s\r\n");
  if (iVar1 != 0) {
    __s = (char *)curl_mvaprintf(iVar1,param_3);
    (*Curl_cfree)(iVar1);
    if (__s != (char *)0x0) {
      local_24[0] = 0;
      sVar2 = strlen(__s);
      Curl_pp_init(param_1);
      iVar1 = Curl_write(piVar3,piVar3[0x55],__s,sVar2,local_24);
      if (iVar1 != 0) {
        (*Curl_cfree)(__s);
        return iVar1;
      }
      if (*(char *)(*piVar3 + 0x310) != '\0') {
        Curl_debug(*piVar3,2,__s,local_24[0],piVar3);
      }
      if (sVar2 != local_24[0]) {
        *(char **)(param_1 + 0x14) = __s;
        *(size_t *)(param_1 + 0x18) = sVar2 - local_24[0];
        *(size_t *)(param_1 + 0x1c) = sVar2;
        return 0;
      }
      (*Curl_cfree)(__s);
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      *(undefined4 *)(param_1 + 0x18) = 0;
      curlx_tvnow(&local_30);
      *(undefined4 *)(param_1 + 0x20) = local_30;
      *(undefined4 *)(param_1 + 0x24) = uStack_2c;
      return 0;
    }
  }
  return 0x1b;
}

