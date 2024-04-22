
/* WARNING: Unknown calling convention */

void clear_register_value_buf(void)

{
  pthread_mutex_t *__mutex;
  reg_buf *prVar1;
  
  __mutex = DAT_00021c54;
  pthread_mutex_lock(DAT_00021c54);
  prVar1 = reg_value_buf;
  reg_value_buf->p_wr = 0;
  prVar1->p_rd = 0;
  prVar1->reg_value_num = 0;
  prVar1->loop_back = 0;
  pthread_mutex_unlock(__mutex);
  (*(code *)PTR_memset_00030184)(reg_value_buf->reg_buffer,0,0xff8);
  return;
}

