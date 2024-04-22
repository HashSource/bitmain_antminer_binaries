
/* WARNING: Unknown calling convention */

int strbuffer_append_byte(strbuffer_t *strbuff,char byte)

{
  int iVar1;
  char local_9 [9];
  
  local_9[0] = byte;
  iVar1 = strbuffer_append_bytes(strbuff,local_9,1);
  return iVar1;
}

