
undefined4 json_load_file(char *param_1,undefined4 param_2,undefined4 param_3)

{
  FILE *__stream;
  undefined4 uVar1;
  int *piVar2;
  char *pcVar3;
  
  jsonp_error_init(param_3,param_1);
  if (param_1 == (char *)0x0) {
    error_set(param_3,0,"wrong arguments");
    uVar1 = 0;
  }
  else {
    __stream = fopen(param_1,"rb");
    if (__stream == (FILE *)0x0) {
      piVar2 = __errno_location();
      pcVar3 = strerror(*piVar2);
      error_set(param_3,0,"unable to open %s: %s",param_1,pcVar3);
      uVar1 = 0;
    }
    else {
      uVar1 = json_loadf(__stream,param_2,param_3);
      fclose(__stream);
    }
  }
  return uVar1;
}

