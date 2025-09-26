
/* WARNING: Unknown calling convention */

void * gpio_thread_function(void *args)

{
  int iVar1;
  clib_iterator *pItr;
  clib_object *pcVar2;
  undefined4 *__ptr;
  int32_t iVar3;
  void *pvVar4;
  uint32_t port;
  uint8_t val;
  gpio_callback_t new_val;
  
  prctl(0xf,&DAT_00209564,0,0,0);
  do {
    if (gpio_thread == 0) {
      return (void *)0x0;
    }
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)&gpio_ctrl_map);
    if (iVar1 == 0) {
      pItr = new_iterator_c_map(gpio_ctrl_map.gpio_callback_map);
      pcVar2 = (*pItr->get_next)(pItr);
      while (pcVar2 != (clib_object *)0x0) {
        pvVar4 = pItr->pCurrentElement;
        __ptr = (undefined4 *)(*pItr->get_value)(pcVar2);
        port = *(uint32_t *)**(undefined4 **)((int)pvVar4 + 0x10);
        val = '\0';
        iVar3 = gpio_read(port,&val);
        if (iVar3 != 0) {
          free(__ptr);
          break;
        }
        if (__ptr[1] != (uint)val) {
          (*(code *)*__ptr)(port,(uint)val);
          new_val.function = (bitmain_gpio_callback)*__ptr;
          new_val.last = (uint32_t)val;
          (*pItr->replace_value)(pItr,&new_val,8);
        }
        free(__ptr);
        pcVar2 = (*pItr->get_next)(pItr);
      }
      delete_iterator_c_map(pItr);
      pthread_mutex_unlock((pthread_mutex_t *)&gpio_ctrl_map);
    }
    usleep(200000);
  } while( true );
}

