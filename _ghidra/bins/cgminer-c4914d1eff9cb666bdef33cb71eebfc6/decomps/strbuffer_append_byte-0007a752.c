
int strbuffer_append_byte(strbuffer_t *strbuff,char byte)

{
  int iVar1;
  char byte_local;
  strbuffer_t *strbuff_local;
  
  byte_local = byte;
  strbuff_local = strbuff;
  iVar1 = strbuffer_append_bytes(strbuff,&byte_local,1);
  return iVar1;
}

