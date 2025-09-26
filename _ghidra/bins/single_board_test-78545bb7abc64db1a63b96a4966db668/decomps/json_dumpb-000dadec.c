
/* WARNING: Unknown calling convention */

size_t json_dumpb(json_t *json,char *buffer,size_t size,size_t flags)

{
  int iVar1;
  size_t sVar2;
  buffer buf;
  
  sVar2 = 0;
  buf.used = 0;
  buf.size = size;
  buf.data = buffer;
  iVar1 = json_dump_callback(json,(json_dump_callback_t)0xda849,&buf,flags);
  if (iVar1 == 0) {
    sVar2 = buf.used;
  }
  return sVar2;
}

