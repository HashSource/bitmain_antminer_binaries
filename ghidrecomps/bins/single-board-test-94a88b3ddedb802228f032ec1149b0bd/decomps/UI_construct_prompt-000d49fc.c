
char * UI_construct_prompt(UI *ui_method,char *object_desc,char *object_name)

{
  char *dst;
  size_t sVar1;
  size_t sVar2;
  undefined2 local_2c [2];
  undefined4 local_28;
  undefined2 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined local_1a;
  
  if (*(code **)(*(int *)ui_method + 0x18) == (code *)0x0) {
    local_2c[0] = 0x3a;
    local_20 = *DAT_000d4abc;
    local_1c = (undefined2)DAT_000d4abc[1];
    local_28 = *DAT_000d4ac0;
    local_1a = (undefined)((uint)DAT_000d4abc[1] >> 0x10);
    local_24 = (undefined2)DAT_000d4ac0[1];
    dst = object_desc;
    if (object_desc != (char *)0x0) {
      sVar1 = strlen(object_desc);
      if (object_name == (char *)0x0) {
        sVar1 = sVar1 + 8;
        dst = (char *)CRYPTO_malloc(sVar1,DAT_000d4ac4,0x19f);
        BUF_strlcpy(dst,(char *)&local_20,sVar1);
        BUF_strlcat(dst,object_desc,sVar1);
      }
      else {
        sVar2 = strlen(object_name);
        sVar1 = sVar2 + sVar1 + 0xd;
        dst = (char *)CRYPTO_malloc(sVar1,DAT_000d4ac4,0x19f);
        BUF_strlcpy(dst,(char *)&local_20,sVar1);
        BUF_strlcat(dst,object_desc,sVar1);
        BUF_strlcat(dst,(char *)&local_28,sVar1);
        BUF_strlcat(dst,object_name,sVar1);
      }
      BUF_strlcat(dst,(char *)local_2c,sVar1);
    }
  }
  else {
    dst = (char *)(**(code **)(*(int *)ui_method + 0x18))();
  }
  return dst;
}

