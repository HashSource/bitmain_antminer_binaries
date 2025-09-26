
char * OBJ_NAME_get(char *name,int type)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint local_30 [2];
  char *local_28;
  
  if (name == (char *)0x0) {
    return (char *)0x0;
  }
  iVar1 = OBJ_NAME_init();
  if (iVar1 == 0) {
    return (char *)0x0;
  }
  pcVar3 = (char *)0xb;
  CRYPTO_THREAD_read_lock(obj_lock);
  local_30[0] = type & 0xffff7fff;
  local_28 = name;
  do {
    iVar1 = OPENSSL_LH_retrieve(names_lh,local_30);
    if (iVar1 == 0) {
      pcVar3 = (char *)0x0;
LAB_0014be3e:
      CRYPTO_THREAD_unlock(obj_lock);
      return pcVar3;
    }
    iVar2 = *(int *)(iVar1 + 4);
    if (iVar2 != 0) {
      iVar2 = 1;
    }
    if ((type & 0x8000U) != 0) {
      iVar2 = 0;
    }
    if (iVar2 == 0) {
      pcVar3 = *(char **)(iVar1 + 0xc);
      goto LAB_0014be3e;
    }
    pcVar3 = pcVar3 + -1;
    if (pcVar3 == (char *)0x0) goto LAB_0014be3e;
    local_28 = *(char **)(iVar1 + 0xc);
  } while( true );
}

