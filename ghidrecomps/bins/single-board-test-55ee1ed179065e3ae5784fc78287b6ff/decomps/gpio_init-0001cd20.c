
undefined4 gpio_init(void)

{
  if (gpio_inited == 0) {
    pthread_mutex_init((pthread_mutex_t *)gpio_ctrl_map,(pthread_mutexattr_t *)0x0);
    gpio_ctrl_map._24_4_ = new_c_map(0x1cba1,0,0);
    pthread_mutex_init((pthread_mutex_t *)api_mutex,(pthread_mutexattr_t *)0x0);
    gpio_thread = 1;
    pthread_create(&thread,(pthread_attr_t *)0x0,gpio_thread_function + 1,(void *)0x0);
    gpio_inited = 1;
  }
  else {
    printf("%s:%d","gpio_init",0x4e);
    puts("gpio re init");
  }
  return 0;
}

