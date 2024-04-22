
undefined4 check_avg_rate(void)

{
  int iVar1;
  FILE *pFVar2;
  uint uVar3;
  uint uVar4;
  int unaff_r8;
  double dVar5;
  double dVar6;
  
  dVar5 = (double)getAVGhashrate();
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: avg_rate = %d, ideal_total_hash_rate = %d\n","driver-btm-c5.c",
              0x27ea,DAT_00035c7c,(int)(longlong)dVar5,ideal_total_hash_rate);
    }
    fclose(pFVar2);
  }
  uVar4 = log_level;
  dVar6 = (double)(longlong)ideal_total_hash_rate;
  if (((int)((uint)(dVar5 < dVar6 + DAT_00035c70) << 0x1f) < 0) &&
     (dVar5 != dVar6 && dVar5 < dVar6 == (NAN(dVar5) || NAN(dVar6)))) {
    if (log_level < 4) {
      return 1;
    }
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: avg hash rate is OK\n","driver-btm-c5.c",0x27ef,DAT_00035c7c);
    }
LAB_00035c16:
    fclose(pFVar2);
    return 1;
  }
  if (adjust_num_14198 == 0) {
    dVar5 = (dVar5 - dVar6) - DAT_00035c70;
    if ((int)((uint)(dVar5 < 0.0) << 0x1f) < 0) {
      if (log_level < 6) {
        return 1;
      }
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: avg hash is not high\n","driver-btm-c5.c",0x2800,DAT_00035c7c);
      }
      goto LAB_00035c16;
    }
    unaff_r8 = (int)(longlong)(dVar5 / (double)(longlong)((total_exist_chain_num * 0xe070) / 1000));
  }
  else {
    iVar1 = (uint)(dVar5 < dVar6) << 0x1f;
    if (iVar1 < 0) {
      unaff_r8 = -1;
    }
    if (-1 < iVar1) {
      unaff_r8 = 1;
    }
    uVar3 = offset_14197 + unaff_r8;
    offset_14197 = uVar3;
    iVar1 = __aeabi_idiv(500);
    if (((uint)(iVar1 < (int)uVar3) | uVar3 >> 0x1f) != 0) {
      if (uVar4 < 4) {
        return 0;
      }
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: offset overflow, offset = %d\n","driver-btm-c5.c",0x2814,
                DAT_00035c7c,offset_14197);
      }
      fclose(pFVar2);
      return 0;
    }
  }
  if (3 < uVar4) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: adjust steps = %d\n","driver-btm-c5.c",0x2819,DAT_00035c7c,unaff_r8)
      ;
    }
    fclose(pFVar2);
  }
  uVar4 = 0;
  iVar1 = DAT_00035c78;
  do {
    while (*(int *)(dev + (uVar4 + 2) * 4) == 1) {
      uVar3 = uVar4 & 0xff;
      uVar4 = uVar4 + 1;
      down_freq_n_steps(uVar3,iVar1,unaff_r8);
      iVar1 = iVar1 + 0x400;
      if (uVar4 == 0x10) goto LAB_00035aae;
    }
    uVar4 = uVar4 + 1;
    iVar1 = iVar1 + 0x400;
  } while (uVar4 != 0x10);
LAB_00035aae:
  adjust_num_14198 = adjust_num_14198 + 1;
  return 0;
}

