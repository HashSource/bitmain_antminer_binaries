
int OBJ_txt2nid(char *s)

{
  ASN1_OBJECT *o;
  int iVar1;
  
  o = OBJ_txt2obj(s,0);
  iVar1 = OBJ_obj2nid(o);
  ASN1_OBJECT_free(o);
  return iVar1;
}

