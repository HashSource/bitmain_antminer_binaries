
int PEM_def_callback(char *buf,int num,int w,void *key)

{
  FILE **ppFVar1;
  size_t sVar2;
  char *pcVar3;
  size_t sVar4;
  int iVar5;
  char *prompt;
  
  prompt = DAT_000bd988;
  if (key == (void *)0x0) {
    pcVar3 = EVP_get_pw_prompt();
    ppFVar1 = DAT_000bd994;
    if (pcVar3 != (char *)0x0) {
      prompt = pcVar3;
    }
    while (iVar5 = EVP_read_pw_string_min(buf,4,num,prompt,w), iVar5 == 0) {
      sVar4 = strlen(buf);
      if (3 < (int)sVar4) {
        return sVar4;
      }
      fprintf(*ppFVar1,DAT_000bd98c,4);
    }
    ERR_put_error(9,100,0x6d,DAT_000bd990,0x6e);
    sVar4 = 0xffffffff;
    memset(buf,0,num);
  }
  else {
    sVar2 = strlen((char *)key);
    sVar4 = num;
    if ((int)sVar2 < num) {
      sVar4 = sVar2;
    }
    memcpy(buf,key,sVar4);
  }
  return sVar4;
}

