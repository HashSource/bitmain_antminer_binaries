
size_t get_file_size(char *filename)

{
  int iVar1;
  char *filename_local;
  stat statbuf;
  
  if (filename == (char *)0x0) {
    statbuf.st_size = 0;
  }
  else {
    iVar1 = __stat(filename,(stat *)&statbuf);
    if (iVar1 != 0) {
      statbuf.st_size = 0;
    }
  }
  return statbuf.st_size;
}

