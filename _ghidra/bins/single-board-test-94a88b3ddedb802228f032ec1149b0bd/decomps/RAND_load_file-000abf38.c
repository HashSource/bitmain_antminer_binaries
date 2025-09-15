
int RAND_load_file(char *file,long max_bytes)

{
  int iVar1;
  FILE *__stream;
  size_t sVar2;
  size_t __n;
  stat sStack_470;
  undefined1 auStack_418 [1024];
  
  if ((((file == (char *)0x0) || (iVar1 = __xstat(3,file,&sStack_470), iVar1 < 0)) ||
      (RAND_add(&sStack_470,0x58,0.0), max_bytes == 0)) ||
     (__stream = fopen(file,"rb"), __stream == (FILE *)0x0)) {
    return 0;
  }
  if ((sStack_470.st_mode & 0x6000) != 0) {
    if (max_bytes == -1) {
      max_bytes = 0x800;
    }
    setvbuf(__stream,(char *)0x0,2,0);
  }
  iVar1 = 0;
  if (0 < max_bytes) goto LAB_000abfaa;
  do {
    __n = 0x400;
LAB_000abfb8:
    sVar2 = fread(auStack_418,1,__n,__stream);
    if ((int)sVar2 < 1) {
LAB_000abfe4:
      fclose(__stream);
      OPENSSL_cleanse(auStack_418,0x400);
      return iVar1;
    }
    iVar1 = iVar1 + sVar2;
    RAND_add(auStack_418,__n,(double)(longlong)(int)sVar2);
  } while (max_bytes < 1);
  max_bytes = max_bytes - __n;
  if (max_bytes < 1) goto LAB_000abfe4;
LAB_000abfaa:
  __n = max_bytes;
  if (0x3ff < max_bytes) {
    __n = 0x400;
  }
  goto LAB_000abfb8;
}

