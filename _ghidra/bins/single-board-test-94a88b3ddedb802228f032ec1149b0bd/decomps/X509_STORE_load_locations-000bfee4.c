
int X509_STORE_load_locations(X509_STORE *ctx,char *file,char *dir)

{
  X509_LOOKUP_METHOD *pXVar1;
  X509_LOOKUP *pXVar2;
  int iVar3;
  uint uVar4;
  
  if (file == (char *)0x0) {
LAB_000bff16:
    if (dir != (char *)0x0) {
      pXVar1 = X509_LOOKUP_hash_dir();
      pXVar2 = X509_STORE_add_lookup(ctx,pXVar1);
      if ((pXVar2 == (X509_LOOKUP *)0x0) ||
         (iVar3 = X509_LOOKUP_ctrl(pXVar2,2,dir,1,(char **)0x0), iVar3 != 1)) goto LAB_000bff10;
    }
    uVar4 = (dir == (char *)0x0 && file == (char *)0x0) ^ 1;
  }
  else {
    pXVar1 = X509_LOOKUP_file();
    pXVar2 = X509_STORE_add_lookup(ctx,pXVar1);
    if ((pXVar2 != (X509_LOOKUP *)0x0) &&
       (iVar3 = X509_LOOKUP_ctrl(pXVar2,1,file,1,(char **)0x0), iVar3 == 1)) goto LAB_000bff16;
LAB_000bff10:
    uVar4 = 0;
  }
  return uVar4;
}

