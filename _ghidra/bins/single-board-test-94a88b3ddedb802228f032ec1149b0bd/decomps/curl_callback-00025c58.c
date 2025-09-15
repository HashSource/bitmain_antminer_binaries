
size_t curl_callback(void *param_1,int param_2,int param_3,int *param_4)

{
  void *pvVar1;
  size_t __n;
  
  __n = param_3 * param_2;
  pvVar1 = realloc((void *)*param_4,__n + param_4[1] + 1);
  *param_4 = (int)pvVar1;
  if (*param_4 == 0) {
    fwrite("ERROR: Failed to expand buffer in curl_callback",1,0x2f,stderr);
    __n = 0xffffffff;
  }
  else {
    memcpy((void *)(param_4[1] + *param_4),param_1,__n);
    param_4[1] = param_4[1] + __n;
    *(undefined1 *)(param_4[1] + *param_4) = 0;
  }
  return __n;
}

