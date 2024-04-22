
undefined4 clement_doTestBoardOnce(undefined param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  char *pcVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  undefined4 *puVar17;
  undefined *puVar18;
  
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
    pthread_create((pthread_t *)&DAT_00082e10,(pthread_attr_t *)0x0,receive_func + 1,&cgpu);
    puVar8 = chain_need_opencore + 0xf;
    do {
      puVar8 = puVar8 + 1;
      *puVar8 = 0;
    } while (puVar8 != StartSendFlag + 0xf);
  }
  puVar16 = DAT_0002cd14 + 0x10;
  puVar18 = (undefined *)((int)DAT_0002cd14 + -0x1d);
  puVar8 = (undefined *)((int)DAT_0002cd18 + -0xd);
  puVar17 = DAT_0002cd18 + -0x14;
  puVar13 = DAT_0002cd14 + 0x20;
  puVar4 = DAT_0002cd14 + 0x120;
  puVar11 = DAT_0002cd18;
  puVar14 = DAT_0002cd1c;
  puVar15 = DAT_0002cd14;
  do {
    puVar11 = puVar11 + 1;
    *puVar11 = 0;
    puVar5 = puVar14;
    puVar2 = puVar13;
    do {
      puVar9 = puVar2;
      puVar2 = puVar9 + 1;
      *puVar2 = 0;
      puVar5 = puVar5 + 1;
      *puVar5 = 0;
      puVar1 = DAT_0002cd20;
    } while (puVar2 != puVar4);
    puVar4 = puVar9 + 0x101;
    puVar13 = puVar13 + 0x100;
    puVar8 = puVar8 + 1;
    *puVar8 = 1;
    puVar14 = puVar14 + 0x100;
    puVar15 = puVar15 + 1;
    *puVar15 = 0x390;
    puVar16 = puVar16 + 1;
    *puVar16 = 0x12b40;
    puVar17 = puVar17 + 1;
    *puVar17 = 0x390;
    puVar18 = puVar18 + 1;
    *puVar18 = 0;
  } while (puVar11 != puVar1);
  doTestBoard_isra_0();
  piVar12 = DAT_0002cd24 + 0x10;
  piVar6 = (int *)(DAT_0002cd28 + 0x10);
  pcVar7 = DAT_0002cd28;
  piVar10 = DAT_0002cd24;
  do {
    piVar10 = piVar10 + 1;
    if ((*piVar10 != 0) && (*pcVar7 != '\0')) {
      *piVar6 = *piVar6 + 1;
    }
    pcVar7 = pcVar7 + 1;
    piVar6 = piVar6 + 1;
  } while (piVar10 != piVar12);
  set_PWM(100);
  return 1;
}

