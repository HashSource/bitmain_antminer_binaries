
int ENGINE_ctrl(ENGINE *e,int cmd,long i,void *p,f *f)

{
  uint *puVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  code *UNRECOVERED_JUMPTABLE;
  uint *puVar8;
  int iVar9;
  
  if (e == (ENGINE *)0x0) {
    ERR_put_error(0x26,0x8e,0x43,"crypto/engine/eng_ctrl.c",0x81);
    return 0;
  }
  CRYPTO_THREAD_write_lock(global_engine_lock);
  DataMemoryBarrier(0x1b);
  iVar9 = *(int *)(e + 0x50);
  DataMemoryBarrier(0x1b);
  CRYPTO_THREAD_unlock(global_engine_lock);
  UNRECOVERED_JUMPTABLE = *(code **)(e + 0x38);
  if (iVar9 < 1) {
    ERR_put_error(0x26,0x8e,0x82,"crypto/engine/eng_ctrl.c",0x89);
    return 0;
  }
  if (cmd == 10) {
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      return 0;
    }
    return 1;
  }
  if ((cmd < 10) || (0x12 < cmd)) {
    if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
      ERR_put_error(0x26,0x8e,0x78,"crypto/engine/eng_ctrl.c",0xab);
      return 0;
    }
LAB_001bb956:
                    /* WARNING: Could not recover jumptable at 0x001bb96a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar9 = (*UNRECOVERED_JUMPTABLE)(e,cmd,i,p);
    return iVar9;
  }
  if (UNRECOVERED_JUMPTABLE == (code *)0x0) {
    ERR_put_error(0x26,0x8e,0x78,"crypto/engine/eng_ctrl.c",0x9e);
    return -1;
  }
  if ((*(uint *)(e + 0x4c) & 2) != 0) goto LAB_001bb956;
  if (cmd == 0xb) {
    piVar7 = *(int **)(e + 0x48);
    if (piVar7 == (int *)0x0) {
      return 0;
    }
    if (*piVar7 == 0) {
      return 0;
    }
    if (piVar7[1] == 0) {
      return 0;
    }
    return *piVar7;
  }
  if ((cmd == 0x11 || (cmd & 0xfffffffdU) == 0xd) && (p == (void *)0x0)) {
    ERR_put_error(0x26,0xac,0x43,"crypto/engine/eng_ctrl.c",0x4f);
    return -1;
  }
  puVar8 = *(uint **)(e + 0x48);
  if (cmd == 0xd) {
    if ((puVar8 != (uint *)0x0) && (*puVar8 != 0)) {
      iVar9 = 0;
      pcVar3 = (char *)puVar8[1];
      puVar6 = puVar8;
      while (pcVar3 != (char *)0x0) {
        iVar4 = strcmp(pcVar3,(char *)p);
        if (iVar4 == 0) {
          return puVar8[iVar9 * 4];
        }
        iVar9 = iVar9 + 1;
        if (puVar6[4] == 0) break;
        pcVar3 = (char *)puVar6[5];
        puVar6 = puVar6 + 4;
      }
    }
    ERR_put_error(0x26,0xac,0x89,"crypto/engine/eng_ctrl.c",0x57);
    return -1;
  }
  if (puVar8 == (uint *)0x0) {
LAB_001bba14:
    ERR_put_error(0x26,0xac,0x8a,"crypto/engine/eng_ctrl.c",0x62);
    return -1;
  }
  uVar5 = *puVar8;
  if (uVar5 == 0) {
    iVar9 = 0;
  }
  else if (puVar8[1] == 0 || (uint)i <= uVar5) {
    iVar9 = 0;
  }
  else {
    iVar9 = 0;
    puVar6 = puVar8;
    do {
      uVar5 = puVar6[4];
      iVar9 = iVar9 + 1;
      if (uVar5 == 0) break;
      puVar1 = puVar6 + 5;
      puVar6 = puVar6 + 4;
    } while (*puVar1 != 0 && uVar5 < (uint)i);
  }
  if (i != uVar5) goto LAB_001bba14;
  switch(cmd) {
  case 0xc:
    uVar5 = 0;
    if ((puVar8[iVar9 * 4 + 4] != 0) && (puVar8[iVar9 * 4 + 5] != 0)) {
      uVar5 = puVar8[iVar9 * 4 + 4];
    }
    break;
  default:
    ERR_put_error(0x26,0xac,0x6e,"crypto/engine/eng_ctrl.c",0x79);
    uVar5 = 0xffffffff;
    break;
  case 0xe:
    pcVar3 = (char *)puVar8[iVar9 * 4 + 1];
    goto LAB_00016610;
  case 0xf:
    pcVar3 = (char *)puVar8[iVar9 * 4 + 1];
    goto LAB_001bba4c;
  case 0x10:
    pcVar3 = (char *)puVar8[iVar9 * 4 + 2];
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "";
    }
    goto LAB_00016610;
  case 0x11:
    pcVar3 = (char *)puVar8[iVar9 * 4 + 2];
    if (pcVar3 == (char *)0x0) {
      pcVar3 = "";
    }
LAB_001bba4c:
    pcVar3 = strcpy((char *)p,pcVar3);
LAB_00016610:
    sVar2 = strlen(pcVar3);
    return sVar2;
  case 0x12:
    uVar5 = puVar8[iVar9 * 4 + 3];
  }
  return uVar5;
}

