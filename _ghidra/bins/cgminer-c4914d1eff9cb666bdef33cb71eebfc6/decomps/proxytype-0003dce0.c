
char * proxytype(proxytypes_t proxytype)

{
  proxytypes_t proxytype_local;
  int i;
  
  i = 0;
  while( true ) {
    if (proxynames[i].name == (char *)0x0) {
      return "invalid";
    }
    if (proxytype == proxynames[i].proxytype) break;
    i = i + 1;
  }
  return proxynames[i].name;
}

