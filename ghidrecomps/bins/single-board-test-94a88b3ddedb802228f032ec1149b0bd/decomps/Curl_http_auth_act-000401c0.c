
int Curl_http_auth_act(int *param_1)

{
  code **ppcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  iVar3 = *(int *)(iVar4 + 200);
  if (iVar3 - 100U < 100) {
    return 0;
  }
  if (*(char *)(iVar4 + 0x8640) != '\0') {
    if (*(char *)(iVar4 + 0x300) == '\0') {
      iVar3 = 0;
    }
    else {
      iVar3 = 0x16;
    }
    return iVar3;
  }
  uVar2 = (uint)*(byte *)((int)param_1 + 0x1f1);
  if (uVar2 != 0) {
    if (iVar3 == 0x191) {
LAB_0004020a:
      uVar2 = pickoneauth(iVar4 + 0x8620);
      if (uVar2 == 0) {
        *(undefined *)(iVar4 + 0x8640) = 1;
      }
    }
    else {
      uVar2 = (uint)*(byte *)((int)param_1 + 0x1fb);
      if (uVar2 != 0) {
        if (iVar3 < 300) goto LAB_0004020a;
        uVar2 = 0;
      }
    }
  }
  if ((*(char *)((int)param_1 + 0x1f2) == '\0') ||
     ((*(int *)(iVar4 + 200) != 0x197 &&
      ((*(char *)((int)param_1 + 0x1fb) == '\0' || (299 < *(int *)(iVar4 + 200))))))) {
LAB_0004024c:
    if (uVar2 == 0) {
      if ((((*(int *)(iVar4 + 200) < 300) && (*(char *)(iVar4 + 0x862c) == '\0')) &&
          (*(char *)((int)param_1 + 0x1fb) != '\0')) &&
         ((*(uint *)(iVar4 + 0x278) & 0xfffffffb) != 1)) {
        iVar3 = (**DAT_000402e8)(*(undefined4 *)(iVar4 + 0x450));
        *(int *)(iVar4 + 0x13c) = iVar3;
        if (iVar3 == 0) {
          return 0x1b;
        }
        *(undefined *)(iVar4 + 0x862c) = 1;
      }
      goto LAB_00040288;
    }
  }
  else {
    iVar3 = pickoneauth(iVar4 + 0x8630);
    if (iVar3 == 0) {
      *(undefined *)(iVar4 + 0x8640) = 1;
      goto LAB_0004024c;
    }
  }
  (**DAT_000402f0)(*(undefined4 *)(iVar4 + 0x13c));
  ppcVar1 = DAT_000402e8;
  *(undefined4 *)(iVar4 + 0x13c) = 0;
  iVar3 = (**ppcVar1)(*(undefined4 *)(iVar4 + 0x450));
  *(int *)(iVar4 + 0x13c) = iVar3;
  if (iVar3 == 0) {
    return 0x1b;
  }
  if ((((*(uint *)(iVar4 + 0x278) & 0xfffffffb) != 1) && (*(char *)(param_1 + 0x7f) == '\0')) &&
     (iVar3 = http_perhapsrewind(param_1), iVar3 != 0)) {
    return iVar3;
  }
LAB_00040288:
  iVar3 = http_should_fail(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  Curl_failf(iVar4,DAT_000402ec,*(undefined4 *)(iVar4 + 200));
  return 0x16;
}

