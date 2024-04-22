
void * bin2hex(undefined4 param_1,int param_2)

{
  void *pvVar1;
  uint local_c;
  
  local_c = param_2 * 2 + 1;
  if ((local_c & 3) != 0) {
    local_c = (local_c & 0xfffffffc) + 4;
  }
  pvVar1 = calloc(local_c,1);
  if (pvVar1 == (void *)0x0) {
    fwrite("Failed to calloc",1,0x10,stderr);
  }
  __bin2hex(pvVar1,param_1,param_2);
  return pvVar1;
}

