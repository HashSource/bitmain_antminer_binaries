
int Curl_http_auth_act(int *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar2 = *(int *)(iVar3 + 200);
  if (iVar2 - 100U < 100) {
    return 0;
  }
  if (*(char *)(iVar3 + 0x8640) != '\0') {
    if (*(char *)(iVar3 + 0x300) == '\0') {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x16;
    }
    return iVar2;
  }
  uVar1 = (uint)*(byte *)((int)param_1 + 0x1f1);
  if (uVar1 != 0) {
    if (iVar2 == 0x191) {
LAB_0004020a:
      uVar1 = pickoneauth(iVar3 + 0x8620);
      if (uVar1 == 0) {
        *(undefined1 *)(iVar3 + 0x8640) = 1;
      }
    }
    else {
      uVar1 = (uint)*(byte *)((int)param_1 + 0x1fb);
      if (uVar1 != 0) {
        if (iVar2 < 300) goto LAB_0004020a;
        uVar1 = 0;
      }
    }
  }
  if ((*(char *)((int)param_1 + 0x1f2) == '\0') ||
     ((*(int *)(iVar3 + 200) != 0x197 &&
      ((*(char *)((int)param_1 + 0x1fb) == '\0' || (299 < *(int *)(iVar3 + 200))))))) {
LAB_0004024c:
    if (uVar1 == 0) {
      if ((((*(int *)(iVar3 + 200) < 300) && (*(char *)(iVar3 + 0x862c) == '\0')) &&
          (*(char *)((int)param_1 + 0x1fb) != '\0')) &&
         ((*(uint *)(iVar3 + 0x278) & 0xfffffffb) != 1)) {
        iVar2 = (*Curl_cstrdup)(*(undefined4 *)(iVar3 + 0x450));
        *(int *)(iVar3 + 0x13c) = iVar2;
        if (iVar2 == 0) {
          return 0x1b;
        }
        *(undefined1 *)(iVar3 + 0x862c) = 1;
      }
      goto LAB_00040288;
    }
  }
  else {
    iVar2 = pickoneauth(iVar3 + 0x8630);
    if (iVar2 == 0) {
      *(undefined1 *)(iVar3 + 0x8640) = 1;
      goto LAB_0004024c;
    }
  }
  (*Curl_cfree)(*(undefined4 *)(iVar3 + 0x13c));
  *(undefined4 *)(iVar3 + 0x13c) = 0;
  iVar2 = (*Curl_cstrdup)(*(undefined4 *)(iVar3 + 0x450));
  *(int *)(iVar3 + 0x13c) = iVar2;
  if (iVar2 == 0) {
    return 0x1b;
  }
  if ((((*(uint *)(iVar3 + 0x278) & 0xfffffffb) != 1) && ((char)param_1[0x7f] == '\0')) &&
     (iVar2 = http_perhapsrewind(param_1), iVar2 != 0)) {
    return iVar2;
  }
LAB_00040288:
  iVar2 = http_should_fail(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  Curl_failf(iVar3,"The requested URL returned error: %d",*(undefined4 *)(iVar3 + 200));
  return 0x16;
}

