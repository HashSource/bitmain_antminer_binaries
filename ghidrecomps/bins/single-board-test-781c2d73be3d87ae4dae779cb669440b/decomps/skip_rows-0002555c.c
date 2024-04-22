
/* WARNING: Unknown calling convention */

int skip_rows(FILE *stream,int count)

{
  char str [1024];
  
  memset(str,0,0x400);
  if (count != 0) {
    do {
      fgets(str,0x3ff,(FILE *)stream);
      count = count + -1;
    } while (count != 0);
  }
  return 0;
}

