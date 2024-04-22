
char * load_config(char *arg,void *unused)

{
  json_t *config_00;
  size_t sVar1;
  size_t sVar2;
  char *__s;
  uint32_t size;
  void *unused_local;
  char *arg_local;
  json_error_t err;
  char *json_error;
  size_t siz;
  json_t *config;
  
  if (cnfbuf == (char *)0x0) {
    cnfbuf = strdup(arg);
  }
  include_count = include_count + 1;
  if (include_count < 0xb) {
    config_00 = json_load_file(arg,0,&err);
    if ((config_00 == (json_t *)0x0) || (config_00->type != JSON_OBJECT)) {
      sVar1 = strlen(arg);
      sVar2 = strlen(err.text);
      size = sVar2 + sVar1 + 0x23;
      __s = (char *)_cgmalloc(size,"cgminer.c","load_config",0x834);
      snprintf(__s,size,"JSON decode of file \'%s\' failed\n %s",arg,err.text);
    }
    else {
      config_loaded = true;
      __s = parse_config(config_00,true);
    }
  }
  else {
    __s = "Too many levels of JSON includes (limit 10) or a loop";
  }
  return __s;
}

