
/* WARNING: Unknown calling convention */

_Bool clement_doTestBoard(_Bool showlog)

{
  int *piVar1;
  void *__arg;
  char *__s;
  __start_routine *__start_routine;
  int iVar2;
  _Bool _Var3;
  _Bool result_flag;
  int iVar4;
  int ret;
  int iVar5;
  int *piVar6;
  undefined *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int k;
  char logstr [256];
  
  iVar10 = DAT_00018000;
  piVar6 = (int *)(DAT_00018000 + 4);
  *(_Bool *)DAT_00018000 = showlog;
  __arg = DAT_00018004;
  if (0 < *piVar6) {
    memset(DAT_00018004,0,0x271974);
    iVar4 = configMiner();
    __s = DAT_00018008;
    if (iVar4 < 0) {
      puts(DAT_00018038);
      return false;
    }
    *(undefined4 *)(iVar10 + 4) = 0;
    puts(__s);
    iVar5 = DAT_0001803c;
    __start_routine = DAT_00018014;
    iVar4 = DAT_00018010;
    iVar10 = DAT_0001800c;
    *(undefined4 *)(DAT_0001800c + 0xd2c) = 0x390;
    *(undefined *)(iVar5 + 0x304) = 0;
    *(undefined *)(iVar5 + 0x305) = 0;
    *(undefined4 *)(iVar10 + 0xd30) = 0x390;
    *(undefined4 *)(iVar10 + 0xd34) = 0x390;
    *(undefined4 *)(iVar10 + 0xd38) = 0x390;
    *(undefined4 *)(iVar4 + 0xee4) = 0x390;
    *(undefined4 *)(iVar4 + 0xee8) = 0x390;
    *(undefined4 *)(iVar4 + 0xeec) = 0x390;
    *(undefined4 *)(iVar4 + 0xef0) = 0x390;
    *(undefined4 *)(iVar10 + 0xd68) = 0x4020;
    *(undefined4 *)(iVar4 + 0xf28) = 0x4020;
    *(undefined4 *)(iVar10 + 0xd6c) = 0x4020;
    *(undefined4 *)(iVar4 + 0xf2c) = 0x4020;
    *(undefined4 *)(iVar10 + 0xd70) = 0x4020;
    *(undefined4 *)(iVar4 + 0xf30) = 0x4020;
    pthread_create((pthread_t *)((int)__arg + 0x200),(pthread_attr_t *)0x0,__start_routine,__arg);
    puVar7 = (undefined *)(iVar5 + 0x357);
    do {
      puVar7 = puVar7 + 1;
      *puVar7 = 0;
    } while (puVar7 != (undefined *)(iVar5 + 0x367));
  }
  iVar4 = DAT_00018040;
  iVar10 = DAT_0001801c;
  iVar15 = 0;
  iVar14 = 0;
  iVar13 = DAT_00018018 + -0x90;
  iVar12 = DAT_00018018 + -0x40;
  iVar11 = DAT_00018040 + -0x54;
  iVar5 = DAT_00018018;
  iVar9 = DAT_0001801c;
  do {
    iVar8 = 0;
    *(undefined4 *)(iVar4 + iVar15) = 0;
    do {
      *(undefined4 *)(iVar5 + iVar8) = 0;
      *(undefined4 *)(iVar9 + iVar8) = 0;
      iVar2 = DAT_00018020;
      iVar8 = iVar8 + 4;
    } while (iVar8 != 0x400);
    iVar5 = iVar5 + 0x400;
    *(undefined4 *)(iVar13 + iVar15) = 0x390;
    iVar9 = iVar9 + 0x400;
    *(undefined4 *)(iVar11 + iVar15) = 0x390;
    *(undefined *)(iVar2 + iVar14) = 1;
    *(undefined *)(DAT_00018024 + iVar14) = 0;
    iVar8 = DAT_00018028;
    iVar14 = iVar14 + 1;
    *(undefined4 *)(DAT_00018028 + iVar15) = 0;
    *(undefined4 *)(iVar8 + 0x40 + iVar15) = 0;
    *(undefined4 *)(iVar8 + 0x80 + iVar15) = 0;
    *(undefined4 *)(iVar12 + iVar15) = 0x4020;
    iVar15 = iVar15 + 4;
  } while (iVar14 != 0x10);
  k = 0;
  do {
    k = k + 1;
    sprintf(logstr,DAT_0001802c,k);
    writeLogFile(logstr);
    iVar14 = 0;
    iVar5 = DAT_0001801c;
    iVar9 = DAT_00018018;
    puVar7 = DAT_00018044;
    do {
      iVar15 = 0;
      do {
        *(undefined4 *)(iVar9 + iVar15) = 0;
        *(undefined4 *)(iVar5 + iVar15) = 0;
        iVar15 = iVar15 + 4;
      } while (iVar15 != 0x400);
      *(undefined4 *)(iVar13 + iVar14) = 0x390;
      iVar9 = iVar9 + 0x400;
      *(undefined4 *)(iVar12 + iVar14) = 0x4020;
      iVar5 = iVar5 + 0x400;
      *(undefined4 *)(iVar11 + iVar14) = 0x390;
      iVar14 = iVar14 + 4;
      puVar7 = puVar7 + 1;
      *puVar7 = 1;
    } while (iVar14 != 0x40);
    _Var3 = doTestBoard(0x40);
    iVar5 = 0;
    iVar9 = 0;
    do {
      if ((*(int *)((int)__arg + (int)cgpu.results[0x6b] + iVar5 + 0x4228) != 0) &&
         (*(char *)(DAT_00018020 + iVar9) != '\0')) {
        *(int *)(iVar4 + iVar5) = *(int *)(iVar4 + iVar5) + 1;
      }
      iVar9 = iVar9 + 1;
      iVar5 = iVar5 + 4;
    } while (iVar9 != 0x10);
  } while ((!_Var3) && (k == 1));
  piVar6 = DAT_00018030;
  do {
    piVar6 = piVar6 + 1;
    if (*piVar6 != 0) {
      iVar4 = 0;
      do {
        piVar1 = (int *)(iVar10 + iVar4);
        iVar4 = iVar4 + 4;
        if (*piVar1 == 0) {
          *DAT_00018034 = 1;
          _Var3 = false;
          goto LAB_00017fdc;
        }
      } while (iVar4 != 0x48);
    }
    iVar10 = iVar10 + 0x400;
  } while (piVar6 != DAT_00018030 + 0x10);
  _Var3 = true;
  *DAT_00018034 = 0;
LAB_00017fdc:
  set_PWM('d');
  return _Var3;
}

