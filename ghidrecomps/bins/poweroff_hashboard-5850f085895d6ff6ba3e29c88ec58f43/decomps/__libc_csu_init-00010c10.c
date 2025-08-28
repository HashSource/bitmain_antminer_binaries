
/* WARNING: Unknown calling convention */

void __libc_csu_init(int argc,char **argv,char **envp)

{
  int iVar1;
  undefined **ppuVar2;
  
  _init((EVP_PKEY_CTX *)argc);
  iVar1 = 0;
  ppuVar2 = &__frame_dummy_init_array_entry;
  do {
    iVar1 = iVar1 + 1;
    (*(code *)*ppuVar2)(argc,argv,envp);
    ppuVar2 = ppuVar2 + 1;
  } while (iVar1 != 1);
  return;
}

