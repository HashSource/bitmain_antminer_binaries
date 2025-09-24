
char * UI_construct_prompt(UI *ui_method,char *object_desc,char *object_name)

{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  int num;
  undefined2 local_2c [2];
  undefined4 local_28;
  undefined2 local_24;
  char local_20 [4];
  undefined2 local_1c;
  undefined1 local_1a;
  
  if (*(code **)(*(int *)ui_method + 0x20) == (code *)0x0) {
    local_2c[0] = 0x3a;
    builtin_strncpy(local_20,"Ente",4);
    local_1c = 0x2072;
    local_1a = 0;
    local_28 = 0x726f6620;
    local_24 = 0x20;
    if (object_desc != (char *)0x0) {
      sVar2 = strlen(object_desc);
      if (object_name == (char *)0x0) {
        num = sVar2 + 8;
        pcVar1 = (char *)CRYPTO_malloc(num,"crypto/ui/ui_lib.c",0x179);
        if (pcVar1 != (char *)0x0) {
          OPENSSL_strlcpy(pcVar1,local_20,num);
          OPENSSL_strlcat(pcVar1,object_desc,num);
          goto LAB_001c53de;
        }
      }
      else {
        sVar3 = strlen(object_name);
        num = sVar3 + sVar2 + 0xd;
        pcVar1 = (char *)CRYPTO_malloc(num,"crypto/ui/ui_lib.c",0x179);
        if (pcVar1 != (char *)0x0) {
          OPENSSL_strlcpy(pcVar1,local_20,num);
          OPENSSL_strlcat(pcVar1,object_desc,num);
          OPENSSL_strlcat(pcVar1,&local_28,num);
          OPENSSL_strlcat(pcVar1,object_name,num);
LAB_001c53de:
          OPENSSL_strlcat(pcVar1,local_2c,num);
          return pcVar1;
        }
      }
      ERR_put_error(0x28,0x79,0x41,"crypto/ui/ui_lib.c",0x17a);
    }
    pcVar1 = (char *)0x0;
  }
  else {
    pcVar1 = (char *)(**(code **)(*(int *)ui_method + 0x20))();
  }
  return pcVar1;
}

