
void Curl_updateconninfo(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  socklen_t local_11c;
  sockaddr asStack_118 [8];
  sockaddr asStack_98 [8];
  
  uVar9 = *param_1;
  if (param_1[0x23] == 2) {
    return;
  }
  if (*(char *)((int)param_1 + 0x1ee) == '\0') {
    local_11c = 0x80;
    iVar2 = getpeername(param_2,asStack_118,&local_11c);
    if (iVar2 != 0) {
      piVar3 = __errno_location();
      iVar2 = *piVar3;
      uVar4 = Curl_strerror(param_1,iVar2);
      Curl_failf(uVar9,DAT_00038f74,iVar2,uVar4);
      return;
    }
    local_11c = 0x80;
    memset(asStack_98,0,0x80);
    iVar2 = getsockname(param_2,asStack_98,&local_11c);
    if (iVar2 != 0) {
      piVar3 = __errno_location();
      iVar2 = *piVar3;
      uVar4 = Curl_strerror(param_1,iVar2);
      Curl_failf(uVar9,DAT_00038f7c,iVar2,uVar4);
      return;
    }
    iVar2 = getaddressinfo(asStack_118,param_1 + 0x2e,param_1 + 0x3a);
    if (iVar2 == 0) {
      piVar3 = __errno_location();
      iVar2 = *piVar3;
      uVar4 = Curl_strerror(param_1,iVar2);
      Curl_failf(uVar9,DAT_00038f78,iVar2,uVar4);
      return;
    }
    puVar7 = param_1 + 0x2e;
    puVar1 = param_1 + 0x16;
    do {
      puVar8 = puVar1;
      puVar6 = puVar7;
      uVar10 = puVar6[1];
      uVar4 = puVar6[2];
      uVar5 = puVar6[3];
      puVar7 = puVar6 + 4;
      *puVar8 = *puVar6;
      puVar8[1] = uVar10;
      puVar8[2] = uVar4;
      puVar8[3] = uVar5;
      puVar1 = puVar8 + 4;
    } while (puVar7 != param_1 + 0x36);
    uVar5 = puVar6[5];
    uVar4 = puVar6[6];
    puVar8[4] = *puVar7;
    puVar8[5] = uVar5;
    puVar8[6] = uVar4;
    *(undefined2 *)(puVar8 + 7) = *(undefined2 *)(puVar6 + 7);
    iVar2 = getaddressinfo(asStack_98,param_1 + 0x3b,param_1 + 0x47);
    if (iVar2 == 0) {
      piVar3 = __errno_location();
      iVar2 = *piVar3;
      uVar4 = Curl_strerror(param_1,iVar2);
      Curl_failf(uVar9,DAT_00038f80,iVar2,uVar4);
      return;
    }
  }
  Curl_persistconninfo(param_1);
  return;
}

