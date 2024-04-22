
void get_statline(char *buf,size_t bufsiz,cgpu_info *cgpu)

{
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  double dVar8;
  undefined8 uVar9;
  undefined8 uVar10;
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
  
  dVar8 = cgpu_runtime(cgpu);
  __aeabi_l2d(*(undefined4 *)&cgpu->diff1,*(undefined4 *)((int)&cgpu->diff1 + 4));
  dVar8 = (cgpu->total_mhashes / dVar8) * DAT_0004b0e8;
  uVar9 = __fixunsdfdi(SUB84(dVar8,0),(int)((ulonglong)dVar8 >> 0x20));
  dVar8 = cgpu->rolling * DAT_0004b0e8;
  uVar10 = __fixunsdfdi(SUB84(dVar8,0),(int)((ulonglong)dVar8 >> 0x20));
  suffix_string(CONCAT44(in_stack_fffff72c,4),(char *)uVar9,(size_t)((ulonglong)uVar9 >> 0x20),
                (int)displayed_hashes);
  suffix_string(CONCAT44(in_stack_fffff72c,4),(char *)uVar10,(size_t)((ulonglong)uVar10 >> 0x20),
                (int)displayed_rolling);
  snprintf(buf,bufsiz,"%s%d ",cgpu->drv->name,cgpu->device_id);
  (*cgpu->drv->get_statline_before)(buf,bufsiz,cgpu);
  sVar1 = strlen(buf);
  uVar4 = *(undefined4 *)&cgpu->diff_accepted;
  uVar5 = *(undefined4 *)((int)&cgpu->diff_accepted + 4);
  uVar6 = *(undefined4 *)&cgpu->diff_rejected;
  uVar7 = *(undefined4 *)((int)&cgpu->diff_rejected + 4);
  iVar3 = cgpu->hw_errors;
  snprintf(tmp13,0x40,"(%ds):%s (avg):%sh/s | A:%.0f R:%.0f HW:%d WU:%.1f/m",opt_log_interval,
           displayed_rolling,displayed_hashes,uVar4,uVar5,uVar6,uVar7,iVar3);
  sVar2 = strlen(tmp13);
  if (bufsiz <= sVar1 + sVar2) {
    snprintf(tmp42,0x800,"tailsprintf buffer overflow in %s %s line %d","cgminer.c","get_statline",
             0xc11,uVar4,uVar5,uVar6,uVar7,iVar3);
    _applog(3,tmp42,true);
    _quit(1);
  }
  strcat(buf,tmp13);
  (*cgpu->drv->get_statline)(buf,bufsiz,cgpu);
  return;
}

