
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void processTEST(void)

{
  uchar uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  double dVar7;
  char logstr [256];
  
  iVar3 = readTestID();
  if (iVar3 == 0xb) {
    saveTestID(0);
    sprintf(logstr,"get TEST ID=%d do 8xPatten test\n",0xb);
    writeInitLogFile(logstr);
    do8xPattenTest();
  }
  else if (iVar3 == 0xc) {
    saveTestID(0);
    sprintf(logstr,"get TEST ID=%d do bitmain_core_reInit test\n",0xc);
    writeInitLogFile(logstr);
    bitmain_core_reInit();
    reCalculateAVG();
    builtin_strncpy(logstr,"Done bitmain_core_reInit tes",0x1c);
    logstr[0x1c] = 't';
    logstr[0x1d] = '\n';
    logstr[0x1e] = '\0';
    writeInitLogFile(logstr);
  }
  else if (iVar3 == 0xd) {
    saveTestID(0);
    sprintf(logstr,"get TEST ID=%d do doReInitTest test\n",0xd);
    writeInitLogFile(logstr);
    doReInitTest();
    reCalculateAVG();
    builtin_strncpy(logstr,"Done doReInitTest test\n",0x18);
    writeInitLogFile(logstr);
  }
  else if (iVar3 == 0xe) {
    saveTestID(0);
    sprintf(logstr,"get TEST ID=%d do do get asicnum\n",0xe);
    writeInitLogFile(logstr);
    iVar3 = 1;
    do {
      while( true ) {
        iVar4 = iVar3 + 1;
        if (dev->chain_exist[iVar3 + -1] != 1) break;
        *(undefined1 *)((int)dev->temp + iVar3 + 0x3f) = 0;
        check_asic_reg_oneChain(iVar3 + -1,0);
        sprintf(logstr,"Chain[J%d] has %d asic\n",iVar3,
                (uint)*(byte *)((int)dev->temp + iVar3 + 0x3f));
        writeInitLogFile(logstr);
        iVar3 = iVar4;
        if (iVar4 == 0x11) goto LAB_0003992a;
      }
      iVar3 = iVar4;
    } while (iVar4 != 0x11);
LAB_0003992a:
    builtin_strncpy(logstr,"Done do get asicnum\n",0x14);
    logstr._20_4_ = logstr._20_4_ & 0xffffff00;
    writeInitLogFile(logstr);
  }
  else {
    if (iVar3 - 0x65U < 0x10) {
      saveTestID(0);
      iVar4 = iVar3 % 100;
      uVar1 = (char)iVar4 + 0xff;
      sprintf(logstr,"get TEST ID=%d up voltage 0.1V on Chain[J%d]\n",iVar3,iVar4);
      writeInitLogFile(logstr);
      if (dev->chain_exist[iVar4 + -1] == 1) {
        bVar2 = get_pic_voltage(uVar1);
        iVar3 = ((int)(longlong)(((364.0704 / ((double)bVar2 + 30.72) + 32.79) * 100.0) / 4.75) / 10
                ) * 10;
        if (iVar3 < 0x3a3) {
          iVar5 = iVar3 + 10;
        }
        else {
          sprintf(logstr,"Chain[J%d] current vol=%d , too high! will set to 940\n",iVar4,iVar3);
          iVar5 = 0x3ac;
          writeInitLogFile(logstr);
        }
        sprintf(logstr,"Try to up 0.1V on chain[J%d] from vol=%d to %d...\n",iVar4,iVar3,iVar5);
        writeInitLogFile(logstr);
        dVar7 = 364.0704 / (((double)(longlong)iVar5 * 4.75) / 100.0 - 32.79) - 30.72;
        uVar6 = (uint)(0.0 < dVar7) * (int)(longlong)dVar7;
        sprintf(logstr,"now set pic voltage=%d on chain[J%d]\n",uVar6 & 0xff,iVar4);
        writeInitLogFile(logstr);
        set_pic_voltage(uVar1,(uchar)uVar6);
        return;
      }
    }
    else {
      if (0xf < iVar3 - 0xc9U) {
        return;
      }
      saveTestID(0);
      iVar4 = iVar3 % 100;
      uVar1 = (char)iVar4 + 0xff;
      sprintf(logstr,"get TEST ID=%d down voltage 0.1V on Chain[J%d]\n",iVar3,iVar4);
      writeInitLogFile(logstr);
      if (dev->chain_exist[iVar4 + -1] == 1) {
        bVar2 = get_pic_voltage(uVar1);
        iVar3 = ((int)(longlong)(((364.0704 / ((double)bVar2 + 30.72) + 32.79) * 100.0) / 4.75) / 10
                ) * 10;
        if (iVar3 < 0x366) {
          sprintf(logstr,"Chain[J%d] current vol=%d , too low! will set to 860\n",iVar4,iVar3);
          iVar5 = 0x35c;
          writeInitLogFile(logstr);
        }
        else {
          iVar5 = iVar3 + -10;
        }
        sprintf(logstr,"Try to down 0.1V on chain[J%d] from vol=%d to %d...\n",iVar4,iVar3,iVar5);
        writeInitLogFile(logstr);
        dVar7 = 364.0704 / (((double)(longlong)iVar5 * 4.75) / 100.0 - 32.79) - 30.72;
        uVar6 = (uint)(0.0 < dVar7) * (int)(longlong)dVar7;
        sprintf(logstr,"now set pic voltage=%d on chain[J%d]\n",uVar6 & 0xff,iVar4);
        writeInitLogFile(logstr);
        set_pic_voltage(uVar1,(uchar)uVar6);
        return;
      }
    }
    sprintf(logstr,"There is hashboard on Chain[J%d]\n",iVar3 % 100);
    writeInitLogFile(logstr);
  }
  return;
}

