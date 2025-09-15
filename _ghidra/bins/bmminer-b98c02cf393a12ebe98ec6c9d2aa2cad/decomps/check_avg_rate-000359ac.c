
undefined4 check_avg_rate(void)

{
  int iVar1;
  uint uVar2;
  FILE *pFVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  int unaff_r8;
  undefined4 uVar7;
  undefined4 extraout_s1;
  double dVar8;
  double dVar9;
  
  uVar7 = getAVGhashrate();
  dVar9 = (double)CONCAT44(extraout_s1,uVar7);
  if (3 < log_level) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: avg_rate = %d, ideal_total_hash_rate = %d\n","driver-btm-c5.c",
              0x27ea,"check_avg_rate",(int)(longlong)dVar9,ideal_total_hash_rate);
    }
    fclose(pFVar3);
  }
  uVar5 = log_level;
  dVar8 = (double)(longlong)ideal_total_hash_rate;
  if (((int)((uint)(dVar9 < dVar8 + 450.0) << 0x1f) < 0) && (dVar8 < dVar9)) {
    if (log_level < 4) {
      return 1;
    }
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: avg hash rate is OK\n","driver-btm-c5.c",0x27ef,"check_avg_rate");
    }
LAB_00035c16:
    fclose(pFVar3);
    return 1;
  }
  if (adjust_num_14198 == 0) {
    dVar9 = (dVar9 - dVar8) - 450.0;
    if ((int)((uint)(dVar9 < 0.0) << 0x1f) < 0) {
      if (log_level < 6) {
        return 1;
      }
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: avg hash is not high\n","driver-btm-c5.c",0x2800,"check_avg_rate")
        ;
      }
      goto LAB_00035c16;
    }
    unaff_r8 = (int)(longlong)(dVar9 / (double)(longlong)((total_exist_chain_num * 0xe070) / 1000));
  }
  else {
    iVar1 = (uint)(dVar9 < dVar8) << 0x1f;
    if (iVar1 < 0) {
      unaff_r8 = -1;
    }
    if (-1 < iVar1) {
      unaff_r8 = 1;
    }
    iVar4 = offset_14197 + unaff_r8;
    offset_14197 = iVar4;
    iVar1 = __aeabi_idiv(500);
    if (iVar1 < iVar4 || iVar4 < 0) {
      if (uVar5 < 4) {
        return 0;
      }
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d:%s: offset overflow, offset = %d\n","driver-btm-c5.c",0x2814,
                "check_avg_rate",offset_14197);
      }
      fclose(pFVar3);
      return 0;
    }
  }
  if (3 < uVar5) {
    pFVar3 = fopen(log_file,"a+");
    if (pFVar3 != (FILE *)0x0) {
      fprintf(pFVar3,"%s:%d:%s: adjust steps = %d\n","driver-btm-c5.c",0x2819,"check_avg_rate",
              unaff_r8);
    }
    fclose(pFVar3);
  }
  uVar5 = 0;
  puVar6 = freq_table;
  do {
    while (*(int *)(dev + (uVar5 + 2) * 4) == 1) {
      uVar2 = uVar5 & 0xff;
      uVar5 = uVar5 + 1;
      down_freq_n_steps(uVar2,puVar6,unaff_r8);
      puVar6 = puVar6 + 0x400;
      if (uVar5 == 0x10) goto LAB_00035aae;
    }
    uVar5 = uVar5 + 1;
    puVar6 = puVar6 + 0x400;
  } while (uVar5 != 0x10);
LAB_00035aae:
  adjust_num_14198 = adjust_num_14198 + 1;
  return 0;
}

