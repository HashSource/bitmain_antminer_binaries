
int i2t_ASN1_OBJECT(char *buf,int buf_len,ASN1_OBJECT *a)

{
  int iVar1;
  
  iVar1 = OBJ_obj2txt(buf,buf_len,a,0);
  return iVar1;
}

