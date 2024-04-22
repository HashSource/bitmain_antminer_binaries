
int EVP_PKEY_CTX_ctrl_str(EVP_PKEY_CTX *ctx,char *type,char *value)

{
  int iVar1;
  EVP_MD *pEVar2;
  code *pcVar3;
  
  if (((ctx == (EVP_PKEY_CTX *)0x0) || (*(int *)ctx == 0)) ||
     (pcVar3 = *(code **)(*(int *)ctx + 0x68), pcVar3 == (code *)0x0)) {
    ERR_put_error(6,0x96,0x93,DAT_000b3eac,0x19f);
    iVar1 = -2;
  }
  else {
    iVar1 = strcmp(type,DAT_000b3ea8);
    if (iVar1 == 0) {
      if ((value == (char *)0x0) || (pEVar2 = EVP_get_digestbyname(value), pEVar2 == (EVP_MD *)0x0))
      {
        ERR_put_error(6,0x96,0x98,DAT_000b3eac,0x1a5);
        iVar1 = 0;
      }
      else if ((*(int *)ctx == 0) || (pcVar3 = *(code **)(*(int *)ctx + 100), pcVar3 == (code *)0x0)
              ) {
        ERR_put_error(6,0x89,0x93,DAT_000b3eac,0x182);
        iVar1 = -2;
      }
      else if (*(uint *)(ctx + 0x10) == 0) {
        ERR_put_error(6,0x89,0x95,DAT_000b3eac,0x189);
        iVar1 = -1;
      }
      else if ((*(uint *)(ctx + 0x10) & 0xf8) == 0) {
        ERR_put_error(6,0x89,0x94,DAT_000b3eac,0x18e);
        iVar1 = -1;
      }
      else {
        iVar1 = (*pcVar3)(ctx,1,0,pEVar2);
        if (iVar1 == -2) {
          ERR_put_error(6,0x89,0x93,DAT_000b3eac,0x195);
        }
      }
    }
    else {
      iVar1 = (*pcVar3)(ctx,type,value);
    }
  }
  return iVar1;
}

