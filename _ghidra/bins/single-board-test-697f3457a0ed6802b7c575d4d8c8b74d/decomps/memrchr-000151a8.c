
void * memrchr(void *__s,int __c,size_t __n)

{
  size_t n_local;
  int c_local;
  void *s_local;
  char *start;
  char *end;
  
  end = (char *)(__n + (int)__s);
  do {
    end = end + -1;
    if (end < __s) {
      return (void *)0x0;
    }
  } while ((uint)(byte)*end != __c);
  return (byte *)end;
}

