
/* WARNING: Unknown calling convention */

int strbuffer_append(strbuffer_t *strbuff,char *string)

{
  size_t size;
  int iVar1;
  
  size = strlen(string);
  iVar1 = strbuffer_append_bytes(strbuff,string,size);
  return iVar1;
}

