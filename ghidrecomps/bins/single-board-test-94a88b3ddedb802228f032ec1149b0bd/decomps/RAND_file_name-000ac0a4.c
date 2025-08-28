
char * RAND_file_name(char *file,size_t num)

{
  int iVar1;
  size_t sVar2;
  char *__s;
  
  __s = (char *)0x0;
  iVar1 = OPENSSL_issetugid();
  if ((((iVar1 == 0) && (__s = getenv("RANDFILE"), __s != (char *)0x0)) && (*__s != '\0')) &&
     (sVar2 = strlen(__s), sVar2 + 1 < num)) {
    sVar2 = BUF_strlcpy(file,__s,num);
    if (num <= sVar2) {
      file = (char *)0x0;
    }
    return file;
  }
  iVar1 = OPENSSL_issetugid();
  if (iVar1 == 0) {
    __s = getenv("HOME");
  }
  if (((__s != (char *)0x0) && (*__s != '\0')) && (sVar2 = strlen(__s), sVar2 + 6 < num)) {
    BUF_strlcpy(file,__s,num);
    BUF_strlcat(file,"/",num);
    BUF_strlcat(file,".rnd",num);
    return file;
  }
  *file = '\0';
  return file;
}

