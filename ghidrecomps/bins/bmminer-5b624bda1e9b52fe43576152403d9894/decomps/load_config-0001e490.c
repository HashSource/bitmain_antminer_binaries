
/* WARNING: Unknown calling convention */

char * load_config(char *arg,void *unused)

{
  json_t *config;
  size_t sVar1;
  size_t sVar2;
  char *json_error;
  char *__s;
  uint size;
  json_error_t err;
  
  if (cnfbuf == (char *)0x0) {
    cnfbuf = (char *)__strdup();
  }
  include_count = include_count + 1;
  if (include_count < 0xb) {
    config = json_load_file(arg,0,&err);
    if ((config == (json_t *)0x0) || (config->type != JSON_OBJECT)) {
      sVar1 = strlen(arg);
      sVar2 = strlen(err.text);
      size = sVar1 + sVar2 + 0x23;
      __s = (char *)_cgmalloc(size,"cgminer.c","load_config",0x7f9);
      snprintf(__s,size,"JSON decode of file \'%s\' failed\n %s",arg,err.text);
    }
    else {
      config_loaded = true;
      __s = parse_config(config,true);
    }
  }
  else {
    __s = "Too many levels of JSON includes (limit 10) or a loop";
  }
  return __s;
}

