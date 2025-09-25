
size_t file_read(int param_1,void *param_2,size_t param_3)

{
  int iVar1;
  int *piVar2;
  size_t sVar3;
  
  if (*(int *)(param_1 + 0x10) == 0 || param_2 == (void *)0x0) {
    sVar3 = 0;
  }
  else {
    sVar3 = fread(param_2,1,param_3,*(FILE **)(param_1 + 0x24));
    iVar1 = ferror(*(FILE **)(param_1 + 0x24));
    if (iVar1 != 0) {
      sVar3 = 0xffffffff;
      piVar2 = __errno_location();
      ERR_put_error(2,0xb,*piVar2,"crypto/bio/bss_file.c",0x95);
      ERR_put_error(0x20,0x82,2,"crypto/bio/bss_file.c",0x96);
    }
  }
  return sVar3;
}

