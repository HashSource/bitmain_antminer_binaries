
void set_time_control_by_frq(undefined4 param_1)

{
  FILE *pFVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: set_time_control_by_frq freqency = %d\n","board_frq_tuning.c",0x1d3,
              param_1);
    }
    fclose(pFVar1);
  }
  uVar2 = calculate_core_number(0x72);
  iVar3 = __aeabi_idiv(0x1000000,uVar2);
  iVar3 = __aeabi_idiv(iVar3 << 1,param_1);
  conf._20_4_ = (iVar3 * 7) / 100;
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: freq=%d\n","board_frq_tuning.c",0x1d8,param_1);
    }
    fclose(pFVar1);
  }
  if (3 < log_level) {
    pFVar1 = fopen(log_file,"a+");
    if (pFVar1 != (FILE *)0x0) {
      fprintf(pFVar1,"%s:%d: set real timeout %d, need sleep=%d\n","board_frq_tuning.c",0x1d9,
              conf._20_4_,(conf._4_4_ + conf._44_4_) * conf._20_4_);
    }
    fclose(pFVar1);
  }
  set_time_out_control(conf._20_4_);
  return;
}

