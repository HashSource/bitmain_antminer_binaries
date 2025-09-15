
void * CRYPTO_malloc_locked(int num,char *file,int line)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  bool bVar3;
  
  if (num < 1) {
    puVar2 = (undefined1 *)0x0;
  }
  else {
    if (allow_customize != 0) {
      allow_customize = 0;
    }
    if (malloc_debug_func != (code *)0x0) {
      if (allow_customize_debug != 0) {
        allow_customize_debug = 0;
      }
      (*malloc_debug_func)(0,num,file,line,0);
    }
    puVar2 = (undefined1 *)(*malloc_locked_ex_func)(num,file,line);
    if (malloc_debug_func != (code *)0x0) {
      (*malloc_debug_func)(puVar2,num,file,line,1);
    }
    bVar3 = puVar2 != (undefined1 *)0x0;
    puVar1 = puVar2;
    if (bVar3) {
      puVar1 = (undefined1 *)(num + -0x800);
    }
    if ((bVar3 && num != 0x800) && (int)puVar1 < 0 == (bVar3 && SBORROW4(num,0x800))) {
      *puVar2 = cleanse_ctr;
    }
  }
  return puVar2;
}

