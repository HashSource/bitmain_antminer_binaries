
int RAND_load_file(char *file,long max_bytes)

{
  int iVar1;
  FILE *__stream;
  size_t sVar2;
  size_t __n;
  double in_stack_fffffb90;
  uint local_460;
  undefined auStack_418 [1024];
  
  if ((((file == (char *)0x0) || (iVar1 = __xstat(3,file,(stat *)&stack0xfffffb90), iVar1 < 0)) ||
      (RAND_add(&stack0xfffffb90,0x58,in_stack_fffffb90), max_bytes == 0)) ||
     (__stream = fopen(file,DAT_000ac000), __stream == (FILE *)0x0)) {
    return 0;
  }
  if ((local_460 & 0x6000) != 0) {
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
    RAND_add(auStack_418,__n,in_stack_fffffb90);
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

