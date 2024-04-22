
void Curl_http_output_auth(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_1 + 0x7c);
  iVar3 = *param_1;
  if (((cVar1 == '\0') || (*(char *)((int)param_1 + 0x1f2) == '\0')) &&
     (*(char *)((int)param_1 + 0x1f1) == '\0')) {
    *(undefined *)(iVar3 + 0x862c) = 1;
    *(undefined *)(iVar3 + 0x863c) = 1;
  }
  else {
    if ((*(int *)(iVar3 + 0x8620) != 0) && (*(int *)(iVar3 + 0x8624) == 0)) {
      *(int *)(iVar3 + 0x8624) = *(int *)(iVar3 + 0x8620);
    }
    if ((*(int *)(iVar3 + 0x8630) != 0) && (*(int *)(iVar3 + 0x8634) == 0)) {
      *(int *)(iVar3 + 0x8634) = *(int *)(iVar3 + 0x8630);
    }
    if ((cVar1 == '\0') || (*(byte *)((int)param_1 + 0x1fa) != param_4)) {
      *(undefined *)(iVar3 + 0x863c) = 1;
    }
    else {
      iVar2 = output_auth_headers(param_1,iVar3 + 0x8630,param_2,param_3,1);
      if (iVar2 != 0) {
        return;
      }
    }
    if ((((*(char *)(iVar3 + 0x85a8) == '\0') || (*(char *)((int)param_1 + 0x1ff) != '\0')) ||
        (*(int *)(iVar3 + 0x85ac) == 0)) ||
       ((*(char *)(iVar3 + 0x303) != '\0' ||
        (iVar2 = Curl_raw_equal(*(int *)(iVar3 + 0x85ac),param_1[0x26]), iVar2 != 0)))) {
      output_auth_headers(param_1,iVar3 + 0x8620,param_2,param_3,0);
    }
    else {
      *(undefined *)(iVar3 + 0x862c) = 1;
    }
  }
  return;
}

