
/* WARNING: Unknown calling convention */

void i2c_uninit(int32_t ctx)

{
  int iVar1;
  clib_bool cVar2;
  clib_iterator *pItr;
  clib_object *pcVar3;
  int32_t local_814;
  char tmp42 [2048];
  
  local_814 = ctx;
  iVar1 = pthread_mutex_lock((pthread_mutex_t *)&i2c_mutex);
  if (iVar1 != 0) {
    builtin_strncpy(tmp42,"failed to i2c lock\n",0x14);
    _applog(0,tmp42,false);
    return;
  }
  cVar2 = exists_c_map(i2c_ctx_map,&local_814);
  if (cVar2 == 1) {
    remove_c_map(i2c_ctx_map,&local_814);
  }
  else {
    snprintf(tmp42,0x800,"ctx(%d) is not inited\n",local_814);
    _applog(1,tmp42,false);
  }
  pItr = new_iterator_c_map(i2c_ctx_map);
  pcVar3 = (*pItr->get_next)(pItr);
  if (pcVar3 != (clib_object *)0x0) {
    do {
      pcVar3 = (*pItr->get_next)(pItr);
    } while (pcVar3 != (clib_object *)0x0);
    delete_iterator_c_map(pItr);
    pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
    return;
  }
  delete_iterator_c_map(pItr);
  pthread_mutex_unlock((pthread_mutex_t *)&i2c_mutex);
  i2c_index = (int32_t)pcVar3;
  delete_c_map(i2c_ctx_map);
  i2c_ctx_map = (clib_map *)pcVar3;
  return;
}

