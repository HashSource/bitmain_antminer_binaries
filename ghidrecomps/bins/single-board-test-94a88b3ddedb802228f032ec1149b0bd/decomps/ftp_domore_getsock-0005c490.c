
uint ftp_domore_getsock(int *param_1,int *param_2,uint param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  if (param_3 != 0) {
    if (param_1[0x10a] != 0) {
      uVar2 = Curl_pp_getsock(param_1 + 0xf0);
      return uVar2;
    }
    cVar1 = *(char *)(*param_1 + 0x2fe);
    *param_2 = param_1[0x55];
    if (cVar1 == '\0') {
      iVar3 = param_1[0x57];
      uVar2 = 0;
      if (iVar3 != -1) {
        param_2[1] = iVar3;
        uVar2 = 2;
      }
      if (iVar3 != -1) {
        param_3 = uVar2 << 0x10 | 1;
      }
      else {
        param_3 = 1;
        uVar2 = param_3;
      }
      if (param_1[0x58] != -1) {
        param_2[uVar2] = param_1[0x58];
        param_3 = param_3 | 1 << uVar2 + 0x10;
      }
    }
    else {
      param_3 = 0x20001;
      param_2[1] = param_1[0x56];
    }
  }
  return param_3;
}

