
/* WARNING: Unknown calling convention */

_Bool clement_doTestBoardOnce(_Bool showlog)

{
  int *piVar1;
  int iVar2;
  char *__s;
  __start_routine *__start_routine;
  int iVar3;
  void *__s_00;
  int iVar4;
  int ret;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  __s_00 = DAT_000181dc;
  iVar2 = DAT_000181ac;
  piVar1 = (int *)(DAT_000181ac + 4);
  *(_Bool *)DAT_000181ac = showlog;
  if (0 < *piVar1) {
    memset(__s_00,0,0x271974);
    iVar4 = configMiner();
    iVar10 = DAT_000181e0;
    __s = DAT_000181b8;
    iVar9 = DAT_000181b4;
    iVar8 = DAT_000181b0;
    if (iVar4 < 0) {
      puts(DAT_000181d8);
      return false;
    }
    *(undefined4 *)(iVar2 + 4) = 0;
    puts(__s);
    __start_routine = DAT_000181bc;
    *(undefined *)(iVar10 + 0x304) = 0;
    *(undefined *)(iVar10 + 0x305) = 0;
    *(undefined4 *)(iVar8 + 0xd2c) = 0x390;
    *(undefined4 *)(iVar8 + 0xd30) = 0x390;
    *(undefined4 *)(iVar8 + 0xd34) = 0x390;
    *(undefined4 *)(iVar8 + 0xd38) = 0x390;
    *(undefined4 *)(iVar9 + 0xee4) = 0x390;
    *(undefined4 *)(iVar9 + 0xee8) = 0x390;
    *(undefined4 *)(iVar9 + 0xeec) = 0x390;
    *(undefined4 *)(iVar9 + 0xef0) = 0x390;
    *(undefined4 *)(iVar8 + 0xd68) = 0x4020;
    *(undefined4 *)(iVar9 + 0xf28) = 0x4020;
    *(undefined4 *)(iVar8 + 0xd6c) = 0x4020;
    *(undefined4 *)(iVar9 + 0xf2c) = 0x4020;
    *(undefined4 *)(iVar8 + 0xd70) = 0x4020;
    *(undefined4 *)(iVar9 + 0xf30) = 0x4020;
    pthread_create((pthread_t *)((int)__s_00 + 0x200),(pthread_attr_t *)0x0,__start_routine,__s_00);
    puVar6 = (undefined *)(iVar10 + 0x357);
    do {
      puVar6 = puVar6 + 1;
      *puVar6 = 0;
    } while (puVar6 != (undefined *)(iVar10 + 0x367));
  }
  iVar2 = DAT_000181e4;
  iVar10 = 0;
  iVar12 = 0;
  iVar11 = DAT_000181c0 + -0x90;
  iVar4 = DAT_000181e4 + -0x10;
  iVar8 = DAT_000181c0;
  iVar9 = DAT_000181c4;
  do {
    iVar5 = 0;
    *(undefined4 *)(iVar2 + iVar10) = 0;
    do {
      *(undefined4 *)(iVar8 + iVar5) = 0;
      iVar7 = 0;
      *(undefined4 *)(iVar9 + iVar5) = 0;
      iVar3 = DAT_000181c8;
      iVar5 = iVar5 + 4;
    } while (iVar5 != 0x400);
    iVar8 = iVar8 + 0x400;
    *(undefined *)(iVar4 + iVar12) = 1;
    iVar9 = iVar9 + 0x400;
    *(undefined4 *)(iVar11 + iVar10) = 0x390;
    *(undefined *)(iVar3 + iVar12) = 0;
    iVar5 = DAT_000181cc;
    iVar12 = iVar12 + 1;
    *(undefined4 *)(DAT_000181cc + iVar10) = 0;
    *(undefined4 *)(iVar5 + 0x40 + iVar10) = 0;
    *(undefined4 *)(iVar5 + 0x80 + iVar10) = 0;
    *(undefined4 *)(DAT_000181d0 + iVar10) = 0x4020;
    *(undefined4 *)(DAT_000181d4 + iVar10) = 0x390;
    iVar10 = iVar10 + 4;
  } while (iVar12 != 0x10);
  doTestBoard(0x4020);
  iVar8 = 0;
  do {
    if ((*(int *)((int)__s_00 + (int)cgpu.results[0x6b] + iVar7 + 0x4228) != 0) &&
       (*(char *)(iVar4 + iVar8) != '\0')) {
      *(int *)(iVar2 + iVar7) = *(int *)(iVar2 + iVar7) + 1;
    }
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 4;
  } while (iVar8 != 0x10);
  set_PWM('d');
  return true;
}

