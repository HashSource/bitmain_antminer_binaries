
int PEM_def_callback(char *buf,int num,int w,void *key)

{
  size_t sVar1;
  char *pcVar2;
  size_t sVar3;
  int iVar4;
  char *prompt;
  
  if (key == (void *)0x0) {
    pcVar2 = EVP_get_pw_prompt();
    prompt = "Enter PEM pass phrase:";
    if (pcVar2 != (char *)0x0) {
      prompt = pcVar2;
    }
    while (iVar4 = EVP_read_pw_string_min(buf,4,num,prompt,w), iVar4 == 0) {
      sVar3 = strlen(buf);
      if (3 < (int)sVar3) {
        return sVar3;
      }
      fprintf(stderr,"phrase is too short, needs to be at least %d chars\n",4);
    }
    ERR_put_error(9,100,0x6d,"pem_lib.c",0x6e);
    sVar3 = 0xffffffff;
    memset(buf,0,num);
  }
  else {
    sVar1 = strlen((char *)key);
    sVar3 = num;
    if ((int)sVar1 < num) {
      sVar3 = sVar1;
    }
    memcpy(buf,key,sVar3);
  }
  return sVar3;
}

