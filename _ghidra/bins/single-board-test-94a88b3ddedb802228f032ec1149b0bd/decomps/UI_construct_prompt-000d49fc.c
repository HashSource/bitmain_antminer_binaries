
char * UI_construct_prompt(UI *ui_method,char *object_desc,char *object_name)

{
  char *dst;
  size_t sVar1;
  size_t sVar2;
  char local_2c [4];
  char local_28 [4];
  undefined2 local_24;
  char local_20 [4];
  undefined2 local_1c;
  undefined1 local_1a;
  
  if (*(code **)(*(int *)ui_method + 0x18) == (code *)0x0) {
    local_2c[0] = ':';
    local_2c[1] = '\0';
    builtin_strncpy(local_20,"Ente",4);
    local_1c = 0x2072;
    local_1a = 0;
    builtin_strncpy(local_28," for",4);
    local_24 = 0x20;
    dst = object_desc;
    if (object_desc != (char *)0x0) {
      sVar1 = strlen(object_desc);
      if (object_name == (char *)0x0) {
        sVar1 = sVar1 + 8;
        dst = (char *)CRYPTO_malloc(sVar1,"ui_lib.c",0x19f);
        BUF_strlcpy(dst,local_20,sVar1);
        BUF_strlcat(dst,object_desc,sVar1);
      }
      else {
        sVar2 = strlen(object_name);
        sVar1 = sVar2 + sVar1 + 0xd;
        dst = (char *)CRYPTO_malloc(sVar1,"ui_lib.c",0x19f);
        BUF_strlcpy(dst,local_20,sVar1);
        BUF_strlcat(dst,object_desc,sVar1);
        BUF_strlcat(dst,local_28,sVar1);
        BUF_strlcat(dst,object_name,sVar1);
      }
      BUF_strlcat(dst,local_2c,sVar1);
    }
  }
  else {
    dst = (char *)(**(code **)(*(int *)ui_method + 0x18))();
  }
  return dst;
}

