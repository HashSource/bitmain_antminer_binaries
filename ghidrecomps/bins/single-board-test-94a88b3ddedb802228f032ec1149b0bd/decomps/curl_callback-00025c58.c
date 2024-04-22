
size_t curl_callback(void *param_1,int param_2,int param_3,void **param_4)

{
  void *pvVar1;
  size_t __n;
  
  __n = param_3 * param_2;
  pvVar1 = realloc(*param_4,(int)param_4[1] + __n + 1);
  *param_4 = pvVar1;
  if (*param_4 == (void *)0x0) {
    fwrite("ERROR: Failed to expand buffer in curl_callback",1,0x2f,stderr);
    __n = 0xffffffff;
  }
  else {
    memcpy((void *)((int)param_4[1] + (int)*param_4),param_1,__n);
    param_4[1] = (void *)((int)param_4[1] + __n);
    *(undefined *)((int)param_4[1] + (int)*param_4) = 0;
  }
  return __n;
}

