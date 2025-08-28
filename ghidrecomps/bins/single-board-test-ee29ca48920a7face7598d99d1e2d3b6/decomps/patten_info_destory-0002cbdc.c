
void patten_info_destory(void)

{
  if (g_patten._88_4_ != 0) {
    free((void *)g_patten._88_4_);
  }
  if (g_patten._108_4_ != 0) {
    free((void *)g_patten._108_4_);
  }
  if (g_patten._116_4_ != 0) {
    free((void *)g_patten._116_4_);
  }
  pthread_mutex_destroy((pthread_mutex_t *)(g_patten + 0x84));
  return;
}

