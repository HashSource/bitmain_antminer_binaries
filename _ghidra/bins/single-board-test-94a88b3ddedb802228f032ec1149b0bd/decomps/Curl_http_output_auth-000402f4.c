
void Curl_http_output_auth(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x7c];
  iVar2 = *param_1;
  if ((((char)iVar1 == '\0') || (*(char *)((int)param_1 + 0x1f2) == '\0')) &&
     (*(char *)((int)param_1 + 0x1f1) == '\0')) {
    *(undefined1 *)(iVar2 + 0x862c) = 1;
    *(undefined1 *)(iVar2 + 0x863c) = 1;
  }
  else {
    if ((*(int *)(iVar2 + 0x8620) != 0) && (*(int *)(iVar2 + 0x8624) == 0)) {
      *(int *)(iVar2 + 0x8624) = *(int *)(iVar2 + 0x8620);
    }
    if ((*(int *)(iVar2 + 0x8630) != 0) && (*(int *)(iVar2 + 0x8634) == 0)) {
      *(int *)(iVar2 + 0x8634) = *(int *)(iVar2 + 0x8630);
    }
    if (((char)iVar1 == '\0') || (*(byte *)((int)param_1 + 0x1fa) != param_4)) {
      *(undefined1 *)(iVar2 + 0x863c) = 1;
    }
    else {
      iVar1 = output_auth_headers(param_1,iVar2 + 0x8630,param_2,param_3,1);
      if (iVar1 != 0) {
        return;
      }
    }
    if ((((*(char *)(iVar2 + 0x85a8) == '\0') || (*(char *)((int)param_1 + 0x1ff) != '\0')) ||
        (*(int *)(iVar2 + 0x85ac) == 0)) ||
       ((*(char *)(iVar2 + 0x303) != '\0' ||
        (iVar1 = Curl_raw_equal(*(int *)(iVar2 + 0x85ac),param_1[0x26]), iVar1 != 0)))) {
      output_auth_headers(param_1,iVar2 + 0x8620,param_2,param_3,0);
    }
    else {
      *(undefined1 *)(iVar2 + 0x862c) = 1;
    }
  }
  return;
}

