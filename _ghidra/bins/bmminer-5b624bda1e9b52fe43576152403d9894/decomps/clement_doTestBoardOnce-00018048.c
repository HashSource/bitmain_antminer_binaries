
/* WARNING: Unknown calling convention */

_Bool clement_doTestBoardOnce(_Bool showlog)

{
  int iVar1;
  int iVar2;
  _Bool *p_Var3;
  int iVar4;
  int (*paiVar5) [256];
  int (*paiVar6) [256];
  int iVar7;
  
  showLogToKernelLog = showlog;
  if (0 < init_once) {
    memset(&cgpu,0,0x271974);
    iVar1 = configMiner();
    if (iVar1 < 0) {
      puts("configMiner Error!");
      return false;
    }
    init_once = 0;
    puts("single board test start");
    ExitFlag = false;
    receiveExit = false;
    conf.dataCount = 0x390;
    conf.passCount1 = 0x390;
    conf.passCount2 = 0x390;
    conf.passCount3 = 0x390;
    Conf.DataCount = 0x390;
    Conf.PassCount1 = 0x390;
    Conf.PassCount2 = 0x390;
    Conf.PassCount3 = 0x390;
    conf.ValidNonce1 = 0x4020;
    Conf.ValidNonce1 = 0x4020;
    conf.ValidNonce2 = 0x4020;
    Conf.ValidNonce2 = 0x4020;
    conf.ValidNonce3 = 0x4020;
    Conf.ValidNonce3 = 0x4020;
    pthread_create(&cgpu.receive_id,(pthread_attr_t *)0x0,(__start_routine *)0x15f7d,&cgpu);
    p_Var3 = chain_need_opencore + 0xf;
    do {
      p_Var3 = p_Var3 + 1;
      *p_Var3 = false;
    } while (p_Var3 != StartSendFlag + 0xf);
  }
  paiVar5 = last_result;
  iVar1 = 0;
  iVar7 = 0;
  paiVar6 = last_result_opencore;
  do {
    iVar2 = 0;
    *(undefined4 *)((int)testModeOKCounter + iVar1) = 0;
    do {
      *(undefined4 *)((int)*paiVar5 + iVar2) = 0;
      iVar4 = 0;
      *(undefined4 *)((int)*paiVar6 + iVar2) = 0;
      iVar2 = iVar2 + 4;
    } while (iVar2 != 0x400);
    paiVar5 = paiVar5 + 1;
    search_freq_result[iVar7] = true;
    paiVar6 = paiVar6 + 1;
    *(undefined4 *)((int)chain_DataCount + iVar1) = 0x390;
    chain_need_opencore[iVar7] = false;
    iVar7 = iVar7 + 1;
    *(undefined4 *)((int)chain_vol_value + iVar1) = 0;
    *(undefined4 *)((int)chain_vol_final + iVar1) = 0;
    *(undefined4 *)((int)chain_vol_added + iVar1) = 0;
    *(undefined4 *)((int)chain_ValidNonce + iVar1) = 0x4020;
    *(undefined4 *)((int)chain_PassCount + iVar1) = 0x390;
    iVar1 = iVar1 + 4;
  } while (iVar7 != 0x10);
  doTestBoard(0x4020);
  iVar1 = 0;
  do {
    if ((*(int *)((int)cgpu.chain_exist + iVar4) != 0) && (search_freq_result[iVar1] != false)) {
      *(int *)((int)testModeOKCounter + iVar4) = *(int *)((int)testModeOKCounter + iVar4) + 1;
    }
    iVar1 = iVar1 + 1;
    iVar4 = iVar4 + 4;
  } while (iVar1 != 0x10);
  set_PWM('d');
  return true;
}

