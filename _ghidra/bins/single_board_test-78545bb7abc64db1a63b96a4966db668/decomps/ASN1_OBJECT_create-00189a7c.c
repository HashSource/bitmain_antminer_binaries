
ASN1_OBJECT * ASN1_OBJECT_create(int nid,uchar *data,int len,char *sn,char *ln)

{
  ASN1_OBJECT *pAVar1;
  ASN1_OBJECT local_28;
  
  local_28.ln = (char **)ln;
  local_28.flags = 0xd;
  local_28.sn = sn;
  local_28.nid = nid;
  local_28.length = len;
  local_28.data = data;
  pAVar1 = OBJ_dup(&local_28);
  return pAVar1;
}

