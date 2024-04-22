
int Curl_pretransfer(int param_1)

{
  code **ppcVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  
  if (*(int *)(param_1 + 0x450) == 0) {
    Curl_failf(param_1,DAT_0004bf08);
    return 3;
  }
  iVar2 = Curl_ssl_initsessions(param_1,*(undefined4 *)(param_1 + 0x2a8));
  ppcVar1 = DAT_0004bf04;
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 0x17c) = 0;
    *(undefined4 *)(param_1 + 0x8620) = *(undefined4 *)(param_1 + 0x174);
    *(undefined4 *)(param_1 + 0x8678) = 0;
    *(undefined *)(param_1 + 0x8640) = 0;
    *(undefined4 *)(param_1 + 0x8630) = *(undefined4 *)(param_1 + 0x178);
    *(undefined *)(param_1 + 0x85a8) = 0;
    pcVar4 = *ppcVar1;
    *(undefined *)(param_1 + 0x85c8) = 0;
    (*pcVar4)(*(undefined4 *)(param_1 + 0x8720));
    *(undefined4 *)(param_1 + 0x8720) = 0;
    if (*(int *)(param_1 + 0x278) == 4) {
      puVar5 = (undefined4 *)(param_1 + 0x218);
    }
    else {
      puVar5 = (undefined4 *)(param_1 + 0x198);
    }
    uVar6 = puVar5[1];
    *(undefined4 *)(param_1 + 0x86b0) = *puVar5;
    *(undefined4 *)(param_1 + 0x86b4) = uVar6;
    if (*(int *)(param_1 + 0x460) != 0) {
      Curl_cookie_loadfiles(param_1);
    }
    if ((*(int *)(param_1 + 0x464) != 0) && (iVar3 = Curl_loadhostpairs(param_1), iVar3 != 0)) {
      return iVar3;
    }
    *(undefined *)(param_1 + 0x85d4) = 1;
    Curl_initinfo(param_1);
    Curl_pgrsResetTimesSizes(param_1);
    Curl_pgrsStartNow(param_1);
    if (*(int *)(param_1 + 0x200) != 0) {
      Curl_expire(param_1);
    }
    if (*(int *)(param_1 + 0x204) != 0) {
      Curl_expire(param_1);
    }
    *(uint *)(param_1 + 0x8624) = *(uint *)(param_1 + 0x8624) & *(uint *)(param_1 + 0x8620);
    *(uint *)(param_1 + 0x8634) = *(uint *)(param_1 + 0x8634) & *(uint *)(param_1 + 0x8630);
  }
  return iVar2;
}

