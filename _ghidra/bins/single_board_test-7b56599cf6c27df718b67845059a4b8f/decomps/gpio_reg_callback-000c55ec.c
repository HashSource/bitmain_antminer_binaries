
/* WARNING: Unknown calling convention */

int32_t gpio_reg_callback(uint32_t port,bitmain_gpio_callback function)

{
  int iVar1;
  clib_bool cVar2;
  int32_t iVar3;
  uint32_t local_81c;
  pthread_attr_t tattr_ctrl;
  
  local_81c = port;
  if (function == (bitmain_gpio_callback)0x0) {
    iVar3 = -1;
    tattr_ctrl._0_1_ = 'b';
    tattr_ctrl._1_1_ = 'a';
    tattr_ctrl._2_1_ = 'd';
    tattr_ctrl._3_1_ = ' ';
    tattr_ctrl._4_1_ = 'p';
    tattr_ctrl._5_1_ = 'a';
    tattr_ctrl._6_1_ = 'r';
    tattr_ctrl._7_1_ = 'a';
    tattr_ctrl._8_3_ = 0xa6d;
    _applog(0,tattr_ctrl.__size,false);
  }
  else {
    if (gpio_inited == 0) {
      pthread_mutex_init((pthread_mutex_t *)&gpio_ctrl_map,(pthread_mutexattr_t *)0x0);
      gpio_ctrl_map.gpio_callback_map =
           new_c_map((clib_compare)0xc55dd,(clib_destroy)0x0,(clib_destroy)0x0);
      pthread_mutex_init((pthread_mutex_t *)&api_mutex,(pthread_mutexattr_t *)0x0);
      gpio_thread = 1;
      pthread_attr_init((pthread_attr_t *)&tattr_ctrl);
      pthread_attr_setstacksize((pthread_attr_t *)&tattr_ctrl,0x200000);
      pthread_create(&thread,(pthread_attr_t *)&tattr_ctrl,(__start_routine *)0xc5c2d,(void *)0x0);
      gpio_inited = 1;
    }
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)&gpio_ctrl_map);
    if (iVar1 == 0) {
      cVar2 = exists_c_map(gpio_ctrl_map.gpio_callback_map,&local_81c);
      if (cVar2 == 0) {
        tattr_ctrl._4_4_ = 0xffffffff;
        tattr_ctrl.__align = (long)function;
        insert_c_map(gpio_ctrl_map.gpio_callback_map,&local_81c,4,&tattr_ctrl,8);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&gpio_ctrl_map);
      iVar3 = 0;
    }
    else {
      iVar3 = -1;
      tattr_ctrl._0_1_ = 'f';
      tattr_ctrl._1_1_ = 'a';
      tattr_ctrl._2_1_ = 'i';
      tattr_ctrl._3_1_ = 'l';
      tattr_ctrl._4_1_ = ' ';
      tattr_ctrl._5_1_ = 't';
      tattr_ctrl._6_1_ = 'o';
      tattr_ctrl._7_1_ = ' ';
      tattr_ctrl._8_1_ = 'l';
      tattr_ctrl._9_1_ = 'o';
      tattr_ctrl._10_1_ = 'c';
      tattr_ctrl._11_1_ = 'k';
      tattr_ctrl._12_1_ = ' ';
      tattr_ctrl._13_1_ = 'g';
      tattr_ctrl._14_1_ = 'p';
      tattr_ctrl._15_1_ = 'i';
      tattr_ctrl._16_1_ = 'o';
      tattr_ctrl._17_1_ = ' ';
      tattr_ctrl._18_1_ = 'c';
      tattr_ctrl._19_1_ = 't';
      tattr_ctrl._20_1_ = 'r';
      tattr_ctrl._21_1_ = 'l';
      tattr_ctrl._22_1_ = ' ';
      tattr_ctrl._23_1_ = 'm';
      tattr_ctrl._24_1_ = 'u';
      tattr_ctrl._25_1_ = 't';
      tattr_ctrl._26_1_ = 'e';
      tattr_ctrl._27_1_ = 'x';
      tattr_ctrl._28_2_ = 10;
      _applog(0,tattr_ctrl.__size,false);
    }
  }
  return iVar3;
}

