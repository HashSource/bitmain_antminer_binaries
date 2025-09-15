
void gpio_uninit(void)

{
  if (gpio_inited != 0) {
    gpio_thread = 0;
    pthread_join(thread,(void **)0x0);
    pthread_mutex_destroy((pthread_mutex_t *)gpio_ctrl_map);
    delete_c_map(gpio_ctrl_map._24_4_);
    gpio_inited = 0;
    pthread_mutex_destroy((pthread_mutex_t *)api_mutex);
  }
  return;
}

