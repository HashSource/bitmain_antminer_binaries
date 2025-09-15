
void dump_str(void *fdp,char *func,uchar *str,int len)

{
  char *__ptr;
  int len_local;
  uchar *str_local;
  char *func_local;
  void *fdp_local;
  char *hexbuff;
  FILE *fd;
  
  if (fdp != (void *)0x0) {
    __ptr = bin2hex(str,len);
    if (func == (char *)0x0) {
      fprintf((FILE *)fdp,"%s\n",__ptr);
    }
    else {
      fprintf((FILE *)fdp,"%s %s len=%d\n",func,__ptr,len);
    }
    fflush((FILE *)fdp);
    free(__ptr);
  }
  return;
}

