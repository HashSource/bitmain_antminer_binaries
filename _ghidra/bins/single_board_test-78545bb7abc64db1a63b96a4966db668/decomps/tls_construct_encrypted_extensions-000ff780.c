
int tls_construct_encrypted_extensions(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = tls_construct_extensions(param_1,param_2,0x400,0,0);
  if (iVar1 != 0) {
    iVar1 = 1;
  }
  return iVar1;
}

