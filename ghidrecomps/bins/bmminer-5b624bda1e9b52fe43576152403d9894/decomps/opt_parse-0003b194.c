
/* WARNING: Unknown calling convention */

_Bool opt_parse(int *argc,char **argv,_func_void_char_ptr_varargs *errlog)

{
  char cVar1;
  uint uVar2;
  int ret;
  uint local_1c [2];
  
  local_1c[0] = 0;
  *DAT_0003b1c8 = *argv;
  do {
    uVar2 = parse_one(argc,argv,local_1c,errlog);
  } while (uVar2 == 1);
  cVar1 = '\x01' - (char)uVar2;
  if (1 < uVar2) {
    cVar1 = '\0';
  }
  return (_Bool)cVar1;
}

