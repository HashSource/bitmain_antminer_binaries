
int dlfcn_pathbyaddr(int param_1,void *param_2,int param_3)

{
  int iVar1;
  size_t __n;
  undefined4 uVar2;
  char *local_28 [5];
  
  if (param_1 == 0) {
    param_1 = DAT_00126a7c;
  }
  iVar1 = dladdr(param_1,local_28);
  if (iVar1 == 0) {
    uVar2 = dlerror();
    ERR_add_error_data(2,DAT_00126a80,uVar2);
    iVar1 = -1;
  }
  else {
    __n = strlen(local_28[0]);
    if (param_3 < 1) {
      iVar1 = __n + 1;
    }
    else {
      if (param_3 <= (int)__n) {
        __n = param_3 - 1;
      }
      memcpy(param_2,local_28[0],__n);
      iVar1 = __n + 1;
      *(undefined *)((int)param_2 + __n) = 0;
    }
  }
  return iVar1;
}

