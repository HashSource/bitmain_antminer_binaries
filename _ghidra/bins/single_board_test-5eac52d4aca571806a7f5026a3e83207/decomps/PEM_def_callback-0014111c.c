
int PEM_def_callback(char *buf,int num,int w,void *key)

{
  size_t sVar1;
  char *prompt;
  int iVar2;
  
  if (key == (void *)0x0) {
    prompt = EVP_get_pw_prompt();
    if (prompt == (char *)0x0) {
      prompt = "Enter PEM pass phrase:";
    }
    if (w == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = 4;
    }
    iVar2 = EVP_read_pw_string_min(buf,iVar2,num,prompt,w);
    if (iVar2 == 0) {
      sVar1 = strlen(buf);
      return sVar1;
    }
    ERR_put_error(9,100,0x6d,"crypto/pem/pem_lib.c",0x3b);
    memset(buf,0,num);
    num = 0xffffffff;
  }
  else {
    sVar1 = strlen((char *)key);
    if ((int)sVar1 <= num) {
      num = sVar1;
    }
    memcpy(buf,key,num);
  }
  return num;
}

