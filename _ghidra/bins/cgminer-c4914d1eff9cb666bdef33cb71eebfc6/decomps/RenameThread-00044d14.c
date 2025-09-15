
void RenameThread(char *name)

{
  char *name_local;
  char buf [16];
  
  snprintf(buf,0x10,"cg@%s",name);
  prctl(0xf,buf,0,0,0);
  return;
}

