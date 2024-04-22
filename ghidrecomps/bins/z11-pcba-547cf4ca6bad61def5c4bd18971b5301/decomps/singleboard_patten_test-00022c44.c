
void singleboard_patten_test(void)

{
  void *__ptr;
  int iVar1;
  int local_14;
  int local_10;
  int local_c;
  
  iVar1 = g_patten._16_4_ + g_patten._8_4_ + g_patten._12_4_;
  g_patten._124_4_ = 1;
  for (local_c = 0; local_c < (int)g_patten._0_4_; local_c = local_c + 1) {
    for (local_10 = 0; local_10 < (int)g_patten._4_4_; local_10 = local_10 + 1) {
      for (local_14 = 0; local_14 < (int)g_patten._20_4_; local_14 = local_14 + 1) {
        g_patten._92_4_ =
             g_patten._88_4_ +
             iVar1 * local_10 * g_patten._20_4_ + iVar1 * g_patten._20_4_ * local_c * g_patten._4_4_
             + iVar1 * local_14;
        __ptr = (void *)bin2hex(g_patten._92_4_,0x8c);
        g_patten._96_4_ = local_c;
        g_patten._100_4_ = local_10;
        g_patten._104_4_ = local_14;
        send_work(__ptr,1,0);
        free(__ptr);
        usleep(app_conf._432_4_ * 1000);
        pthread_mutex_lock(DAT_00022de0);
        g_patten._120_4_ = __aeabi_idiv(g_patten._112_4_,g_patten._116_4_);
        pthread_mutex_unlock(DAT_00022de0);
      }
    }
  }
  g_patten._124_4_ = 0;
  return;
}

