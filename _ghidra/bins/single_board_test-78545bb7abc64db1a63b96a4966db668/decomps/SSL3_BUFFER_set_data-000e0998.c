
void SSL3_BUFFER_set_data(undefined4 *param_1,void *param_2,size_t param_3)

{
  if (param_2 != (void *)0x0) {
    memcpy((void *)*param_1,param_2,param_3);
  }
  param_1[4] = param_3;
  param_1[3] = 0;
  return;
}

