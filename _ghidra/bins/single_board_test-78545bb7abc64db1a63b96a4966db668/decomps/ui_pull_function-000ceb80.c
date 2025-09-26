
/* WARNING: Unknown calling convention */

void * ui_pull_function(void *args)

{
  int iVar1;
  clib_iterator *pItr;
  clib_object *pcVar2;
  uint32_t *__ptr;
  uint32_t uVar3;
  filker_interval_t new_value;
  
  prctl(0xf,&DAT_002098a8,0,0,0);
  while (ui_pull_thread != 0) {
    iVar1 = pthread_mutex_lock((pthread_mutex_t *)&ui_api_mutex);
    if (iVar1 == 0) {
      pItr = new_iterator_c_map(ui_flicker_map);
      pcVar2 = (*pItr->get_next)(pItr);
      while (pcVar2 != (clib_object *)0x0) {
        __ptr = (uint32_t *)(*pItr->get_value)(pcVar2);
        uVar3 = __ptr[1];
        if (uVar3 == 0) {
          gpio_write(*(uint32_t *)**(undefined4 **)((int)pItr->pCurrentElement + 0x10),
                     (uint8_t)__ptr[2]);
          new_value.interval = *__ptr;
          new_value.next_val = __ptr[2] - 1;
          if (new_value.next_val != 0) {
            new_value.next_val = 1;
          }
          __ptr[2] = new_value.next_val;
          uVar3 = new_value.interval;
        }
        else {
          new_value.interval = *__ptr;
          new_value.next_val = __ptr[2];
        }
        new_value.timeout = uVar3 - 200;
        __ptr[1] = new_value.timeout;
        (*pItr->replace_value)(pItr,&new_value,0xc);
        free(__ptr);
        pcVar2 = (*pItr->get_next)(pItr);
      }
      delete_iterator_c_map(pItr);
      pthread_mutex_unlock((pthread_mutex_t *)&ui_api_mutex);
    }
    usleep(200000);
  }
  return (void *)0x0;
}

