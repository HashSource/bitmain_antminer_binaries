
/* WARNING: Unknown calling convention */

int32_t i2c_ioctl(int32_t ctx,uint16_t cmd,uint32_t arg)

{
  int iVar1;
  clib_iterator *pItr;
  clib_object *pcVar2;
  uint32_t *__ptr;
  int32_t iVar3;
  i2c_value_t new_val;
  
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  if (iVar1 == 0) {
    pItr = new_iterator_c_map(i2c_ctx_map);
    pcVar2 = (*pItr->get_next)(pItr);
    if (pcVar2 != (clib_object *)0x0) {
      iVar1 = *(int *)**(undefined4 **)((int)pItr->pCurrentElement + 0x10);
      while (ctx != iVar1) {
        pcVar2 = (*pItr->get_next)(pItr);
        if (pcVar2 == (clib_object *)0x0) goto LAB_000cfdee;
        iVar1 = *(int *)**(undefined4 **)((int)pItr->pCurrentElement + 0x10);
      }
      __ptr = (uint32_t *)(*pItr->get_value)(pcVar2);
      if (cmd == 0x703) {
        new_val.master = *__ptr;
        new_val.slave = arg;
        (*pItr->replace_value)(pItr,&new_val,8);
        free(__ptr);
      }
    }
LAB_000cfdee:
    delete_iterator_c_map(pItr);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    iVar3 = 0;
  }
  else {
    iVar3 = -4;
    new_val.master._0_1_ = 'f';
    new_val.master._1_1_ = 'a';
    new_val.master._2_1_ = 'i';
    new_val.master._3_1_ = 'l';
    new_val.slave._0_1_ = 'e';
    new_val.slave._1_1_ = 'd';
    new_val.slave._2_1_ = ' ';
    new_val.slave._3_1_ = 't';
    _applog(0,(char *)&new_val,false);
  }
  return iVar3;
}

