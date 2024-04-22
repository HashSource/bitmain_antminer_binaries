
void * realloc_strcat(char *ptr,char *s)

{
  char *s_local;
  char *ptr_local;
  size_t len;
  char *ret;
  size_t old;
  
  old = 0;
  len = strlen(s);
  ret = ptr;
  if (len != 0) {
    if (ptr != (char *)0x0) {
      old = strlen(ptr);
    }
    len = len + old + 1;
    align_len(&len);
    ret = (char *)_cgmalloc(len,"util.c","realloc_strcat",0xc8a);
    if (ptr == (char *)0x0) {
      strcpy(ret,s);
    }
    else {
      sprintf(ret,"%s%s",ptr,s);
      free(ptr);
    }
  }
  return ret;
}

