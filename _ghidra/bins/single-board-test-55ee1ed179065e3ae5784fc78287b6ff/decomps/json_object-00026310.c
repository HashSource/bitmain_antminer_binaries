
int json_object(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = jsonp_malloc(0x24);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    json_init(iVar1,0);
    iVar2 = hashtable_init(iVar1 + 8);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar1 + 0x1c) = 0;
      *(undefined4 *)(iVar1 + 0x20) = 0;
    }
    else {
      jsonp_free(iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}

