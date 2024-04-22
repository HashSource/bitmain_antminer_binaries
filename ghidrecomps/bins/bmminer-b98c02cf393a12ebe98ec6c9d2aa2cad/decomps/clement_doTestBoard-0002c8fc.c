
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 clement_doTestBoard(char param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  undefined4 *puVar10;
  char *pcVar11;
  undefined *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 uVar16;
  undefined4 *puVar17;
  int *piVar18;
  undefined4 *puVar19;
  undefined4 *puVar20;
  undefined *puVar21;
  int local_434;
  char acStack_428 [1028];
  
  showLogToKernelLog = param_1;
  if (0 < init_once) {
    memset(&cgpu,0,0x271974);
    iVar3 = configMiner();
    if (iVar3 < 0) {
      puts("configMiner Error!");
      return 0;
    }
    init_once = 0;
    puts("single board test start");
    conf._0_4_ = 0x390;
    conf._4_4_ = 0x390;
    conf._8_4_ = 0x390;
    conf._12_4_ = 0x390;
    conf._60_4_ = 0x12b40;
    conf._64_4_ = 0x12b40;
    conf._68_4_ = 0x12b40;
    ExitFlag = 0;
    Conf._76_4_ = 0x12b40;
    Conf._8_4_ = 0x390;
    Conf._12_4_ = 0x390;
    Conf._16_4_ = 0x390;
    Conf._20_4_ = 0x390;
    Conf._80_4_ = 0x12b40;
    Conf._84_4_ = 0x12b40;
    pthread_create((pthread_t *)&DAT_00082e10,(pthread_attr_t *)0x0,receive_func + 1,&cgpu);
    puVar12 = chain_need_opencore + 0xf;
    do {
      puVar12 = puVar12 + 1;
      *puVar12 = 0;
    } while (puVar12 != StartSendFlag + 0xf);
  }
  puVar4 = DAT_0002cb88 + 0x110;
  puVar20 = DAT_0002cb88 + -0x10;
  puVar12 = (undefined *)((int)DAT_0002cb68 + -0xd);
  puVar5 = DAT_0002cb68 + -0x14;
  puVar21 = (undefined *)((int)DAT_0002cb88 + -0x5d);
  puVar10 = DAT_0002cb88 + 0x10;
  puVar15 = DAT_0002cb68;
  puVar17 = DAT_0002cb6c;
  puVar19 = DAT_0002cb88;
  do {
    puVar15 = puVar15 + 1;
    *puVar15 = 0;
    puVar7 = puVar17;
    puVar14 = puVar10;
    do {
      puVar13 = puVar14;
      puVar14 = puVar13 + 1;
      *puVar14 = 0;
      puVar7 = puVar7 + 1;
      *puVar7 = 0;
      puVar1 = DAT_0002cb70;
    } while (puVar14 != puVar4);
    puVar4 = puVar13 + 0x101;
    puVar10 = puVar10 + 0x100;
    puVar12 = puVar12 + 1;
    *puVar12 = 1;
    puVar17 = puVar17 + 0x100;
    puVar20 = puVar20 + 1;
    *puVar20 = 0x390;
    puVar19 = puVar19 + 1;
    *puVar19 = 0x12b40;
    puVar5 = puVar5 + 1;
    *puVar5 = 0x390;
    puVar21 = puVar21 + 1;
    *puVar21 = 0;
    piVar2 = DAT_0002cb74;
  } while (puVar15 != puVar1);
  local_434 = 0;
  do {
    local_434 = local_434 + 1;
    sprintf(acStack_428,"do heat board 8xPatten for %d times\n",local_434);
    if (showLogToKernelLog != '\0') {
      writeInitLogFile(acStack_428);
    }
    puVar20 = DAT_0002cb78 + -0x110;
    puVar15 = DAT_0002cb78 + -0x120;
    puVar12 = (undefined *)((int)DAT_0002cb8c + 0x43);
    puVar5 = DAT_0002cb78;
    puVar17 = DAT_0002cb6c;
    puVar19 = DAT_0002cb8c;
    do {
      puVar10 = puVar17;
      puVar4 = puVar5 + -0x100;
      do {
        puVar14 = puVar4;
        puVar4 = puVar14 + 1;
        *puVar4 = 0;
        puVar10 = puVar10 + 1;
        *puVar10 = 0;
      } while (puVar4 != puVar5);
      puVar12 = puVar12 + 1;
      *puVar12 = 1;
      puVar17 = puVar17 + 0x100;
      puVar15 = puVar15 + 1;
      *puVar15 = 0x390;
      puVar5 = puVar14 + 0x101;
      puVar20 = puVar20 + 1;
      *puVar20 = 0x12b40;
      puVar19 = puVar19 + 1;
      *puVar19 = 0x390;
    } while (puVar12 != (undefined *)((int)puVar1 + -0x3d));
    uVar6 = doTestBoard_isra_0();
    piVar18 = DAT_0002cb7c;
    piVar8 = (int *)(DAT_0002cb80 + 0x10);
    pcVar11 = DAT_0002cb80;
    piVar9 = DAT_0002cb7c;
    do {
      piVar9 = piVar9 + 1;
      if ((*piVar9 != 0) && (*pcVar11 != '\0')) {
        *piVar8 = *piVar8 + 1;
      }
      pcVar11 = pcVar11 + 1;
      piVar8 = piVar8 + 1;
    } while (piVar2 != piVar9);
    piVar9 = DAT_0002cb84;
  } while (uVar6 < (local_434 == 1));
  do {
    piVar18 = piVar18 + 1;
    if (*piVar18 != 0) {
      piVar8 = piVar9 + -0x54;
      do {
        piVar8 = piVar8 + 1;
        if (*piVar8 == 0) {
          someBoardUpVoltage = 1;
          uVar16 = 0;
          goto LAB_0002cb28;
        }
      } while (piVar9 != piVar8);
    }
    piVar9 = piVar9 + 0x100;
  } while (piVar2 != piVar18);
  uVar16 = 1;
  someBoardUpVoltage = 0;
LAB_0002cb28:
  set_PWM(100);
  return uVar16;
}

