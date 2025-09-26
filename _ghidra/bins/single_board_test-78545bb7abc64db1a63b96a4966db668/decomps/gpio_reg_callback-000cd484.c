
/* WARNING: Unknown calling convention */

int32_t gpio_reg_callback(uint32_t port,bitmain_gpio_callback function)

{
  int iVar1;
  clib_bool cVar2;
  int32_t iVar3;
  uint32_t local_81c;
  gpio_callback_t val;
  
  local_81c = port;
  if (function == (bitmain_gpio_callback)0x0) {
    iVar3 = -1;
    val.function = (bitmain_gpio_callback)0x20646162;
    val.last._0_1_ = 'p';
    val.last._1_1_ = 'a';
    val.last._2_1_ = 'r';
    val.last._3_1_ = 'a';
    _applog(0,(char *)&val,false);
  }
  else {
    if (gpio_inited == 0) {
      pthread_mutex_init((pthread_mutex_t *)&gpio_ctrl_map,(pthread_mutexattr_t *)0x0);
      gpio_ctrl_map.gpio_callback_map =
           new_c_map((clib_compare)0xcd475,(clib_destroy)0x0,(clib_destroy)0x0);
      pthread_mutex_init((pthread_mutex_t *)&api_mutex,(pthread_mutexattr_t *)0x0);
      gpio_thread = 1;
      pthread_attr_init((pthread_attr_t *)&val);
      pthread_attr_setstacksize((pthread_attr_t *)&val,0x200000);
      pthread_create(&thread,(pthread_attr_t *)&val,(__start_routine *)0xcdacd,(void *)0x0);
      gpio_inited = 1;
    }
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)&gpio_ctrl_map);
    if (iVar1 == 0) {
      cVar2 = exists_c_map(gpio_ctrl_map.gpio_callback_map,&local_81c);
      if (cVar2 == 0) {
        val.last = 0xffffffff;
        val.function = function;
        insert_c_map(gpio_ctrl_map.gpio_callback_map,&local_81c,4,&val,8);
      }
      pthread_mutex_unlock((pthread_mutex_t *)&gpio_ctrl_map);
      iVar3 = 0;
    }
    else {
      iVar3 = -1;
      val.function = (bitmain_gpio_callback)0x6c696166;
      val.last._0_1_ = ' ';
      val.last._1_1_ = 't';
      val.last._2_1_ = 'o';
      val.last._3_1_ = ' ';
      _applog(0,(char *)&val,false);
    }
  }
  return iVar3;
}

