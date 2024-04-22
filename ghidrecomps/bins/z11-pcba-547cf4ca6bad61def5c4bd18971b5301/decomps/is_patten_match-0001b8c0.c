
undefined4 is_patten_match(int param_1,void *param_2,void *param_3)

{
  int iVar1;
  int iVar2;
  
  if (g_patten._96_4_ == param_1) {
    iVar1 = memcmp((void *)(g_patten._92_4_ + g_patten._8_4_),param_2,g_patten._12_4_);
    iVar2 = memcmp((void *)(g_patten._92_4_ + g_patten._12_4_ + g_patten._8_4_),param_3,
                   g_patten._16_4_);
    if ((iVar1 == 0) && (iVar2 == 0)) {
      pthread_mutex_lock(DAT_0001ba0c);
      *(undefined *)
       (g_patten._104_4_ + g_patten._20_4_ * (g_patten._4_4_ * g_patten._96_4_ + g_patten._100_4_) +
       g_patten._108_4_) = 1;
      g_patten._112_4_ = g_patten._112_4_ + 1;
      pthread_mutex_unlock(DAT_0001ba0c);
      return 0;
    }
  }
  dump_str(stderr,"Not Match Golden:",param_2,g_patten._12_4_);
  dump_str(stderr,"Not Match Recv:",param_3,g_patten._16_4_);
  return 1;
}

