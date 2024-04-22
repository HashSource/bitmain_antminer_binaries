
int RAND_write_file(char *file)

{
  int iVar1;
  FILE *__s;
  size_t sVar2;
  stat sStack_468;
  uchar auStack_410 [1024];
  
  iVar1 = __xstat(3,file,&sStack_468);
  if ((iVar1 == -1) || ((sStack_468.st_mode & 0xb000) != 0x2000)) {
    iVar1 = open(file,0x41,0x180);
    if (((iVar1 != -1) && (__s = fdopen(iVar1,DAT_000ac0a0), __s != (FILE *)0x0)) ||
       (__s = fopen(file,DAT_000ac0a0), __s != (FILE *)0x0)) {
      chmod(file,0x180);
      iVar1 = RAND_bytes(auStack_410,0x400);
      sVar2 = fwrite(auStack_410,1,0x400,__s);
      fclose(__s);
      OPENSSL_cleanse(auStack_410,0x400);
      if (iVar1 < 1) {
        __s = (FILE *)0xffffffff;
      }
      else {
        __s = (FILE *)(sVar2 & ~((int)sVar2 >> 0x1f));
      }
    }
  }
  else {
    __s = (FILE *)0x1;
  }
  return (int)__s;
}

