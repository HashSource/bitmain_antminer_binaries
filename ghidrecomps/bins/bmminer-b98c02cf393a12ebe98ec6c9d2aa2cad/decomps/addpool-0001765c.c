
void addpool(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  char *__ptr;
  undefined4 *puVar2;
  void *__ptr_00;
  void *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  if ((param_3 == (char *)0x0) || (*param_3 == '\0')) {
    message(param_1,0x34,0,0,param_4);
  }
  else {
    iVar1 = pooldetails(param_3,&local_24,&local_20,&local_1c);
    if (iVar1 == 0) {
      __ptr = (char *)escape_string(param_3,param_4);
      message(param_1,0x35,0,__ptr,param_4);
      if (param_3 != __ptr) {
        free(__ptr);
      }
    }
    else {
      puVar2 = (undefined4 *)add_pool();
      detect_stratum(puVar2,local_24);
      add_pool_details(puVar2,1,local_24,local_20,local_1c);
      __ptr_00 = (void *)escape_string(local_24,param_4);
      message(param_1,0x37,*puVar2,__ptr_00,param_4);
      if (__ptr_00 != local_24) {
        free(__ptr_00);
        return;
      }
    }
  }
  return;
}

