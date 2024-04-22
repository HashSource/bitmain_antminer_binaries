
void get_statline(char *buf,size_t bufsiz,cgpu_info *cgpu)

{
  size_t sVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  UDItype UVar8;
  UDItype UVar9;
  undefined4 in_stack_fffff728;
  undefined4 in_stack_fffff72c;
  cgpu_info *cgpu_local;
  size_t bufsiz_local;
  char *buf_local;
  char tmp13 [64];
  char tmp42 [2048];
  char displayed_rolling [16];
  char displayed_hashes [16];
  size_t len13;
  size_t buflen;
  uint64_t dr64;
  uint64_t dh64;
  double wu;
  double dev_runtime;
  
  cgpu_runtime(cgpu);
  __aeabi_l2d(*(undefined4 *)&cgpu->diff1,*(undefined4 *)((int)&cgpu->diff1 + 4));
  UVar8 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff72c,in_stack_fffff728));
  UVar9 = __fixunsdfdi((DFtype)CONCAT44(in_stack_fffff72c,in_stack_fffff728));
  dh64._0_4_ = (char *)UVar8;
  dh64._4_4_ = (size_t)(UVar8 >> 0x20);
  suffix_string(CONCAT44(in_stack_fffff72c,4),(char *)dh64,dh64._4_4_,(int)displayed_hashes);
  dr64._0_4_ = (char *)UVar9;
  dr64._4_4_ = (size_t)(UVar9 >> 0x20);
  suffix_string(CONCAT44(in_stack_fffff72c,4),(char *)dr64,dr64._4_4_,(int)displayed_rolling);
  snprintf(buf,bufsiz,"%s%d ",cgpu->drv->name,cgpu->device_id);
  (*cgpu->drv->get_statline_before)(buf,bufsiz,cgpu);
  sVar1 = strlen(buf);
  uVar6 = *(undefined4 *)&cgpu->diff_accepted;
  uVar7 = *(undefined4 *)((int)&cgpu->diff_accepted + 4);
  uVar4 = *(undefined4 *)&cgpu->diff_rejected;
  uVar5 = *(undefined4 *)((int)&cgpu->diff_rejected + 4);
  iVar2 = cgpu->hw_errors;
  snprintf(tmp13,0x40,"(%ds):%s (avg):%sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m",opt_log_interval,
           displayed_rolling,displayed_hashes,uVar6,uVar7,uVar4,uVar5,iVar2);
  sVar3 = strlen(tmp13);
  if (bufsiz <= sVar3 + sVar1) {
    snprintf(tmp42,0x800,"tailsprintf buffer overflow in %s %s line %d","cgminer.c","get_statline",
             0xc15,uVar6,uVar7,uVar4,uVar5,iVar2);
    _applog(3,tmp42,true);
    _quit(1);
  }
  strcat(buf,tmp13);
  (*cgpu->drv->get_statline)(buf,bufsiz,cgpu);
  return;
}

