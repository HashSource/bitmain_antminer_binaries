
/* WARNING: Unknown calling convention */

void __libc_csu_init(int argc,char **argv,char **envp)

{
  undefined **ppuVar1;
  int iVar2;
  
  _init((EVP_PKEY_CTX *)argc);
  iVar2 = 0;
  do {
    ppuVar1 = &__frame_dummy_init_array_entry + iVar2;
    iVar2 = iVar2 + 1;
    (*(code *)*ppuVar1)(argc,argv,envp);
  } while (iVar2 != 1);
  return;
}

