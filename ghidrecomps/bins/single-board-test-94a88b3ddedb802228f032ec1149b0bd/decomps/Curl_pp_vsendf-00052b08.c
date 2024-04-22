
int Curl_pp_vsendf(int param_1,undefined4 param_2,undefined4 param_3)

{
  code **ppcVar1;
  int iVar2;
  char *__s;
  size_t sVar3;
  int *piVar4;
  undefined4 local_30;
  undefined4 uStack_2c;
  size_t local_24 [2];
  
  piVar4 = *(int **)(param_1 + 0x2c);
  iVar2 = curl_maprintf(DAT_00052bc0);
  ppcVar1 = DAT_00052bc4;
  if (iVar2 != 0) {
    __s = (char *)curl_mvaprintf(iVar2,param_3);
    (**ppcVar1)(iVar2);
    if (__s != (char *)0x0) {
      local_24[0] = 0;
      sVar3 = strlen(__s);
      Curl_pp_init(param_1);
      iVar2 = Curl_write(piVar4,piVar4[0x55],__s,sVar3,local_24);
      if (iVar2 != 0) {
        (**ppcVar1)(__s);
        return iVar2;
      }
      if (*(char *)(*piVar4 + 0x310) != '\0') {
        Curl_debug(*piVar4,2,__s,local_24[0],piVar4);
      }
      if (sVar3 != local_24[0]) {
        *(char **)(param_1 + 0x14) = __s;
        *(size_t *)(param_1 + 0x18) = sVar3 - local_24[0];
        *(size_t *)(param_1 + 0x1c) = sVar3;
        return 0;
      }
      (**ppcVar1)(__s);
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

