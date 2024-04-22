
/* WARNING: Unknown calling convention */

void get_statline(char *buf,size_t bufsiz,cgpu_info *cgpu)

{
  size_t sVar1;
  size_t buflen;
  size_t sVar2;
  size_t len13;
  int iVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined4 in_stack_fffff73c;
  char displayed_hashes [16];
  char displayed_rolling [16];
  char tmp13 [64];
  char tmp42 [2048];
  
  dVar6 = DAT_00020308;
  dVar4 = cgpu_runtime(cgpu);
  __aeabi_l2d(*(undefined4 *)&cgpu->diff1,*(undefined4 *)((int)&cgpu->diff1 + 4));
  dVar5 = cgpu->rolling * dVar6;
  uVar7 = __fixunsdfdi(SUB84(dVar5,0),(int)((ulonglong)dVar5 >> 0x20));
  dVar6 = (cgpu->total_mhashes / dVar4) * dVar6;
  uVar8 = __fixunsdfdi(SUB84(dVar6,0),(int)((ulonglong)dVar6 >> 0x20));
  suffix_string(CONCAT44(in_stack_fffff73c,4),(char *)uVar8,(size_t)((ulonglong)uVar8 >> 0x20),
                (int)displayed_hashes);
  suffix_string(CONCAT44(in_stack_fffff73c,4),(char *)uVar7,(size_t)((ulonglong)uVar7 >> 0x20),
                (int)displayed_rolling);
  snprintf(buf,bufsiz,DAT_00020318,cgpu->drv->name,cgpu->device_id);
  (*cgpu->drv->get_statline_before)(buf,bufsiz,cgpu);
  sVar1 = strlen(buf);
  iVar3 = cgpu->hw_errors;
  dVar4 = cgpu->diff_accepted;
  dVar6 = cgpu->diff_rejected;
  snprintf(tmp13,0x40,DAT_00020320,*(undefined4 *)(DAT_0002031c + 0x7f8),displayed_rolling,
           displayed_hashes,dVar4,dVar6,iVar3);
  sVar2 = strlen(tmp13);
  len13 = sVar2 + sVar1;
  if (bufsiz <= len13) {
    snprintf(tmp42,0x800,DAT_00020328,DAT_0002032c,DAT_00020324,0xbda,dVar4,dVar6,iVar3);
    _applog(3,tmp42,true);
    _quit(1);
  }
  strcat(buf,tmp13);
  (*cgpu->drv->get_statline)(buf,bufsiz,cgpu);
  return;
}

