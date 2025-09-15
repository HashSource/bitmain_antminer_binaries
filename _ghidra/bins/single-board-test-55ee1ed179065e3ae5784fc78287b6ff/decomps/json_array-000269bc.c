
int json_array(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = jsonp_malloc(0x18);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    json_init(iVar1,1);
    *(undefined4 *)(iVar1 + 0xc) = 0;
    *(undefined4 *)(iVar1 + 8) = 8;
    uVar2 = jsonp_malloc(*(int *)(iVar1 + 8) << 2);
    *(undefined4 *)(iVar1 + 0x10) = uVar2;
    if (*(int *)(iVar1 + 0x10) == 0) {
      jsonp_free(iVar1);
      iVar1 = 0;
    }
    else {
      *(undefined4 *)(iVar1 + 0x14) = 0;
    }
  }
  return iVar1;
}

