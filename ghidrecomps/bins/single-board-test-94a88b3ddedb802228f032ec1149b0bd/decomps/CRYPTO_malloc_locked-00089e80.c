
void * CRYPTO_malloc_locked(int num,char *file,int line)

{
  undefined *puVar1;
  int iVar2;
  code **ppcVar3;
  undefined *puVar4;
  code *pcVar5;
  bool bVar6;
  
  iVar2 = DAT_00089f04;
  if (num < 1) {
    puVar4 = (undefined *)0x0;
  }
  else {
    if (*(int *)(DAT_00089f04 + 0xc) != 0) {
      *(undefined4 *)(DAT_00089f04 + 0xc) = 0;
    }
    ppcVar3 = DAT_00089f0c;
    pcVar5 = *DAT_00089f0c;
    if (pcVar5 != (code *)0x0) {
      if (*(int *)(iVar2 + 0x24) != 0) {
        *(undefined4 *)(DAT_00089f04 + 0x24) = 0;
      }
      (*pcVar5)(0,num,file,line,0);
    }
    puVar4 = (undefined *)(**(code **)(iVar2 + 0x1c))(num,file,line);
    if (*ppcVar3 != (code *)0x0) {
      (**ppcVar3)(puVar4,num,file,line,1);
    }
    bVar6 = puVar4 != (undefined *)0x0;
    puVar1 = puVar4;
    if (bVar6) {
      puVar1 = (undefined *)(num + -0x800);
    }
    if ((bVar6 && num != 0x800) && (int)puVar1 < 0 == (bVar6 && SBORROW4(num,0x800))) {
      *puVar4 = *DAT_00089f08;
    }
  }
  return puVar4;
}

