
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 clement_doTestBoard(char param_1)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  int *piVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined1 *puVar18;
  int local_434;
  char acStack_428 [1028];
  
  showLogToKernelLog = param_1;
  if (0 < init_once) {
    memset(&cgpu,0,0x271974);
    iVar1 = configMiner();
    if (iVar1 < 0) {
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
    pthread_create((pthread_t *)&DAT_00082e10,(pthread_attr_t *)0x0,(__start_routine *)0x2a94d,&cgpu
                  );
    puVar5 = chain_need_opencore + 0xf;
    do {
      puVar5 = puVar5 + 1;
      *puVar5 = 0;
    } while (puVar5 != StartSendFlag + 0xf);
  }
  puVar16 = (undefined4 *)(chain_DataCount + 0x3c);
  puVar11 = (undefined4 *)(search_freq_result + 0xc);
  puVar13 = (undefined4 *)(last_result + 0x3ffc);
  puVar2 = (undefined4 *)(last_result + 0x3fc);
  puVar6 = (undefined4 *)(StartSendFlag + 0xc);
  puVar5 = chain_PassCount + 0x3f;
  puVar17 = (undefined4 *)(last_result_opencore + 0x3ffc);
  puVar18 = send_work_num + 0x3f;
  puVar15 = (undefined4 *)(chain_ValidNonce + 0x3c);
  do {
    puVar11 = puVar11 + 1;
    *puVar11 = 0;
    puVar4 = puVar13;
    puVar8 = puVar15;
    do {
      puVar7 = puVar8;
      puVar8 = puVar7 + 1;
      *puVar8 = 0;
      puVar4 = puVar4 + 1;
      *puVar4 = 0;
    } while (puVar8 != puVar2);
    puVar2 = puVar7 + 0x101;
    puVar15 = puVar15 + 0x100;
    puVar5 = puVar5 + 1;
    *puVar5 = 1;
    puVar13 = puVar13 + 0x100;
    puVar6 = puVar6 + 1;
    *puVar6 = 0x390;
    puVar16 = puVar16 + 1;
    *puVar16 = 0x12b40;
    puVar17 = puVar17 + 1;
    *puVar17 = 0x390;
    puVar18 = puVar18 + 1;
    *puVar18 = 0;
  } while (puVar11 != (undefined4 *)(testModeOKCounter + 0x3c));
  local_434 = 0;
  do {
    local_434 = local_434 + 1;
    sprintf(acStack_428,"do heat board 8xPatten for %d times\n",local_434);
    if (showLogToKernelLog != '\0') {
      writeInitLogFile(acStack_428);
    }
    puVar17 = (undefined4 *)(last_result + 0x3fc);
    puVar16 = (undefined4 *)(last_result_opencore + 0x3ffc);
    puVar2 = (undefined4 *)(last_result + 0x3ffc);
    puVar6 = (undefined4 *)(chain_DataCount + 0x3c);
    puVar11 = (undefined4 *)(StartSendFlag + 0xc);
    puVar5 = chain_PassCount + 0x3f;
    do {
      puVar15 = puVar2;
      puVar13 = puVar17 + -0x100;
      do {
        puVar8 = puVar13;
        puVar13 = puVar8 + 1;
        *puVar13 = 0;
        puVar15 = puVar15 + 1;
        *puVar15 = 0;
      } while (puVar13 != puVar17);
      puVar5 = puVar5 + 1;
      *puVar5 = 1;
      puVar2 = puVar2 + 0x100;
      puVar11 = puVar11 + 1;
      *puVar11 = 0x390;
      puVar17 = puVar8 + 0x101;
      puVar6 = puVar6 + 1;
      *puVar6 = 0x12b40;
      puVar16 = puVar16 + 1;
      *puVar16 = 0x390;
    } while (puVar5 != search_freq_result + 0xf);
    uVar3 = doTestBoard_isra_0();
    piVar14 = &DAT_002f44f8;
    puVar18 = search_freq_result;
    piVar9 = &DAT_002f44f8;
    puVar5 = testModeOKCounter;
    do {
      piVar9 = piVar9 + 1;
      if ((*piVar9 != 0) && (*puVar18 != '\0')) {
        *(int *)puVar5 = *(int *)puVar5 + 1;
      }
      puVar18 = puVar18 + 1;
      puVar5 = (undefined1 *)((int)puVar5 + 4);
    } while (piVar9 != (int *)&DAT_002f4538);
  } while (uVar3 < (local_434 == 1));
  piVar9 = (int *)(last_result_opencore + 0x14c);
  do {
    piVar14 = piVar14 + 1;
    if (*piVar14 != 0) {
      piVar10 = piVar9 + -0x54;
      do {
        piVar10 = piVar10 + 1;
        if (*piVar10 == 0) {
          someBoardUpVoltage = 1;
          uVar12 = 0;
          goto LAB_0002cb28;
        }
      } while (piVar9 != piVar10);
    }
    piVar9 = piVar9 + 0x100;
  } while (piVar14 != (int *)&DAT_002f4538);
  uVar12 = 1;
  someBoardUpVoltage = 0;
LAB_0002cb28:
  set_PWM(100);
  return uVar12;
}

