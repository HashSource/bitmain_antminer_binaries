
/* WARNING: Unknown calling convention */

_Bool clement_doTestBoard(_Bool showlog)

{
  int *piVar1;
  _Bool _Var2;
  int iVar3;
  int (*paiVar4) [256];
  uint *puVar5;
  _Bool *p_Var6;
  int iVar7;
  int (*paiVar8) [256];
  undefined1 *puVar9;
  int iVar10;
  int local_134;
  int (*local_12c) [256];
  char logstr [256];
  
  showLogToKernelLog = showlog;
  if (0 < init_once) {
    memset(&cgpu,0,0x271974);
    iVar3 = configMiner();
    if (iVar3 < 0) {
      puts("configMiner Error!");
      return false;
    }
    init_once = 0;
    puts("single board test start");
    conf.dataCount = 0x390;
    ExitFlag = false;
    receiveExit = false;
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
    p_Var6 = chain_need_opencore + 0xf;
    do {
      p_Var6 = p_Var6 + 1;
      *p_Var6 = false;
    } while (p_Var6 != StartSendFlag + 0xf);
  }
  paiVar4 = last_result;
  iVar10 = 0;
  iVar3 = 0;
  paiVar8 = last_result_opencore;
  do {
    iVar7 = 0;
    *(undefined4 *)((int)testModeOKCounter + iVar10) = 0;
    do {
      *(undefined4 *)((int)*paiVar4 + iVar7) = 0;
      *(undefined4 *)((int)*paiVar8 + iVar7) = 0;
      iVar7 = iVar7 + 4;
    } while (iVar7 != 0x400);
    paiVar4 = paiVar4 + 1;
    *(undefined4 *)((int)chain_DataCount + iVar10) = 0x390;
    paiVar8 = paiVar8 + 1;
    *(undefined4 *)((int)chain_PassCount + iVar10) = 0x390;
    search_freq_result[iVar3] = true;
    chain_need_opencore[iVar3] = false;
    iVar3 = iVar3 + 1;
    *(undefined4 *)((int)chain_vol_value + iVar10) = 0;
    *(undefined4 *)((int)chain_vol_final + iVar10) = 0;
    *(undefined4 *)((int)chain_vol_added + iVar10) = 0;
    *(undefined4 *)((int)chain_ValidNonce + iVar10) = 0x4020;
    iVar10 = iVar10 + 4;
  } while (iVar3 != 0x10);
  local_12c = last_result_opencore;
  local_134 = 0;
  do {
    local_134 = local_134 + 1;
    sprintf(logstr,"do heat board 8xPatten for %d times\n",local_134);
    writeLogFile(logstr);
    puVar9 = (undefined1 *)((int)&result + 3);
    iVar3 = 0;
    paiVar4 = last_result_opencore;
    paiVar8 = last_result;
    do {
      iVar10 = 0;
      do {
        *(undefined4 *)((int)*paiVar8 + iVar10) = 0;
        *(undefined4 *)((int)*paiVar4 + iVar10) = 0;
        iVar10 = iVar10 + 4;
      } while (iVar10 != 0x400);
      *(undefined4 *)((int)chain_DataCount + iVar3) = 0x390;
      paiVar8 = paiVar8 + 1;
      *(undefined4 *)((int)chain_ValidNonce + iVar3) = 0x4020;
      paiVar4 = paiVar4 + 1;
      *(undefined4 *)((int)chain_PassCount + iVar3) = 0x390;
      iVar3 = iVar3 + 4;
      puVar9 = puVar9 + 1;
      *puVar9 = 1;
    } while (iVar3 != 0x40);
    _Var2 = doTestBoard(0x40);
    iVar3 = 0;
    iVar10 = 0;
    do {
      if ((*(int *)((int)cgpu.chain_exist + iVar3) != 0) && (search_freq_result[iVar10] != false)) {
        *(int *)((int)testModeOKCounter + iVar3) = *(int *)((int)testModeOKCounter + iVar3) + 1;
      }
      iVar10 = iVar10 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar10 != 0x10);
  } while ((!_Var2) && (local_134 == 1));
  puVar5 = &cgpu.CommandMode;
  do {
    puVar5 = puVar5 + 1;
    if (*puVar5 != 0) {
      iVar3 = 0;
      do {
        piVar1 = (int *)((int)*local_12c + iVar3);
        iVar3 = iVar3 + 4;
        if (*piVar1 == 0) {
          someBoardUpVoltage = true;
          _Var2 = false;
          goto LAB_00017fdc;
        }
      } while (iVar3 != 0x48);
    }
    local_12c = local_12c + 1;
  } while (puVar5 != cgpu.chain_exist + 0xf);
  _Var2 = true;
  someBoardUpVoltage = false;
LAB_00017fdc:
  set_PWM('d');
  return _Var2;
}

