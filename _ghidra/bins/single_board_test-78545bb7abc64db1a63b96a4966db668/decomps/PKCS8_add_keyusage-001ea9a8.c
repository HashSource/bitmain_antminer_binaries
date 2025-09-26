
int PKCS8_add_keyusage(PKCS8_PRIV_KEY_INFO *p8,int usage)

{
  int iVar1;
  undefined1 local_9;
  
  local_9 = (undefined1)usage;
  iVar1 = PKCS8_pkey_add1_attr_by_NID(p8,0x53,3,&local_9,1);
  return iVar1;
}

