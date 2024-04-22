
void * file_read(int param_1,void *param_2,size_t param_3)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  
  pvVar1 = *(void **)(param_1 + 0xc);
  if ((*(void **)(param_1 + 0xc) != (void *)0x0) && (pvVar1 = param_2, param_2 != (void *)0x0)) {
    pvVar1 = (void *)fread(param_2,1,param_3,*(FILE **)(param_1 + 0x20));
    iVar2 = ferror(*(FILE **)(param_1 + 0x20));
    if (iVar2 != 0) {
      piVar3 = __errno_location();
      ERR_put_error(2,0xb,*piVar3,DAT_000a98c0,0xf4);
      pvVar1 = (void *)0xffffffff;
      ERR_put_error(0x20,0x82,2,DAT_000a98c0,0xf5);
    }
  }
  return pvVar1;
}

