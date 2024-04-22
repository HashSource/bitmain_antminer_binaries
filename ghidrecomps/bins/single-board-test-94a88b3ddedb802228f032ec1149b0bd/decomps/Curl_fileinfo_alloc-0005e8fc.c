
void * Curl_fileinfo_alloc(void)

{
  void *__s;
  
  __s = (void *)(**DAT_0005e918)(0x48);
  if (__s != (void *)0x0) {
    memset(__s,0,0x48);
  }
  return __s;
}

