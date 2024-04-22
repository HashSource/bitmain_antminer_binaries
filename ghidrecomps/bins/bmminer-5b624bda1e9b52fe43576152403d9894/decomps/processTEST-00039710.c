
/* WARNING: Unknown calling convention */

void processTEST(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uchar uVar4;
  byte bVar5;
  int iVar6;
  int testID;
  uchar temp_voltage_1;
  int chainIndex;
  int i;
  uchar temp_voltage;
  int iVar7;
  int set_vol_value;
  int iVar8;
  int chainIndex_00;
  uint uVar9;
  double dVar10;
  char logstr [256];
  
  iVar6 = readTestID();
  puVar3 = DAT_00039a28;
  puVar2 = DAT_00039a20;
  piVar1 = DAT_000399fc;
  if (iVar6 == 0xb) {
    saveTestID(0);
    sprintf(logstr,DAT_00039a1c,0xb);
    writeInitLogFile(logstr);
    do8xPattenTest();
  }
  else if (iVar6 == 0xc) {
    saveTestID(0);
    sprintf(logstr,DAT_00039a24,0xc);
    writeInitLogFile(logstr);
    bitmain_core_reInit();
    reCalculateAVG();
    logstr._0_4_ = *puVar2;
    logstr._4_4_ = puVar2[1];
    logstr._8_4_ = puVar2[2];
    logstr._12_4_ = puVar2[3];
    logstr._16_4_ = puVar2[4];
    logstr._20_4_ = puVar2[5];
    logstr._24_4_ = puVar2[6];
    logstr._28_2_ = (undefined2)puVar2[7];
    logstr[30] = (char)((uint)puVar2[7] >> 0x10);
    writeInitLogFile(logstr);
  }
  else if (iVar6 == 0xd) {
    saveTestID(0);
    sprintf(logstr,DAT_00039a2c,0xd);
    writeInitLogFile(logstr);
    doReInitTest();
    reCalculateAVG();
    logstr._0_4_ = *puVar3;
    logstr._4_4_ = puVar3[1];
    logstr._8_4_ = puVar3[2];
    logstr._12_4_ = puVar3[3];
    logstr._16_4_ = puVar3[4];
    logstr._20_4_ = puVar3[5];
    writeInitLogFile(logstr);
  }
  else if (iVar6 == 0xe) {
    saveTestID(0);
    sprintf(logstr,DAT_00039a10,0xe);
    writeInitLogFile(logstr);
    iVar6 = 1;
    do {
      while( true ) {
        iVar7 = *piVar1;
        iVar8 = iVar6 + 1;
        chainIndex_00 = iVar6 + -1;
        if (*(int *)(iVar7 + iVar8 * 4) != 1) break;
        *(undefined *)(iVar7 + chainIndex_00 + 0x2faa) = 0;
        check_asic_reg_oneChain(chainIndex_00,0);
        sprintf(logstr,DAT_00039a14,iVar6,(uint)*(byte *)(*piVar1 + chainIndex_00 + 0x2faa));
        writeInitLogFile(logstr);
        iVar6 = iVar8;
        if (iVar8 == 0x11) goto LAB_0003992a;
      }
      iVar6 = iVar8;
    } while (iVar8 != 0x11);
LAB_0003992a:
    logstr._0_4_ = *DAT_00039a18;
    logstr._4_4_ = DAT_00039a18[1];
    logstr._8_4_ = DAT_00039a18[2];
    logstr._12_4_ = DAT_00039a18[3];
    logstr._16_4_ = DAT_00039a18[4];
    logstr[20] = (char)DAT_00039a18[5];
    writeInitLogFile(logstr);
  }
  else {
    if (iVar6 - 0x65U < 0x10) {
      saveTestID(0);
      iVar7 = iVar6 % 100;
      uVar4 = (char)iVar7 + 0xff;
      sprintf(logstr,DAT_000399f8,iVar6,iVar7);
      writeInitLogFile(logstr);
      if (*(int *)(*DAT_000399fc + (iVar7 + 1) * 4) == 1) {
        bVar5 = get_pic_voltage(uVar4);
        iVar6 = ((int)(longlong)
                      (((DAT_00039b40 / ((double)(longlong)(int)(uint)bVar5 + DAT_00039b38) +
                        DAT_00039b48) * DAT_00039b50) / 4.75) / 10) * 10;
        if (iVar6 < 0x3a3) {
          iVar8 = iVar6 + 10;
        }
        else {
          sprintf(logstr,DAT_00039b64,iVar7,iVar6);
          iVar8 = 0x3ac;
          writeInitLogFile(logstr);
        }
        sprintf(logstr,DAT_00039b58,iVar7,iVar6,iVar8);
        writeInitLogFile(logstr);
        dVar10 = DAT_00039b40 / (((double)(longlong)iVar8 * 4.75) / DAT_00039b50 - DAT_00039b48) -
                 DAT_00039b38;
        uVar9 = (uint)(0.0 < dVar10) * (int)(longlong)dVar10;
        sprintf(logstr,DAT_00039b5c,uVar9 & 0xff,iVar7);
        writeInitLogFile(logstr);
        set_pic_voltage(uVar4,(uchar)uVar9);
        return;
      }
    }
    else {
      if (0xf < iVar6 - 0xc9U) {
        return;
      }
      saveTestID(0);
      iVar7 = iVar6 % 100;
      uVar4 = (char)iVar7 + 0xff;
      sprintf(logstr,DAT_00039a04,iVar6,iVar7);
      writeInitLogFile(logstr);
      if (*(int *)(*DAT_000399fc + (iVar7 + 1) * 4) == 1) {
        bVar5 = get_pic_voltage(uVar4);
        iVar6 = ((int)(longlong)
                      (((DAT_000399e0 / ((double)(longlong)(int)(uint)bVar5 + DAT_000399d8) +
                        DAT_000399e8) * DAT_000399f0) / 4.75) / 10) * 10;
        if (iVar6 < 0x366) {
          sprintf(logstr,DAT_00039b60,iVar7,iVar6);
          set_vol_value = 0x35c;
          writeInitLogFile(logstr);
        }
        else {
          set_vol_value = iVar6 + -10;
        }
        sprintf(logstr,DAT_00039a08,iVar7,iVar6,set_vol_value);
        writeInitLogFile(logstr);
        dVar10 = DAT_000399e0 /
                 (((double)(longlong)set_vol_value * 4.75) / DAT_000399f0 - DAT_000399e8) -
                 DAT_000399d8;
        uVar9 = (uint)(0.0 < dVar10) * (int)(longlong)dVar10;
        sprintf(logstr,DAT_00039a0c,uVar9 & 0xff,iVar7);
        writeInitLogFile(logstr);
        set_pic_voltage(uVar4,(uchar)uVar9);
        return;
      }
    }
    sprintf(logstr,DAT_00039a00,iVar6 % 100);
    writeInitLogFile(logstr);
  }
  return;
}

