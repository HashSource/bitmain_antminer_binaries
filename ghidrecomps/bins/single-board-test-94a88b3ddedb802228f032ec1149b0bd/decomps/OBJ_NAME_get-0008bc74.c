
char * OBJ_NAME_get(char *name,int type)

{
  int iVar1;
  int iVar2;
  _LHASH *p_Var3;
  void *pvVar4;
  void *pvVar5;
  uint local_20 [2];
  char *local_18;
  
  iVar1 = DAT_0008bda4;
  if (name != (char *)0x0) {
    p_Var3 = *(_LHASH **)(DAT_0008bda4 + 8);
    if (p_Var3 == (_LHASH *)0x0) {
      CRYPTO_mem_ctrl(3);
      p_Var3 = lh_new(DAT_0008bdac,DAT_0008bda8);
      *(_LHASH **)(iVar1 + 8) = p_Var3;
      CRYPTO_mem_ctrl(2);
      p_Var3 = *(_LHASH **)(iVar1 + 8);
      if (p_Var3 == (_LHASH *)0x0) {
        return (char *)0x0;
      }
    }
    local_20[0] = type & 0xffff7fff;
    local_18 = name;
    if (type << 0x10 < 0) {
      pvVar4 = lh_retrieve(p_Var3,local_20);
      pvVar5 = pvVar4;
    }
    else {
      pvVar4 = lh_retrieve(p_Var3,local_20);
      iVar2 = DAT_0008bda4;
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar1 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar2 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar2 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar2 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar1 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar2 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar2 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar2 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar2 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      if (*(int *)((int)pvVar4 + 4) == 0) goto LAB_0008bd82;
      local_18 = *(char **)((int)pvVar4 + 0xc);
      pvVar4 = lh_retrieve(*(_LHASH **)(iVar1 + 8),local_20);
      if (pvVar4 == (void *)0x0) {
        return (char *)0x0;
      }
      pvVar5 = *(void **)((int)pvVar4 + 4);
    }
    if (pvVar5 != (void *)0x0) {
LAB_0008bd82:
      return *(char **)((int)pvVar4 + 0xc);
    }
  }
  return (char *)0x0;
}

