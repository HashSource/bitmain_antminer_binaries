
/* WARNING: Unknown calling convention */

void get_statline(char *buf,size_t bufsiz,cgpu_info *cgpu)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  double dVar4;
  double dVar5;
  uint64_t val;
  uint64_t val_00;
  char displayed_hashes [16];
  char displayed_rolling [16];
  char tmp13 [64];
  char tmp42 [2048];
  
  dVar4 = cgpu_runtime(cgpu);
  __aeabi_l2d((int)cgpu->diff1,*(undefined4 *)((int)&cgpu->diff1 + 4));
  dVar5 = cgpu->rolling * 1000000.0;
  val = __fixunsdfdi(SUB84(dVar5,0),(int)((ulonglong)dVar5 >> 0x20));
  dVar4 = (cgpu->total_mhashes / dVar4) * 1000000.0;
  val_00 = __fixunsdfdi(SUB84(dVar4,0),(int)((ulonglong)dVar4 >> 0x20));
  suffix_string(val_00,displayed_hashes,0x10,4);
  suffix_string(val,displayed_rolling,0x10,4);
  snprintf(buf,bufsiz,"%s%d ",cgpu->drv->name,cgpu->device_id);
  (*cgpu->drv->get_statline_before)(buf,bufsiz,cgpu);
  sVar1 = strlen(buf);
  iVar3 = cgpu->hw_errors;
  dVar5 = cgpu->diff_accepted;
  dVar4 = cgpu->diff_rejected;
  snprintf(tmp13,0x40,"(%ds):%s (avg):%sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m",opt_log_interval,
           displayed_rolling,displayed_hashes,dVar5,dVar4,iVar3);
  sVar2 = strlen(tmp13);
  if (bufsiz <= sVar2 + sVar1) {
    snprintf(tmp42,0x800,"tailsprintf buffer overflow in %s %s line %d","cgminer.c","get_statline",
             0xbda,dVar5,dVar4,iVar3);
    _applog(3,tmp42,true);
    _quit(1);
  }
  strcat(buf,tmp13);
  (*cgpu->drv->get_statline)(buf,bufsiz,cgpu);
  return;
}

