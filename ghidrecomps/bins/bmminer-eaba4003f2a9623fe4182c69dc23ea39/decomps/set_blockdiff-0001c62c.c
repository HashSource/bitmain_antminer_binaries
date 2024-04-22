
void set_blockdiff(work *work)

{
  double dVar1;
  uint __bsx;
  uint uVar2;
  double dVar3;
  undefined8 uVar4;
  uint in_stack_fffff7bc;
  work *work_local;
  char tmp42 [2048];
  double ddiff;
  double numerator;
  uint diff32;
  uchar pow;
  int powdiff;
  
  powdiff = (0x1d - (uint)work->data[0x48]) * 8;
  if (powdiff < 8) {
    powdiff = 8;
  }
  uVar2 = *(uint *)(work->data + 0x48);
  dVar3 = (double)__aeabi_ul2d(0xffff << (powdiff & 0xffU),
                               0 << (powdiff & 0xffU) | 0xffff << (powdiff - 0x20U & 0xff) |
                               0xffffU >> (0x20U - powdiff & 0xff));
  dVar3 = dVar3 / (double)(ulonglong)
                          (uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8);
  dVar1 = (double)CONCAT44(current_diff._4_4_,current_diff._0_4_);
  if ((double)CONCAT44(current_diff._4_4_,current_diff._0_4_) != dVar3) {
    ddiff._0_4_ = SUB84(dVar3,0);
    ddiff._4_4_ = (undefined4)((ulonglong)dVar3 >> 0x20);
    uVar4 = __fixunsdfdi(ddiff._0_4_,ddiff._4_4_);
    suffix_string((ulonglong)in_stack_fffff7bc << 0x20,(char *)uVar4,
                  (size_t)((ulonglong)uVar4 >> 0x20),0x8b158);
    if (((use_syslog != false) || (opt_log_output != false)) || (dVar1 = dVar3, 4 < opt_log_level))
    {
      current_diff = dVar3;
      snprintf(tmp42,0x800,"Network diff set to %s",block_diff);
      _applog(5,tmp42,false);
      dVar1 = current_diff;
    }
  }
  current_diff._4_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
  current_diff._0_4_ = SUB84(dVar1,0);
  return;
}

