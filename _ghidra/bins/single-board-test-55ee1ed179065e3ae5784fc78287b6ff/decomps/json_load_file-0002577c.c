
undefined4 json_load_file(char *param_1,undefined4 param_2,undefined4 param_3)

{
  FILE *__stream;
  int *piVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  jsonp_error_init(param_3,param_1);
  if (param_1 == (char *)0x0) {
    error_set(param_3,0,"wrong arguments");
    uVar3 = 0;
  }
  else {
    __stream = fopen(param_1,"rb");
    if (__stream == (FILE *)0x0) {
      piVar1 = __errno_location();
      pcVar2 = strerror(*piVar1);
      error_set(param_3,0,"unable to open %s: %s",param_1,pcVar2);
      uVar3 = 0;
    }
    else {
      uVar3 = json_loadf(__stream,param_2,param_3);
      fclose(__stream);
    }
  }
  return uVar3;
}

