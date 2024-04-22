
void cg_savelogwork(int param_1,undefined4 param_2)

{
  int iVar1;
  void *__ptr;
  void *__ptr_00;
  void *__ptr_01;
  void *__ptr_02;
  void *__ptr_03;
  void *__ptr_04;
  size_t sVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  bool bVar11;
  char local_498 [4];
  byte abStack_494 [12];
  undefined4 local_488;
  undefined4 uStack_484;
  undefined4 uStack_480;
  undefined4 uStack_47c;
  undefined4 local_478;
  undefined4 uStack_474;
  undefined4 uStack_470;
  undefined4 uStack_46c;
  undefined4 local_468;
  undefined4 uStack_464;
  undefined4 uStack_460;
  undefined4 local_448;
  undefined4 uStack_444;
  undefined4 uStack_440;
  undefined4 uStack_43c;
  undefined4 local_438;
  undefined4 uStack_434;
  undefined4 uStack_430;
  undefined4 uStack_42c;
  char acStack_428 [1028];
  
  if (fd_log == (FILE *)0x0) {
    fd_log = fopen("/etc/config/worklog.txt","wb");
  }
  memset(acStack_428,0,0x400);
  memset(&local_468,0,0x20);
  local_488 = *(undefined4 *)(param_1 + 0x80);
  uStack_484 = *(undefined4 *)(param_1 + 0x84);
  uStack_480 = *(undefined4 *)(param_1 + 0x88);
  uStack_47c = *(undefined4 *)(param_1 + 0x8c);
  local_478 = *(undefined4 *)(param_1 + 0x90);
  uStack_474 = *(undefined4 *)(param_1 + 0x94);
  uStack_470 = *(undefined4 *)(param_1 + 0x98);
  uStack_46c = *(undefined4 *)(param_1 + 0x9c);
  iVar8 = 0;
  uVar7 = 0;
  local_468 = *(undefined4 *)(param_1 + 0x40);
  uStack_464 = *(undefined4 *)(param_1 + 0x44);
  uStack_460 = *(undefined4 *)(param_1 + 0x48);
  local_448 = *(undefined4 *)(param_1 + 0xc0);
  uStack_444 = *(undefined4 *)(param_1 + 0xc4);
  uStack_43c = *(undefined4 *)(param_1 + 0xcc);
  uStack_440 = *(undefined4 *)(param_1 + 200);
  local_438 = *(undefined4 *)(param_1 + 0xd0);
  uStack_434 = *(undefined4 *)(param_1 + 0xd4);
  uStack_430 = *(undefined4 *)(param_1 + 0xd8);
  uStack_42c = *(undefined4 *)(param_1 + 0xdc);
  rev(&local_488,0x20);
  rev(&local_468,0xc);
  rev(&local_448,0x20);
  __ptr = (void *)bin2hex(param_1,0x80);
  __ptr_00 = (void *)bin2hex(&local_488,0x20);
  __ptr_01 = (void *)bin2hex(&local_468,0xc);
  __ptr_02 = (void *)bin2hex(param_2,4);
  __ptr_03 = (void *)bin2hex(param_2,5);
  __ptr_04 = (void *)bin2hex(&local_448,0x20);
  pbVar10 = abStack_494;
  while (sVar2 = strlen((char *)abStack_494), uVar7 < sVar2) {
    pbVar9 = pbVar10 + 1;
    uVar4 = (uint)*pbVar10;
    uVar6 = uVar4 - 0x30 & 0xff;
    if (9 < uVar6) {
      iVar1 = -0x37;
      if (uVar4 - 0x61 < 6) {
        iVar1 = -0x57;
      }
      uVar6 = uVar4 + iVar1 & 0xff;
      if ((5 < uVar4 - 0x61) && (5 < uVar4 - 0x41)) break;
    }
    cVar5 = (char)uVar6;
    bVar11 = (uVar7 & 1) == 0;
    cVar3 = (char)(uVar6 << 4);
    if (!bVar11) {
      cVar3 = local_498[iVar8];
    }
    uVar7 = uVar7 + 1;
    if (bVar11) {
      local_498[iVar8] = cVar3;
    }
    else {
      cVar5 = cVar5 + cVar3;
    }
    pbVar10 = pbVar9;
    if (!bVar11) {
      local_498[iVar8] = cVar5;
      iVar8 = iVar8 + 1;
    }
  }
  sprintf(acStack_428,"midstate %s data %s nonce %s \r\n",__ptr_00,__ptr_01,__ptr_02);
  sVar2 = strlen(acStack_428);
  fwrite(acStack_428,sVar2,1,fd_log);
  fflush(fd_log);
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  if (__ptr_00 != (void *)0x0) {
    free(__ptr_00);
  }
  if (__ptr_01 != (void *)0x0) {
    free(__ptr_01);
  }
  if (__ptr_02 != (void *)0x0) {
    free(__ptr_02);
  }
  if (__ptr_03 != (void *)0x0) {
    free(__ptr_03);
  }
  if (__ptr_04 != (void *)0x0) {
    free(__ptr_04);
  }
  return;
}

