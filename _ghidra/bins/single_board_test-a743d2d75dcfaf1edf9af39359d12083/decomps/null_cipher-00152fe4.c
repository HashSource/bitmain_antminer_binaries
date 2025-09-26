
undefined4 null_cipher(undefined4 param_1,void *param_2,void *param_3,size_t param_4)

{
  if (param_3 != param_2) {
    memcpy(param_2,param_3,param_4);
  }
  return 1;
}

