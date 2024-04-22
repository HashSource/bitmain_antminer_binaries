
/* WARNING: Unknown calling convention */

char * load_config(char *arg,void *unused)

{
  int iVar1;
  int iVar2;
  json_t *config_00;
  json_t *config;
  size_t sVar3;
  size_t sVar4;
  char *__s;
  char *json_error_1;
  undefined4 uVar5;
  int iVar6;
  char *json_error;
  uint size;
  size_t siz;
  json_error_t err;
  
  iVar1 = DAT_0001e518;
  if (*(int *)(DAT_0001e518 + 0x340) == 0) {
    uVar5 = __strdup();
    *(undefined4 *)(iVar1 + 0x340) = uVar5;
  }
  iVar2 = DAT_0001e518;
  iVar6 = *(int *)(iVar1 + 0x344) + 1;
  *(int *)(iVar1 + 0x344) = iVar6;
  __s = DAT_0001e51c;
  if (iVar6 < 0xb) {
    config_00 = json_load_file(arg,0,&err);
    if ((config_00 == (json_t *)0x0) || (config_00->type != JSON_OBJECT)) {
      sVar3 = strlen(arg);
      sVar4 = strlen(err.text);
      size = sVar3 + sVar4 + 0x23;
      __s = (char *)_cgmalloc(size,DAT_0001e520,DAT_0001e524,0x7f9);
      snprintf(__s,size,DAT_0001e528,arg,err.text);
    }
    else {
      *(undefined *)(iVar2 + 0x348) = 1;
      __s = parse_config(config_00,true);
    }
  }
  return __s;
}

