
undefined4 clement_doTestBoardOnce(undefined1 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined1 *puVar14;
  
  showLogToKernelLog = param_1;
  if (0 < init_once) {
    memset(&cgpu,0,0x271974);
    iVar2 = configMiner();
    if (iVar2 < 0) {
      puts("configMiner Error!");
      return 0;
    }
    init_once = 0;
    puts("single board test start");
    ExitFlag = 0;
    conf._0_4_ = 0x390;
    conf._4_4_ = 0x390;
    conf._8_4_ = 0x390;
    conf._12_4_ = 0x390;
    conf._60_4_ = 0x12b40;
    conf._64_4_ = 0x12b40;
    conf._68_4_ = 0x12b40;
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
  puVar11 = (undefined4 *)(StartSendFlag + 0xc);
  puVar8 = (undefined4 *)(search_freq_result + 0xc);
  puVar10 = (undefined4 *)(last_result + 0x3ffc);
  puVar12 = (undefined4 *)(chain_DataCount + 0x3c);
  puVar14 = send_work_num + 0x3f;
  puVar5 = chain_PassCount + 0x3f;
  puVar13 = (undefined4 *)(last_result_opencore + 0x3ffc);
  puVar9 = (undefined4 *)(chain_ValidNonce + 0x3c);
  puVar3 = (undefined4 *)(last_result + 0x3fc);
  do {
    puVar8 = puVar8 + 1;
    *puVar8 = 0;
    puVar4 = puVar10;
    puVar1 = puVar9;
    do {
      puVar6 = puVar1;
      puVar1 = puVar6 + 1;
      *puVar1 = 0;
      puVar4 = puVar4 + 1;
      *puVar4 = 0;
    } while (puVar1 != puVar3);
    puVar3 = puVar6 + 0x101;
    puVar9 = puVar9 + 0x100;
    puVar5 = puVar5 + 1;
    *puVar5 = 1;
    puVar10 = puVar10 + 0x100;
    puVar11 = puVar11 + 1;
    *puVar11 = 0x390;
    puVar12 = puVar12 + 1;
    *puVar12 = 0x12b40;
    puVar13 = puVar13 + 1;
    *puVar13 = 0x390;
    puVar14 = puVar14 + 1;
    *puVar14 = 0;
  } while (puVar8 != (undefined4 *)(testModeOKCounter + 0x3c));
  doTestBoard_isra_0();
  piVar7 = &DAT_002f44f8;
  puVar14 = search_freq_result;
  puVar5 = testModeOKCounter;
  do {
    piVar7 = piVar7 + 1;
    if ((*piVar7 != 0) && (*puVar14 != '\0')) {
      *(int *)puVar5 = *(int *)puVar5 + 1;
    }
    puVar14 = puVar14 + 1;
    puVar5 = (undefined1 *)((int)puVar5 + 4);
  } while (piVar7 != (int *)&DAT_002f4538);
  set_PWM(100);
  return 1;
}

