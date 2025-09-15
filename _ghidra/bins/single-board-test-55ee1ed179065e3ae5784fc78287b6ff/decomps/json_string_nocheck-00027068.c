
int json_string_nocheck(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = jsonp_malloc(0xc);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      json_init(iVar2,2);
      uVar1 = jsonp_strdup(param_1);
      *(undefined4 *)(iVar2 + 8) = uVar1;
      if (*(int *)(iVar2 + 8) == 0) {
        jsonp_free(iVar2);
        iVar2 = 0;
      }
    }
  }
  return iVar2;
}

