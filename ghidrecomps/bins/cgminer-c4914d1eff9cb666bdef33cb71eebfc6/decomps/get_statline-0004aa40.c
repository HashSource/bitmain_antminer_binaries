
void get_statline(char *buf,size_t bufsiz,cgpu_info *cgpu)

{
  size_t sVar1;
  int iVar2;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 extraout_s1;
  DFtype a;
  UDItype val;
  UDItype val_00;
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
  uVar7 = __aeabi_l2d((int)cgpu->diff1,*(undefined4 *)((int)&cgpu->diff1 + 4));
  val = __fixunsdfdi((DFtype)CONCAT44(extraout_s1,uVar7));
  val_00 = __fixunsdfdi(a);
  suffix_string(val,displayed_hashes,0x10,4);
  suffix_string(val_00,displayed_rolling,0x10,4);
  snprintf(buf,bufsiz,"%s%d ",cgpu->drv->name,cgpu->device_id);
  (*cgpu->drv->get_statline_before)(buf,bufsiz,cgpu);
  sVar1 = strlen(buf);
  uVar5 = *(undefined4 *)&cgpu->diff_accepted;
  uVar6 = *(undefined4 *)((int)&cgpu->diff_accepted + 4);
  uVar7 = *(undefined4 *)&cgpu->diff_rejected;
  uVar4 = *(undefined4 *)((int)&cgpu->diff_rejected + 4);
  iVar2 = cgpu->hw_errors;
  snprintf(tmp13,0x40,"(%ds):%s (avg):%sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m",opt_log_interval,
           displayed_rolling,displayed_hashes,uVar5,uVar6,uVar7,uVar4,iVar2);
  sVar3 = strlen(tmp13);
  if (bufsiz <= sVar3 + sVar1) {
    snprintf(tmp42,0x800,"tailsprintf buffer overflow in %s %s line %d","cgminer.c","get_statline",
             0xc15,uVar5,uVar6,uVar7,uVar4,iVar2);
    _applog(3,tmp42,true);
    _quit(1);
  }
  strcat(buf,tmp13);
  (*cgpu->drv->get_statline)(buf,bufsiz,cgpu);
  return;
}

