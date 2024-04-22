
undefined4 is_patten_match(undefined4 param_1,void *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_14;
  
  pthread_mutex_lock(DAT_0002d1dc);
  iVar1 = memcmp((void *)(g_patten._92_4_ + g_patten._8_4_),param_2,g_patten._12_4_);
  iVar2 = memcmp((void *)(g_patten._92_4_ + g_patten._12_4_ + g_patten._8_4_),param_3,
                 g_patten._16_4_);
  if ((iVar1 == 0) && (iVar2 == 0)) {
    *(undefined *)
     (g_patten._104_4_ + g_patten._20_4_ * (g_patten._4_4_ * g_patten._96_4_ + g_patten._100_4_) +
     g_patten._108_4_) = 1;
    g_patten._112_4_ = g_patten._112_4_ + 1;
    g_patten._124_4_ =
         (float)(longlong)(int)g_patten._112_4_ / (float)(longlong)(int)g_patten._120_4_;
    piVar3 = (int *)(g_patten._96_4_ * 4 + g_patten._116_4_);
    *piVar3 = *piVar3 + 1;
    dump_str(stderr,"Match Recv:",param_2,g_patten._12_4_);
    dump_str(stderr,"Match Expect:",g_patten._92_4_ + g_patten._8_4_,g_patten._12_4_);
    printf("Patten Success Rate %.2f recv %d total %d asic %d recv %d\n",g_patten._120_4_,
           SUB84((double)((float)g_patten._124_4_ * DAT_0002d1e0),0),
           (int)((ulonglong)(double)((float)g_patten._124_4_ * DAT_0002d1e0) >> 0x20),
           g_patten._112_4_,g_patten._120_4_,g_patten._96_4_,
           *(undefined4 *)(g_patten._96_4_ * 4 + g_patten._116_4_));
    local_14 = 0;
  }
  else {
    local_14 = 0xffffffff;
  }
  pthread_mutex_unlock(DAT_0002d1dc);
  return local_14;
}

