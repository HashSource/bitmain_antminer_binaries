
int X509_STORE_CTX_get_obj_by_subject
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = X509_OBJECT_new();
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = X509_STORE_CTX_get_by_subject(param_1,param_2,param_3,iVar1,param_4);
  if (iVar2 != 0) {
    return iVar1;
  }
  X509_OBJECT_free(iVar1);
  return 0;
}

