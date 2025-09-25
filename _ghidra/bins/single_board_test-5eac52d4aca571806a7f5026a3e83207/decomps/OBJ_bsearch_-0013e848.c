
void * OBJ_bsearch_(void *key,void *base,int num,int size,cmp *cmp)

{
  void *pvVar1;
  
  pvVar1 = OBJ_bsearch_ex_(key,base,num,size,cmp,0);
  return pvVar1;
}

