
/* WARNING: Unknown calling convention */

char * proxytype(proxytypes_t proxytype)

{
  anon_struct_8_2_f5308dc4 *paVar1;
  char *pcVar2;
  anon_struct_8_2_f5308dc4 *paVar3;
  
  if (proxytype == 0) {
    pcVar2 = "http:";
  }
  else {
    paVar3 = proxynames;
    do {
      pcVar2 = paVar3[1].name;
      if (pcVar2 == (char *)0x0) {
        return "invalid";
      }
      paVar1 = paVar3 + 1;
      paVar3 = paVar3 + 1;
    } while (paVar1->proxytype != proxytype);
  }
  return pcVar2;
}

